/*
 * IR.h
 *
 *  Created on: Jun 14, 2025
 *      Author: krushna
 */

#ifndef IR_H_
#define IR_H_


#include <stm32f4xx.h>
#define IR_PIN  0
#define GREEN_LED 12

void ir_init();
void EXTI0_IRQHandler(void);
void led_on(void);
void led_off(void);




#endif /* IR_H_ */


