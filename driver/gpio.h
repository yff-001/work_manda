#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/* Port definition for Pin Group SW */
#define SW_PORT                                                          (GPIOA)

/* Defines for TWO: GPIOA.14 with pinCMx 15 on package pin 18 */
#define SW_TWO_PIN                                              (DL_GPIO_PIN_14)
#define SW_TWO_IOMUX                                             (IOMUX_PINCM15)
/* Port definition for Pin Group GPIO_LEDS */
#define GPIO_LEDS_PORT                                                   (GPIOA)

/* Defines for USER_LED_B: GPIOA.27 with pinCMx 28 on package pin 31 */
#define GPIO_LEDS_USER_LED_B_PIN                                (DL_GPIO_PIN_27)
#define GPIO_LEDS_USER_LED_B_IOMUX                               (IOMUX_PINCM28)
/* Defines for USER_LED_R: GPIOA.26 with pinCMx 27 on package pin 30 */
#define GPIO_LEDS_USER_LED_R_PIN                                (DL_GPIO_PIN_26)
#define GPIO_LEDS_USER_LED_R_IOMUX                               (IOMUX_PINCM27)
/* Defines for USER_LED_G: GPIOA.13 with pinCMx 14 on package pin 17 */
#define GPIO_LEDS_USER_LED_G_PIN                                (DL_GPIO_PIN_13)
#define GPIO_LEDS_USER_LED_G_IOMUX                               (IOMUX_PINCM14)
/* Defines for LED1: GPIOA.0 with pinCMx 1 on package pin 1 */
#define GPIO_LEDS_LED1_PIN                                       (DL_GPIO_PIN_0)
#define GPIO_LEDS_LED1_IOMUX                                      (IOMUX_PINCM1)

void gpio_init();

void gpio_set_tx_pin(uint8_t level);

int gpio_read_vcom();

#endif