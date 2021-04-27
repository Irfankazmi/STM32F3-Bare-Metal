#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"

int main()
{		

		GPIOA_CLK_ENABLE(); //Enable Clock to GPIO Port A
		TIM2_CLK_ENABLE(); //Enbale Clock to Timer 2
		
		GPIOA_PIN1_AF(); //Configured GPIOA Pin 1 to Alternate Function as TIM2 CH2
		
	  SET_PWM(2); //Takes Duty Cycle i.e 2=1/2, 3=1/3 ....

	while(1){
		
	}
}

