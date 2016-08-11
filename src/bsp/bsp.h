/*
 * bsp.h
 *
 *  Created on: 11 de ago. de 2016
 *      Author: LCSR-AF
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stdint.h"

#define LED_NARANJA (uint16_t)0x2000U
#define LED_VERDE (uint16_t)0x1000U
#define LED_ROJO (uint16_t)0x4000U
#define LED_AZUL (uint16_t)0x8000U
#define ALL_LEDS LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE
#define LEDS_PORT GPIOD

void BSP_Init(void);

void LedToggle(uint16_t led);
void LedOff(uint16_t led);
void LedOn(uint16_t led);
uint32_t Get_SW_State(void);


#endif /* BSP_BSP_H_ */
