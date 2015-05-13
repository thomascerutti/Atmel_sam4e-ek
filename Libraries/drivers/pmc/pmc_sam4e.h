/*
 * uart_sam4e.h
 *
 * Created: 26/03/2015 15:17:43
 *  Author: t.cerutti
 */ 
#ifndef PMC_SAM4E_H_
#define PMC_SAM4E_H_

#include "sam.h"

void pmc_unlock_protection(Pmc* pmc);

void pmc_lock_protection(Pmc* pmc);

int pmc_enable_clock(Pmc* pmc,unsigned char Periph_ID);

#endif /* PMC_SAM4E_H_ */