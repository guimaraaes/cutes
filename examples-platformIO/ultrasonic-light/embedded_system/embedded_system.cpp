
class UltrasonicLight : public EmbeddedSystem
{

public:
  ActuatorDigital *light;
  SensorUltrasonicCM *ultrasonic;

  UltrasonicLight(String description, String author) : EmbeddedSystem(description, author){};
  void configuration(){};

  void setup()
  {
    CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
    this->light = creatorActuatorDigital->createComponent(13);

    CreatorUltrasonic *creatorUltrasonic = new CreatorUltrasonic();
    this->ultrasonic = creatorUltrasonic->createComponent(4, 5);
  }

  void loop()
  {
    float distance = ultrasonic->read_cm();
    if (distance < 20)
    {
      light->write(LOW);
      delay(1000);
    }
    if (distance >= 20 && distance < 30)
    {
      light->write(HIGH);
      delay(1000);
      light->write(LOW);
      delay(1000);
      delay(1000);
    }
    if (distance >= 30)
    {
      light->write(HIGH);
      delay(1000);
    }
  }

  void runUnitTests()
  {
    light->unitTest();
    ultrasonic->unitTest();
  }
};
UltrasonicLight ultrasonicLight = UltrasonicLight("sistema embarcado alerta com luz de acordo com a distância", "Sara Guimarães");
