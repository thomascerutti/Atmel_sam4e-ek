/*
 * adc_sam4e.c
 *
 * Created: 22/04/2015 10:24:57
 *  Author: t.cerutti
 */ 
#include "adc_sam4e.h"

void adc_init(Afec* p_afec)
{
	/* Initialize clock AFEC0 */
	PMC->PMC_WPMR = 0x504D4300;								// Unlock writing protection
	PMC->PMC_PCER0 |= PMC_PCER0_PID30;						// Enable clock corresponding to AFEC0
	//PMC->PMC_WPMR = 0x504D4301;							// Lock writing protection (Optional)
	
	/* Initialize Analog to Digital Converter */
	p_afec->AFEC_WPMR = 0x41444300;							// Unlock writing protection
	p_afec->AFEC_CR = AFEC_CR_SWRST;						// Reset
	
	/* Channel Selection */
	p_afec->AFEC_CHER = 0;
	p_afec->AFEC_CHER |= AFEC_CHER_CH5;						// Select Channel 5
	
	/* Mode register configuration */
	p_afec->AFEC_MR = 0;
	p_afec->AFEC_MR |= AFEC_MR_TRANSFER(0x00);				// Transfer Period = (TRANSFER * 2 + 3) AFEClock periods
	p_afec->AFEC_MR |= AFEC_MR_TRACKTIM(0x0000);			// Tracking time = (TRACKTIM+1) * AFEClock periods
	p_afec->AFEC_MR |= AFEC_MR_ANACH;
	p_afec->AFEC_MR |= AFEC_MR_STARTUP_SUT0;				// Start-up Time 0 periods of AFEClock
	p_afec->AFEC_MR |= AFEC_MR_PRESCAL(0x00);				// Prescaler AFEClock = MCK / ((PRESCAL+1)*2)
	
	/* Extended Mode register configuration */
	p_afec->AFEC_EMR = 0;
	//p_afec->AFEC_EMR = AFEC_EMR_SIGNMODE_ALL_SIGNED;		// Ne comprend pas pourquoi ca fonctionne pas
	p_afec->AFEC_EMR = 0x03000000;
	
	/* Channel Calibration DC Offset register configuration */
	p_afec->AFEC_CDOR = 0;
	p_afec->AFEC_CDOR |= AFEC_CDOR_OFF5;
	
	/* Channel Gain register configuration */
	p_afec->AFEC_CGR = 0;
	p_afec->AFEC_CGR |= AFEC_CGR_GAIN5(0x1);					// Input Gain
	
	/* Channel Selection register */
	p_afec->AFEC_CSELR = 0;
	p_afec->AFEC_CSELR |= AFEC_CSELR_CSEL(0x5);				// Select display channel
	
	/* Channel Offset Compensation register */
  	p_afec->AFEC_COCR = 0;
  	p_afec->AFEC_COCR |= AFEC_COCR_AOFF(0x800);				// 
	
	//p_afec->AFEC_WPMR = 0x41444301;						// Lock writing protection (Optional)
}


void adc_strat(Afec* p_afec)
{
	p_afec->AFEC_CR = AFEC_CR_START;						// Start
}


void adc_value(Afec* p_afec,unsigned short int* data)
{
	*data = p_afec->AFEC_LCDR;
}