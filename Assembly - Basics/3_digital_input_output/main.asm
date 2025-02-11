.ORG 0x0000
    
    ; Define the built in led pin to output
    LDI	    R16, 0xFF
    OUT	    DDRB, R16
    
    ; define the pins of the port D to input and the pin 3 with pull up
    LDI	    R16, 0x00
    OUT	    DDRD, R16
    LDI	    R16, 0x04
    OUT	    PORTD, R16

LOOP:
    ; if pin 3 is clear turn on the led, otherwise turn off
    SBIC PIND, PD3
    RJMP LED_TURN_OFF
    RJMP LED_TURN_ON
    
LED_TURN_OFF:
    ; pin3 clear
    CBI PORTB, PB5
    RJMP LOOP
    
LED_TURN_ON:
    ; pin3 set
    SBI PORTB, PB5
    RJMP LOOP 