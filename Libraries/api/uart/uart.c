/*
 * uart_sam4e.c
 *
 * Created: 26/03/2015 15:17:25
 *  Author: t.cerutti
 */ 

#include "uart.h"

int uart_init(Uart* p_uart,int baudrate)
{
	if(p_uart == UART0)
	{
		/* Initialize clock UART0 */
		pmc_unlock_protection(PMC);								// Unlock writing protection
		pmc_enable_clock(PMC,7);								// Enable clock corresponding to UART0
		//pcm_lock_protection(PMC);								// Lock writing protection (Optional)
			
		/* Disable PIO9 and PIO10 (enable peripheral mode) */
		gpio_unlock_protection(PIOA);
		gpio_disable_pin(PIOA,(PIO_PA9 | PIO_PA10));
			
		/* IO initialize for uart0 (peripheral A) */
		gpio_enable_periph(PIOA,(PIO_PA9 | PIO_PA10),'A');
		gpio_enable_periph(PIOA,(PIO_PA9 | PIO_PA10),'A');
	}
	else if(p_uart == UART1)
	{
		
	}
	else
		return 0;
	
	/* Reset and disable UART */
	uart_reset_rx(p_uart);
	uart_reset_tx(p_uart);
	uart_disable_rx(p_uart);
	uart_disable_tx(p_uart);
	
	/* Configure baudrate */
	uart_baudrate(p_uart,((SystemCoreClock/baudrate) / 16));
	
	/* Configure mode */
	uart_mode(p_uart,UART_MR_CHMODE_NORMAL);
	
	/* Enable transmitter and receiver */
	uart_enable_rx(p_uart);
	uart_enable_tx(p_uart);
	
	return 1;
}

/* Put Data in THR								*/
/* Value return :								*/
/*		1 - Data not send						*/
/*		0 - Data send							*/
int uart_put_char(Uart* p_uart,char data)
{
	if(uart_is_tx_ready(p_uart))
	{
		uart_set_data(p_uart,data);
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Get Data from RHR							*/
/* Value return :								*/
/*		0 - Data read							*/
/*		1 - Data not read						*/
int uart_get_char(Uart* p_uart,char* p_data)
{
	if(uart_is_rx_ready(p_uart))
	{
		uart_get_data(p_uart,p_data);
		return 1;
	}
	else
	{
		return 0;
	}
}


void uart_write(Uart* p_uart,char buffer[])
 {
		int i = 0;
		
		while(buffer[i] != 0)
		{
			if(uart_put_char(p_uart,buffer[i]))
			{
				i++;
			}
		}
}

int uart_read(Uart* p_uart,char buffer[])
{
		int i = 0;
		
		if(uart_is_rx_ready(p_uart))
		{
			do 
			{
				while(uart_get_char(p_uart,&buffer[i]))
					i++;
			} while ((buffer[i-1] != 0) && (buffer[i-1] != '.'));
		}
		return 1;
}

void uart_reset_buffer(char buffer[],int length)
{
	int i;
	
	for(i=0;i<length;i++)
		buffer[i] = 0;
}