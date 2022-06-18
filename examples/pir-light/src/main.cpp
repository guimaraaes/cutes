
// #include "../arduino/arduino.cpp"
// Arduino *arduino;

#include "../test/test.cpp"
StatechartTest *statecharttest;

void setup()
{
  // put your setup code here, to run once:
  // arduino->setupArduino();
  Serial.begin(115200);
  statecharttest->setupTeste();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // arduino->loopArduino();
  statecharttest->loopTeste();
}
