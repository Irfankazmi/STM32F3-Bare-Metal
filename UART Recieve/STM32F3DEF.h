#include "stm32f3xx.h"                  // Device header

#define CLK_GPIOE_ENABLE 0x200000

#define GPIOE_PIN8_OUTPUT 0x10000

#define GPIOE_PIN8_SET 0x100

#define CLK_TIM2_ENABLE 0x1

#define UART2_ENABLE_BIT 17


void GPIOE_CLK_ENABLE(void);
void GPIOD_CLK_ENABLE(void);
void GPIOA_CLK_ENABLE(void);
void GPIOB_CLK_ENABLE(void);
void UART2_CLK_ENABLE(void);
void GPIOA_PIN3_AF_USART2_RX(void);
void UART_Write(char ch);
void UART_Init(void);
void SYSCNFG_CLK_ENABLE(void);
void GPIOA_PIN5_AF(void);
void GPIOA_PIN6_AF(void);
void GPIOA_PIN1_AF(void);
void GPIOA_PIN2_AF(void);
void GPIOA_PIN2_AF_USART2_TX(void);

void GPIOD_PIN4_AF(void);
void EXTI0_PA0_Enable(void);
void EXTI1_PB1_Enable(void);
void LED_BLUE_ON(void);
void LED_BLUE_OFF(void);
void TIM2_CLK_ENABLE(void);
void TIM3_CLK_ENABLE(void);
void SET_PWM(int);
void TIM2_CH2_OUTPUT_COMPARE(void);
void TIM2_CH3_OUTPUT_COMPARE(void);
void TIM3_INPUT_CAPTURE(void);
void LED_BLUE_TOGGLE(void);
void Delay_ms(int Delay);
void Delay_ms_GPT(unsigned int ms);
