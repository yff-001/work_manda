// #include <stdint.h>
#include <stdbool.h>

#include "xtimer.h"
#include "../event_queue.h"

#define MAX_NUMBER_PERM 5
#define MAX_NUMBER_SYS  10

struct timer_t {
    uint32_t duration;
    enum event_t event;
    enum xtimer_t type;
    bool is_suspended;
};

struct timer_t timers[MAX_NUMBER_PERM + MAX_NUMBER_SYS];

/* function prototype */
static bool create_timer(const enum xtimer_t timer_type, const enum event_t event, const uint32_t duration);

void xtimer_init() {
    for (uint8_t index = 0; index < (MAX_NUMBER_PERM + MAX_NUMBER_SYS); index++) {
        timers[index].duration = 0;
        timers[index].event = E_VOID;
        timers[index].is_suspended = false;
        if (index < MAX_NUMBER_PERM) {
            timers[index].type = XTIMER_PERM;
        }
        else {
            timers[index].type = XTIMER_SYS;
        }
    }
}

void xtimer_create(const enum xtimer_t timer_type, const enum event_t event, const uint32_t duration) {
    create_timer(timer_type, event, duration);
}

void xtimer_cancel(const enum xtimer_t timer_type, const enum event_t event) {

}

void xtimer_task(const enum xtimer_t timer_type) {
    for (uint8_t index = 0; index < (MAX_NUMBER_PERM + MAX_NUMBER_SYS); index++) {
        if (timers[index].type == timer_type) {
            if (timers[index].duration > 0) {
                if (timers[index].is_suspended == false) {
                    timers[index].duration--;
                    if (timers[index].duration == 0) {
                        event_queue_put(timers[index].event);
                    }
                }
            }
        }
    }
}

static bool create_timer(const enum xtimer_t timer_type, const enum event_t event, const uint32_t duration) {
    /* overwrite existing timer if same type */
    for (uint8_t index = 0; index < (MAX_NUMBER_PERM + MAX_NUMBER_SYS); index++) {
        if (timers[index].type == timer_type && timers[index].event == event) {
            timers[index].duration = duration;
            timers[index].is_suspended = false;
            return true;
        }
    }
    /* create new timer if no existing one found */
    for (uint8_t index = 0; index < (MAX_NUMBER_PERM + MAX_NUMBER_SYS); index++) {
        if (timers[index].type == timer_type && timers[index].duration == 0) {
            timers[index].duration = duration;
            timers[index].event = event;
            timers[index].is_suspended = false;
            return true;
        }
    }
    return false;
}
