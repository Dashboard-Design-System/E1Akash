/*
 * IR.c
 *
 *  Created on: Jun 14, 2025
 *      Author: Akash kute
 */

#include "IR.h"


void ir_init()
{
	RCC-> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER &= ~(	BV(IR_PIN *2) | BV(IR_PIN * 2 + 1) );
	GPIOA->PUPDR &= ~(	BV(IR_PIN *2) | BV(IR_PIN * 2 + 1) );

	RCC-> AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD-> MODER &=  ~BV(GREEN_LED *2 + 1);
	GPIOD->MODER |= BV(GREEN_LED * 2);
	GPIOD ->PUPDR &= ~(BV(GREEN_LED * 2 ) | BV(GREEN_LED * 2 + 1));


	SYSCFG -> EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3) );
	EXTI->IMR |= BV(IR_PIN);
	EXTI-> FTSR |= BV(IR_PIN);

	NVIC_EnableIRQ(EXTI0_IRQn);


}

void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR0)
		{
			EXTI ->PR |= EXTI_PR_PR0;
		}

	led_on();
	DelayMs(50);
	led_off();

}

void led_on(void){

	GPIOD->ODR |= BV(GREEN_LED);


}
void led_off(void){
	GPIOD ->ODR &= ~BV(GREEN_LED);

}




