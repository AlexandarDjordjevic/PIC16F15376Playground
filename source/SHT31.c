// #include "SHT31.h"


// //=============================================================================

// sht31_t SHT31Data;

// //-----------------------------------------------------------------------------
// static uint8_t SHT31CalculateCrc(uint8_t* Data, uint8_t DataCnt)
// {
// 	uint8_t Bit = 0; // bit mask
// 	uint8_t Crc = 0xFF; // calculated checksum
// 	uint8_t ByteCtr; // byte counter

// 	// calculates 8-Bit checksum with given polynomial
// 	for(ByteCtr = 0; ByteCtr < DataCnt; ByteCtr++)
// 	{
// 		Crc ^= (Data[ByteCtr]);
// 		for(Bit = 8; Bit > 0; --Bit)
// 		{
// 			if(Crc & 0x80) Crc = (Crc << 1) ^ POLYNOMIAL;
// 			else Crc = (Crc << 1);
// 		}
// 	}

// 	return Crc;
// }
// //-----------------------------------------------------------------------------
// static sht31error_t SHT31CheckCrc(uint8_t* Data, uint8_t DataCnt, uint8_t Checksum)
// {
// 	 uint8_t Crc = 0; // calculated checksum

// 	 // calculates 8-Bit checksum
// 	 Crc = SHT31CalculateCrc(Data, DataCnt);

// 	 // verify checksum
// 	 if(Crc != Checksum) return CHECKSUM_ERROR;
// 	 else return NO_ERROR;
// }

// sht31error_t SHT31ReadStatusRegister(uint16_t* Status)
// {
// 	// uint8_t Command[2];
// 	// uint8_t I2CBuffer[4];
// 	sht31error_t SHT31Error = NO_ERROR;
//     // I2C1_MESSAGE_STATUS i2c_Result = I2C1_MESSAGE_FAIL;
// 	// Command[0] = (uint8_t)(CMD_READ_STATUS >> 8);
// 	// Command[1] = (uint8_t)(CMD_READ_STATUS);
	
// 	// I2C1_MasterWrite(Command, 2, SHT31_I2C_ADDRESS, &i2c_Result);
//     // if (i2c_Result != I2C1_MESSAGE_COMPLETE){
//     //     return ACK_ERROR;
//     // }
//     // I2C1_MasterRead(I2CBuffer, 3, SHT31_I2C_ADDRESS, &i2c_Result);
//     // if (i2c_Result != I2C1_MESSAGE_COMPLETE){
//     //     return ACK_ERROR;
//     // }
// 	// SHT31Error |= SHT31CheckCrc(I2CBuffer, 2, I2CBuffer[2]);
// 	// if (SHT31Error == NO_ERROR){
//     //     *Status = (uint16_t)I2CBuffer[0] << 8 | I2CBuffer[1];
//     // }
      
//     return SHT31Error;
// }