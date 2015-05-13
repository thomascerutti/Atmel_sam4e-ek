/*
 * adc.h
 *
 * Created: 22/04/2015 10:25:11
 *  Author: t.cerutti
 */ 
#include "../../drivers/adc/adc_sam4e.h"

#ifndef ADC_H_
#define ADC_H_

void adc_init(Afec*);

void adc_strat(Afec*);

void adc_value(Afec*,unsigned short int*);

#endif /* ADC_H_ */