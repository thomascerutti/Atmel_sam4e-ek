/*
 * gpio_sam4e.c
 *
 * Created: 02/04/2015 15:38:10
 *  Author: t.cerutti
 */ 

#include "gpio_sam4e.h"

void gpio_unlock_protection(Pio* p_pio)
{
	p_pio->PIO_WPMR = 0x50494F00;
}

void gpio_lock_protection(Pio* p_pio)
{
	p_pio->PIO_WPMR = 0x50494F01;
}

void gpio_disable_pin(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_PDR |= pin;
}

void gpio_enable_pin(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_PER |= pin;
}

int gpio_enable_periph(Pio* p_pio,unsigned int pin,char ABCD)
{
	if((ABCD == 'A') || (ABCD == 'a'))
	{
		p_pio->PIO_ABCDSR[0] &= !pin;
		p_pio->PIO_ABCDSR[1] &= !pin;
	}
	else if((ABCD == 'B') || (ABCD == 'b'))
	{
		p_pio->PIO_ABCDSR[0] &= !pin;
		p_pio->PIO_ABCDSR[1] |= pin;
	}
	else if((ABCD == 'C') || (ABCD == 'c'))
	{
		p_pio->PIO_ABCDSR[0] |= pin;
		p_pio->PIO_ABCDSR[1] &= !pin;
	}
	else if((ABCD == 'D') || (ABCD == 'd'))
	{
		p_pio->PIO_ABCDSR[0] |= pin;
		p_pio->PIO_ABCDSR[1] |= pin;
	}
	else 
		return 0;
	
	return 1;
}

void gpio_set_input(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_ODR |= pin;
}

void gpio_set_output(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_OER |= pin;
}

void gpio_set_pin(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_SODR |= pin;
}

void gpio_clear_pin(Pio* p_pio,unsigned int pin)
{
	p_pio->PIO_CODR |= pin;
}

int gpio_get_status(Pio* p_pio,unsigned int pin)
{
	return (p_pio->PIO_PDSR & pin);
}