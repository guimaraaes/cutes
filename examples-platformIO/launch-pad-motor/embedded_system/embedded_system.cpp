class LaunchPadMotor : public EmbeddedSystem
{
public:
    SensorDigital *buttonActuation;
    SensorDigital *buttonCancel;

    ActuatorDigital *motor;
    ActuatorDigital *ledRed;
    ActuatorDigital *ledGreen;

    LaunchPadMotor(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorSensorDigital *creatorSensorDigital = new CreatorSensorDigital();
        buttonActuation = creatorSensorDigital->createComponent(4);
        buttonCancel = creatorSensorDigital->createComponent(3);

        CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
        motor = creatorActuatorDigital->createComponent(5);
        ledRed = creatorActuatorDigital->createComponent(1);
        ledGreen = creatorActuatorDigital->createComponent(2);
    }
    void loop()
    {
        motor->write(LOW);
        ledRed->write(LOW);
        ledGreen->write(LOW);
        if (buttonActuation->read() == HIGH)
        {
            ledRed->write(HIGH);
            delay(5000);
            ledGreen->write(HIGH);
            delay(2000);
            if (buttonCancel->read() == HIGH)
            {
                ledRed->write(LOW);
                ledGreen->write(LOW);
            }
            else if (buttonCancel->read() == LOW)
            {
                ledRed->write(LOW);
                motor->write(HIGH);
                delay(200);
                motor->write(LOW);
                digitalWrite(motor, LOW);
                ledGreen->write(LOW);
            }
        }
    };
    void runUnitTests()
    {
        buttonActuation->unitTest();
        buttonCancel->unitTest();

        motor->unitTest();
        ledRed->unitTest();
        ledGreen->unitTest();
    }
};
LaunchPadMotor launchPadMotor = LaunchPadMotor("sistema embarcado para acionamento de foguete pet", "Sara Guimarães");
