#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{
    char flag = 0;
    DDRD &= ~0x04; // set the pin to input
    PORTD |= 0x04; // enable pull up
    DDRB |= 0x20; // set the pin to output

    while (1) 
    {
        if (!(PIND & 0x04)) // read from pind and not from portD
        {
            _delay_ms(10);
            flag = 1;
        }
        if ((PIND & 0x04) && flag)   
        {
            _delay_ms(10);
            flag = 0;
            PORTB ^= 0x20;
        }
    }
}
