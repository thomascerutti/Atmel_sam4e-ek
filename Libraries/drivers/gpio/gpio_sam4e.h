/*
 * gpio_sam4e.h
 *
 * Created: 02/04/2015 15:38:22
 *  Author: t.cerutti
 */ 

#ifndef GPIO_SAM4E_H_
#define GPIO_SAM4E_H_

#include "sam.h"

void gpio_unlock_protection(Pio* Port);

void gpio_lock_protection(Pio* Port);

void gpio_disable_pin(Pio* Port,unsigned int Pin);

void gpio_enable_pin(Pio* Port,unsigned int Pin);

int gpio_enable_periph(Pio* Port,unsigned int Pin,char ABCD);

void gpio_set_input(Pio* Port,unsigned int Pin);

void gpio_set_output(Pio* Port,unsigned int Pin);

void gpio_set_pin(Pio* Port,unsigned int Pin);

void gpio_clear_pin(Pio* Port,unsigned int Pin);

int gpio_get_status(Pio* Port,unsigned int Pin);

#endif /* GPIO_SAM4E_H_ */