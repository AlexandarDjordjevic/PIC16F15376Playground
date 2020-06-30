#include "Timer0.h"

uint16_t counter = 0;
bool Flag100ms = false;
bool Flag1s = false;

void T0_Initialize(){
    //Reset Timer 0 counter 
    TMR0 = 0;
    //Disable Timer 0 interrupt
    TMR0IE = 0;
    //Disable Timer 0
    T0EN = 0;
    //Set 16 bit mode
    T016BIT = 1;
    //Set output postscaler
    T0CON0bits.T0OUTPS = 0; //1:1
    //Set prescaler rate
    T0CON1bits.T0CKPS = 0; //1:1
    //Timer 0 clock source select bits
    T0CON1bits.T0CS = 2; //Fosc/4

    TMR0H = 0xF8;
    TMR0L = 0xEE;
    //Clear interrupt flag 
    TMR0IF = 0;
    //Enable timer interrupt
    TMR0IE = 1;
    //Global interrupt enable bit
    GIE = 1;
    //Enable timer
    T0EN = 1;
}

void T0_ISR_Handler(){
    TMR0H = 0xF8;
    TMR0L = 0xEE;
    counter++;
    if ((counter % 10) == 0){
        Flag100ms = true;
        if ((counter % 100) == 0){
            counter = 0;
            Flag1s = true;
        }
    }
}