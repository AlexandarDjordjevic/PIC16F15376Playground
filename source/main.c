#include <stdio.h>
#include "mcc.h"
#include "Timer0.h"
#include "SHT31.h"

int main()
{
	SYSTEM_Initialize();

	while (1)
	{
		if (Flag100ms){
			Flag100ms = false;
			if (Flag1s){
				Flag1s = false;
				printf("Sending command\r\n");
				uint16_t status = 0;
				sht31error_t result = SHT31ReadStatusRegister(&status);
				printf("SHT 31 Result: %d\r\n", result);
				
			}
		}
	}
}
