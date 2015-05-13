/*
 * pwm_sam4e.c
 *
 * Created: 20/04/2015 09:49:02
 *  Author: t.cerutti
 */ 

#include "pwm_sam4e.h"

unsigned short int tab_prescaler[11] = {1,2,4,8,16,32,64,128,256,512,1024};

void pwm_unlock_protection(Pwm* p_pwm)
{
	p_pwm->PWM_WPCR = 0x50574D00;
}

void pwm_lock_protection(Pwm* p_pwm)
{
	p_pwm->PWM_WPCR = 0x50574D01;
}

void pwm_enable_channel(Pwm* p_pwm,int channel)
{
	p_pwm->PWM_ENA |= (1 << channel);
}

void pwm_disable_channel(Pwm* p_pwm,int channel)
{
	p_pwm->PWM_DIS |= (1 << channel);
}

void pwm_channel_prescaler(Pwm* p_pwm,int channel,unsigned char prescaler)
{
	p_pwm->PWM_CH_NUM[channel].PWM_CMR = prescaler;
}

void pwm_set_periode_channel(Pwm* p_pwm,int channel,unsigned short int value)
{
	p_pwm->PWM_CH_NUM[channel].PWM_CPRD = value;
}

unsigned short int pwm_get_periode_channel(Pwm* p_pwm,int channel)
{
	return p_pwm->PWM_CH_NUM[channel].PWM_CPRD;
}

void pwm_update_periode_channel(Pwm* p_pwm,int channel, unsigned short int value)
{
	p_pwm->PWM_CH_NUM[channel].PWM_CPRDUPD = value;
}

void pwm_set_duty_cycle(Pwm* p_pwm,int channel,unsigned short int value)
{
	p_pwm->PWM_CH_NUM[channel].PWM_CDTY = value;
}

unsigned short int pwm_get_duty_cycle(Pwm* p_pwm,int channel)
{
	return p_pwm->PWM_CH_NUM[channel].PWM_CDTY;
}

void pwm_update_duty_clycle(Pwm* p_pwm,int channel,unsigned short int value)
{
	p_pwm->PWM_CH_NUM[channel].PWM_CDTYUPD = value;
}

void pwm_set_prea(Pwm* p_pwm,unsigned char value)
{
	p_pwm->PWM_CLK &= 0xFFFFF0FF;
	p_pwm->PWM_CLK |= ((int)value << 8);
}

void pwm_set_diva(Pwm* p_pwm,unsigned char value)
{
	p_pwm->PWM_CLK &= 0xFFFFFF00;
	p_pwm->PWM_CLK |= value;
}

void pwm_init_clock(Pwm* p_pwm,int channel,unsigned int frequency)
{
	int cprd = 100;
	int diva;
	int i = 0;
	pwm_channel_prescaler(p_pwm,channel,11);
	
	do {
		diva = (SystemCoreClock / tab_prescaler[i]) / (frequency * cprd);
		if (diva <= 255) {
			break;
		}
		i++;
	} while (i < 11);
	
	pwm_set_prea(p_pwm,i);
	pwm_set_diva(p_pwm,diva);
	
	pwm_set_periode_channel(p_pwm,channel,cprd);
	pwm_set_duty_cycle(p_pwm,channel,(cprd/2));
}

void pwm_set_clock(Pwm* p_pwm,int channel,unsigned int frequence)
{
	pwm_channel_prescaler(p_pwm,channel,11);
}

char pwm_get_channel_id(Pwm* p_pwm)
{
	return ((char)p_pwm->PWM_SR);
}