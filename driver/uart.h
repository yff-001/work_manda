#ifndef UART_H
#define UART_H

#include <stdint.h>

void SYSCFG_DL_UART_0_init(void);

void uart0_init(void (*callback)(uint8_t));
void uart0_puts(char *message);

#endif
