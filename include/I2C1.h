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

#define I2C_ACK 0
#define I2C_NACK 1

#define I2C_TIMEOUT_IN_MS 100

void I2C1_Initialize(uint32_t speed);
bool I2C1_Master_Wait();
bool I2C1_Master_Start();
bool I2C1_Master_RepeatedStart();
bool I2C1_Master_Stop();
bool I2C1_Master_Write(uint8_t data);
bool I2C1_Master_Read(uint8_t* data, uint8_t ack);

extern uint8_t I2C1_TimeoutTimer;

#endif //_I2C1_H
