/*
 * uart_sam4e.h
 *
 * Created: 26/03/2015 15:17:45
 *  Author: t.cerutti
 */ 

 #include "pmc_sam4e.h"
 
void pmc_unlock_protection(Pmc* p_pmc)
{
	p_pmc->PMC_WPMR = 0x504D4300;
}

void pmc_lock_protection(Pmc* p_pmc)
{
	p_pmc->PMC_WPMR = 0x504D4301;
}

int pmc_enable_clock(Pmc* p_pmc,unsigned char id)
{
	if((id > 6) & (id < 32))
		p_pmc->PMC_PCER0 |= (1<<id);
	else if((id > 31) & (id < 48))
		p_pmc->PMC_PCER1 |= (1<<(id - 32));
	else
		return 0;
	
	return 1;
}