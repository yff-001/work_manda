#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>

void timer_init();

void systick_count();
void permtick_count();
bool has_systick_elapsed();
bool has_permtick_elapsed();

#endif