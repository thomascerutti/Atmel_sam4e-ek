/*
 * pwm_sam4e.c
 *
 * Created: 20/04/2015 09:49:02
 *  Author: t.cerutti
 */ 

#include "pwm.h"

/* Declaration variables */
int i = 0;

/* Declaration structure */
struct pwm_param
{
    int period_init[4];
	int period_current[4];
    int duty_cycle_init[4];
	int duty_cycle_current[4];
}pwm_params;

void pwm_init(Pwm* p_pwm, int channel)
{
		/* Enable Peripheral clock */
		pmc_unlock_protection(PMC);
		pmc_enable_clock(PMC,36);
		
		/* Enable Peripheral A */
		gpio_disable_pin(PIOD,PIO_PD20);
		gpio_enable_periph(PIOD,PIO_PD20,'A');

		gpio_disable_pin(PIOA,PIO_PA0);
		gpio_enable_periph(PIOA,PIO_PA0,'A');
				
		pwm_unlock_protection(p_pwm);
		/* Disable Channel 0 */
		pwm_disable_channel(p_pwm,channel);
		
		/* Initialize Clock register */
		pwm_init_clock(p_pwm,channel,10);
		
		/* Enable interrupt channel */
// 		PWM->PWM_IER1 |= PWM_IER1_CHID0;
// 		//PWM->PWM_IER1 |= PWM_IER1_FCHID0;
// 		
// 		NVIC_DisableIRQ(PWM_IRQn);
// 		NVIC_ClearPendingIRQ(PWM_IRQn);
// 		NVIC_SetPriority(PWM_IRQn, 0);
// 		NVIC_EnableIRQ(PWM_IRQn);
		
		/* Enable corresponding Channel */

		pwm_enable_channel(p_pwm,channel);
		
		pwm_params.period_init[channel] = pwm_params.period_current[channel] = p_pwm->PWM_CH_NUM[channel].PWM_CPRD;
		pwm_params.duty_cycle_init[channel] = pwm_params.duty_cycle_current[channel] = 50;
}

int pwm_duty_cycle(Pwm* p_pwm,int channel,int duty_cycle)
{
	if(duty_cycle > 100)
	{
		return 0;
	}
	else
	{
		pwm_params.duty_cycle_current[channel] = duty_cycle;
		p_pwm->PWM_CH_NUM[channel].PWM_CDTYUPD = ((pwm_params.period_current[channel] * pwm_params.duty_cycle_current[channel]) / 100);
		return 1;
	}
}

int pwm_period_ms(Pwm* p_pwm,int channel,int period_ms)
{
	if(period_ms > 1000)
	{
		return 0;
	}
	else
	{
		pwm_params.period_current[channel] = ((pwm_params.period_init[channel] * period_ms) / 1000);		
		p_pwm->PWM_CH_NUM[channel].PWM_CPRDUPD = pwm_params.period_current[channel];
		
		pwm_duty_cycle(p_pwm,channel,pwm_params.duty_cycle_current[channel]);
		return 1;
	}
}

// void PWM_Handler(void)
// {
// 	if(i)
//	{
//		PWM->PWM_CH_NUM[0].PWM_CDTYUPD = 0x0000007D;			// Short Flash
//	}
//	else
//	{
//		PWM->PWM_CH_NUM[0].PWM_CDTYUPD = 0x000001F4;			// Long Flash
//	}
//	i = !i;
//}