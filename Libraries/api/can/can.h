/*
 * can.h
 *
 * Created: 29/04/2015 14:16:18
 *  Author: t.cerutti
 */ 

#include "../../lib/drivers/can/can_sam4e.h"

#ifndef CAN_H_
#define CAN_H_

int can_init(Can* can);

int can_init_mailbox(Can* can,int,int,int);

int can_write_mailbox(Can* can,int,unsigned int, unsigned int);

int can_read_mailbox(Can* can,int,unsigned int*,unsigned int*);

#endif /* CAN_H_ */