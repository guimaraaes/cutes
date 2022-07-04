// #include <Arduino.h>
// #include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../../../unit-embedded-system-framework/embedded_system/EmbeddedSystem.h"
#include "../../../unit-embedded-system-framework/component/units-creatores/CreatorUltrasonic.h"
#include "../../../unit-embedded-system-framework/component/units-creatores/CreatorLight.h"
class Arduino : public EmbeddedSystem
{

public:
  ActuatorDigital *light;
  SensorUltrasonicNumericCM *ultrasonic;
  Arduino(String description, String author) : EmbeddedSystem(description, author){};
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
Arduino ultrasonic_light = Arduino("sistema embarcado alerta com luz de acordo com a distância", "Sara Guimarães");
