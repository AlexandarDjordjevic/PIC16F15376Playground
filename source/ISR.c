#include "ISR.h"

void __interrupt ISR_Handler(){
    if (TMR0IF == 1){
        TMR0IF = 0;
        TMR0_ISR_Handler();
    } 
}