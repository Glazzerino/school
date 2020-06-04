#pragma once
#include <string>
#include "Video.h"
#include <vector>
using namespace std;

class Contenedor {
public:
    Contenedor(string type,string nombre, bool limit_one);
    bool agregar(Video*);
    virtual void imprimir()=0;
    vector<Video*> get_contenido() {return contenido;};
protected:
    string type, nombre;
    vector<Video*> contenido;
    bool limit_one;
};

Contenedor::Contenedor(string type,string nombre, bool limit_one) {
    this->limit_one = limit_one;
    this->type = type;
    this->nombre = nombre;
}

bool Contenedor::agregar(Video* nuevo_vid) {
    if (limit_one && contenido.size() >= 1) {
        return false;
    } else {
        contenido.push_back(nuevo_vid);
        return true;
    }
}
