#include "I2C1.h"
#include "mcc.h"

uint8_t I2C1_TimeoutTimer = 0;

void I2C1_Initialize(uint32_t Speed)
{
  SSP1STATbits.SMP = 1; // Slew rate control disabled for Standard Speed mode (100 kHz and 1 MHz)
  SSP1STATbits.CKE = 0; // Disable SMBus specific inputs
  
  SSP1CON1bits.SSPEN = 1;
  SSP1CON1bits.SSPM = 0b1000; //  I2C Master mode, clock = FOSC / (4 * (SSPxADD+1))
  
  SSP1ADD = (_XTAL_FREQ / (4 * Speed)) - 1;  
}

bool I2C1_Master_Wait()
{
  I2C1_TimeoutTimer = I2C_TIMEOUT_IN_MS;
  do {
    if(I2C1_TimeoutTimer == 0) return false;
  }while (SSP1CON2bits.SEN ||
          SSP1CON2bits.PEN ||
          SSP1CON2bits.RSEN ||
          SSP1CON2bits.RCEN ||
          SSP1CON2bits.ACKEN ||
          SSP1STATbits.R_nW);
  
  return true;
} 

bool I2C1_Master_Start()
{
  if(I2C1_Master_Wait() == false){
    return false;
  }  
  SSP1CON2bits.SEN = 1;
  return true;  
}

bool I2C1_Master_RepeatedStart()
{
  if(I2C1_Master_Wait() == false){
    return false;
  }
  SSP1CON2bits.RSEN = 1;           //Initiate repeated start condition
  return true;
}


bool I2C1_Master_Stop()
{
  if(I2C1_Master_Wait() == false){
    return false;
  }
  SSP1CON2bits.PEN = 1;           //Initiate stop condition
  return true;
}

bool I2C1_Master_Write(uint8_t data)
{
  if(I2C1_Master_Wait() == false){
    return false;
  }
  SSP1BUF = data;         //Write data to SSPBUF
  return true;
}

bool I2C1_Master_Read(uint8_t* data, uint8_t ack)
{
  if(I2C1_Master_Wait() == false){
    return false;
  }
  SSP1CON2bits.RCEN = 1;
  if(I2C1_Master_Wait() == false){
    return false;
  }
  *data = SSP1BUF;      //Read data from SSPBUF
  if(I2C1_Master_Wait() == false){
    return false;
  }
  SSP1CON2bits.ACKDT = ack;      //Acknowledge bit
  SSP1CON2bits.ACKEN = 1;        //Acknowledge sequence
  return true;
}

/**
 End of File
*/
