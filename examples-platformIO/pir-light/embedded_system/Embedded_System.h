#include "../component/Creator.h"
#include "../component/Component.h"

#ifndef EMBEDDED_SYSTEM_H_INCLUDED
#define EMBEDDED_SYSTEM_H_INCLUDED
class Embedded_System
{
protected:
    String description;
    String author;

public:
    void configuration();
    void setup();
    void loop();
};

class AbstractEmbedded_System : public Embedded_System
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