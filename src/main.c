#include <libopencm3/stm32/gpio.h>

#include "../lib/init/init.h"

int main(void) {
  init_clock();
  init_gpio();

  while (1) {
    gpio_toggle(GPIOC, GPIO13);         /* LED on/off */
    for (int i = 0; i < 1000000; i++) { /* Wait a bit. */
      __asm__("nop");
    }

    return 0;
  }
}