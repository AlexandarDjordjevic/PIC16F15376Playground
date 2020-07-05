#include "MLX90615.h"
#include "I2C1.h"
#include <stdio.h>

void MLX90615_Init(){
}

bool MLX90615_ReadAmbientTemperature(MLX90615_t* data){
    uint8_t temp_l = 0, temp_h = 0;

    I2C1_Master_Start();
    if (I2C1_Master_Write(MLX90615_I2C_ADDRESS << 1) == false)return false;
    if (I2C1_Master_Write(MLX90615_AMBIENT_TEMPERATURE | MLX90615_RAM_MEMORY) == false)return false;
    if (I2C1_Master_RepeatedStart() == false)return false;
    if (I2C1_Master_Write(MLX90615_I2C_ADDRESS << 1 | 0x01) == false) return false; //Address with read
    if (I2C1_Master_Read(&temp_l, I2C_ACK) == false)return false;
    if (I2C1_Master_Read(&temp_h, I2C_ACK) == false)return false;
    data->temperature.ambient = (float)((uint16_t)temp_l + temp_h * 256) * 0.02 - 273.15;
    /* CRC Data */
    if (I2C1_Master_Read(&temp_h, I2C_NACK) == false)return false;
    I2C1_Master_Stop();

    return true;
}

bool MLX90615_ReadObjectTemperature(MLX90615_t* data){
    uint8_t temp_l = 0, temp_h = 0;

    I2C1_Master_Start();
    if (I2C1_Master_Write(MLX90615_I2C_ADDRESS << 1) == false)return false;
    if (I2C1_Master_Write(MLX90615_OBJECT_TEMPERATURE | MLX90615_RAM_MEMORY) == false)return false;
    if (I2C1_Master_RepeatedStart() == false)return false;
    if (I2C1_Master_Write(MLX90615_I2C_ADDRESS << 1 | 0x01) == false)return false; //Address with read
    if (I2C1_Master_Read(&temp_l, I2C_ACK) == false)return false;
    if (I2C1_Master_Read(&temp_h, I2C_ACK) == false)return false;
    data->temperature.object = (float)((uint16_t)temp_l + temp_h * 256) * 0.02 - 273.15;
    /* CRC Data */
    if (I2C1_Master_Read(&temp_h, I2C_NACK) == false)return false;

    I2C1_Master_Stop();

    return true;
}


bool MLX90615_ReadEmissivity(MLX90615_t* data){

    // I2C1_Master_Start();
    // I2C1_Master_Write((MLX90615_I2C_ADDRESS << 1) & 0xFE); //Address with write
    // I2C1_Master_Write(0x13); //Command read emissivity from EEPROM 
    // I2C1_Master_RepeatedStart();
    // I2C1_Master_Write((MLX90615_I2C_ADDRESS << 1) | 0x01); //Address with read
    // data->settings.emissivity = I2C1_Master_Read(I2C_ACK);
    // data->settings.emissivity |= I2C1_Master_Read(I2C_ACK) * 256;
    // I2C1_Master_Read(I2C_NACK);
    // I2C1_Master_Stop();
    return true;
}