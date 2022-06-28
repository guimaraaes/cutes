#include "../src/AUnit/src/AUnit.h"
using namespace aunit;

#include "../arduino/arduino.cpp"
Arduino *arduino;

#include "../statechart/statechart.cpp"

class StatechartTest : public TestOnce
{

protected:
  void setup() override
  {
    TestOnce::setup();
    arduino->setupArduino();
  }
  void teardown() override
  {
    TestOnce::teardown();
  }

public:
  void setupTest()
  {
    // TestRunner::setTimeout(20);

    TestRunner::exclude("*");
    TestRunner::include("StatechartTest", "*");
  }

  void loopTest()
  {
    TestRunner::run();
  }
};

test(StatechartTest, testLightOn)
{
  statechart->list->clear();
  Serial.println("testLightOn");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseON())
    failTestNow();
  assertTrue(statechart->light->isRaisedON());
  runner->proceed_time(1 * 1000);
}
test(StatechartTest, testLightOff)
{
  statechart->list->clear();
  Serial.println("testLightOff");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseOFF())
    failTestNow();
  assertTrue(statechart->light->isRaisedOFF());
  runner->proceed_time(1 * 1000);
}
