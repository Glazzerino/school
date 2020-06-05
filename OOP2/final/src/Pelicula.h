#pragma once
#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(string, string, int, int, double, GENERO, bool, string,bool);
    
    bool get_oscar() {return oscar;};
    virtual void imprimir();
private:
    bool oscar;
    string saga;
};

Pelicula::Pelicula(): Video() {
    oscar = false;
    saga = "NA";
}

Pelicula::Pelicula(string nombre, string resumen, int id, int duracion, double rating, 
GENERO genero, bool oscar, string saga,bool espeli) : Video(nombre,resumen,id,duracion,rating,genero,espeli) {
    this->oscar = oscar;
    this->saga = saga;
}

void Pelicula::imprimir() {
    Video::imprimir();
    cout << "Oscar: " << (oscar ? "Si": "No") << endl;
    cout << "Saga: " << saga << endl;
}


