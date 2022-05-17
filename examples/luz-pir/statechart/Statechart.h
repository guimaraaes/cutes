

class Statechart
{
public:
    Statechart();

    virtual ~Statechart();

public:
    class Luz
    {

    public:
        bool luzStatus;

        Luz()
        {
            this->luzStatus = true;
        }
        bool isRaisedOFF()
        {
            //  Serial.println("na classe luz ");
            // this->luzStatus = true;

            return luzStatus == false;
        };
        bool isRaisedON()
        {

            return this->luzStatus == true;
        };
    };

    // public:
    class Pir
    {

        bool pirStatus;

    public:
        bool raiseON()
        {

            return this->pirStatus == true;
        };

        bool raiseOFF()
        {
            return this->pirStatus == false;
        };
    };

public:
    Luz *luz = new Luz();

    Pir *pir = new Pir;

public:
    void enter()
    {
        luz->luzStatus = false;
    }
    // virtual void enter();
    int getCount();
    // private:
    //     bool luzStatus;
    //     bool pirStatus;

    // public:
    //     void enter();
    //     // Statechart *luz();
    //     // bool isRaisedOFF();
    //     // bool isRaisedON();

    //     // Statechart *pir();
    //     // bool raiseON();
    //     // bool raiseOFF();
    //     int getCount();
};
