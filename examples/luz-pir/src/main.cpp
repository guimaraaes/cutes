
#include "../arduino/arduino.cpp"
#include "../test/test.cpp"
Arduino *arduino;
StatechartTest *statecharttest;
void setup()
{
  Serial.begin(115200);

  // put your setup code here, to run once:
  arduino->setupArduino();
  statecharttest->setupTeste();
  // setupTeste();
}

void loop()
{
  // put your main code here, to run repeatedly:
  arduino->loopArduino();
  statecharttest->loopTeste();
  // Test::run();
}
