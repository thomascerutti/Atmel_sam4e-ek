/*
 * timer_sam4e.c
 *
 * Created: 02/04/2015 11:22:47
 *  Author: t.cerutti
 */ 

#include "timer_sam4e.h"

void timer_unlock_protection(Tc* p_timer)
{
	p_timer->TC_WPMR = 0x54494D00;	
}

void timer_lock_protection(Tc* p_timer)
{
	p_timer->TC_WPMR = 0x54494D01;	
}

void timer_enable_clock(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_CCR |= TC_CCR_CLKEN;
}

void timer_disable_clock(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_CCR |= TC_CCR_CLKDIS;
}

void timer_clock_selection(Tc* p_timer,unsigned char Channel,unsigned char Clock)
{
	switch(Clock)
	{
		case 1 : {Clock = TC_CMR_TCCLKS_TIMER_CLOCK1; break;}
		case 2 : {Clock = TC_CMR_TCCLKS_TIMER_CLOCK2; break;}
		case 3 : {Clock = TC_CMR_TCCLKS_TIMER_CLOCK3; break;}
		case 4 : {Clock = TC_CMR_TCCLKS_TIMER_CLOCK4; break;}
		case 5 : {Clock = TC_CMR_TCCLKS_TIMER_CLOCK5; break;}
		case 6 : {Clock = TC_CMR_TCCLKS_XC0; break;}
		case 7 : {Clock = TC_CMR_TCCLKS_XC1; break;}
		case 8 : {Clock = TC_CMR_TCCLKS_XC2; break;}
		default : break;
	}
	p_timer->TC_CHANNEL[Channel].TC_CMR = Clock;
}

void timer_enable_capture_mode(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_CMR &= !TC_CMR_WAVE;
}

void timer_enable_waveform_mode(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_CMR |= TC_CMR_WAVE;
}

void timer_up_counter(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_SMMR &= !TC_SMMR_DOWN;
}

void timer_down_counter(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_SMMR |= TC_SMMR_DOWN;
}

void timer_reset_counter(Tc* p_timer,unsigned char Channel)
{
	p_timer->TC_CHANNEL[Channel].TC_CCR |= TC_CCR_SWTRG;
}

int timer_get_counter_value(Tc* p_timer,unsigned char Channel)
{
	return p_timer->TC_CHANNEL[Channel].TC_CV;
}