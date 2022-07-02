
// #include "../arduino/arduino.cpp"
// Arduino *arduino;
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../test/test.cpp"
StatechartTest *statecharttest;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // arduino->setupArduino();
  statecharttest->setupTeste();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // arduino->loopArduino();
  statecharttest->loopTeste();
}