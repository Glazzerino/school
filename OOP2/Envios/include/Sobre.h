#pragma once
#include "Envio.h"

class Sobre : public Envio {
    public:
        Sobre();
        Sobre(Persona, Persona, double,double,double,double);
        void   setLargo(double n) {largo = n;};
        void   setAncho(double n) {ancho = n;};
        double getLargo() {return largo;};
        double getAncho() {return ancho;};
        void   setCargoAdicional(double n) {cargoAdicional = n;};
        double getCargoAdicional() {return cargoAdicional;};
        double calculaCosto();
    private:
        double 
        largo,
        ancho,
        cargoAdicional;
};

Sobre::Sobre() : Envio(), largo(0), ancho(0),cargoAdicional(0) {}

Sobre::Sobre(Persona rem, Persona des, double costo, double largo, double ancho, double cargoAdicional) : 
    Envio(rem,des,costo) {
        this->largo = largo;
        this->ancho = ancho;
        this->cargoAdicional = cargoAdicional;
}

double Sobre::calculaCostoEnvio() {
    if (ancho > 30 && largo > 25) {
        return Envio::costo_base + cargoAdicional;
    } else {
        return Envio::costo_base;
    }
}