#include <stdio.h>
#include "unity_fixture.h"
#include "LedDriver.h"

static uint16_t * ledsAddress;

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static void RunAllTests(void) {
    RUN_TEST_GROUP(LedDriver);
}

void LedDriver_Create(uint16_t * address) {
   ledsAddress = address;
   * ledsAddress = 0;
}

static uint16_t convertLedNumberToBit(int ledNumber) {
    return 1 << (ledNumber - 1);
}

void LedDriver_TurnOn(int ledNumber) {
    *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber) {
    *ledsAddress &= ~(convertLedNumberToBit(ledNumber));
}

void LedDriver_TurnAllOn(void) {
    *ledsAddress = ALL_LEDS_ON;
}

void LedDriver_Destroy(void) {

}
int main (int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}

