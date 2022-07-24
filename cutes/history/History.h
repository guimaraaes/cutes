#include "Interation.h"
#include "../lib/LinkedList/LinkedList.h"

#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

class History
{

public:
    LinkedList<Interation> *list;
    void showList()
    {
        // Serial.println("show list");
        Interation element = Interation();
        for (int i = 0; i < list->size(); i++)
        {
            element = list->get(i);
            Serial.print(element.time);
            Serial.print(", ");
            Serial.print(element.pin);
            Serial.print(", ");
            Serial.print(element.value);

            Serial.println(" ");
        }
    }

    bool proceed_time(int time)
    {
        Interation element1 = list->shift();
        Interation element2 = list->get(0);

        return (element2.time - element1.time) >= time;
    }

    static History *get()
    {
        if (history == 0)
            history = new History();
        return history;
    }

    // History(const History &) = delete;

public:
    History()
    {
        list = new LinkedList<Interation>();
    }
    static History *history;
};
History *History::history = 0;
History *history = History::get();
#endif