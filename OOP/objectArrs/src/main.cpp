#include <iostream>
#include "Empleado.h"
#include <vector>
#include <fstream>
#include "Depto.h"
using namespace std;

void cargaDatosDepto(Depto lista[], int &cantEmpleados) {
   ifstream data;
   data.open("data.txt");
   string nombre;
   int idDep;
   int i = 0;
   while(data >> idDep >> nombre) {
       lista[i].setIdDep(idDep);
       lista[i].setNombre(nombre);
       i++;
   }
   cantEmpleados = i;
   data.close();
}

void muestraDatosDepto(Depto lista[], int cantidad) {
    for (int i=0;i<cantidad;i++) {
        cout << lista[i].getNombre() << " ";
        cout << lista[i].getIdDep() << endl;
    }
}

int main() {
    int cantEmpleados;
    Depto lista[10];
    cargaDatosDepto(lista,cantEmpleados);
    muestraDatosDepto(lista,cantEmpleados);
    return 0;
}