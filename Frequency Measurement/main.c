#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"

int period;
float freq;

int main()
{		

	int last_value = 0;	
	int current_value = 0 ;
		
	
		GPIOA_CLK_ENABLE(); //Enable Clock to GPIO Port A
		TIM2_CLK_ENABLE(); //Enbale Clock to Timer 2
		TIM3_CLK_ENABLE(); //Enbale Clock to Timer 3
	
		GPIOA_PIN1_AF(); //Configured GPIOA Pin 1 to Alternate Function as TIM2 CH2
		GPIOA_PIN6_AF(); //Configured GPIOA Pin 6 to Alternate Function as TIM3 CH1
	
	  TIM2_CH2_OUTPUT_COMPARE(); //comparing Output at the rate of 1 Hz 

		TIM3_INPUT_CAPTURE(); //Capturing Input at the rate of 1 Hz
	// Doing 02 Operations in CCER:: 01) Enabling Input capture 02) making sensitive for both falling and rising edge.

	while(1){
		while(!(TIM3->SR & 2)){} //Checking while CNT is equal to CCR1 or not
			
			current_value = TIM3->CCR1;
			period = current_value - last_value;
			freq = 1000.0f/period;
			last_value = current_value;
	}
}

