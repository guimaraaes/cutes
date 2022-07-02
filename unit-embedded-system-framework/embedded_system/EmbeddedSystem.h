

#ifndef EMBEDDEDSYSTEM_H_INCLUDED
#define EMBEDDEDSYSTEM_H_INCLUDED
class EmbeddedSystem
{
protected:
    String description;
    String author;

public:
    EmbeddedSystem(String description, String author)
    {
        this->description = description;
        this->author = author;
    };
    virtual void configuration() = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif