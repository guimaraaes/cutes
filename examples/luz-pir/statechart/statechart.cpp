#ifndef STATECHART_H_INCLUDED
#define STATECHART_H_INCLUDED

class Statechart
{

public:
    class Luz
    {
    public:
        bool luzStatus;
        Luz(){};
        void set(bool value)
        {
            luzStatus = value;
        };
        bool isRaisedOFF()
        {
            return luzStatus == false;
        };
        bool isRaisedON()
        {
            return luzStatus == true;
        };
    };

    class Pir
    {
        bool pirStatus = true;

    public:
        Pir(){};
        void set(bool value)
        {
            pirStatus = value;
        };
        void raiseON()
        {

            while (this->pirStatus == false)
            {
            };
        };
        void raiseOFF()
        {
            while (this->pirStatus == true)
            {
            };
        };
    };

    Luz *luz;
    Pir *pir;
    void enter()
    {
        // luz->luzStatus = t;
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
        luz = new Luz();
        pir = new Pir();
    }

    static Statechart *statechart;
};
Statechart *Statechart::statechart = 0;
#endif
