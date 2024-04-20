#ifndef XTIMER_H
#define XTIMER_H

#include "../events.h"

#include <stdint.h>

enum xtimer_t {
    XTIMER_PERM,
    XTIMER_SYS,
    XTIMER_COUNT
};

void xtimer_init();
void xtimer_create(const enum xtimer_t timer_type, const enum event_t event, const uint32_t duration);
void xtimer_cancel(const enum xtimer_t timer_type, const enum event_t event);
void xtimer_task(const enum xtimer_t timer_type);

#endif