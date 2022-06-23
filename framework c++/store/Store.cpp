
#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include "Interation.cpp"
#include "../lib/LinkedList/LinkedList.h"
class Store
{

public:
    LinkedList<Interation> *list;
    void showList()
    {
        Interation element = Interation();
        for (int i = 0; i < list->size(); i++)
        {
            element = list->get(i);
            // Serial.print(element.time);
            // Serial.print(", ");
            // Serial.print(element.pin);
            // Serial.print(", ");
            // Serial.print(element.value);

            // Serial.println(" ");
        }
    }

    bool proceed_time(int time)
    {
        Interation element1 = list->shift();
        Interation element2 = list->get(0);

        return (element2.time - element1.time) >= time;
    }

    static Store *get()
    {
        if (store == 0)
            store = new Store();
        return store;
    }

    // Store(const Store &) = delete;

public:
    Store()
    {
        list = new LinkedList<Interation>();
    }
    static Store *store;
};
Store *Store::store = 0;
Store *store = Store::get();
#endif