#define F_CPU 12000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define GREEN_LED PB1
#define RED_LED PB0

volatile uint8_t st = 0;

inline void setup() {
  cli(); 

  DDRB |= (1 << RED_LED);
  DDRB |= (1 << GREEN_LED);

  // TCCR1B = 0;
  // OCR0B = 255;

  // TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TIMSK1 |= (1 << TOIE1);

  sei();
}

ISR(TIMER1_OVF_vect) {
    // // _delay_ms(2);
    st++;
    if (st == 5) {
	    PORTB |= (1 << GREEN_LED);
	    _delay_ms(20);
	    PORTB &= ~(1 << GREEN_LED);
	}
    // reti();
}

void main(void) {
	setup();
	while (1)
	{
		PORTB |= (1 << RED_LED);
		_delay_ms(200);
		PORTB &= ~(1 << RED_LED);
		_delay_ms(200);
	}
}
