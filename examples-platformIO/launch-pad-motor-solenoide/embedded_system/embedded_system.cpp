// #include <Arduino.h>

#include "../../../cutes/embedded_system/EmbeddedSystem.h"
#include "../../../cutes/component/units-creatores/CreatorActuatorDigital.h"
#include "../../../cutes/component/units-creatores/CreatorSensorDigital.h"

class Arduino : public EmbeddedSystem
{

public:
    SensorDigital *buttonMotor;
    SensorDigital *buttonValve;
    SensorDigital *buttonCancel;

    ActuatorDigital *motor;
    ActuatorDigital *valve;

    int actuation = 0;
    Arduino(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorSensorDigital *creator_button = new CreatorSensorDigital();
        buttonMotor = creator_button->createComponent(7);
        buttonValve = creator_button->createComponent(12);
        buttonCancel = creator_button->createComponent(13);

        CreatorActuatorDigital *creator_actuator_digital = new CreatorActuatorDigital();
        motor = creator_actuator_digital->createComponent(3);
        valve = creator_actuator_digital->createComponent(11);
    }
    void loop()
    {

        if (buttonValve->read() == HIGH)
        { // Se o botão for pressionado
            if (buttonCancel->read() == LOW)
            { // Se o botão não estiver pressionado
                delay(3000);
                actuation = actuation + 1;
                switch (actuation)
                {
                case '1':
                    valve->write(HIGH);
                    delay(20000); // Solenoide abre por 20s
                    valve->write(LOW);
                    break;
                case '2':
                    valve->write(HIGH);
                    delay(32000); // Solenoide abre por 32s
                    valve->write(LOW);
                    break;
                case '3':
                    valve->write(HIGH);
                    delay(400000); // Solenoide abre por 40s
                    valve->write(LOW);
                    break;
                }
            }
        }
        if (buttonMotor->read() == HIGH)
        { // Se o botão for pressionado
            if (buttonCancel->read() == LOW)
            { // Se o botão não estiver pressionado
                delay(3000);
                motor->write(HIGH);

                delay(200); // Motor trabalha por 0,2s
                motor->write(LOW);
            }
        }
    }
};
Arduino launch_pad = Arduino("sistema embarcado para acionamento e inserção de combustível de foguete pet", "Sara Guimarães");
