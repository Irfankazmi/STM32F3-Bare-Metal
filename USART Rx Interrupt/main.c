#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"

/*
This Program initializes UART2 Reciever in interrupt Mode and 
receives single byte.
*/

char ch;// defining Array for Recieving data
int main()
{		
	__disable_irq(); //Disabling Global Interrupt, Always Need to Disable IRQ first while working in Interrupt Programming
	
	GPIOA_CLK_ENABLE(); // Enabling Clock For Port A Because we are using PA2 as UART2 Tx Pin
	GPIOE_CLK_ENABLE();  // Enabling Clock to GPIO PORT E  , BLUE Led is connected to PE8
	
	GPIOE->MODER |= GPIOE_PIN8_OUTPUT; //// GPIOE Pin 8 output mode selected

	UART_init_Rx(); // Initializing UART Peripheral ... See Defination for more
	
	USART2->CR1 |= 0x20; // Enable Rx Interrupt Bit in USART_CR1
	
	NVIC_EnableIRQ(USART2_IRQn); //Enabling USART2 NVIC 
	
   __enable_irq(); //Enabling Global interrupt

	while(1)
	{
	 LED_BLUE_ON();
	}	
}


void USART2_IRQHandler(void)
{
	while(!(USART2->ISR & 0x0020)){} //checks availability of data
		
		ch = USART2->RDR ;  //Fetching data 

	}
