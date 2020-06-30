#ifndef TIMER0_H_INC
#define TIMER0_H_INC

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void T0_Initialize();
void T0_ISR_Handler();

extern bool Flag100ms;
extern bool Flag1s;


#endif //TIMER0_H_INC