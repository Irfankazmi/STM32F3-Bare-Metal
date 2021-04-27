#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"
uint64_t timestamp ;
int main()
{		
		GPIOA_CLK_ENABLE();
		GPIOD_CLK_ENABLE();
	
		TIM2_CLK_ENABLE();
		//GPIOA_PIN1_AF(); //TIM2 CH2
		GPIOA_PIN2_AF();
		//TIM3_CLK_ENABLE();
	
		//GPIOA_PIN5_AF();
		//GPIOA_PIN6_AF();
		GPIOD->PUPDR = 0;
		GPIOD_PIN4_AF();
		
		//TIM2_OUTPUT_COMPARE();// TIM 2 CH1
	
	 TIM2_CH2_OUTPUT_COMPARE();// TIM 2 CH2 
    //TIM2_CH3_OUTPUT_COMPARE();
		TIM3_INPUT_CAPTURE();

	while(1){
		while(!(TIM3->SR & 2)){}
			timestamp = TIM3->CCR1;
	}
}

