#include "gpio.h"
#include "driver/gpio.h"

#include "ti_msp_dl_config.h"

/*
    DL_GPIO_clearPins(gpioPort, gpioPins);
    DL_GPIO_setPins(gpioPort, gpioPins);
    DL_GPIO_togglePins(gpioPort, gpioPins);
*/

void gpio_init() {
    /* set PA0 as output, clear pin */
    // DL_GPIO_initDigitalOutput(IOMUX_PINCM1);
    // DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_0);
    // DL_GPIO_enableOutput(GPIOA, DL_GPIO_PIN_0);

    DL_GPIO_initDigitalInputFeatures(SW_TWO_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(GPIO_LEDS_USER_LED_B_IOMUX);
    DL_GPIO_initDigitalOutput(GPIO_LEDS_USER_LED_R_IOMUX);
    DL_GPIO_initDigitalOutput(GPIO_LEDS_USER_LED_G_IOMUX);
    DL_GPIO_initDigitalOutput(GPIO_LEDS_LED1_IOMUX);

    DL_GPIO_clearPins(GPIOA, GPIO_LEDS_USER_LED_B_PIN | GPIO_LEDS_USER_LED_R_PIN | GPIO_LEDS_USER_LED_G_PIN | GPIO_LEDS_LED1_PIN);
    DL_GPIO_enableOutput(GPIOA, GPIO_LEDS_USER_LED_B_PIN | GPIO_LEDS_USER_LED_R_PIN | GPIO_LEDS_USER_LED_G_PIN | GPIO_LEDS_LED1_PIN);
}

/* look for a VCOM HIGH, thus reading RX LOW returns a 1/'true' makes sense */
int gpio_read_vcom() {
    if (DL_GPIO_readPins(GPIOA, DL_GPIO_PIN_14)) {
        return 0;
    }
    else {
        return 1;
    }
}

void gpio_set_tx_pin(uint8_t level) {
    if (level == 0) {
        DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_8);
    }
    else {
        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_8);
    }
}
