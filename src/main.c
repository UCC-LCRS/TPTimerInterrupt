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

int main(void) {

	BSP_Init();

	while (1) {



	}
}

void APP_1ms(void){
	static uint16_t counter = ONE_SECOND;

		if (counter) {
			counter--;
			if (!counter) {
				LedToggle(ALL_LEDS);
				counter = ONE_SECOND;
			}
		}
}


