/*
 * i2c_sam4e.c
 *
 * Created: 02/04/2015 14:31:39
 *  Author: t.cerutti
 */ 

#include "i2c_sam4e.h"

void twi_unlock_protection(Twi* p_twi)
{
	p_twi->TWI_WPMR = 0x54574900;
}

void twi_lock_protection(Twi* p_twi)
{
	p_twi->TWI_WPMR = 0x54574901;
}

void twi_master_enable(Twi* p_twi)
{
	p_twi->TWI_CR &= !TWI_CR_MSDIS;
	p_twi->TWI_CR |= TWI_CR_MSEN;
}

void twi_master_disable(Twi* p_twi)
{
	p_twi->TWI_CR &= !TWI_CR_MSEN;
	p_twi->TWI_CR |= TWI_CR_MSDIS;
}

void twi_slave_enable(Twi* p_twi)
{
	p_twi->TWI_CR &= !TWI_CR_SVDIS;
	p_twi->TWI_CR |= TWI_CR_SVEN;
}

void twi_slave_disable(Twi* p_twi)
{
	p_twi->TWI_CR &= !TWI_CR_SVEN;
	p_twi->TWI_CR |= TWI_CR_SVDIS;
}

void twi_start(Twi* p_twi)
{
	p_twi->TWI_CR |= TWI_CR_START;
}

void twi_stop(Twi* p_twi)
{
	p_twi->TWI_CR |= TWI_CR_STOP;
}

void twi_set_address(Twi* p_twi,unsigned char address)
{
	p_twi->TWI_MMR &= 0xFF00FFFF;
	p_twi->TWI_MMR |= (address << 16);
}

void twi_master_write_direction(Twi* p_twi)
{
	p_twi->TWI_MMR &= !TWI_MMR_MREAD;
}

void twi_master_read_direction(Twi* p_twi)
{
	p_twi->TWI_MMR |= TWI_MMR_MREAD;
}

int twi_get_nack(Twi* p_twi)
{
	return (p_twi->TWI_SR & TWI_SR_NACK);
}

int twi_tx_is_ready(Twi* p_twi)
{
	return (p_twi->TWI_SR & TWI_SR_TXRDY);
}

int twi_rx_is_ready(Twi* p_twi)
{
	return (p_twi->TWI_SR & TWI_SR_RXRDY);
}

int twi_tx_is_complete(Twi* p_twi)
{
	return (p_twi->TWI_SR & TWI_SR_TXCOMP);
}

void twi_set_data(Twi* p_twi,char data)
{
	p_twi->TWI_THR = data;
}

void twi_get_data(Twi* p_twi,char* p_data)
{
	*p_data = p_twi->TWI_RHR;
}

void twi_set_clock_waveform(Twi* p_twi,unsigned int waveform_value)
{
	p_twi->TWI_CWGR = waveform_value;
}