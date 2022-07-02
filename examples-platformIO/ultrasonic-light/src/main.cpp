#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
#include "../test/test_ArduinoUnit.cpp"

// #include "../test/test_AUnit.cpp"
// #include "AUnit/src/AUnit.h"
// using namespace aunit;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ultrasonic_light.setup();

  // casesTest->setup();

  // TestRunner::exclude("*");
  // TestRunner::include("TestUltrasonic", "*");
}

void loop()
{
  // put your main code here, to run repeatedly:
  // ultrasonic_light.loop();
  // casesTest->loop();
  Test::run();

  // TestRunner::run();
}