#include <Arduino.h>
// #define TEST_ENVIROMENT
// #define Test_AUnit
#define Test_ArduinoUnit
#define CREATE_ENVIROMENT

#include "../embedded_system/embedded_system.cpp"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
#include "../test/test_AUnit.cpp"
#include "AUnit/src/AUnit.h"
using namespace aunit;
#endif

#if (defined TEST_ENVIROMENT && defined Test_ArduinoUnit)
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
#include "../test/test_ArduinoUnit.cpp"
#endif

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifdef CREATE_ENVIROMENT
  ultrasonic_light.setup();
#endif

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
  TestRunner::exclude("*");
  TestRunner::include("TestUltrasonic", "*");
#endif
#if (defined TEST_ENVIROMENT && defined Test_AUnit)

#endif
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  ultrasonic_light.loop();
#endif

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
  TestRunner::run();
#endif

#if (defined TEST_ENVIROMENT && defined Test_ArduinoUnit)
  Test::run();
#endif
}