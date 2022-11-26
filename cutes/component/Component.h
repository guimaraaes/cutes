#pragma once

#ifdef TEST_ENVIROMENT
#include "ComponentBehavior.h"
#include "../history/History.h"
#include "../history/Interation.h"
#endif

class Component
{
public:
    int pin;
#ifdef TEST_ENVIROMENT
    ComponentBehavior *behavior;
    History *history;
#endif
    void addHistory(int pin, int value)
    {
#ifdef TEST_ENVIROMENT
        Interation element = Interation(millis(), value, pin);
        history->list->add(element);
#endif
    };

    void unitTest(int value);

    // bool assertValueSensor(int value)
    // {
    //     Serial.println((String) "--- Put within 5 seconds component with the value " + value);
    //     delay(5000);
    //     int valueReaded = this->read_cm();
    //     Serial.println((String) "--- Unit test result: you must assert. Wait to answer." + (valueReaded == value));
    //     delay(2000);
    //     Serial.println((String) "---- Value expected" + value);
    //     Serial.println((String) "---- Value readed" + valueReaded);
    //     delay(2000);
    //     Serial.println("Unit test pass?");
    //     bool result = Serial.read();
    //     Serial.println("Reload unit test?");
    //     bool reload = Serial.read();
    //     return [ result, reload ];
    // }
};
