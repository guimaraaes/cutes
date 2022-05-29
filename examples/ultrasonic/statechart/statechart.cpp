#ifndef STATECHART_H_INCLUDED
#define STATECHART_H_INCLUDED

class Statechart
{

public:
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
        bool isRaisedONOFF()
        {
            return this->light_status == true;
        };
    };

    class Ultrasonic
    {
        float distance = 0.0;

    public:
        Ultrasonic(){};
        void set(bool value)
        {
            this->distance = value;
        };
        void raise_10a20()
        {

            while (this->distance < 10 && this->distance > 20)
            {
            };
        };
        void raise_20a30()
        {

            while (this->distance < 20 && this->distance > 30)
            {
            };
        };

        void raise_30()
        {
            while (this->distance < 20)
            {
            };
        };
    };

    Light *light;
    Ultrasonic *ultrasonic;
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
    }

    static Statechart *statechart;
};
Statechart *Statechart::statechart = 0;
Statechart *statechart = Statechart::get();

#endif