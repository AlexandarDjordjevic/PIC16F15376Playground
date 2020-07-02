#include "MLX90615.h"
#include "I2C1.h"
#include <stdio.h>

void MLX90615_Init(){
}

bool MLX90615_ReadTemperature(MLX90615_t* data){
    uint8_t temp_l, temp_h;
    I2C1_Master_Start();
    I2C1_Master_Write(0xb6); //Address with write
    I2C1_Master_Write(0x26); //Command read temperature
    I2C1_Master_RepeatedStart();
    I2C1_Master_Write(0xb7); //Address with read
    temp_l = I2C1_Master_Read(true);
    temp_h = I2C1_Master_Read(true);
    I2C1_Master_Read(false);
    I2C1_Master_Stop();
    uint16_t tempAmb = temp_l + temp_h*256;
    printf("Raw Temp: %u\r\n", tempAmb);

    data->temperature.ambient = (float)((uint16_t)temp_l + temp_h * 256) * 0.02 - 273.15;

    return true;
}

bool MLX90615_ReadEmissivity(MLX90615_t* data){

    I2C1_Master_Start();
    I2C1_Master_Write((MLX90615_I2C_ADDRESS << 1) & 0xFE); //Address with write
    I2C1_Master_Write(0x13); //Command read emissivity from EEPROM 
    I2C1_Master_RepeatedStart();
    I2C1_Master_Write((MLX90615_I2C_ADDRESS << 1) | 0x01); //Address with read
    data->settings.emissivity = I2C1_Master_Read(true);
    data->settings.emissivity |= I2C1_Master_Read(true) * 256;
    I2C1_Master_Read(false);
    I2C1_Master_Stop();
    return true;
}