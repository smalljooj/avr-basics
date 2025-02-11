.ORG 0X0000
    
    LDI	    R16, 0xFF
    OUT	    DDRD, R16
    
    ; sum with registers
    LDI	    R20, 5
    LDI	    R21, 4
    ADD	    R20, R21
    OUT	    PORTD, R20
    
    ; subtraction with registers
    LDI	    R20, 5
    LDI	    R21, 4
    SUB	    R20, R21
    OUT	    PORTD, R20
    
    ; subtraction with constants
    LDI	    R20, 230
    SUBI    R20, 45
    OUT	    PORTD, R20
    
    ; register comparison
    
    LDI	    R20, 134
    LDI	    R21, 134
    CPSE    R20, R21    ; ComPare and Skip if Equal
    RJMP    DIFFERENT
    RJMP    EQUAL
    
LOOP:
    RJMP    LOOP
    
DIFFERENT:
    CBI	    PORTD, 7 ; clear bit 7
    RJMP    LOOP
EQUAL:
    SBI	    PORTD, 7 ; set bit 7
    RJMP    LOOP
    



