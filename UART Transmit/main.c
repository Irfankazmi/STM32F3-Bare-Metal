#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"


int main()
{		
	GPIOA_CLK_ENABLE(); // Enabling Clock For Port A Because we are using PA2 as UART2 Tx Pin
	UART_Init(); // Initializing UART Peripheral ... See Defination for more
	
	while(1)
	{
		UART_Write('H'); // Sending or transmiting data ... see defination for more info
		UART_Write('i');
		Delay_ms(1000);
	}
}	



