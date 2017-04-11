#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void main(void) {
	DDRB |= (1 << PB1);
	// PORTB |= (1 << PB1);
	for (;;)
	{
		PORTB |= (1 << PB1);
		_delay_ms(200);
		PORTB &= ~(1 << PB1);
		_delay_ms(200);
	}
}
