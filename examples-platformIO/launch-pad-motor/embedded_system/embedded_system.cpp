

#include "../../../cutes/embedded_system/EmbeddedSystem.h"
#include "../../../cutes/component/units-creatores/CreatorActuatorDigital.h"
#include "../../../cutes/component/units-creatores/CreatorSensorDigital.h"

class Arduino : public EmbeddedSystem
{

public:
    SensorDigital *buttonActuation;
    SensorDigital *buttonCancel;

    ActuatorDigital *motor;
    ActuatorDigital *ledRed;
    ActuatorDigital *ledGreen;

    Arduino(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorSensorDigital *creator_sensor_digital = new CreatorSensorDigital();
        buttonActuation = creator_sensor_digital->createComponent(4);
        buttonCancel = creator_sensor_digital->createComponent(3);

        CreatorActuatorDigital *creator_actuator_digital = new CreatorActuatorDigital();
        motor = creator_actuator_digital->createComponent(5);
        ledRed = creator_actuator_digital->createComponent(1);
        ledGreen = creator_actuator_digital->createComponent(2);
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
    void unitTests()
    {
        buttonActuation->unitTest();
        buttonCancel->unitTest();

        motor->unitTest();
        ledRed->unitTest();
        ledGreen->unitTest();
    }
};
Arduino launch_pad = Arduino("sistema embarcado para acionamento de foguete pet", "Sara Guimarães");
