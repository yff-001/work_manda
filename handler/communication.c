#include "communication.h"

#include "driver/gpio.h"
#include "driver/uart.h"

#include <stdint.h>

#define BUFFER_SIZE 255

enum communication_state_t {
    MESSAGE_IDLE,
    MESSAGE_SETUP,
    MESSAGE_SYNC,
    MESSAGE_WAIT_FOR_COMMAND,
    MESSAGE_START,
    MESSAGE_LENGTH,
    MESSAGE_BODY,
    MESSAGE_DEFAULT
};

static enum communication_state_t current_state;

volatile static uint8_t buffer_index = 0;

void rx_put(uint8_t data);

void communication_init() {
    uart0_init(&rx_put);
    uart0_puts("UART ready\r\n");
    current_state = MESSAGE_DEFAULT;
}

uint8_t message_buffer[BUFFER_SIZE] = {0};

/*  a section performs actions similar to pon.c
    for power plug detection, RX pin should be configured as INPUT
*/
// void pon_task() {
//     /* check the inverted VCOM level */
//     uint16_t vcom_inverted = 0;

//     /* set TX high (but why?) */
    
//     for (;;) {
//         //
//     }

//     /* set TX low (again why?) */

//     vcom_inverted = vcom_inverted << 1;
//     if (gpio_read_vcom()) {                      // look for a VCOM HIGH, thus reading RX LOW returns a 1 makes sense
//         vcom_inverted |= 1;
//     }
// }

/*  a section performs actions similar to com.c
    for communication, RX is configured as UART initialization process
*/

void rx_put(uint8_t data) {
    message_buffer[buffer_index] = data;
    buffer_index++;

    switch (current_state) {
        case MESSAGE_IDLE:
        if (0 /* receives comm. request */) {                       // from PON module
            current_state = MESSAGE_START;
        }
        break;
        case MESSAGE_SETUP:
        // wait 30 ms, and enable serial
        if (0 /* wait period ends */) {
            current_state = MESSAGE_SYNC;
        }
        break;
        case MESSAGE_SYNC:
        // send sync byte (0x55), set up 20 ms timeout              // if timeout, exit super-state
        if (0 /* send comfirmation arrives */) {
            current_state = MESSAGE_WAIT_FOR_COMMAND;
        }
        break;
        case MESSAGE_START:
        break;
        case MESSAGE_LENGTH:
        break;
        case MESSAGE_BODY:
        break;
        default:
        break;
    }
}
