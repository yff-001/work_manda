#ifndef EVENTS_H
#define EVENTS_H

enum event_t {
    E_BUTTON_PRESS,
    E_BUTTON_RELEASE,

    E_MOTOR_ON,
    E_MOTOR_OFF,

    E_LED_ON,
    E_LED_OFF,

    E_PON,

    E_TIMER_TIMEOUT,

    E_VOID
};

#endif
