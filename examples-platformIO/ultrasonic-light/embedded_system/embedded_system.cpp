#include <Arduino.h>
// #include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../../../cutes/embedded_system/EmbeddedSystem.h"
#include "../../../cutes/component/units-creatores/CreatorUltrasonic.h"
#include "../../../cutes/component/units-creatores/CreatorActuatorDigital.h"

class Arduino : public EmbeddedSystem
{

public:
  ActuatorDigital *light;
  SensorUltrasonicCM *ultrasonic;

  Arduino(String description, String author) : EmbeddedSystem(description, author){};
  void configuration(){};

  void setup()
  {
    CreatorActuatorDigital *creator_light = new CreatorActuatorDigital();
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
      light->write(LOW);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 20 && distance < 30)
    {
      light->write(HIGH);
      delay(500);
      light->write(LOW);
      delay(500);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 30)
    {
      light->write(HIGH);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
  }

  void unitTests()
  {
    light->unitTest(1);
    ultrasonic->unitTest(20);
  }
};
Arduino ultrasonic_light = Arduino("sistema embarcado alerta com luz de acordo com a distância", "Sara Guimarães");
