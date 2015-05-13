/*
 * pwm_sam4e.h
 *
 * Created: 20/04/2015 09:49:20
 *  Author: t.cerutti
 */ 


#ifndef PWM_SAM4E_H_
#define PWM_SAM4E_H_

#include "sam.h"

void pwm_unlock_protection(Pwm* pwm);

void pwm_lock_protection(Pwm* pwm);

void pwm_enable_channel(Pwm* pwm,int channel);

void pwm_disable_channel(Pwm* pwm,int channel);

void pwm_channel_prescaler(Pwm* pwm,int channel,unsigned char prescaler);

void pwm_set_periode_channel(Pwm* pmw,int channel,unsigned short int value);

unsigned short int pwm_get_periode_channel(Pwm* pwm,int channel);

void pwm_update_periode_channel(Pwm* pwm,int channel, unsigned short int value);

void pwm_set_duty_cycle(Pwm* pwm,int channel,unsigned short int value);

unsigned short int pwm_get_duty_cycle(Pwm* pwm,int channel);

void pwm_update_duty_clycle(Pwm* pwm,int channel,unsigned short int value);

void pwm_init_clock(Pwm* pwm,int channel,unsigned int frequence);

void pwm_set_clock(Pwm* pwm,int channel,unsigned int frequence);

char pwm_get_channel_id(Pwm* pwm);

#endif /* PWM_SAM4E_H_ */