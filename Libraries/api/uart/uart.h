/*
 * uart_sam4e.h
 *
 * Created: 26/03/2015 15:17:43
 *  Author: t.cerutti
 */ 

#ifndef UART_H_
#define UART_H_

#include "../../drivers/uart/uart_sam4e.h"
#include "../../drivers/pmc/pmc_sam4e.h"
#include "../../drivers/gpio/gpio_sam4e.h"

int uart_init(Uart* uart,int baudrate);

int uart_put_char(Uart* uart,char data);

int uart_get_char(Uart* uart,char* data);

void uart_write(Uart* uart,char* buffer);

int uart_read(Uart* uart,char* buffer);

void uart_reset_buffer(char* buffer,int length);

#endif /* UART_H_ */