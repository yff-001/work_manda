#include "state_machine.h"

#include "events.h"
#include "event_queue.h"

#include "driver/uart.h"

#include "handler/xtimer.h"

#include "ti_msp_dl_config.h"

void state_machine_task() {
    // enum event_t current_event;
    // event_queue_get(&current_event);
    // dispatch_event(current_event);
}

#define EXECUTE_ACTION(handler, triggered, state_machine)   \
do {                                                        \
    if (handler != 0) {                                     \
        result = handler(state_machine);                    \
        switch (reslut) {                                   \
            case TRIGGER_TO_SELF:                           \
                triggered = true;                           \
            case EVENT_HANDLED:                             \
                break;                                      \
            default:                                        \
                return result;                              \
        }                                                   \
    }                                                       \
} while (0)

enum user_state_t {
    USER,
    SERVICE
};

enum operate_state_t {
    IDLE,
    MOTOR_ON,
    CHARGE
};

static enum result_t user_action(state_machine_t* const state);
static enum result_t user_entry(state_machine_t* const state);
static enum result_t user_exit(state_machine_t* const state);
static enum result_t service_action(state_machine_t* const state);
static enum result_t service_entry(state_machine_t* const state);
static enum result_t service_exit(state_machine_t* const state);
static enum result_t idle_action(state_machine_t* const state);
static enum result_t idle_entry(state_machine_t* const state);
static enum result_t idle_exit(state_machine_t* const state);
static enum result_t motor_on_action(state_machine_t* const state);
static enum result_t motor_on_entry(state_machine_t* const state);
static enum result_t motor_on_exit(state_machine_t* const state);
static enum result_t charge_action(state_machine_t* const state);
static enum result_t charge_entry(state_machine_t* const state);
static enum result_t charge_exit(state_machine_t* const state);

void dispatch_event(state_machine_t* const p_state_machine) {
    enum event_t current_event;
    event_queue_get(&current_event);

    /* it is possible to iterate a list of state machines */
    
    do {
        const state_t* p_state = p_state_machine->state;

        enum result_t result = p_state->handler(p_state_machine);       // call event handler

        switch (result) {
            case EVENT_HANDLED:
                DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_27);
                break;

            /* specific to a hierarchical state machine */
            case EVENT_NOT_HANDLED:
                do {
                    // p_state = p_state -> parent;
                } while (0 /* */);
                break;

            default:
                break;

        }

        break;
    } while (1);
}

void traverse_state(state_machine_t* const p_state_machine) {
    //
}

/* states on the same level are grouped in an array */
static const state_t user_modes[2];
static const state_t operate_modes[3];

static const state_t user_modes[] = {
    [USER] = {
        .handler = user_action,
        .entry   = user_entry,
        .exit    = user_exit,
        .parent  = 0,
        .child   = operate_modes,
        .level   = 0,
    },
    [SERVICE] = {
        .handler = service_action,
        .entry   = service_entry,
        .exit    = service_exit,
        .parent  = 0,
        .child   = 0,
        .level   = 0,
    }
};

static const state_t operate_modes[] = {
    [IDLE] = {
        .handler = idle_action,
        .entry   = idle_entry,
        .exit    = idle_exit,
        .parent  = &user_modes[0],
        .child   = 0,
        .level   = 1,
    },
    [MOTOR_ON] = {
        .handler = motor_on_action,
        .entry   = motor_on_entry,
        .exit    = motor_on_exit,
        .parent  = &user_modes[0],
        .child   = 0,
        .level   = 1,
    },
    [CHARGE] = {
        .handler = charge_action,
        .entry   = charge_entry,
        .exit    = charge_exit,
        .parent  = &user_modes[0],
        .child   = 0,
        .level   = 1,
    }
};

void state_machine_init(state_machine_t* const p_state_machine) {
    p_state_machine->state = &user_modes[0];
    user_entry(p_state_machine);
}

static enum result_t user_action(state_machine_t* const state) {
    // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_27);
    uart0_puts("User Mode Action\r\n");
    return EVENT_HANDLED;
}

static enum result_t user_entry(state_machine_t* const state) {
    // DL_GPIO_togglePins(GPIOA, DL_GPIO_PIN_27);
    return EVENT_HANDLED;
}

static enum result_t user_exit(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t service_action(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t service_entry(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t service_exit(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t idle_action(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t idle_entry(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t idle_exit(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t motor_on_action(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t motor_on_entry(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t motor_on_exit(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t charge_action(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t charge_entry(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}

static enum result_t charge_exit(state_machine_t* const state) {
    //
    return EVENT_HANDLED;
}
