
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

test(test_0to20)
{
  statechart->list->clear();
  Serial.println("test_0to20");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->ultrasonic->raise_0to20())
    fail();

  assertTrue(statechart->light->isRaisedOFF());
}

test(test_20to30)
{
  statechart->list->clear();
  Serial.println("test_20to30");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->ultrasonic->raise_20to30())
    fail();

  assertTrue(statechart->light->isRaisedONOFF());
}

test(test_30toLarger)
{
  statechart->list->clear();
  Serial.println("test_30toLarger");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->ultrasonic->raise_30toLarger())
    fail();

  assertTrue(statechart->light->isRaisedON());
}
