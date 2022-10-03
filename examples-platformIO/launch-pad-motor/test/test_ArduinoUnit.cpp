#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/history/History.h"

void enter(String name)
{
    Serial.println(name);
    delay(3000);
    launch_pad.setup();
    launch_pad.loop();
};

void exit()
{
    history->list->clear();
};

test(testState1Actuation)
{
    enter("testState1Actuation");
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    assertTrue(launch_pad.ledRed->behavior->isRaisedHigh());
    exit();
}

test(testState2Actuation)
{
    enter("testState2Actuation");
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    runner->proceed_time(5 * 1000);
    assertTrue(launch_pad.ledGreen->behavior->isRaisedHigh());
}

test(testStateCancelActuation)
{
    enter("testStateCancelActuation");
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    runner->proceed_time(7 * 1000);
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    assertTrue(launch_pad.motor->behavior->isRaisedLow());
    exit();
}

test(testActuation)
{
    enter("testActuation");
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    runner->proceed_time(7 * 1000);
    if (!launch_pad.buttonActuation->behavior->isRaisedLow())
        fail();
    assertTrue(launch_pad.motor->behavior->isRaisedHigh());
    exit();
}

test(testActuationTime)
{
    enter("testActuation");
    if (!launch_pad.buttonActuation->behavior->isRaisedHigh())
        fail();
    runner->proceed_time(7 * 1000);
    if (!launch_pad.buttonActuation->behavior->isRaisedLow())
        fail();
    assertTrue(launch_pad.motor->behavior->isRaisedHigh());
    runner->proceed_time(200);
    assertTrue(launch_pad.motor->behavior->isRaisedLow());
    exit();
}
