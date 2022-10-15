#pragma once
#include "../lib/LinkedList/LinkedList.h"
#include "Interation.h"

class History
{

public:
    LinkedList<Interation> *list;
    void showList()
    {
        Serial.println("---- history embedded system ----");
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

    static History *get()
    {
        if (history == 0)
            history = new History();
        return history;
    }

    // History(const History &) = delete;

    bool proceedTime(int time)
    {
        Interation element1 = this->list->shift();
        Interation element2 = this->list->get(0);

        return (element2.time - element1.time) >= time;
    }

public:
    History()
    {
        list = new LinkedList<Interation>();
    }
    static History *history;
};
History *History::history = 0;
History *history = History::get();
