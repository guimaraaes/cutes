#include <Arduino.h>
// #define TEST_ENVIROMENT

#define CREATE_ENVIROMENT

#include "../embedded_system/embedded_system.cpp"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

#ifdef TEST_ENVIROMENT
#include "../lib/ArduinoUnit/src/ArduinoUnit.h"
#include "../test/test_ArduinoUnit.cpp"
#endif

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifdef CREATE_ENVIROMENT
  ultrasonic_light.setup();
#endif
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  ultrasonic_light.loop();
#endif

#ifdef TEST_ENVIROMENT
  ultrasonic_light.unitTests();
  Test::run();
#endif
}