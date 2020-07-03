#ifndef _I2C1_H
#define _I2C1_H

/**
  Section: Included Files
*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xc.h>

#define I2C_SPEED_100K       100000ul
#define I2C_SPEED_400K       400000ul

void I2C1_Initialize(uint32_t speed);
void I2C1_Master_Wait();
void I2C1_Master_Start();
void I2C1_Master_RepeatedStart();
void I2C1_Master_Stop();
void I2C1_Master_Write(uint8_t data);
uint8_t I2C1_Master_Read(bool ack);

#endif //_I2C1_H
