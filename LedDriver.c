#include <stdio.h>
#include <stdbool.h>
#include "unity_fixture.h"
#include "LedDriver.h"
#include "RuntimeError.h"

static uint16_t *ledsAddress;
static uint16_t ledsImage;

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum {
    FIRST_LED = 1u,
    LAST_LED = 16u
};

static void RunAllTests(void) {
    RUN_TEST_GROUP(LedDriver);
}

// For invert logic
//static void updateHardware(void) {
//    *ledsAddress = ~ledsImage;
//}

// For normal logic
static void updateHardware(void) {
    *ledsAddress = ledsImage;
}

static bool IsLedOutOfBounds(int ledNumber) {
    if ((ledNumber < FIRST_LED) || (ledNumber > LAST_LED)) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
        return true;
    }
    return false;
}

void LedDriver_Create(uint16_t *address) {
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber) {
    return 1 << (ledNumber - 1);
}

static void setLedImageBit(int ledNumber) {
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber) {
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOn(int ledNumber) {
    if (IsLedOutOfBounds(ledNumber)) return;
    setLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber) {
    if (IsLedOutOfBounds(ledNumber)) return;
    clearLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnAllOn(void) {
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

void LedDriver_TurnAllOff(void) {
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_Destroy(void) {

}

bool LedDriver_IsOn(int ledNumber) {
    if (IsLedOutOfBounds(ledNumber)) return false;
    
    return ledsImage & (convertLedNumberToBit(ledNumber));
}

bool LedDriver_IsOff(int ledNumber) {
    return !LedDriver_IsOn(ledNumber);
}

int main(int argc, const char *argv[]) {
    return UnityMain(argc, argv, RunAllTests);
}


