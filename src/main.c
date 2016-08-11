/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#define LED_NARANJA GPIO_PIN_13
#define LED_VERDE GPIO_PIN_12
#define LED_ROJO GPIO_PIN_14
#define LED_AZUL GPIO_PIN_15
#define ALL_DISCOVERY_LEDS LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE
#define LEDS_PORT GPIOD

#define ONE_SECOND 1000

void APP_ISR_1ms(void);

TIM_HandleTypeDef TIM2_Handle;

int main(void) {
	__GPIOD_CLK_ENABLE()
	;

	GPIO_InitTypeDef GPIO_Init;

	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FAST;
	GPIO_Init.Pin = ALL_DISCOVERY_LEDS;
	HAL_GPIO_Init(LEDS_PORT, &GPIO_Init);

	__TIM2_CLK_ENABLE()
	;

	TIM2_Handle.Instance = TIM2;
	TIM2_Handle.Init.Period = 1000;
	TIM2_Handle.Init.Prescaler = 15;
	TIM2_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIM2_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TIM2_Handle);
	HAL_TIM_Base_Start_IT(&TIM2_Handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	while (1) {
		//En el while no se hace nada gracias a la interrupción
	}
}

void APP_ISR_1ms(void) {
	static uint16_t counter = ONE_SECOND;

	if (counter) {
		counter--;
		if (!counter) {
			HAL_GPIO_TogglePin(LEDS_PORT, ALL_DISCOVERY_LEDS);
			counter = ONE_SECOND;
		}
	}
}

void TIM2_IRQHandler(void) {

	__HAL_TIM_CLEAR_FLAG(&TIM2_Handle, TIM_FLAG_UPDATE);
	APP_ISR_1ms();

}
