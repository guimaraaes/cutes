
// #include <ArduinoUnit.h>
#include "../src/ArduinoUnit/src/ArduinoUnit.h"
#include "../arduino/arduino.cpp"
Arduino *arduino;

#include "../statechart/statechart.cpp"

class StatechartTest : public Test
{

public:
  void setupTeste()
  {
    arduino->setupArduino();
  }
  void loopTeste()
  {
    Test::run();
  }
};

test(testLuzInitOFF)
{
  statechart->list->clear();
  Serial.println("testLuzInitOFF");
  delay(3000);

  arduino->loopArduino();

  assertTrue(statechart->light->isRaisedOFF());
}

test(testSinalPIR_SinalLuz)
{
  statechart->list->clear();
  Serial.println("testSinalPIR_SinalLuz");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseON())
    fail();
  assertTrue(statechart->light->isRaisedON());
  if (!statechart->pir->raiseOFF())
    fail();
  assertTrue(statechart->light->isRaisedOFF());
}