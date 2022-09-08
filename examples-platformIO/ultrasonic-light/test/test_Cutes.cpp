#include "../../../cutes/history/History.h"

#include "../../../cutes/test/Test.h"

class CasesTest : TestCutes
{
  virtual void setup() = 0;
  virtual void teardown() = 0;
  virtual void beforeEach(String name) = 0;
  void case_test("test_0to20")
  {

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(0, 20))
      this->failTest();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
      this->failTest();
  };
};
