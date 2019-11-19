#include "CtaBanc.h"
#include <iostream>
using namespace std;
CtaBanc::CtaBanc(){
    nombre = "-";
    saldo = 0;
}

CtaBanc::CtaBanc(string nom, double sal) {
    nombre = nom;
    saldo = sal;
}

void CtaBanc::setSaldo(double input) {
    saldo = input;
}

void CtaBanc::setNombre(string nom) {
    nombre = nom;
}
void CtaBanc::deposita(double input) {
    saldo += input;
}
bool CtaBanc::retira(double input) {
    if (input <= saldo) {
        saldo -= input;
        return true;
    } else {
        return false;
    }
}
void CtaBanc::muestra() {
    cout << "Cliente : " << nombre << " saldo : $" << saldo << endl;
}
