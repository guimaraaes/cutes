#include <Arduino.h>
#define TEST_ENVIROMENT
#define CREATE_ENVIROMENT

#include "../embedded_system/embedded_system.cpp"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

// #include "../lib/ArduinoUnit/src/ArduinoUnit.h"
// #include "../test/test_ArduinoUnit.cpp"
#ifdef TEST_ENVIROMENT
#include "../test/test_AUnit.cpp"
#include "AUnit/src/AUnit.h"
using namespace aunit;
#endif

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ultrasonic_light.setup();

  // casesTest->setup();
#ifdef TEST_ENVIROMENT
  TestRunner::exclude("*");
  TestRunner::include("TestUltrasonic", "*");
#endif
}

void loop()
{
  // put your main code here, to run repeatedly:
  // ultrasonic_light.loop();
  // casesTest->loop();
  // Test::run();
#ifdef TEST_ENVIROMENT
  TestRunner::run();
#endif
}