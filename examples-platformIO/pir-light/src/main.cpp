#include <Arduino.h>
#include "../../../unit-embedded-system-framework/embedded_system/EmbeddedSystem.h"
class Arduino : public AbstractEmbeddedSystem
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

  class CreatorPir : public Creator
  {
  public:
    CreatorPir(){};
    Component *createComponent(int pin)
    {
      return new SensorDigital(pin);
    };
  };

public:
  ActuatorDigital *light;
  SensorDigital *pir;

  void configuration(){};

  void setup()
  {
    CreatorLight *creator_light = new CreatorLight();
    this->light = creator_light->createComponent(13);

    CreatorPir *creator_pir = new CreatorPir();
    this->pir = creator_pir->createComponent(3);
  };
  void loop()
  {
    if (this->pir->read() == HIGH)
    {
      this->light->write(HIGH);
      delay(1000);
    }
    if (this->pir->read() == LOW)
    {
      this->light->write(LOW);
      delay(1000);
    }
  };
};
Arduino pir_light;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pir_light.setup();
}

void loop()
{

  // put your main code here, to run repeatedly:
  pir_light.loop();
}