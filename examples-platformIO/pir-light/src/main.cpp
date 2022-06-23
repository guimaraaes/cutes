#include <Arduino.h>
#include "../embedded_system/EmbeddedSystem.h"
class Arduino : public AbstractEmbeddedSystem
{
  class CreatorLight : public AbstractCreator
  {
  public:
    CreatorLight(){};
    Component *createComponent(int pin)
    {
      return new ActuatorHighLow(pin);
    };
  };

  class CreatorPir : public AbstractCreator
  {
  public:
    CreatorPir(){};
    Component *createComponent(int pin)
    {
      return new SensorHighLow(pin);
    };
  };

public:
  ActuatorHighLow *light;
  SensorHighLow *pir;

  void configuration(){};

  void setup()
  {
    CreatorLight *creator_light = new CreatorLight();
    this->light = creator_light->createComponent(13);

    CreatorPir *creator_pir = new CreatorPir();
    this->pir = creator_pir->createComponent(3);
  }
  void loop()
  {
    if (digitalRead(3) == HIGH)
    {
      this->light->write(1);
      delay(1000);
    }
    if (digitalRead(3) == LOW)
    {
      this->light->write(0);
      delay(1000);
    }
  }
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