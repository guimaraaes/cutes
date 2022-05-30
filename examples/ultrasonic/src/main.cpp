
// #include "../arduino/arduino.cpp"
// Arduino *arduino;
// #include <Arduino.h>
#include "../test/test.cpp"
StatechartTest *statecharttest;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // arduino->setupArduino();
  statecharttest->setupTest();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // arduino->loopArduino();
  statecharttest->loopTest();
}