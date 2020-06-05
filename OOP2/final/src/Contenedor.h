#pragma once
#include <string>
#include "Video.h"
#include <vector>
using namespace std;

class Contenedor {
public:
    Contenedor(string nombre, bool limit_one);
    bool agregar(Video*);
    void set_nombre(string nombre) {this->nombre = nombre;};
    string get_nombre() {return nombre;};
    virtual void imprimir()=0;
    vector<Video*> get_contenido() {return contenido;};
    bool es_pelicula() {return limit_one;}; // si se limita el vector a 1 entonces es peli
protected:
    string type, nombre;
    vector<Video*> contenido;
    bool limit_one;
};

Contenedor::Contenedor(string nombre, bool limit_one) {
    this->type = type;
    this->nombre = nombre;
}

bool Contenedor::agregar(Video* nuevo_vid) {
    //Es bool como medida de protección 
    if (limit_one && contenido.size() >= 1) {
        return false;
    } else {
        contenido.push_back(nuevo_vid);
        return true;
    }
}
