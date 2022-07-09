#include <Arduino.h>
#include "../embedded_system/embedded_system.cpp"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pir_light.setup();
}

void loop()
{

  // put your main code here, to run repeatedly:
  pir_light.loop();
}