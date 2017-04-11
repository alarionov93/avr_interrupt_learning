#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define GREEN_LED PB1
#define RED_LED PB0

volatile uint8_t st = 0;
volatile uint8_t incom;

inline void setup() {
  cli(); 

  DDRB |= (1 << RED_LED);
  DDRB |= (1 << GREEN_LED);

  // TCCR1B = 0;
  // OCR0B = 255;

  // TCCR1B |= (1 << WGM12);
  // TCCR1B |= (1 << CS12);
  // TCCR1B |= (1 << CS10);
  // TIMSK1 |= (1 << TOIE1);
  //8 data bits
  // UCSR0C |= (1 << UCSZ01);
  // UCSR0C |= (1 << UCSZ00);
  // //enable recieve and transmit
  // UCSR0B |= (1 << RXEN0);
  // UCSR0B |= (1 << TXEN0);
  // //enable interrupt on recieving
  // UCSR0B |= (1 << RXCIE0);

  // UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
  // UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

  // sei();
}

// ISR(USART_RX_vect) {
//     // // _delay_ms(2);
//     cli();
//     incom = UDR0;
//     PORTB |= (1 << GREEN_LED);
//     _delay_ms(20);
//     PORTB &= ~(1 << GREEN_LED);
//     // reti();
// }

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
