#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"

#include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../test/test.cpp"
#include "AUnit/src/AUnit.h"
using namespace aunit;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ultrasonic_light.setup();

  TestRunner::exclude("*");
  TestRunner::include("TestUltrasonic", "*");
}

void loop()
{
  // put your main code here, to run repeatedly:
  // ultrasonic_light.loop();

  TestRunner::run();
}