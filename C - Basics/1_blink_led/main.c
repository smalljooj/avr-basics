#define F_CPU 16000000UL

#include <avr/io.h> // register mapping library
#include <util/delay.h>

int main(void) 
{
    DDRB |= 0x20;
    
    while (1) 
    {
        PORTB |= 0x20;
        _delay_ms(500);
        PORTB &= ~0x20;
        _delay_ms(500);
        
        // also -> PORTB ^= 0x20;
    }
    
    return 0;
}
