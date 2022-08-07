#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"
#define TEST_ENVIROMENT
// #define Test_AUnit
#define Test_ArduinoUnit
// #define CREATE_ENVIROMENT

#if (defined TEST_ENVIROMENT && defined Test_ArduinoUnit)
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
#include "../test/test_ArduinoUnit.cpp"
#endif

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
#include "../test/test_AUnit.cpp"
#include "AUnit/src/AUnit.h"
using namespace aunit;
#endif
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifdef CREATE_ENVIROMENT
  pir_light.setup();
#endif

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
  TestRunner::exclude("*");
  TestRunner::include("TestPirLigh", "*");
#endif
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  pir_light.loop();
#endif

#if (defined TEST_ENVIROMENT && defined Test_ArduinoUnit)
  Test::run();
#endif

#if (defined TEST_ENVIROMENT && defined Test_AUnit)
  TestRunner::run();
#endif
}