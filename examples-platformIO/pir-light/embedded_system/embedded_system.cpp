
class PirLight : public EmbeddedSystem
{

public:
    ActuatorDigital *light;
    SensorDigital *pir;

    PirLight(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
        light = creatorActuatorDigital->createComponent(13);

        CreatorSensorDigital *creatorSensorDigital = new CreatorSensorDigital();
        pir = creatorSensorDigital->createComponent(3);
    };
    void loop()
    {
        if (pir->read() == HIGH)
        {
            light->write(HIGH);
            delay(1000);
        }
        if (pir->read() == LOW)
        {
            light->write(LOW);
            delay(1000);
        }
    };

    void runUnitTests()
    {
        pir->unitTest();
        light->unitTest();
    }
};
PirLight pirLight = PirLight("sistema embarcado acender luz enquanto movimento for detectado", "Sara Guimarães");