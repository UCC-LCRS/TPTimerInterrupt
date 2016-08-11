/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "bsp/bsp.h"

#define ONE_SECOND 1000

void APP_1ms(void);

void delay(uint16_t delay_ms);

volatile uint16_t counter = 0;

int main(void) {

	BSP_Init();

	while (1) {

		LedOn(LED_AZUL);
		delay(1000);
		LedOff(LED_AZUL);
		LedOn(LED_ROJO);
		delay(1000);
		LedOff(LED_ROJO);
		LedOn(LED_NARANJA);
		delay(1000);
		LedOff(LED_NARANJA);
		LedOn(LED_VERDE);
		delay(1000);
		LedOff(LED_VERDE);
	}
}

void delay(uint16_t delay_ms) {
	counter = delay_ms;
	while(counter);
}

void APP_1ms(void) {
	if (counter) {
		counter--;
	}
}

