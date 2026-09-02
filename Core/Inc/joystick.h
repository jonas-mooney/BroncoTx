#ifndef __JOYSTICK_H
#define __JOYSTICK_H

#include "main.h"

uint32_t Read_ADC_Channel(uint32_t channel);

void Joystick_Read(uint16_t *x, uint16_t *y);

#endif