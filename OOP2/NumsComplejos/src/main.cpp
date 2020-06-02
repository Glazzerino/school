#include <iostream>
#include "Complejo.h"
#include <fstream>
using namespace std;
int main() {
    Complejo arr[100];
    ifstream file("data.txt");
    int r,i;
    int arrlen = 0;
    Complejo suma;
    while(file >> r >> i) {
        Complejo nuevo{r,i};
        arr[arrlen] = nuevo;
        arrlen++;
        cout << nuevo.muestra() << endl;
        suma = suma.suma(nuevo);
    }
    cout << "Suma: "<< suma.muestra() << endl;
}