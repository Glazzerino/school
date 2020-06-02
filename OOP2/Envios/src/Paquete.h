#pragma once
#include "Envio.h"

class Paquete : public Envio {
public:
    Paquete();
    Paquete(Persona, Persona, double, double, double);
    void setPeso(double p) {
        peso = p;
    };
    double getPeso() {
        return peso;
    };
    void setCostoKg(double c) {
        costoKg = c;
    };
    double getCostoKg() {
        return costoKg;
    };
    double calculaCosto();
private:
    double peso, costoKg;
};

Paquete::Paquete() : Envio() {
    peso = 0;
    costoKg = 0;
}

Paquete::Paquete(Persona rem, Persona des, double costo, double peso, double costoKg) :
    Envio(rem, des, costo),peso(peso), costoKg(costoKg) {}

double Paquete::calculaCosto() {
    return Envio::costo_base + (peso * costoKg);
}