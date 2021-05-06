#include "STM32F3DEF.h"



void GPIOE_CLK_ENABLE()
{
RCC->AHBENR |= CLK_GPIOE_ENABLE;
}

void GPIOB_CLK_ENABLE()
{
	RCC->AHBENR |= 0x40000;
}

void SYSCNFG_CLK_ENABLE()
{
   RCC->APB2ENR |= 1;
}

void GPIOA_CLK_ENABLE()
{
		RCC->AHBENR |= 0x20000;

}

void GPIOD_CLK_ENABLE()
{
	RCC->AHBENR |= (1<<20);
}

void UART2_CLK_ENABLE()
{ 
	RCC->APB1ENR |= 0x20000;
}

void TIM2_CLK_ENABLE()
{
RCC->APB1ENR |= CLK_TIM2_ENABLE;
}

void TIM3_CLK_ENABLE()
{
RCC->APB1ENR |= 0x2;
}

void GPIOA_PIN5_AF()
{
	GPIOA->MODER |= (1<<11);
	
	GPIOA->AFR[0] |= 0x100000;
}

void GPIOA_PIN1_AF()
{
	GPIOA->MODER &= ~0xc;
	GPIOA->MODER |= 0x8;
	GPIOA->AFR[0] |= 0x10;
}

void GPIOA_PIN2_AF()
{
  GPIOA->MODER &= ~0x30;
	GPIOA->MODER |= 0x20;
	GPIOA->AFR[0] |= 0x100;
}

void GPIOA_PIN2_AF_USART2_TX()
{
	GPIOA->MODER &= ~0x30;
	GPIOA->MODER |= 0x20;
	GPIOA->AFR[0] |= 0x0700;
}

void GPIOA_PIN3_AF_USART2_RX()
{
	GPIOA->MODER &= ~0xc0;
	GPIOA->MODER |= 0x80;
	GPIOA->AFR[0] |= 0x07000;

}

void GPIOD_PIN4_AF()
{
	GPIOD->MODER &= ~0x300;
	GPIOD->MODER |= 0x200;
	GPIOD->AFR[0] |= 0x10000;
}

void GPIOA_PIN6_AF()
{
	GPIOA->MODER |= (1<<13);
	GPIOA->AFR[0] |= 0x2000000;
}

void EXTI0_PA0_Enable()
{
  SYSCFG->EXTICR[0] |= 0;	 //EXTI0 connected to PA0
	EXTI->IMR |= 1;  // Unmasked EXTI0
	EXTI->FTSR |=1; //Enable Falling edge
	
}

void EXTI1_PB1_Enable()
{
	SYSCFG->EXTICR[0] |= 0X10;	 //EXTI0 connected to PA0
	EXTI->IMR |= 0x2;  // Unmasked EXTI1
	EXTI->FTSR |=0x2; //Enable Falling edge

}


void TIM2_OUTPUT_COMPARE()
{
	TIM2->PSC = 8000-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->CCR1 = 0;
	TIM2->CCMR1 = 0x30;
	TIM2->CCER |= 1;
	TIM2->CR1 = 1;
	//LED_BLUE_TOGGLE();
}

void SET_PWM(int Duty_cycle)
{
  TIM2->PSC = 1;
	TIM2->CCR2 = 8889-1;
	TIM2->ARR = ((TIM2->CCR2)*Duty_cycle)-1;
	TIM2->CNT = 0;
	
	TIM2->CCMR1 |= 0x6000;
	TIM2->CCER |= 0x10;
	TIM2->CR1 = 1;
}

void TIM2_CH3_OUTPUT_COMPARE()
{
  TIM2->PSC = 8000-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->CCR3 = 0;
	TIM2->CCMR2 |= 0x30;
	TIM2->CCER |= 0x100;
	TIM2->CR1 = 1;
}
void TIM3_INPUT_CAPTURE()
{
  TIM3->PSC = 8000-1;
	TIM3->CCMR1 = 0x1;
	TIM3->CCER = 0x0B; // Doing 02 Operations:: 01) Enabling Input capture 02) making sensitive for both falling and rising edge.
	TIM3->CR1 = 1;
}


void LED_BLUE_ON()
{
	GPIOE->BSRR |= GPIOE_PIN8_SET;
}

void LED_BLUE_OFF()
{
	
	GPIOE->BSRR = (1<<24);
}

void LED_BLUE_TOGGLE(void)
{
	GPIOE->ODR ^=0x100;
}

void UART_Init()
{
	UART2_CLK_ENABLE(); //Enabling Clock to USART2
  GPIOA_PIN2_AF_USART2_TX(); //PA2 Alternate function AF7 for UART2
	USART2->BRR = 0x340; // This sets Baudrate for UART .. one can fine Hex value by this formula : CLK divided by Required Baud rate
	USART2->CR1 |= 0x1; // This bit Enables UART 
	USART2->CR1 |= 0x8; //  This bit Enables UART Transmitter
}

void UART_Write(char ch)
{
	while(!(USART2->ISR & 0x0080)){} // It checks Status register , that whether Data Moved from Tx Register or not ...
	USART2->TDR = (ch & 0xFF); // Writing Data directly in Data register
}


void Delay_ms(int Delay)
{
SysTick->LOAD = 8000;
SysTick->VAL  = 0;
SysTick->CTRL = 0x05;

	for (int i=0;i<=Delay;i++)
	{
	while((SysTick->CTRL & 0x10000)==0){}
	}
	SysTick->CTRL = 0;
}

void Delay_ms_GPT(unsigned int ms)
{
		TIM2->PSC = 8000-1;
		TIM2->ARR = ms-1;
		TIM2->CNT = 0;
		TIM2->CR1 = 1;
	while((TIM2->SR & 1)==0){}
			TIM2->SR &= 0;
}
