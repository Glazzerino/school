#pragma once
#include <string>
using namespace std;
class Pasajero {
    private:
        int id;
        string destino;
        string inicio;
        string nombre;
    public:
        Pasajero();
        Pasajero(int id, string nombre, string destino, string salida);
        void setId(int id);
        int getId();
        void setDestino(string destino);
        string getDestino();
        void setSalida(string inicio);
        string getSalida();
        void setNombre(string nombre);
        string getNombre();
};

Pasajero::Pasajero() {
    nombre = "null";
    inicio = "DEFAULT";
    destino = "DEFAULT";
    id = 0;
}

Pasajero::Pasajero(int id, string destino, string inicio, string nombre) {
    this->nombre = nombre;
    this->inicio = inicio;
    this->destino = destino;
    this->id = id;
}

void Pasajero::setId(int id) {
    this->id = id;
}

int Pasajero::getId() {
    return this->id;
}

void Pasajero::setDestino(string idDestino) {
    this->destino = idDestino;
}

string Pasajero::getDestino() {
    return this->destino;
}

void Pasajero::setSalida(string inicio) {
    this->inicio = inicio;
}

string Pasajero::getSalida() {
    return this->inicio;
}

