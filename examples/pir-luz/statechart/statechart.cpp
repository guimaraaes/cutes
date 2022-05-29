#ifndef STATECHART_H_INCLUDED
#define STATECHART_H_INCLUDED
#include <LinkedList.h>
#include "store.cpp"
#include <AUnit.h>
using namespace aunit;

class Statechart
{

public:
    class Runner
    {
    public:
        Runner(){};
        void proceed_time(long time){
            // delay(time);
        };
    };
    class Light
    {
    public:
        bool light_status;
        int pin = 13;
        Light(){};

        bool isRaisedOFF()
        {
            Store element = statechart->list->get(0);
            statechart->list->remove(0);

            return false == element.status && pin == element.pin;
        };
        bool isRaisedON()
        {
            Store element = statechart->list->get(0);
            statechart->list->remove(0);

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
            Store element = statechart->list->get(0);
            statechart->list->remove(0);

            return true == element.status && pin == element.pin;
        };
        bool raiseOFF()
        {
            Store element = statechart->list->get(0);
            statechart->list->remove(0);

            return false == element.status && pin == element.pin;
        };
    };

    Runner *runner;
    Light *light;
    Pir *pir;
    LinkedList<Store> *list;

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
        runner = new Runner();
        light = new Light();
        pir = new Pir();
    }

    static Statechart *statechart;
};
Statechart *Statechart::statechart = 0;
Statechart *statechart = Statechart::get();
#endif
