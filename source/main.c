#include <stdio.h>
#include "mcc.h"
#include "Timer0.h"
#include "MLX90615.h"

MLX90615_t MLX90615;

int main()
{
	SYSTEM_Initialize();

	while (1)
	{
		
		if (Flag100ms){
			Flag100ms = false;
			if (Flag1s){
				Flag1s = false;
				printf("MLX90615 >\r\n");
				if(MLX90615_ReadAmbientTemperature(&MLX90615) && MLX90615_ReadObjectTemperature(&MLX90615))
				{
					printf("\tAmbient temperature: %.2f\r\n\tObject temperature: %.2f\r\n\r\n", 
							MLX90615.temperature.ambient,
							MLX90615.temperature.object);
				}
				else
				{
					printf("\tFail to read sensor!\r\n\r\n");
				}
				
			}
		}
	}
}
