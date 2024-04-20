#include "timer.h"
#include "driver/timer.h"
#include "ti_msp_dl_config.h"
#include <sys/_stdint.h>

/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (127U)

static volatile uint8_t systick_temp = 0;
static volatile uint8_t permtick_temp = 0;
static uint32_t systick_cnt;
static uint32_t systick_cnt_accumulated;
static uint32_t permtick_cnt;
static uint32_t permtick_cnt_accumulated;

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void);


void timer_init() {
    DL_TimerG_reset(TIMER_0_INST);
    DL_TimerG_enablePower(TIMER_0_INST);
    SYSCFG_DL_TIMER_0_init();

    /*  systick is a 24-bit counter
        the desired period is 10 ms
    */
    DL_SYSTICK_config(320000);
}

/*
 * Timer clock configuration to be sourced by LFCLK /  (32768 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   128 Hz = 32768 Hz / (1 * (255 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_LFCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_0_INST_LOAD_VALUE = (1000 ms * 128 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_0TimerConfig = {
    .period     = TIMER_0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void) {
    DL_TimerG_setClockConfig(TIMER_0_INST, (DL_TimerG_ClockConfig *) &gTIMER_0ClockConfig);
    DL_TimerG_initTimerMode(TIMER_0_INST, (DL_TimerG_TimerConfig *) &gTIMER_0TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_0_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_0_INST);
}

void TIMG0_IRQHandler(void)
{
    permtick_temp++;

    /* ISR seems to work fine without checking interrupt source */
    // static uint32_t count = TIMER_500_MILLISECONDS_TICKS;
    // switch (DL_TimerG_getPendingInterrupt(TIMG0)) {
    //     case DL_TIMER_IIDX_ZERO:
    //         DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_0);
    //         break;
    //     default:
    //         break;
    // }
}

void SysTick_Handler(void) {
    systick_temp++;
}

void systick_count() {
    if (systick_temp > 0) {
        systick_temp--;
        systick_cnt++;
        systick_cnt_accumulated++;
    }
}

bool has_systick_elapsed() {
    bool ret = false;
    if (systick_temp > 0) {
        ret = true;
    }
    return ret;
}

void permtick_count() {
    if (permtick_temp > 0) {
        permtick_temp--;
        permtick_cnt++;
        permtick_cnt_accumulated++;
    }
}

bool has_permtick_elapsed() {
    bool ret = false;
    if (permtick_temp > 0) {
        ret = true;
    }
    return ret;
}
