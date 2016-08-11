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
int8_t estado = 0;

int main(void) {

	BSP_Init();

	while (1) {
		if (!counter) {
			counter = 1000;

			if (Get_SW_State())
				estado++;
			else
				estado--;

			if (estado > 3)
				estado = 0;
			if (estado < 0)
				estado = 3;

			LedOff(ALL_LEDS);
			switch (estado) {
			case 0:
				LedOn(LED_AZUL);
				break;

			case 1:
				LedOn(LED_ROJO);
				break;

			case 2:
				LedOn(LED_NARANJA);
				break;

			case 3:
				LedOn(LED_VERDE);
				break;

			}
		}

	}
}

void delay(uint16_t delay_ms) {
	counter = delay_ms;
	while (counter)
		;
}

void APP_1ms(void) {
	if (counter) {
		counter--;

	}
}

