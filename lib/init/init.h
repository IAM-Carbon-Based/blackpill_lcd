#ifndef INIT_H
#define INIT_H

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rcc.h>

// Clock setup
void init_clock(void);

// GPIO Setup
void init_gpio(void);

#endif
