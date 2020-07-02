#include "I2C1.h"
#include "mcc.h"


void I2C1_Initialize(uint32_t Speed)
{
  SSP1STATbits.SMP = 1; // Slew rate control disabled for Standard Speed mode (100 kHz and 1 MHz)
  SSP1STATbits.CKE = 0; // Disable SMBus specific inputs
  
  SSP1CON1bits.SSPEN = 1;
  SSP1CON1bits.SSPM = 0b1000; //  I2C Master mode, clock = FOSC / (4 * (SSPxADD+1))
  
  SSP1ADD = (_XTAL_FREQ / (4 * Speed)) - 1;  
}

void I2C1_Master_Wait()
{
  while (SSP1CON2bits.SEN ||
          SSP1CON2bits.PEN ||
          SSP1CON2bits.RSEN ||
          SSP1CON2bits.RCEN ||
          SSP1CON2bits.ACKEN ||
          SSP1STATbits.R_nW);
} 

void I2C1_Master_Start()
{
  I2C1_Master_Wait();  
  SSP1CON2bits.SEN = 1;  
}

void I2C1_Master_RepeatedStart()
{
  I2C1_Master_Wait();
  SSP1CON2bits.RSEN = 1;           //Initiate repeated start condition
}


void I2C1_Master_Stop()
{
  I2C1_Master_Wait();
  SSP1CON2bits.PEN = 1;           //Initiate stop condition
}

void I2C1_Master_Write(uint8_t data)
{
  I2C1_Master_Wait();
  SSP1BUF = data;         //Write data to SSPBUF
}

uint8_t I2C1_Master_Read(bool ack)
{
  unsigned short temp;
  I2C1_Master_Wait();
  SSP1CON2bits.RCEN = 1;
  I2C1_Master_Wait();
  temp = SSP1BUF;      //Read data from SSPBUF
  I2C1_Master_Wait();
  SSP1CON2bits.ACKDT = ack;      //Acknowledge bit
  SSP1CON2bits.ACKEN = 1;        //Acknowledge sequence
  return temp;
}

/**
 End of File
*/
