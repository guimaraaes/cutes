
// #include <ArduinoUnit.h>
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
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

test(testLightOn)
{
  statechart->list->clear();
  Serial.println("testLightOn");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseON())
    fail();
  assertTrue(statechart->light->isRaisedON());
  runner->proceed_time(1 * 1000);
}

test(testLightOff)
{
  statechart->list->clear();
  Serial.println("testLightOff");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseOFF())
    fail();
  assertTrue(statechart->light->isRaisedOFF());
  runner->proceed_time(1 * 1000);
}