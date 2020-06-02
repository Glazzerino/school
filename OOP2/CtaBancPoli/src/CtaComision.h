// Escribe la clase CtaComision
// Usa estas líneas para mostrar los datos de una cuenta por comision.
// En la primera línea muestras los datos de la cuenta bancaria
// y en la línea de abajo muestras la comisión de la cuenta.
//    CtaBanc:: mostrar();     
//    cout <<"Comision: " << comision << endl;
#pragma once
#include "CtaBanc.h"
#include <iostream>

class CtaComision : public CtaBanc {

    public:
        
        CtaComision();
        CtaComision(int id, double saldo, double comision);
        bool retira(double cantidad);
        double getComision() {return comision;};
        void setComision(double n) {this->comision = n;};
        void mostrar();
    private:
        double comision;
};

CtaComision::CtaComision() : CtaBanc(),comision(0) {}

CtaComision::CtaComision(int id, double saldo, double com): CtaBanc::CtaBanc(id,saldo), comision(com){}
                                                    
void CtaComision::mostrar() {
   CtaBanc::mostrar();     
   cout <<"Comision: " << comision << endl;
}

bool CtaComision::retira(double cantidad) {
    cantidad += comision;
    return CtaBanc::retira(cantidad);
}
