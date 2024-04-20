#include <stdint.h>
#include <stdio.h>

#include "event_queue.h"
// #include "events.h"

#define QUEUE_SIZE  16

int event_queue[QUEUE_SIZE] = {0};
int event_queue_index = 0;
int event_queue_head = 0;
int event_queue_tail = 0;

int event_queue_available() {
    return (QUEUE_SIZE + event_queue_head - event_queue_tail) % QUEUE_SIZE;
}

int event_queue_put(const enum event_t event) {
    int ret = 0;

    event_queue_index = (event_queue_index + 1) % QUEUE_SIZE;
    if (event_queue_index != event_queue_tail) {                        // if queue is full, discard event
        event_queue[event_queue_head] = event;
        event_queue_head = event_queue_index;
    }

    return ret;
}

int event_queue_get(enum event_t* event) {
    int ret = 0;
    if (event != NULL) {
        *event = event_queue[event_queue_tail];
        event_queue_tail = (event_queue_tail + 1) % QUEUE_SIZE;
    }

    return ret;
}
