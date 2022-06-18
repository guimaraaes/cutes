#ifndef STATECHART_H_INCLUDED
#define STATECHART_H_INCLUDED
#include "../lib/LinkedList/LinkedList.h"
#include "store.cpp"

class Statechart
{

public:
    class Light
    {
    public:
        bool light_status;
        int pin = 13;
        Light(){};

        bool isRaisedOFF()
        {
            Store element = statechart->list->shift();

            return false == element.status && pin == element.pin;
        };
        bool isRaisedON()
        {
            Store element = statechart->list->shift();

            return true == element.status && pin == element.pin;
        };
    };

    class Pir
    {

    public:
        bool pir_status;
        int pin = 6;
        Pir(){};
        bool raiseON()
        {
            Store element = statechart->list->shift();

            return true == element.status && pin == element.pin;
        };
        bool raiseOFF()
        {
            Store element = statechart->list->shift();

            return false == element.status && pin == element.pin;
        };
    };

    Light *light;
    Pir *pir;
    LinkedList<Store> *list;
    void showList()
    {
        Store element = Store();
        for (int i = 0; i < statechart->list->size(); i++)
        {
            element = statechart->list->get(i);
            Serial.print(element.time);
            Serial.print(", ");
            Serial.print(element.pin);
            Serial.print(", ");
            Serial.print(element.status);

            Serial.println(" ");
        }
    }

    void enter()
    {
    }

    int getCount();

    static Statechart *get()
    {
        if (statechart == 0)
            statechart = new Statechart();
        return statechart;
    }

    Statechart(const Statechart &) = delete;

private:
    Statechart()
    {
        list = new LinkedList<Store>();
        light = new Light();
        pir = new Pir();
    }

    static Statechart *statechart;
};
Statechart *Statechart::statechart = 0;
Statechart *statechart = Statechart::get();

class Runner
{
public:
    Runner(){};

    bool proceed_time(int time)
    {
        Store element1 = statechart->list->shift();
        Store element2 = statechart->list->get(0);

        return (element2.time - element1.time) >= time;
    }
};
Runner *runner = new Runner();
#endif
