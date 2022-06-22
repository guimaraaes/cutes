#include "src/Embedded_System.cpp"
#include <iostream>
using namespace std;

int main()
{
    // Embedded_System configuration();
    Arduino es;
    es.createSensor();
    // es.configuration();
    // std::cout << "Hello World!" << std::endl;

    return 0;
}