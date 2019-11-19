//
#include <iostream>
#include <cmath>
using namespace std;

#include "Circulo.h"

int main()
{
    Circulo circ1;
    circ1.setRadio(10);
    cout<<"Radio = "<<circ1.getRadio()<<endl;
    cout<<"Area = "<<circ1.calcArea()<<endl;
    cout<<"Perimetro = "<<circ1.calcPerim()<<endl;
    
    return 0;
}
