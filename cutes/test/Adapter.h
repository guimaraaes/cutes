// #include "../lib/AUnit/src/AUnit.h"
// class Target
// {
// public:
//     virtual ~Target() = default;

//     virtual void Test() const
//     {
//         return "Target: The default target's behavior.";
//     }
// };
// class AdapteeAUnit : public TestOnce
// {
// public:
//     void setup() override
//     {
//         TestOnce::setup();
//         TestRunner::setTimeout(30);
//         TestRunner::exclude("*");
//         // TestRunner::include("looping*");
//         TestRunner::include("StatechartTest", "*");
//     }
//     void teardown() override
//     {
//         TestOnce::teardown();
//     }
//     void loop()
//     {
//         // arduino->loopArduino(statechart);
//         TestRunner::run();
//     }
// };
// test(StatechartTest, test_0to20)
// {
//     statechart->list->clear();
//     Serial.println("test_0to20");
//     delay(3000);

//     arduino->loopArduino();

//     if (!statechart->ultrasonic->raise_0to20())
//         failTestNow();

//     assertTrue(statechart->light->isRaisedOFF());

//     // runner->proceed_time(4 * 1000);
// }
// class Adapter : public Target
// {
// private:
//     AdapteeAUnit *adaptee_;

// public:
//     Adapter(AdapteeAUnit *adaptee) : adaptee_(adaptee) {}
//     void Test() const override
//     {
//     }
// };