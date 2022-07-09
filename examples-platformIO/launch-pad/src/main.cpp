#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
#include "../test/test_ArduinoUnit.cpp"

void setup()
{
  // put your setup code here, to run once:
  // launch_pad.setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // launch_pad.loop();
  Test::run();
}