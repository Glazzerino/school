#pragma once
#include "Persona.h"
class Envio {
    public:
        Envio();
        Envio(Persona, Persona, double);
        void setRemitente(Persona rem) {remitente=rem;};
        Persona getRemitente() {return remitente;};
        void setDestinatario(Persona des) {destinatario=des;};
        Persona getDestinatario() {return destinatario;};
        void setCostoEstandar(double c) {costo_base=c;};
        double getCostoEstandar() {return costo_base;};
        virtual double calculaCosto() = 0; 
    protected:
        Persona remitente;
        Persona destinatario;
        double costo_base;
};

Envio::Envio() : remitente(Persona()), destinatario(Persona()), costo_base(0) {}

Envio::Envio(Persona rem, Persona dest, double costo) : remitente(rem), destinatario(dest), costo_base(costo) {};
