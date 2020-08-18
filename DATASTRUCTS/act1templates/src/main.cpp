//Francisco Zamora Treviño A01570484
// ago 10 2020
#include <iostream>
#include <vector>
#include "Lista.h"
// #include <conio.h>
using namespace std;

int main() {
    Lista<int> lista;
    //prueba de insert
    for (int i= 1; i < 102; i++) { // debe ignorar 1 dato en cout
        lista.insert(i*2);
    }

    //prueba de getData
    try {
        cout << "Dato recuperado:" << lista.getData(2) << endl;
    } catch(runtime_error const& e) {
        cout << "Error: " << e.what()<< endl;
    }

    //prueba de erase
    lista.erase();
    for (int i= 1; i < 102; i++) { //debe decir NO HAY ELEMENTOS 2 veces en cout
        lista.erase();
    }

    //prueba de getSize()
    cout << "Tamaño actual del vector: " << lista.getSize() << endl; //debe ser 0

    for (int i = 0; i < 20; i++) {
        lista.insert(i*2);
    }
    cout << "Tamaño actual del vector: " << lista.getSize() << endl; //debe ser 20

    //pruba de print
    lista.print();

}