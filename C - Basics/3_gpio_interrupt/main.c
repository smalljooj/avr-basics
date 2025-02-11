#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT2_vect);

int main(void)
{
    DDRB |= 0x20;
    DDRD &= 0x04;
    PORTD |= 0x04;
    
    sei();          // enable interrupts
    PCICR = 0x04;   // enable PortD interrupts -> portD 0x04, portC 0x2, portB 0x1
    PCMSK2 = 0x04;  // enable PD2 interrupt  -> portD PCMSK2, portC PCMSK1, portB PCMSK0
    
    while (1) 
    {
        
    }
    return 0;
}

// portD PCINT2, portC PCINT1, portB PCINT0 
ISR(PCINT2_vect)
{
   if (!(PIND & 0x04)) 
   {
       PORTB ^= 0x20;
   }
}
