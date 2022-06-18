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

test(StatechartTest, test_LightOff_PirOff_LightOff)
{
  statechart->list->clear();
  Serial.println("test_LightOff_PirOff_LightOff");
  delay(3000);

  arduino->loopArduino();

  assertTrue(statechart->light->isRaisedOFF());
  // statechart->pir->raiseOFF();
  if (!statechart->pir->raiseOFF())
    failTestNow();
  assertTrue(statechart->light->isRaisedOFF());
}
test(StatechartTest, test_PirOn_LightOn_5s_PirOn_LightOn)
{
  statechart->list->clear();
  Serial.println("testStateLightOn");
  delay(3000);

  arduino->loopArduino();

  if (!statechart->pir->raiseON())
    failTestNow();

  assertTrue(statechart->light->isRaisedON());

  runner->proceed_time(5 * 1000);
  if (!statechart->pir->raiseON())
    failTestNow();

  assertTrue(statechart->light->isRaisedON());
}
