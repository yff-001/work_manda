#include "scheduler.h"

/* driver */
#include "driver/timer.h"

/* handler */
#include "events.h"
#include "handler/button.h"
#include "handler/communication.h"
#include "handler/display.h"
#include "handler/xtimer.h"

#include "handler/xtimer.h"
#include "ti_msp_dl_config.h"

#include "event_queue.h"
#include "state_machine.h"

static enum power_mode_t current_power_mode;
state_machine_t machine;

void scheduler_init() {
    current_power_mode = HIGH_POWER;

    xtimer_init();
    communication_init();
    state_machine_init(&machine);

    xtimer_create(XTIMER_PERM, E_TIMER_TIMEOUT, 2);                 // for test only
}

void scheduler_high_power() {
    while (current_power_mode == HIGH_POWER) {
        while (has_systick_elapsed() == false && has_permtick_elapsed() == false && event_queue_available() == 0) {
            __WFI();
        }

        if (has_permtick_elapsed() == true) {
            permtick_count();
            
            xtimer_task(XTIMER_PERM);
        }

        if (has_systick_elapsed() == true) {
            systick_count();

            button_task();
            // communication_task();
            display_task();
            xtimer_task(XTIMER_SYS);
        }

        if (event_queue_available()) {
            dispatch_event(&machine);
        }

    }
}

void scheduler_low_power() {
    current_power_mode = POWER_DOWN;
}

void scheduler_power_down() {
    current_power_mode = HIGH_POWER;
}

enum power_mode_t get_power_mode() {
    return current_power_mode;
}
