/*
 * timer_sam4e.h
 *
 * Created: 02/04/2015 11:23:08
 *  Author: t.cerutti
 */ 


#ifndef TIMER_SAM4E_H_
#define TIMER_SAM4E_H_

#include "../../drivers/pmc/pmc_sam4e.h"
#include "../../drivers/gpio/gpio_sam4e.h"
#include "../../drivers/timer/timer_sam4e.h"

void timer_init(void);
void delay_s(int);
void delay_ms(int);
void delay_us(int);

#endif /* TIMER_SAM4E_H_ */