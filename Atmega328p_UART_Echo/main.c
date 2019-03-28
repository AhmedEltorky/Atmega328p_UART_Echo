/*
 * Atmega328p_UART_Echo.c
 *
 * Created: 3/23/19 6:02:58 PM
 * Author : Ahmed El-Torky
 */

#define F_CPU 1000000ul

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	/* UART initialization */
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);		 // enable Tx and Rx pins
	UCSR0C &= ~(1 << UMSEL01) & ~(1 << UMSEL00); // UART in Asynchronous mode
	UCSR0C &= ~(1 << UPM01) & ~(1 << UPM00);	 // Parity Mode disable
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	 // Character Size 8-bit
	UBRR0L = 25;								 // set baud rate to 2400 ==> (1M / (16*2400)) - 1
	UCSR0B |= (1 << RXCIE0);					 // enable receive complete interrupt
	sei();										 // set global interrupt

	while (1)
	{
		// polling technique
		/*
		while (!(UCSR0A & (1 << RXC0)))
			; // wait for receiving completed

		while (!(UCSR0A & (1 << UDRE0)))
			; // wait for data register to be empty
		UDR0 = UDR0; // read from UART data read register to UART data write register
		*/
	}
}

ISR(USART_RX_vect)
{
	UDR0 = UDR0; // read from UART data read register to UART data write register
}
