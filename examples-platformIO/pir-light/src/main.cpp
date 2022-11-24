#include <Arduino.h>
// #define CREATE_ENVIROMENT
#define TEST_ENVIROMENT

#include "../../../cutes/cutes.h"

#include "../embedded-system/embedded-system.cpp"

#ifdef TEST_ENVIROMENT
#include "../test/test.cpp"
#endif

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pirLight.setup();
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  pirLight.loop();
#endif

#ifdef TEST_ENVIROMENT
  pirLight.runUnitTests();
  systemTests.run();
#endif
}