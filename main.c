#include <avr/io.h>

void main(void) {
	DDRB |= (1 << PB1);
	PORTB |= (1 << PB1);
}
