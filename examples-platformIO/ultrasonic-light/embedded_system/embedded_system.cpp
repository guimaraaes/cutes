// #include <Arduino.h>
// #include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../../../unit-embedded-system-framework/embedded_system/EmbeddedSystem.h"

// #ifndef ARDUINO_H_INCLUDED
// #define ARDUINO_H_INCLUDED
class Arduino
{
  class CreatorLight : public Creator
  {
  public:
    CreatorLight(){};
    Component *createComponent(int pin)
    {
      return new ActuatorDigital(pin);
    };
  };

  class CreatorUltrasonic : public Creator
  {
  public:
    CreatorUltrasonic(){};
    Component *createComponent(int pinTrigger, int pinEcho)
    {
      return new SensorUltrasonicNumericCM(4, 5);
    };
  };

public:
  ActuatorDigital *light;
  SensorUltrasonicNumericCM *ultrasonic;

  void configuration(){};

  void setup()
  {

    CreatorLight *creator_light = new CreatorLight();
    this->light = creator_light->createComponent(13);

    CreatorUltrasonic *creator_ultrasonic = new CreatorUltrasonic();
    this->ultrasonic = creator_ultrasonic->createComponent(4, 5);
  }
  void loop()
  {
    Serial.println("loop");
    float distance = ultrasonic->read_cm();
    if (distance < 20)
    {
      this->light->write(LOW);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 20 && distance < 30)
    {
      this->light->write(HIGH);
      delay(500);
      this->light->write(LOW);
      delay(500);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 30)
    {
      this->light->write(HIGH);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
  }
};
Arduino ultrasonic_light;
// #endif