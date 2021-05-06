#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"

/*
This Program initializes UART2 Reciever and 
turn on & off Blue Led upon recieving
"on" and "off" from serial port
*/

char ch[3]; // defining Array for Recieving data
void UART_init_Rx(void); // see defination for detail
char UART_Read();

int check = 1;
int main()
{		
	GPIOA_CLK_ENABLE(); // Enabling Clock For Port A Because we are using PA2 as UART2 Tx Pin
	GPIOE_CLK_ENABLE();
	GPIOE->MODER |= GPIOE_PIN8_OUTPUT;
	
	UART_init_Rx(); // Initializing UART Peripheral ... See Defination for more
	
	while(1)
	{
		if(check == 1)
		{
		ch[0] = UART_Read();
		ch[1] = UART_Read();
		//ch[2] = UART_Read();
		if (ch[0] == 'o' && ch[1] == 'n')
		{
			LED_BLUE_ON();
			check = 0;
		}
		else {
		memset(ch, 0, sizeof ch);

		}
		}
		
		else if (check ==0)
		{
				ch[0] = UART_Read();
		    ch[1] = UART_Read();
			ch[2] = UART_Read();
		if (ch[1] == 'f' && ch[2] == 'f' )
		{
		LED_BLUE_OFF();
		check = 1;
		}
			else {
		memset(ch, 0, sizeof ch);
				
		}
		
		}
	}
}	

void UART_init_Rx()
{
	UART2_CLK_ENABLE(); //Enabling Clock to USART2
  GPIOA_PIN3_AF_USART2_RX(); //PA3 Alternate function AF7 for UART2
	USART2->BRR = 0x340; // This sets Baudrate for UART .. one can fine Hex value by this formula : CLK divided by Required Baud rate
	USART2->CR1 |= 0x1; // This bit Enables UART 
	USART2->CR1 |= 0x4; //  This bit Enables UART Reciever
}

char UART_Read()
{
	while(!(USART2->ISR & 0x0020)){} //checks availability of data
		return USART2->RDR ;	// returning data from Recieving data register of UART2
}
