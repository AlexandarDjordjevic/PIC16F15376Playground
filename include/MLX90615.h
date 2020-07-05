#ifndef MLX90615_H_INC
#define MLX90615_H_INC

#include <stdbool.h>
#include <stdint.h>

#define MLX90615_I2C_ADDRESS 0x5B

enum MLX90615_Registers{
    MLX90615_AMBIENT_TEMPERATURE = 0x06,
    MLX90615_OBJECT_TEMPERATURE = 0x07
} ;

enum MLX90615_Memory_Type{
    MLX90615_RAM_MEMORY = 0x20,
    MLX90615_EEPROM_MEMORY = 0x10
} ;

typedef struct{
    uint16_t emissivity;
}MLX96015_settings_t;

typedef struct 
{
    float ambient;
    float object;
}MLX90615_temperature_t;

typedef struct
{
    MLX90615_temperature_t  temperature;
    MLX96015_settings_t     settings;
}MLX90615_t;

bool MLX90615_ReadObjectTemperature(MLX90615_t* data);
bool MLX90615_ReadAmbientTemperature(MLX90615_t* data);
bool MLX90615_ReadEmissivity(MLX90615_t* data);

#endif