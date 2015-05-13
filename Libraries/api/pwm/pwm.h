/*
 * pwm_sam4e.h
 *
 * Created: 20/04/2015 09:49:20
 *  Author: t.cerutti
 */ 


#ifndef PWM_SAM4E_H_
#define PWM_SAM4E_H_

#include "../../drivers/pwm/pwm_sam4e.h"
#include "../../drivers/gpio/gpio_sam4e.h"
#include "../../drivers/pmc/pmc_sam4e.h"

void pwm_init(Pwm*,int channel);

int pwm_duty_cycle(Pwm*,int,int);

int pwm_period_ms(Pwm*,int,int);

#endif /* PWM_SAM4E_H_ */