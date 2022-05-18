#include <ArduinoUnit.h>
#include "../statechart/Statechart.hpp"

class StatechartTest : public Test
{

public:
  void setupTeste()
  {
  }
  void loopTeste()
  {
    Test::run();
  }
};

Statechart *statechart = Statechart::get();
test(testLuzInitOFF)
{
  statechart->enter(true);

  assertTrue(statechart->luz->isRaisedOFF());
}

test(testSinalPIR_SinalLuz)
{

  statechart->enter(true);
  statechart->pir->raiseON();

  assertTrue(statechart->luz->isRaisedON());
  statechart->pir->raiseOFF();
  // instance2->enter(false);

  assertTrue(statechart->luz->isRaisedOFF());
}