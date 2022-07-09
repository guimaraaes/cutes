// #include <Arduino.h>

#include "../../../unit-embedded-system-framework/embedded_system/EmbeddedSystem.h"
// #include "../../../unit-embedded-system-framework/component/units-creatores/CreatorUltrasonic.h"
#include "../../../unit-embedded-system-framework/component/units-creatores/CreatorActuatorDigital.h"
#include "../../../unit-embedded-system-framework/component/units-creatores/CreatorSensorDigital.h"

class Arduino : public EmbeddedSystem
{

public:
    SensorDigital *buttonMotor;
    SensorDigital *buttonValve;
    SensorDigital *buttonCancel;

    ActuatorDigital *motor;
    ActuatorDigital *valve;

    int acionamento = 0;
    Arduino(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorSensorDigital *creator_buttonMotor = new CreatorSensorDigital();
        buttonMotor = creator_buttonMotor->createComponent(7);

        CreatorSensorDigital *creator_buttonValve = new CreatorSensorDigital();
        buttonValve = creator_buttonValve->createComponent(12);

        CreatorSensorDigital *creator_buttonCancel = new CreatorSensorDigital();
        buttonCancel = creator_buttonCancel->createComponent(13);

        CreatorActuatorDigital *creator_motor = new CreatorActuatorDigital();
        motor = creator_motor->createComponent(3);

        CreatorActuatorDigital *creator_valve = new CreatorActuatorDigital();
        valve = creator_valve->createComponent(11);
    }
    void loop()
    {

        if (buttonValve->read() == HIGH)
        { // Se o botão for pressionado
            if (buttonCancel->read() == LOW)
            { // Se o botão não estiver pressionado
                delay(3000);
                acionamento = acionamento + 1;
                switch (acionamento)
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
