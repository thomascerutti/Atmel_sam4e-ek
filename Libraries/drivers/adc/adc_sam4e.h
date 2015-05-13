/*
 * adc_sam4e.h
 *
 * Created: 22/04/2015 10:25:11
 *  Author: t.cerutti
 */ 
#include "sam.h"

#ifndef ADC_SAM4E_H_
#define ADC_SAM4E_H_

void adc_unlock_protection(Afec* afec);

void adc_lock_protection(Afec* afec);

void adc_reset(Afec* afec);

void adc_channel_enable(Afec* afec,int channel);

void adc_set_transfer_period(Afec* afec,unsigned char value);

void adc_set_tracking_time(Afec* afec,unsigned char value);

void adc_set_analog_change(Afec* afec,unsigned char value);

void adc_set_stratup_time(Afec* afec,unsigned char value);

void adc_set_prescaler(Afec* afec,unsigned char value);

void adc_extended_mode(Afec* afec); //!

void adc_channel_offset(Afec* afec,int channel);

void adc_channel_gain(Afec* afec,int channel,unsigned char value);

void adc_channel_selection(Afec* afec,int channel);

void adc_set_offset(Afec* afec,int value);

void adc_strat_conversion(Afec* afec);

void adc_get_value(Afec* afec,unsigned short int* value);

#endif /* ADC_SAM4E_H_ */