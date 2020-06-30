#include "I2C.h"

void I2C_Init(){
    // SMP Standard Speed; CKE disabled; 
    SSP1STAT = 0x80;
    // SSPEN enabled; CKP Idle:Low, Active:High; SSPM FOSC/4_SSPxADD_I2C; 
    SSP1CON1 = 0x28;
    // SBCDE disabled; BOEN disabled; SCIE disabled; PCIE disabled; DHEN disabled; SDAHT 100ns; AHEN disabled; 
    SSP1CON3 = 0x00;
    // SSPADD 4; 
    SSP1ADD = 0x04;
    
    // clear the interrupt flags
    PIR3bits.SSP1IF = 0;
    PIR3bits.BCL1IF = 0;
	
    // enable the interrupts
    PIE3bits.SSP2IE = 1;
    PIE3bits.BCL2IE = 1; 
}

void I2C_Start(){

}