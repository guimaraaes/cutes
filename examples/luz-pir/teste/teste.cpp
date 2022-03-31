//#include <AUnitVerbose.h>
#include <AUnit.h>
using namespace aunit;


class CustomTestAgain: public TestAgain {
  protected:
    void setup() override {
      TestAgain::setup();
      when = 5000;
      //ledStatus = 0;
    }

    void teardown() override {
      TestAgain::teardown();
      //ledStatus = 0;
    }

    void tPirON_eLuzON() {
      
      //assertMoreOrEqual(ledStatus, 1);
    }

    void tPirOFF_eLuzOFF() {
      
    }

    void luzAcendeu(){
      
    }
    uint16_t when;
};

testingF(CustomTestAgain, example_test) {
  //  assertNoFatalFailure(assertBigStuff());
  
  if (millis() >= when) {
    //luzAcendeu();
//    assertEqual(ledStatus, 1);
//    pass(); // if assertion is ok
  }
}


void setupTeste() {
  // put your setup code here, to run once:
  delay(1000);

  Serial.begin(115200);
  TestRunner::setTimeout(7);

  TestRunner::exclude("*");
  //TestRunner::include("looping*");
  TestRunner::include("CustomTestAgain", "example*");
}

void loopTeste() {
  // put your main code here, to run repeatedly:

  TestRunner::run();
}
