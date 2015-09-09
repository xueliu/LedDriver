#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver) {
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnFirstOne);
    RUN_TEST_CASE(LedDriver, TurnOffFirstOne);
    RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(LedDriver, AllOn);
}
