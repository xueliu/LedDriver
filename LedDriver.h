#ifndef __LEDDRIVER_H_INCL__
#define __LEDDRIVER_H_INCL__

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);

#endif // __LEDDRIVER_H_INCL__

