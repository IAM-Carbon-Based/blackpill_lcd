#include "init.h"

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include "gpio_defines.h"

// Clock Initialization
void init_clock(void) {
  struct rcc_clock_scale clk_settings;

  clk_settings.pllm = 25;
  clk_settings.plln = 200;
  clk_settings.pllp = 2;
  clk_settings.pllq = 4;
  clk_settings.pllr = 2;
  clk_settings.pll_source = RCC_CFGR_PLLSRC_HSE_CLK;
  clk_settings.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_LATENCY_2WS;
  clk_settings.hpre = RCC_CFGR_HPRE_DIV_NONE;
  clk_settings.ppre1 = RCC_CFGR_PPRE_DIV_2;
  clk_settings.ppre2 = RCC_CFGR_PPRE_DIV_NONE;
  clk_settings.voltage_scale = PWR_SCALE1;
  clk_settings.ahb_frequency = 100000000;
  clk_settings.apb1_frequency = 50000000;
  clk_settings.apb2_frequency = 100000000;

  rcc_clock_setup_pll(&clk_settings);
}

// GPIO Initialization
void init_gpio(void) {
  rcc_periph_clock_enable(RCC_GPIOC);
  gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
}
