/*
 * uart_sam4e.c
 *
 * Created: 26/03/2015 15:17:25
 *  Author: t.cerutti
 */ 

#include "uart_sam4e.h"

/* Enable UART transmitter */
void uart_enable_tx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_TXEN;
}

/* Disable UART transmitter */
void uart_disable_tx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_TXDIS;
}

/* Reset UART transmitter */
void uart_reset_tx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_RSTTX;
	p_uart->UART_CR |= UART_CR_TXDIS;
}

/* Enable UART receiver	*/
void uart_enable_rx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_RXEN;
}

/* Disable UART receiver */
void uart_disable_rx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_RXDIS;
}

/* Reset UART receiver */
void uart_reset_rx(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_RSTRX;
	p_uart->UART_CR |= UART_CR_RXDIS;
}

/* Reset Status PARE, FRAME et OVRE*/
void uart_reset_status(Uart* p_uart)
{
	p_uart->UART_CR |= UART_CR_RSTSTA;
}

void uart_mode(Uart* p_uart,unsigned short int mode)
{
	p_uart->UART_MR &= 0x0000C000;
	p_uart->UART_MR |= mode;
}

void uart_enable_interrupt(Uart* p_uart,unsigned short int interrupt)
{
	p_uart->UART_IER |= interrupt;
}

void uart_disable_interrupt(Uart* p_uart,unsigned short int interrupt)
{
	p_uart->UART_IDR &= !interrupt;
}

/* Check if data has been loaded in UART_THR	*/
/* Value return :								*/
/*		0 - Transmitter not ready				*/
/*		1 - Transmitter ready					*/
int uart_is_tx_ready(Uart* p_uart)
{
	return (p_uart->UART_SR & UART_SR_TXRDY) > 0;
}

/* Check if THR is empty						*/
/* Value return :								*/
/*		0 - THR not empty						*/
/*		1 - THR empty							*/
int uart_is_tx_empty(Uart* p_uart)
{
	return (p_uart->UART_SR & UART_SR_TXEMPTY) > 0;
}

/* Check if transmition is complete				*/
/* Value return :								*/
/*		0 -	Transmition not complete			*/
/*		1 - Transmition complete				*/
int uart_is_tx_buf_end(Uart* p_uart)
{
	return (p_uart->UART_SR & UART_SR_ENDTX) > 0;
}

/* Check if data has been receive in UART_RHR	*/
/* Value return :								*/
/*		0 - No data has been received			*/
/*		1 - Data has been received				*/
int uart_is_rx_ready(Uart* p_uart)
{
	return (p_uart->UART_SR & UART_SR_RXRDY) > 0;
}

/* Check if receive buffer is filled			*/
/* Value return :								*/
/*		0 - Receive is not completed			*/
/*		1 - Receive is completed				*/
int uart_is_rx_buf_end(Uart* p_uart)
{
	return (p_uart->UART_SR & UART_SR_ENDRX) > 0;
}

/* Configure baudrate register					*/
void uart_baudrate(Uart* p_uart, unsigned short int cd)
{
	p_uart->UART_BRGR = cd;
}

/* Set data in THR register						*/
void uart_set_data(Uart* p_uart,char data)
{
	p_uart->UART_THR = data;
}

/* get data from RHR register					*/
void uart_get_data(Uart* p_uart,char* p_data)
{
	*p_data = p_uart->UART_RHR;
}
