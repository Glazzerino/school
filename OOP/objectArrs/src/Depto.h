//
//  Depto.h
//  departamentosYEmpleados
//
//  Created by Yolanda Martinez on 11/21/19.
//  Copyright © 2019 com.itesm. All rights reserved.
//

#ifndef Depto_h
#define Depto_h

class Depto {
public:
    Depto();
    Depto(int i, string n);
    int getIdDep();
    void setIdDep(int i);
    string getNombre();
    void setNombre(string n);
private:
    int idDep;
    string nombre;
};

Depto::Depto(){
    idDep = 0;
    nombre = '-';
}

Depto::Depto(int i, string n){
    idDep = i;
    nombre = n;
}

int Depto::getIdDep(){
    return idDep;
}
void Depto::setIdDep(int i){
    idDep = i;
}
string Depto::getNombre(){
    return nombre;
}
void Depto::setNombre(string n){
    nombre = n;
}

#endif /* Depto_h */
