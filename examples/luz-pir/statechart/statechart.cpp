#ifndef STATECHART_H_INCLUDED
#define STATECHART_H_INCLUDED

class Statechart
{

public:
    class Runner
    {
    public:
        Runner(){};
        void proceed_time(long time)
        {
            delay(time);
        };
    };
    class Light
    {
    public:
        bool light_status;
        Light(){};
        void set(bool value)
        {
            this->light_status = value;
        };
        bool isRaisedOFF()
        {
            return this->light_status == false;
        };
        bool isRaisedON()
        {
            return this->light_status == true;
        };
    };

    class Pir
    {
        bool pir_status = true;

    public:
        Pir(){};
        void set(bool value)
        {
            this->pir_status = value;
        };
        void raiseON()
        {

            while (this->pir_status == false)
            {
            };
        };
        void raiseOFF()
        {
            while (this->pir_status == true)
            {
            };
        };
    };

    Runner *runner;
    Light *light;
    Pir *pir;
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
        runner = new Runner();
        light = new Light();
        pir = new Pir();
    }

    static Statechart *statechart;
};
Statechart *Statechart::statechart = 0;
#endif
