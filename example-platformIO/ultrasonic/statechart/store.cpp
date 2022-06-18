#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

class Store
{

public:
    unsigned long time;
    bool status;
    int distance;
    int pin;
    Store(){};
    Store(unsigned long time, bool status, float distance, int pin)
    {
        this->time = time;
        this->status = status;
        this->distance = distance;
        this->pin = pin;
    };
};
Store *store;
#endif
