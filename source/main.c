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
				printf("Reading Emissivity!\r\n");
				if(MLX90615_ReadTemperature(&MLX90615))
				{
					printf("MLX Ambient Temperature: %.2f\r\n", MLX90615.temperature.ambient);
				}
			}
		}
	}
}
