/*
 * can_sam4e.c
 *
 * Created: 29/04/2015 14:15:58
 *  Author: t.cerutti
 */

#include "can_sam4e.h"

void can_Unlock_Protection(Can* p_can)
{
	p_can->CAN_WPMR = 0x43414E00;
}

void can_lock_protection(Can* p_can)
{
	p_can->CAN_WPMR = 0x43414E01;
}

void can_enable(Can* p_can)
{
	p_can->CAN_MR |= CAN_MR_CANEN;
}

void can_disable(Can* p_can)
{
	p_can->CAN_MR &= !CAN_MR_CANEN;
}

void can_baudrate(Can* p_can,unsigned int value)
{
	p_can->CAN_MR = 0;
	p_can->CAN_BR |= value;
}

void can_mailbox_mode(Can* p_can,int canMB,unsigned char mode)
{
	p_can->CAN_MB[canMB].CAN_MMR |= (mode << 24);
}

void can_mailbox_priority(Can* p_can,int canMB,unsigned char priority)
{
	p_can->CAN_MB[canMB].CAN_MMR |= (priority << 16);
}

int can_mailbox_is_ready(Can* p_can,int canMB)
{
	return (p_can->CAN_MB[canMB].CAN_MSR & CAN_MSR_MRDY);
}

void can_mailbox_ID(Can* p_can,int canMB,unsigned short int value)
{
	p_can->CAN_MB[canMB].CAN_MID |= CAN_MID_MIDvA(value);
}

void can_mailbox_set_data_low(Can* p_can,int canMB,unsigned int dataL)
{
	p_can->CAN_MB[canMB].CAN_MDL = dataL;
}

void can_mailbox_set_data_high(Can* p_can,int canMB,unsigned int dataH)
{
	p_can->CAN_MB[canMB].CAN_MDH = dataH;
}

void can_mailbox_data_length(Can* p_can,int canMB,unsigned char length)
{
	p_can->CAN_MB[canMB].CAN_MCR |= CAN_MCR_MDLC(length);
}

void can_mailbox_command(Can* p_can,int canMB)
{
	p_can->CAN_TCR = (1 << canMB);
}

void can_mailbox_get_data_low(Can* p_can,int canMB,unsigned int* dataL)
{
	*dataL = p_can->CAN_MB[canMB].CAN_MDL;
}

void can_mailbox_get_data_high(Can* p_can,int canMB,unsigned int* dataH)
{
	*dataH = p_can->CAN_MB[canMB].CAN_MDH;
}