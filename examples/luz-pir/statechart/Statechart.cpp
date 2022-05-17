#include "Statechart.h"
// using namespace std;

// void Statechart::luz(){

// };

Statechart::Statechart()
{
}
Statechart::~Statechart()
{
}
// Statechart::Pir::Pir(Statechart *parent) : ON_raised(false),
//                                            OFF_raised(false),
//                                            parent(parent)
// {
// }
// Statechart::Luz::Luz()
// {
// }
// bool Statechart::Luz::isRaisedOFF()
// {
//     return this->luzStatus == false;
// };

bool Statechart::Luz::isRaisedON()
{

    return this->luzStatus == true;
};

bool Statechart::Pir::raiseOFF()
{
    return this->pirStatus == false;
};

bool Statechart::Pir::raiseON()
{

    return this->pirStatus == true;
};

// void Statechart::enter()
// {
// }