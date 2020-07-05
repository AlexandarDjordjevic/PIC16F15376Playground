#include "I2C2.h"
#include "mcc.h"

uint8_t I2C2_TimeoutTimer = 0;

void I2C2_Initialize(uint32_t Speed)
{
  SSP2STATbits.SMP = 1; // Slew rate control disabled for Standard Speed mode (100 kHz and 1 MHz)
  SSP2STATbits.CKE = 0; // Disable SMBus specific inputs
  
  SSP2CON1bits.SSPEN = 1;
  SSP2CON1bits.SSPM = 0b1000; //  I2C Master mode, clock = FOSC / (4 * (SSPxADD+1))
  
  SSP2ADD = (_XTAL_FREQ / (4 * Speed)) - 1;  
}

bool I2C2_Master_Wait()
{
  I2C2_TimeoutTimer = I2C2_TIMEOUT_IN_MS;
  do {
    if(I2C2_TimeoutTimer == 0) return false;
  }while (SSP2CON2bits.SEN ||
          SSP2CON2bits.PEN ||
          SSP2CON2bits.RSEN ||
          SSP2CON2bits.RCEN ||
          SSP2CON2bits.ACKEN ||
          SSP2STATbits.R_nW);
  
  return true;
} 

bool I2C2_Master_Start()
{
  if(I2C2_Master_Wait() == false){
    return false;
  }  
  SSP2CON2bits.SEN = 1;
  return true;  
}

bool I2C2_Master_RepeatedStart()
{
  if(I2C2_Master_Wait() == false){
    return false;
  }
  SSP2CON2bits.RSEN = 1;           //Initiate repeated start condition
  return true;
}


bool I2C2_Master_Stop()
{
  if(I2C2_Master_Wait() == false){
    return false;
  }
  SSP2CON2bits.PEN = 1;           //Initiate stop condition
  return true;
}

bool I2C2_Master_Write(uint8_t data)
{
  if(I2C2_Master_Wait() == false){
    return false;
  }
  SSP2BUF = data;         //Write data to SSPBUF
  return true;
}

bool I2C2_Master_Read(uint8_t* data, uint8_t ack)
{
  if(I2C2_Master_Wait() == false){
    return false;
  }
  SSP2CON2bits.RCEN = 1;
  if(I2C2_Master_Wait() == false){
    return false;
  }
  *data = SSP2BUF;      //Read data from SSPBUF
  if(I2C2_Master_Wait() == false){
    return false;
  }
  SSP2CON2bits.ACKDT = ack;      //Acknowledge bit
  SSP2CON2bits.ACKEN = 1;        //Acknowledge sequence
  return true;
}

/**
 End of File
*/
