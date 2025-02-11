#define  F_CPU 16000000
#define cpl_bit(y, bit) (y ^= (1 << bit))

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


// hardware pwm

int main(void)
{
    DDRD |= 0x40;
    TCCR0A = 0x83;
    TCCR0B = 0x05;
    TCNT0 = 0;
    OCR0A = 16;

    uint8_t duty = 0;
    while(1)
    {
        _delay_ms(200);
        duty += 1;
        if(duty == 50)
            duty = 16;
        OCR0A = duty;
    }
    return 0;
}

/*
 * software PWM
 
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
 */


