
class LaunchPadMotorValve : public EmbeddedSystem
{

public:
    SensorDigital *buttonMotor;
    SensorDigital *buttonValve;
    SensorDigital *buttonCancel;

    ActuatorDigital *motor;
    ActuatorDigital *valve;

    int actuation = 0;

    LaunchPadMotorValve(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setupES()
    {
        CreatorSensorDigital *creatorSensorDigital = new CreatorSensorDigital();
        buttonMotor = creatorSensorDigital->createComponent(7);
        buttonValve = creatorSensorDigital->createComponent(12);
        buttonCancel = creatorSensorDigital->createComponent(13);

        CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
        motor = creatorActuatorDigital->createComponent(3);
        valve = creatorActuatorDigital->createComponent(11);
    }
    void loopES()
    {
        if (buttonValve->read() == HIGH)
        {
            if (buttonCancel->read() == LOW)
            {
                delay(3000);
                actuation = actuation + 1;
                switch (actuation)
                {
                case '1':
                    valve->write(HIGH);
                    delay(20000);
                    valve->write(LOW);
                    break;
                case '2':
                    valve->write(HIGH);
                    delay(32000);
                    valve->write(LOW);
                    break;
                case '3':
                    valve->write(HIGH);
                    delay(400000);
                    valve->write(LOW);
                    break;
                }
            }
        }
        if (buttonMotor->read() == HIGH)
        {
            if (buttonCancel->read() == LOW)
            {
                delay(3000);
                motor->write(HIGH);

                delay(200);
                motor->write(LOW);
            }
        }
    }

    void runComponentTests()
    {
        buttonMotor->componentTest();
        buttonValve->componentTest();
        buttonCancel->componentTest();

        motor->componentTest();
        valve->componentTest();
    }
};
LaunchPadMotorValve embeddedSystem = LaunchPadMotorValve("sistema embarcado para acionamento e inserção de combustível de foguete pet", "Sara Guimarães");
