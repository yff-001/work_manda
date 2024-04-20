#include "uart.h"

#include "ti_msp_dl_config.h"

/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_0_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM10)
#define GPIO_UART_0_IOMUX_TX                                      (IOMUX_PINCM9)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM10_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                       IOMUX_PINCM9_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (1200)
#define UART_0_IBRD_32_MHZ_1200_BAUD                                      (1666)
#define UART_0_FBRD_32_MHZ_1200_BAUD                                        (43)

volatile uint8_t rx_data = 0;

static void (*write_to_buffer)(uint8_t);

void uart0_init(void (*callback)(uint8_t)) {
    write_to_buffer = callback;

    DL_GPIO_initPeripheralOutputFunction(GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);

    SYSCFG_DL_UART_0_init();
}

static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void) {
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 1200
     *  Actual baud rate: 1200
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_32_MHZ_1200_BAUD, UART_0_FBRD_32_MHZ_1200_BAUD);

    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_0_INST, DL_UART_MAIN_INTERRUPT_RX | DL_UART_MAIN_INTERRUPT_TX);

    /* Configure FIFOs */
    DL_UART_Main_enableFIFOs(UART_0_INST);
    DL_UART_Main_setRXFIFOThreshold(UART_0_INST, DL_UART_RX_FIFO_LEVEL_3_4_FULL);
    DL_UART_Main_setTXFIFOThreshold(UART_0_INST, DL_UART_TX_FIFO_LEVEL_1_2_EMPTY);

    DL_UART_Main_setRXInterruptTimeout(UART_0_INST, 15);

    DL_UART_Main_enable(UART_0_INST);
}

/* it looks like it should belong to a handler */
void uart0_puts(char *message) {
    char* p = message;
    while (*p != '\0') {
        DL_UART_Main_transmitDataBlocking(UART_0_INST, *p);                     // 'blocking' means data is loaded to FIFO only if it's not full
        p++;
    }
}

/*  getPendingInterrupt() returns higherst priority pending UART interrupt
    the question is whether it returns any other interrupts?
*/
void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_0);
            rx_data = DL_UART_Main_receiveData(UART_0_INST);
            // DL_UART_Main_transmitData(UART_0_INST, rx_data);
            write_to_buffer(rx_data);
            break;
        default:
            break;
    }

    // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_13);
}
