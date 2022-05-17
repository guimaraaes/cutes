
#include "../arduino/arduino.cpp"
#include "../test/test.cpp"
StatechartTest *statecharttest;

void setup()
{

  // put your setup code here, to run once:
  setupArduino();
  statecharttest->setupTeste();
  // setupTeste();
}

void loop()
{
  // put your main code here, to run repeatedly:
  loopArduino();
  statecharttest->loopTeste();
  // Serial.println("loop");

  // loopTeste();
}
