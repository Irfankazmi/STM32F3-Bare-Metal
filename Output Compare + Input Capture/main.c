#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"
uint32_t timestamp ;
int main()
{		
		GPIOA_CLK_ENABLE(); //Enable Clock to GPIO Port A
		TIM2_CLK_ENABLE(); //Enbale Clock to Timer 2
		TIM3_CLK_ENABLE(); //Enbale Clock to Timer 3
	
		GPIOA_PIN1_AF(); //Configured GPIOA Pin 1 to Alternate Function as TIM2 CH2
		GPIOA_PIN6_AF(); //Configured GPIOA Pin 6 to Alternate Function as TIM3 CH1
	
	  TIM2_CH2_OUTPUT_COMPARE(); //comparing Output at the rate of 1 Hz 

		TIM3_INPUT_CAPTURE(); //Capturing Input at the rate of 1 Hz

	while(1){
		while(!(TIM3->SR & 2)){} //Checking while CNT is equal to CCR1 or not
			timestamp = TIM3->CCR1;
	}
}

