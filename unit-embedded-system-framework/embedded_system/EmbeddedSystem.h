#include "../component/Creator.h"
#include "../component/Component.h"

#include <Arduino.h>
#ifndef EMBEDDEDSYSTEM_H_INCLUDED
#define EMBEDDEDSYSTEM_H_INCLUDED
class EmbeddedSystem
{
protected:
    String description;
    String author;

public:
    void configuration();
    void setup();
    void loop();
};

class AbstractEmbeddedSystem : public EmbeddedSystem
{
protected:
    String description;
    String author;

public:
    virtual void configuration() = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
#endif