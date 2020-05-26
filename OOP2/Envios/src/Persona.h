#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona {
public:
    Persona();
    
    Persona(string n,string estado, string cd, string cp);

    void setNombre(string n) { nombre=n; };

    string getNombre() { return nombre; };

    void setCP(string cp) {
        this->cp=cp;
    };
    string getCiudad() {
        return ciudad;
    };
    void setCiudad(string c) {
        ciudad=c;
    };
    string getEstado() {
        return estado;
    };
    void setEstado(string e) {
        estado=e;
    };
    void Imprimir();
private:
    string
    nombre,
    estado,
    ciudad,
    cp;
};

Persona::Persona() {
    nombre = "NA";
    estado = "NA";
    ciudad = "NA";
    cp = "NA";
}

Persona::Persona(string n,string e, string c, string cp_input):nombre(n),estado(e),ciudad(c),cp(cp_input) {}

void Persona::Imprimir() {
    cout << "Dirección: " << estado << " " << ciudad << " " << cp << endl;
}