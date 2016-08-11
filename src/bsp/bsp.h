/*
 * bsp.h
 *
 *  Created on: 11 de ago. de 2016
 *      Author: LCSR-AF
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#define LED_NARANJA GPIO_PIN_13
#define LED_VERDE GPIO_PIN_12
#define LED_ROJO GPIO_PIN_14
#define LED_AZUL GPIO_PIN_15
#define ALL_DISCOVERY_LEDS LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE
#define LEDS_PORT GPIOD

void BSP_Init(void);


#endif /* BSP_BSP_H_ */
