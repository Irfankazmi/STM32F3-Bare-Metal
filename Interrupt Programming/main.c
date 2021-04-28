#include "stm32f3xx.h"                  // Device header
#include "STM32F3DEF.h"

int main()
{	
	__disable_irq();  // Always Need to Disable IRQ first while working in Interrupt Programming
	
	GPIOA_CLK_ENABLE();  // Enabling Clock to GPIO PORT A  , Push Button is connected to PA0
	GPIOE_CLK_ENABLE();  // Enabling Clock to GPIO PORT E  , BLUE Led is connected to PE8
	SYSCNFG_CLK_ENABLE();  // Always need to Enable SYSTEM CONFIG Clock while working in interrupt Programming

	GPIOE->MODER |= GPIOE_PIN8_OUTPUT;  // GPIOE Pin 8 output mode selected
	
	GPIOA->MODER &= ~0x3;  // Reset PA0 means writing 00 to MODER register so that this pin acts as input
	
	EXTI0_PA0_Enable();  // PA0 connected to EXTI0, (for more info see Defination)
	
	NVIC_EnableIRQ(EXTI0_IRQn); // whenever interrupt pin is selected, NVIC_ENABLE(EXTIx_IRQn) must be called to enable ISR
	
	__enable_irq(); //After enabling ISR, all irqs must be enable
	
	while(1){}  //Usual while(1) loop
}

void EXTI0_IRQHandler()  //Interrupt Callback Function
{
	
	LED_BLUE_TOGGLE();
	Delay_ms(1000);
	LED_BLUE_TOGGLE();
	Delay_ms(1000);
	LED_BLUE_TOGGLE();
	Delay_ms(1000);
	LED_BLUE_TOGGLE();
	Delay_ms(1000);
	
	EXTI->PR = 1;  // At the end of callback function EXTI pending bit must be cleared. passing 1 means we are clearing that bit.
}


