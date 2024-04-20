#include "button.h"

#include "events.h"
#include "event_queue.h"

#include "ti_msp_dl_config.h"

#include <stdint.h>


void button_init() {
    //
}

void button_task() {
    static uint16_t button_level = 0;                                                   // stores history of logic levels on button gpio

    /* either configure PA18 as input
     * or PA14 as input with pull-up resistor
     */
    if (!DL_GPIO_readPins(GPIOA, DL_GPIO_PIN_14)) {
        button_level = (button_level << 1) | 0x01;
    }
    else {
        button_level = (button_level << 1) | 0x00;
    }

    if ((button_level & 0xfff) == 0x07f) {                                              // button press
        // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_27);
        event_queue_put(E_BUTTON_PRESS);
        button_level = 0xffff;
    }
    else if ((button_level & 0xfff) == 0xf80) {                                         // button release
        // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_26);
        event_queue_put(E_BUTTON_RELEASE);
        button_level = 0x0;
    }
}
