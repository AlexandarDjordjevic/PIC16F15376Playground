#ifndef MLX90615_H_INC
#define MLX90615_H_INC

#include <stdbool.h>
#include <stdint.h>

#define MLX90615_I2C_ADDRESS 0x5B

typedef enum {
    AMBIENT_TEMPERATURE = 0x06,
    OBJECT_TEMPERATURE = 0x07
}registers;

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

bool MLX90615_ReadTemperature(MLX90615_t* data);
bool MLX90615_ReadEmissivity(MLX90615_t* data);

#endif