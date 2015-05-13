/*
 * can_sam4e.c
 *
 * Created: 29/04/2015 14:15:58
 *  Author: t.cerutti
 */

#include "can.h"

int can_init(Can* p_can)
{
	PMC->PMC_WPMR = 0x504D4300;								// Unlock writing protection
	p_can->CAN_WPMR = 0x43414E00;							// Unlock writing protection
	
	p_can->CAN_MR &= !CAN_MR_CANEN;							// Disable CAN
	
	if(p_can == CAN0)
	{
		/* Disable PB2 and PB3 (enable peripheral mode) for CAN0 */
		PIOB->PIO_PDR |= PIO_PB2;
		PIOB->PIO_PDR |= PIO_PB3;
		
		/* Initialize Peripheral A for CAN0 */
		PIOA->PIO_ABCDSR[0] &= !(PIO_PB2 | PIO_PB3);
		PIOA->PIO_ABCDSR[1] &= !(PIO_PB2 | PIO_PB3);
		
		/* Initialize Peripheral Clock PID37 for CAN0 */
		PMC->PMC_PCER1 |= PMC_PCER1_PID37;
	}
	else if(p_can == CAN1)
	{
		/* Disable PC12 and PC15 (enable peripheral mode) for CAN 1 */
		PIOC->PIO_PDR |= PIO_PC12;
		PIOC->PIO_PDR |= PIO_PC15;
				
		/* Initialize Peripheral C for CAN1 */
		PIOC->PIO_ABCDSR[0] &= !(PIO_PC12 | PIO_PC15);
		PIOC->PIO_ABCDSR[1] |= (PIO_PC12 | PIO_PC15);
		
		/* Initialize Peripheral Clock PID37 for CAN1 */
		PMC->PMC_PCER1 |= PMC_PCER1_PID38;
	}
	else
		return 0;
		
	// PMC->PMC_WPMR = 0x504D4301;							// Lock writing protection (Optional)

	p_can->CAN_BR |= 0x00043777;
	

	p_can->CAN_MR |= CAN_MR_CANEN;							// Enable CAN
	//p_can->CAN_WPMR = 0x43414E01;							// Lock writing protection (Optional)
	return 1;
}

int can_init_mailbox(Can* p_can,int canMB,int mode,int priority)
{
	p_can->CAN_MB[canMB].CAN_MMR |= (mode << 24);
	p_can->CAN_MB[canMB].CAN_MMR |= (priority << 16);
	return 1;
}

int can_write_mailbox(Can* p_can,int canMB,unsigned int dataL, unsigned int dataH)
{
	if(!(p_can->CAN_MB[canMB].CAN_MSR & CAN_MSR_MRDY))
		return 0;
		
	p_can->CAN_MB[canMB].CAN_MID |= 0x000C0000;
		
	p_can->CAN_MB[canMB].CAN_MDL = dataL;
	p_can->CAN_MB[canMB].CAN_MDH = dataH;
	
	p_can->CAN_MB[canMB].CAN_MCR |= (8 << 16);
	p_can->CAN_TCR = (1 << canMB);
	return 1;
}

int can_read_mailbox(Can* p_can,int canMB,unsigned int* dataL,unsigned int* dataH)
{
	if(!(p_can->CAN_MB[canMB].CAN_MSR & CAN_MSR_MRDY))
		return 0;
		
	*dataL = p_can->CAN_MB[canMB].CAN_MDL;
	*dataH = p_can->CAN_MB[canMB].CAN_MDH;
	
	return 1;
}