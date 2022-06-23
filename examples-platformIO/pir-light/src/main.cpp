#include <Arduino.h>
#include "../embedded_system/Embedded_System.cpp"
Arduino ligh;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  ligh.setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  ligh.loop();
}