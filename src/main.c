#include <i2c_lcd.h>
#include <init.h>
#include <libopencm3/stm32/gpio.h>

int main(void) {
  init_clock();
  init_gpio();

  lcd_init(16, 2, LCD_5x8DOTS);

  print("Hello World!");

  while (1) {
    // gpio_toggle(GPIOC, GPIO13);         /* LED on/off */
    // for (int i = 0; i < 1000000; i++) { /* Wait a bit. */
    //   __asm__("nop");
    // }
  }
  return 0;
}