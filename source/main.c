#include <stdio.h>
#include "mcc.h"
#include "Timer0.h"

int main()
{
	SYSTEM_Initialize();

	while (1)
	{
		// printf("running\r\n");
		if (Flag100ms){
			Flag100ms = false;
			if (Flag1s){
				Flag1s = false;
				printf("Hello every second\r\n");
			}
		}
	}
}
