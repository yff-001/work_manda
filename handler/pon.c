#include "pon.h"

#include "../driver/cpu.h"
#include "../driver/gpio.h"
#include "driver/cpu.h"
#include "driver/gpio.h"

#define VCOM_CHECK_COUNT    4

static uint8_t check_comm_request();
static void pon_debounce();

void pon_task() {
    // uint16_t vcom_inverted = 0;                     // check the inverted VCOM level

    // vcom_inverted = vcom_inverted << 1;             
    // if (gpio_read_vcom()) {                         // look for a VCOM HIGH, thus reading RX LOW returns a 1 makes sense
    //     vcom_inverted |= 1;
    // }

    pon_debounce();
}

/*  this functions checks if voltage present on VCOM is 3.3V or 12V
    the threshold voltage is set by a zener diode
    when the voltage is greater than the threshold voltage, i.e. 12V
    the zener diode conducts, and T401B turns on, thus shorting TX to GND
    pulling TX HIGH won't turn on T401A, VCOM will not be shorted to GND
    gpio_read_vcom() always returns 1
    the opposite is true if voltage on VCOM is less than threshold, i.e. 3.3V
*/
static uint8_t check_comm_request() {
    uint8_t read_count = 0;

    gpio_set_tx_pin(0);

    for (uint8_t count = 0; count < VCOM_CHECK_COUNT; count++) {
        if (count == 0) {
            cpu_delay_microsecond(75);
        }
        else {
            cpu_delay_microsecond(25);
        }

        if (gpio_read_vcom() == 0) {
            read_count++;
        }
    }

    gpio_set_tx_pin(0);

    if (read_count < 3) {
        return 0;
    }
    else {
        return 1;
    }
}

/*  xxx
*/
static void pon_debounce() {
    /* check the inverted VCOM level */
    uint16_t vcom_inverted = 0;

    /* set TX high (but why?) */
    
    for (;;) {
        //
    }

    /* set TX low (again why?) */

    vcom_inverted = (vcom_inverted << 1);
    if (gpio_read_vcom() == 1) {                      // look for a VCOM HIGH, thus reading RX LOW should return 1
        vcom_inverted |= 1;
    }

    if (vcom_inverted == 3) {
        /* xxxx xxxx xxxx 0011 */

        /* need to enclose this with conditions */
        check_comm_request();
    }
    else if (vcom_inverted == 0x1f) {
        /* xxxx xxxx 0001 1111 */
    }
    else if (0) {
        /* */
    }
    else if (0) {
        /* */
    }
    else if (0) {
        /* */
    }
}
