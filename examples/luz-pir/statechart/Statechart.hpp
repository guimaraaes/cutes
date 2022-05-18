class Statechart
{

public:
    class Luz
    {
    public:
        bool luzStatus;
        Luz()
        {
        }
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
        bool pirStatus;

    public:
        Pir()
        {
            pirStatus = false;
        }
        bool raiseON()
        {
            this->pirStatus = true;
            return this->pirStatus == true;
        };

        bool raiseOFF()
        {
            return this->pirStatus == false;
        };
    };

    Luz *luz;
    Pir *pir;
    void enter(bool t)
    {
        luz->luzStatus = t;
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