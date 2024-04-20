#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "events.h"

int event_queue_available();
int event_queue_put(const enum event_t event);
int event_queue_get(enum event_t* event);

#endif
