#ifndef COMMUNICATION_H
#define COMMUNICATION_H

// #define RX_BUFFER_SIZE  64

// volatile uint8_t rx_buffer[RX_BUFFER_SIZE] = {0};
// volatile uint8_t rx_buffer_index;
// volatile uint8_t rx_buffer_head;
// volatile uint8_t rx_buffer_tail;

void communication_init();
void communication_task();

#endif