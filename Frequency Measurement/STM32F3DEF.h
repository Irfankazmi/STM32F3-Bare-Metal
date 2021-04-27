#include "stm32f3xx.h"                  // Device header

#define CLK_GPIOE_ENABLE 0x200000

#define GPIOE_PIN8_OUTPUT 0x10000

#define GPIOE_PIN8_SET 0x100

#define CLK_TIM2_ENABLE 0x1




void GPIOE_CLK_ENABLE(void);
void GPIOD_CLK_ENABLE(void);
void GPIOA_CLK_ENABLE(void);
void GPIOA_PIN5_AF(void);
void GPIOA_PIN6_AF(void);
void GPIOA_PIN1_AF(void);
void GPIOA_PIN2_AF(void);
void GPIOD_PIN4_AF(void);
void LED_BLUE_ON(void);
void LED_BLUE_OFF(void);
void TIM2_CLK_ENABLE(void);
void TIM3_CLK_ENABLE(void);
void TIM2_OUTPUT_COMPARE(void);
void TIM2_CH2_OUTPUT_COMPARE(void);
void TIM2_CH3_OUTPUT_COMPARE(void);
void TIM3_INPUT_CAPTURE(void);
void LED_BLUE_TOGGLE(void);
void Delay_ms(int Delay);
void Delay_ms_GPT(unsigned int ms);
