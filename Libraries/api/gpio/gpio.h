/*
 * gpio.h
 *
 * Created: 02/04/2015 15:38:22
 *  Author: t.cerutti
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../../drivers/gpio/gpio_sam4e.h"
#include "../../drivers/pmc/pmc_sam4e.h"

int gpio_init(Pio*,int pin);

void gpio_output(Pio*,unsigned int pin);

void gpio_input(Pio*,unsigned int pin);

void gpio_set(Pio*,unsigned int,int);

int gpio_check(Pio*,unsigned int);

#endif /* GPIO_H_ */