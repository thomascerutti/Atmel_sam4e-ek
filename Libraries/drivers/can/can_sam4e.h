/*
 * can_sam4e.h
 *
 * Created: 29/04/2015 14:16:18
 *  Author: t.cerutti
 */ 

#include "sam.h"

#ifndef CAN_SAM4E_H_
#define CAN_SAM4E_H_

void can_unlock_protection(Can* can);

void can_lock_protection(Can* can);

void can_enable(Can* can);

void can_disable(Can* can);

void can_baudrate(Can* can,unisgned int value);

void canMailboxMode(Can* can,int canMailbox,unsigned char mode);

void canMailboxPriority(Can* can,int canMailbox,unsigned char priority);

#endif /* CAN_SAM4E_H_ */