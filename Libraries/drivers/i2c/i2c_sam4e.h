/*
 * i2c_sam4e.h
 *
 * Created: 02/04/2015 14:31:56
 *  Author: t.cerutti
 */ 
 
#ifndef I2C_SAM4E_H_
#define I2C_SAM4E_H_

#include "sam.h"

void twi_unlock_protection(Twi* twi);

void twi_lock_protection(Twi* twi);

void twi_master_enable(Twi* twi);

void twi_master_disable(Twi* twi);

void twi_slave_enable(Twi* twi);

void twi_slave_disable(Twi* twi);

void twi_start(Twi* twi);

void twi_stop(Twi* twi);

void twi_set_address(Twi* twi,unsigned char address);

void twi_master_write_direction(Twi* twi);

void twi_master_read_direction(Twi* twi);

int twi_get_nack(Twi* twi);

int twi_tx_is_ready(Twi* twi);

int twi_rx_is_ready(Twi* twi);

int twi_tx_is_complete(Twi* twi);

int twi_rx_is_complete(Twi* twi);

void twi_set_data(Twi* twi,char data);

void twi_get_data(Twi* twi, char* data);

void twi_set_clock_waveform(Twi* twi,unsigned int value);

#endif /* I2C_SAM4E_H_ */