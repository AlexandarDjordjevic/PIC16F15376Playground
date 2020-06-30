#ifndef SSD1306_H_INC
#define SSD1306_H_INC

#include <stdint.h>
#include <stdbool.h>

#include <xc.h>

#define SSD1306_I2C_ADDRESS 0x3C

bool SSD1306_SendCommand(uint8_t command);

#endif //SSD1306_H_INC