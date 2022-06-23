#include "../store/Store.cpp"
#include "../store/Interation.cpp"

#ifndef COMPONENTBEHAVIOR_H_INCLUDED
#define COMPONENTBEHAVIOR_H_INCLUDED

class ComponentBehavior
{
public:
    Store store;
    void addStore(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        this->store.list->add(element);
        // this->store.showList();
    };
};
#endif
