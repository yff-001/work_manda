#include "cpu.h"

#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#define ONE_MICROSECOND 32

void cpu_delay_microsecond(uint16_t number) {
    delay_cycles(ONE_MICROSECOND * number);
}