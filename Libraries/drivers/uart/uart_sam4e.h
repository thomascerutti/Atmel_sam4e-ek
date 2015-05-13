/*
 * uart_sam4e.h
 *
 * Created: 26/03/2015 15:17:43
 *  Author: t.cerutti
 */ 

#ifndef UART_SAM4E_H_
#define UART_SAM4E_H_

#include "sam.h"

void uart_enable_tx(Uart* uart);

void uart_disable_tx(Uart* uart);

void uart_reset_tx(Uart* uart);

void uart_enable_rx(Uart* uart);

void uart_disable_rx(Uart* uart);

void uart_reset_rx(Uart* uart);

void uart_reset_status(Uart* uart);

void uart_mode(Uart* uart,unsigned short int mode);

void uart_enable_interrupt(Uart* uart,unsigned short int interrupt);

void uart_disable_interrupt(Uart* uart,unsigned short int interrupt);

int uart_is_tx_ready(Uart* uart);

int uart_is_tx_empty(Uart* uart);

int uart_is_tx_buf_end(Uart* uart);

int uart_is_rx_ready(Uart* uart);

int uart_is_rx_buf_end(Uart* uart);

void uart_baudrate(Uart* uart,unsigned short int cd);

void uart_set_data(Uart* uart, char data);

void uart_get_data(Uart* uart,char* data);

#endif /* UART_SAM4E_H_ */