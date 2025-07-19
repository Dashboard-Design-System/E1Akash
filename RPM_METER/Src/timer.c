/*
 * timer.c
 *
 *  Created on: Jun 14, 2025
 *      Author: Akash Kute
 */

#include "TIMER.h"

void timer_init()
{

	RCC ->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->PSC = PC;

	TIM2 ->ARR =1000-1;
	TIM2 ->CNT =0;

	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;

	NVIC_EnableIRQ(TIM2_IRQn);


}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;

        static uint8_t state = 0;
        if (state)
            led_on();
        else
            led_off();

        state = !state;
    }
}
