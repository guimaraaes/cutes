#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

class Store
{

public:
    unsigned long time;
    bool status;
    int pin;
    Store(){};
    Store(unsigned long time, bool status, int pin)
    {
        this->time = time;
        this->status = status;
        this->pin = pin;
    };
};
Store *store;
#endif
