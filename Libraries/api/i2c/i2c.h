/*
 * i2c_sam4e.h
 *
 * Created: 02/04/2015 14:31:56
 *  Author: t.cerutti
 */ 
 
#ifndef I2C_SAM4E_H_
#define I2C_SAM4E_H_

#include "../../lib/drivers/i2c/i2c_sam4e.h"
	
int i2c_init(Twi*);

int i2c_master_write(Twi*,unsigned int,char*,int);

int i2c_master_read(Twi*,unsigned int,char*,int);

#endif /* I2C_SAM4E_H_ */