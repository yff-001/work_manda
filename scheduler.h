#ifndef SCHEDULER_H
#define SCHEDULER_H

enum power_mode_t {
    HIGH_POWER,
    LOW_POWER,
    POWER_DOWN
};

void scheduler_init();
void scheduler_high_power();
void scheduler_low_power();
void scheduler_power_down();

enum power_mode_t get_power_mode();

#endif
