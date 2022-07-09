#include "../../../cutes/embedded_system/EmbeddedSystem.h"
#include "../../../cutes/component/units-creatores/CreatorActuatorDigital.h"
#include "../../../cutes/component/units-creatores/CreatorSensorDigital.h"

class Arduino : public EmbeddedSystem
{

public:
    ActuatorDigital *light;
    SensorDigital *pir;

    Arduino(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        CreatorActuatorDigital *creator_light = new CreatorActuatorDigital();
        light = creator_light->createComponent(13);

        CreatorSensorDigital *creator_pir = new CreatorSensorDigital();
        pir = creator_pir->createComponent(3);
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
};
Arduino pir_light = Arduino("sistema embarcado acender luz enquanto movimento for detectado", "Sara Guimarães");