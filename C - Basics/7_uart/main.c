#include <avr/io.h>
#include <avr/interrupt.h>

void uart_write_txt(uint8_t*, int);

ISR(USART_RX_vect)
{
    char data = 0;
    data = UDR0; // receive the byte
    UDR0 = data; // send the received byte
}

int main(void)
{
    
    UBRR0 = 103; // baud rate = 9600BPS, baud rate register = (FREQ_OSC/(16 * BAUD)) - 1
    UCSR0B = 0x98; // enable RX interrupt with 7 bit and enable TX and RX with 4:3 bits
    UCSR0C = 0x06; // set the word length to 8 bits with 2:1 bits
    sei(); // enable interrupts
    while (1)
    {
      
    }
}

void uart_write_txt(uint8_t* buffer, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(buffer[i] != 0)
            UDR0 = buffer[i];
        while(!(UCSR0A & 0x20));
    }
}