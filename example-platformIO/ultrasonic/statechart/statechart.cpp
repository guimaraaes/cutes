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
        bool isRaisedONOFF()
        {
            Store element1 = statechart->list->shift();
            Store element2 = statechart->list->shift();

            return (true == element1.status && pin == element1.pin) && (false == element2.status && pin == element2.pin);
        };
    };

    class Ultrasonic
    {
        float distance = 0.0;
        int pinTrigger = 4;
        int pinEcho = 5;

    public:
        Ultrasonic(){};

        bool raise_0to20()
        {
            Store element = statechart->list->shift();
            while ((element.distance < 0 || element.distance >= 20 || pinTrigger != element.pin) && statechart->list->size() > 0)
            {
                element = statechart->list->shift();
            }
            return element.distance >= 0 && element.distance < 20 && pinTrigger == element.pin;
        };
        bool raise_20to30()
        {
            Store element = statechart->list->shift();
            while ((element.distance < 20 || element.distance >= 30 || pinTrigger != element.pin) && statechart->list->size() > 0)
            {
                element = statechart->list->shift();
            }
            return element.distance >= 20 && element.distance < 30 && pinTrigger == element.pin;
        };

        bool raise_30toLarger()
        {
            Store element = statechart->list->shift();
            while ((element.distance < 30 || pinTrigger != element.pin) && statechart->list->size() > 0)
            {
                element = statechart->list->shift();
            }
            return element.distance >= 30 && pinTrigger == element.pin;
        };
    };

    Light *light;
    Ultrasonic *ultrasonic;
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
            Serial.print(", ");
            Serial.print(element.distance);
            Serial.println(" ");
        }
    }

    void enter()
    {
    }

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
        light = new Light();
        ultrasonic = new Ultrasonic();
        list = new LinkedList<Store>();
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