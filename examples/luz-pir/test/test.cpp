#include "../arduino/arduino.cpp"
Arduino *arduino;

#include <ArduinoUnit.h>

#include "../statechart/statechart.cpp"
Statechart *statechart = Statechart::get();

class StatechartTest : public Test
{

public:
  void setupTeste()
  {
    arduino->setupArduino();
  }
  void loopTeste()
  {
    // arduino->loopArduino(statechart);

    Test::run();
  }
};

test(testLuzInitOFF)
{
  arduino->loopArduino(statechart);

  statechart->enter();
  assertTrue(statechart->luz->isRaisedOFF());
}

test(testSinalPIR_SinalLuz)
{
  arduino->loopArduino(statechart);

  statechart->enter();
  statechart->pir->raiseON();
  assertTrue(statechart->luz->isRaisedON());
  statechart->pir->raiseOFF();
  assertTrue(statechart->luz->isRaisedOFF());
}