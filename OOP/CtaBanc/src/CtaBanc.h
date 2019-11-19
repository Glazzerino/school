#pragma once
#include <string>
using namespace std;

class CtaBanc {
public:
    CtaBanc();
    CtaBanc(string nom, double salto);
    double getSaldo();
    string getNombre();
    void setSaldo(double input);
    void setNombre(string nom);
    void deposita(double input);
    bool retira(double input);
    void muestra();
private:
    string nombre;
    double saldo;
};
