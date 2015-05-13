/*
 * adc_sam4e.c
 *
 * Created: 22/04/2015 10:24:57
 *  Author: t.cerutti
 */ 
#include "adc_sam4e.h"

void adc_unlock_protection(Afec* p_afec)
{
	p_afec->AFEC_WPMR = 0x41444300;	
}

void adc_lock_protection(Afec* p_afec)
{
	p_afec->AFEC_WPMR = 0x41444301;	
}

void adc_reset(Afec* p_afec)
{
	p_afec->AFEC_CR |= AFEC_CR_SWRST;
}

void adc_channel_enable(Afec* p_afec,int channel)
{
	p_afec->AFEC_CHER = 0;
	p_afec->AFEC_CHER = (1 << channel);
}

void adc_set_transfer_period(Afec* p_afec,unsigned char value)
{
	p_afec->AFEC_MR &= 0xCFFFFFFF;
	p_afec->AFEC_MR |= AFEC_MR_TRANSFER(value);
}

void adc_set_tracking_time(Afec* p_afec,unsigned char value)
{
	p_afec->AFEC_MR &= 0xF0FFFFFF;
	p_afec->AFEC_MR |= AFEC_MR_TRACKTIM(value);
}

void adc_set_analog_change(Afec* p_afec)
{
	p_afec->AFEC_MR |= AFEC_MR_ANACH;
}

void adc_set_stratup_time(Afec* p_afec,unsigned char value)
{
	p_afec->AFEC_MR &= 0xFFF0FFFF;
	p_afec->AFEC_MR |= (value << 16);
}

void adc_set_prescaler(Afec* p_afec,unsigned char value)
{
	p_afec ->AFEC_MR &= 0xFFFF00FF
	p_afec->AFEC_MR |= AFEC_MR_PRESCAL(value);
}

void adc_channel_offset(Afec* p_afec,int channel)
{
	p_afec->AFEC_CDOR = 0;
	p_afec->AFEC_CDOR |= (1 << channel);
}

void adc_channel_gain(Afec* p_afec,int channel,unsigned char value)
{
	p_afec->AFEC_CGR = 0;
	p_afec->AFEC_CGR |= (value << (2 * channel));
}

void adc_channel_selection(Afec* p_afec,int channel)
{
	p_afec->AFEC_CSELR = 0;
	p_afec->AFEC_CSELR |= AFEC_CSELR_CSEL(channel);
}

void adc_set_offset(Afec* p_afec,int value)
{
	p_afec->AFEC_COCR = 0;
  	p_afec->AFEC_COCR |= AFEC_COCR_AOFF(value);
}

void adc_strat_conversion(Afec* afec)
{
	p_afec->AFEC_CR = AFEC_CR_START;
}

void adc_get_value(Afec* afec,unsigned short int* value)
{
	*value = p_afec->AFEC_LCDR;
}

