#include <Arduino.h>

// #define CREATE_ENVIROMENT
#define TEST_ENVIROMENT

#include "../../../cutes/cutes.h"

#include "../embedded_system/embedded_system.cpp"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

#ifdef TEST_ENVIROMENT
#include "../test/test_ArduinoUnit.cpp"
#endif

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultrasonicLight.setup();
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  ultrasonicLight.loop();
#endif

#ifdef TEST_ENVIROMENT
  // ultrasonicLight.runUnitTests();

  systemTests.run();
#endif
}