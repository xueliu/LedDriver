#include "unity_fixture.h"
#include "LedDriver.h"

TEST_GROUP(LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(LedDriver) {
    LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver){

}

TEST(LedDriver, LedsOffAfterCreate) {
//    TEST_FAIL_MESSAGE("Start here");
    uint16_t virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnFirstOne) {
//    uint16_t virtualLeds;
//    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffFirstOne) {
//    uint16_t virtualLeds;
//    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed) {
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

TEST(LedDriver, AllOn) {
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}
