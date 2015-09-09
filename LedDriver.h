#ifndef __LEDDRIVER_H_INCL__
#define __LEDDRIVER_H_INCL__

#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
bool LedDriver_IsOn(int ledNumber);

#endif // __LEDDRIVER_H_INCL__

