#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int ad_read;

ISR(ADC_vect)
{
    // get the value using "ADC" register
    ad_read = ADC;
}

int main(void)
{
    ADMUX = 0x40; // set the voltage reference on 7:6 bits(AVcc) and the channel with 3:0 bits (channel 0)
    ADCSRA = 0x8F; // enable the adc with 7 bit, enable interrupt with 3 bit and set the prescaler to maximun on 2:0 bits (128)

    sei();
    while (1)
    {
        ADCSRA |= 0x40; // start conversion with 6 bit
        
        //while(ADCSRA & 0x40); // wait until the end of the conversion or use interrupts
    }
}
