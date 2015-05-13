/*
 * i2c_sam4e.c
 *
 * Created: 02/04/2015 14:31:39
 *  Author: t.cerutti
 */ 

#include "i2c.h"
#include "sam.h"

int i2c_init(Twi* p_twi)
{
//	PMC->PMC_WPMR = 0x504D4300;									// Unlock writing protection
	pmc_unlock_protection(PMC);
	
	if(p_twi == TWI0)
	{
		/* Initialize PMC for TWI0 */
		pmc_enable_clock(PMC,17);

		/* Disable PIOA3 and PIOA4 (enable peripheral mode) */
		gpio_unlock_protection(PIOA);
		gpio_disable_pin(PIOA,(PIO_PA3 | PIO_PA4));
			
		/* Enable peripheral A */
		gpio_enable_periph(PIOA,(PIO_PA3 | PIO_PA4),'A');
	}
	else if (p_twi == TWI1)
	{
 		/* Initialize PMC for TWI1 */
 		pmc_enable_clock(PMC,18);
 
 		/* Disable PIOB4 and PIOB5 (enable peripheral mode) */
		gpio_unlock_protection(PIOB);
		gpio_disable_pin(PIOB,(PIO_PB4 | PIO_PB5));
 		
 		/* Enable peripheral B */
		gpio_enable_periph(PIOB,(PIO_PB4 | PIO_PB5),'A');	
	}
	else 
		return 0;
		
	/* Configure TWI0 in master receiver */
	twi_master_disable(p_twi);
	twi_slave_disable(p_twi);
	twi_master_enable(p_twi);
	twi_set_clock_waveform(p_twi,0x0009595);
	
	return 1;
}

int i2c_master_write(Twi* p_twi,unsigned int address,char* buffer,int length)
{
	int cnt = length;
	
	twi_set_address(p_twi,address);
	twi_master_write_direction(p_twi);

	twi_start(p_twi);
	
	while(cnt > 0)
	{
		if(twi_get_nack(p_twi))
			return 0;
		
		if(!twi_tx_is_ready(p_twi))
			continue;
		
		twi_set_data(p_twi,*buffer++);
		cnt--;
	}
	
	while(1)
	{
		if(twi_get_nack(p_twi))
			return 0;
		
		if(twi_tx_is_ready(p_twi))
			break;
	}
	
	twi_stop(p_twi);
	
	while(!twi_tx_is_complete(p_twi))
	
	return 1;
}

int i2c_master_read(Twi* p_twi,unsigned int address,char* p_buffer, int length)
{
	int cnt = length;
	int stop_sent = 0;
	
	twi_set_address(p_twi,address);
	twi_master_read_direction(p_twi);

	twi_start(p_twi);

	while (cnt > 0) {
		if(twi_get_nack(p_twi)){
			return 0;
		}

		if (cnt == 1  && !stop_sent) {
			twi_stop(p_twi);
			stop_sent = 1;
		}

		if(!twi_rx_is_ready(p_twi)){
			continue;
		}
		twi_get_data(p_twi,*p_buffer++);

		cnt--;
	}

	while(!twi_tx_is_complete(p_twi));

	return 1;
}