//
//  Empleado.h
//  departamentosYEmpleados
//
//  Created by Yolanda Martinez on 11/21/19.
//  Copyright © 2019 com.itesm. All rights reserved.
//

#ifndef Empleado_h
#define Empleado_h
#include<string>
using namespace std;
class Empleado {
public:
    Empleado();
    Empleado(int i, string n, int nuD);
    int getIdEmp();
    void setIdEmp(int i);
    string getNombre();
    void setNombre(string n);
    int getNumDepto();
    void setNumDepto(int d);
private:
    int idEmp;
    string nombre;
    int numDepto;
};

Empleado::Empleado(){
    idEmp = 0;
    nombre = '-';
    numDepto = 0;
}

Empleado::Empleado(int i, string n, int nuD){
    idEmp = i;
    nombre = n;
    numDepto = nuD;
}

int Empleado::getIdEmp(){
    return idEmp;
}
void Empleado::setIdEmp(int i){
    idEmp = i;
}
string Empleado::getNombre(){
    return nombre;
}
void Empleado::setNombre(string n){
    nombre = n;
}

int Empleado::getNumDepto() {
    return numDepto;
}

void Empleado::setNumDepto(int d) {
    numDepto = d;
}

#endif /* Empleado_h */
