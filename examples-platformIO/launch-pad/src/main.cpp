#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"

void setup()
{
  // put your setup code here, to run once:
  launch_pad.setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  launch_pad.loop();
}