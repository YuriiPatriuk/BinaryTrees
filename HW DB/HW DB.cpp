#include "DB.h"

int main()
{
    Violation vi("strinh", {21,12,2021}, 345.345);
    Violation vi2("st1111rinh", {21,12,2021}, 345);
    vi.print();

    DB base;
    base.addCar(153672, vi);
    base.addCar(333333, { "qwerty",{3,3,2012},444.6 });
    base.addCar(153672, vi2);
    base.print();

   
    
    
}
