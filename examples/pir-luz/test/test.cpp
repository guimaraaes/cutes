#include <AUnit.h>
using namespace aunit;
#include "../arduino/arduino.cpp"
Arduino *arduino;

#include "../statechart/statechart.cpp"
#include "../statechart/store.cpp"

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
    // delete statechart;
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

test(StatechartTest, testStateLightOff)
{
  arduino->loopArduino();
  statechart->enter();
  // Serial.println(statechart->light->light_status);
  assertTrue(statechart->light->isRaisedOFF());
  // statechart->pir->raiseOFF();
  if (!statechart->pir->raiseOFF())
    failTestNow();
  assertTrue(statechart->light->isRaisedOFF());
}
test(StatechartTest, testStateLightOn)
{
  arduino->loopArduino();
  statechart->enter();
  // statechart->pir->raiseON();
  if (!statechart->pir->raiseON())
    failTestNow();

  assertTrue(statechart->light->isRaisedON());

  // statechart->runner->proceed_time(5 * 1000);
  statechart->pir->raiseOFF();
  assertTrue(statechart->light->isRaisedOFF());
}

// test(StatechartTest, testStateDelay)
// {
//   // arduino->StateLightON();
//   statechart->enter();
//   statechart->pir->raiseON();
//   // statechart->runner->proceed_time(5 * 1000);
//   assertTrue(statechart->light->isRaisedON());

//   statechart->pir->raiseON();
//   // statechart->runner->proceed_time(5 * 1000);
//   assertTrue(statechart->light->isRaisedON());

//   statechart->pir->raiseOFF();
//   // statechart->runner->proceed_time(5 * 1000);
//   assertTrue(statechart->light->isRaisedOFF());
// }