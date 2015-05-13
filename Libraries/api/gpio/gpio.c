/*
 * gpio.c
 *
 * Created: 02/04/2015 15:38:10
 *  Author: t.cerutti
 */ 
#include "gpio.h"

int gpio_init(Pio* p_pio, int pin)
{
	/* Initialize PORT */
//	PMC->PMC_WPMR = 0x504D4300;								// Unlock writing protection
	pmc_unlock_protection(PMC);
	if(p_pio == PIOA)
//		PMC->PMC_PCER0 |= PMC_PCER0_PID9;					// Enable clock corresponding to PIOA
		pmc_enable_clock(PMC,9); 
	else if(p_pio == PIOB)	
//		PMC->PMC_PCER0 |= PMC_PCER0_PID10;					// Enable clock corresponding to PIOB
		pmc_enable_clock(PMC,10);
	else if(p_pio == PIOC)
//		PMC->PMC_PCER0 |= PMC_PCER0_PID11;					// Enable clock corresponding to PIOC 
		pmc_enable_clock(PMC,11);
	else if(p_pio == PIOD)
//		PMC->PMC_PCER0 |= PMC_PCER0_PID12;					// Enable clock corresponding to PIOD
		pmc_enable_clock(PMC,12);
	else if(p_pio == PIOE)
//		PMC->PMC_PCER0 |= PMC_PCER0_PID13;					// Enable clock corresponding to PIOD
		pmc_enable_clock(PMC,13);
	else
		return 0;
	//PMC->PMC_WPMR = 0x504D4301;							// Lock writing protection (Optional)

	/* Initialize Pin */
// 	p_pio->PIO_WPMR = 0x50494F00;							// Unlock writing protection
// 	p_pio->PIO_PER |= pin;									// Enable Pin control
// 	p_pio->PIO_OER |= pin;									// Enable Pin in Output
// 	p_pio->PIO_PUER |= pin;									// Enable Pin in Pull-up
	//p_pio->PIO_WPMR = 0x50494F01;						// Lock writing protection (Optional)
	
	gpio_unlock_protection(p_pio);
	gpio_enable_pin(p_pio,pin);
	gpio_output(p_pio,pin);
	
	return 1;	
}

void gpio_output(Pio* p_pio,unsigned int pin)
{
// 	p_pio->PIO_WPMR = 0x50494F00;							// Unlock writing protection
// 	p_pio->PIO_OER |= pin;									// Enable Pin in Output
	//p_pio->PIO_WPMR = 0x50494F01;						// Lock writing protection (Optional)
	gpio_unlock_protection(p_pio);
	gpio_set_output(p_pio,pin);
}

void gpio_input(Pio* p_pio,unsigned int pin)
{
// 	p_pio->PIO_WPMR = 0x50494F00;							// Unlock writing protection
// 	p_pio->PIO_ODR |= pin;									// Enable Pin in Input
	//p_pio->PIO_WPMR = 0x50494F01;							// Lock writing protection (Optional)
	gpio_unlock_protection(p_pio);
	gpio_set_input(p_pio,pin);
}

void gpio_set(Pio* p_pio,unsigned int pin,int lvl)
{
	if(lvl)
	{
//		p_pio->PIO_SODR |= pin;
		gpio_set_pin(p_pio,pin);
	}
	else
	{
//		p_pio->PIO_CODR |= pin;
		gpio_clear_pin(p_pio,pin);
	}
}

int gpio_check(Pio* p_pio,unsigned int pin)
{
//	return (p_pio->PIO_PDSR & pin);
	return gpio_get_status(p_pio,pin);
}