/*
 * timer_sam4e.c
 *
 * Created: 02/04/2015 11:22:47
 *  Author: t.cerutti
 */ 

#include "timer.h"

void timer_init(void)
{
	/* Initialize PMC for Timer Clock 3 */
	pmc_unlock_protection(PMC);									// Unlock writing protection
	pmc_enable_clock(PMC,24);
	//PMC->PMC_WPMR = 0x504D4301;								// Lock writing protection (Optional)
	
	/* Initialize Peripheral mode B */
	gpio_unlock_protection(PIOC);								// Unlock writing protection							
	gpio_disable_pin(PIOC,PIO_PC25);							// Enable peripheral mode for Pin25
	gpio_enable_periph(PIOC,PIO_PC25,'B');						// Enable peripheral mode B for ID 24
	//gpio_lock_protection(PIOC);								// Lock writing protection (optional)
	
	/* Initialize Timer1 channel0 Clock3 */	
	timer_unlock_protection(TC1);								// Unlock writing protection
	timer_enable_clock(TC1,0);									// Enable Clock
	
	timer_clock_selection(TC1,0,3);								// Enable Timer Clock 3
	timer_enable_capture_mode(TC1,0);							// Enable Capture mode / Disable Waveform mode				
	
	timer_up_counter(TC1,0);									// Enable up counter 
	//timer_lock_protection(TC1);								// Lock writing protection (Optional)
}

void delay_s(int time_s)
{
	timer_reset_counter(TC1,0);									// Reset Counter
	while(timer_get_counter_value(TC1,0) < (0x03938700 * time_s));	// Wait time_s * 1s
}

void delay_ms(int time_ms)
{
	timer_reset_counter(TC1,0);									// Reset Counter
	while(timer_get_counter_value(TC1,0) < (0x0000EA60 * time_ms));	// Wait time_ms * 1ms
}

void delay_us(int time_us)
{
	timer_reset_counter(TC1,0);									// Reset Counter
	while(timer_get_counter_value(TC1,0) < (0x0000003C * time_us));	// Wait time_us * 1us
}