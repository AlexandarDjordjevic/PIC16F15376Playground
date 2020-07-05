#include "Timer0.h"
#include "I2C1.h"
#include "I2C2.h"

uint16_t counter = 0;
bool Flag100ms = false;
bool Flag1s = false;

void TMR0_Initialize(){
    //Reset Timer 0 counter 
    TMR0 = 0;

    // T0OUTPS 1:1; T0EN disabled; T016BIT 16-bit; 
    T0CON0 = 0x10;

    // T0CS FOSC/4; T0CKPS 1:1; T0ASYNC synchronised; 
    T0CON1 = 0x40;

    // TMR0H 224; 
    TMR0H = 0xE0;

    // TMR0L 192; 
    TMR0L = 0xC0;

    PIR0bits.TMR0IF = 0; // clear inetrrupt flag
    PIE0bits.TMR0IE = 1; // enable interrupt
    INTCONbits.PEIE = 1; // enable peripheral interrupt
    // Enable timer
    T0CON0bits.T0EN = 1;
    GIE = 1;
}

void TMR0_ISR_Handler(){
    
    counter++;
    if(I2C1_TimeoutTimer){
        I2C1_TimeoutTimer--;
    }
    if(I2C2_TimeoutTimer){
        I2C2_TimeoutTimer--;
    }
    if ((counter % 100) == 0){
        Flag100ms = true;
        if ((counter % 1000) == 0){
            counter = 0;
            Flag1s = true;
        }
    }
    // TMR0H 224; 
    TMR0H = 0xE0;
    // TMR0L 192; 
    TMR0L = 0xC0;

}