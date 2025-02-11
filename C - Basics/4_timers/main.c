#define cpl_bit(y, bit) (y ^= (1 << bit))

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int count = 0;

ISR(TIMER0_OVF_vect)
{
    TCNT0 = 3;
    count++;
    if (count == 31)
    {
        count = 0; // ~501 ms
        cpl_bit(PORTB, 5);
    }
}

int main(void)
{
    DDRB |= 0x20;
    TCCR0B = 0x05; // Timer Control Register -> first 3 bits set the prescaler, 0x05 = 1024 on timer 0
    TIMSK0 = 0x01; // Interrupt Mask Register -> enable interrupts, 0x01 = timer overflow interrupt
    TCNT0 = 3; // set the start of the count
    sei(); // enable interrupts
    
    while(1)
    {
        
    }
    return 0;
}
