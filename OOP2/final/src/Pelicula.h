#pragma once
#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(string, string ,string, int, int, double, GENERO, bool, string);

    bool get_oscar() {return oscar;};
    void imprimir();
private:
    bool oscar;
    string saga;
};

Pelicula::Pelicula(): Video() {
    oscar = false;
    saga = "NA";
}

Pelicula::Pelicula(string nombre, string resumen,string estudio, int id, int duracion, double rating, 
GENERO genero, bool oscar, string saga) : Video(nombre,resumen,estudio,id,duracion,rating,genero) {
    this->oscar = oscar;
    this->saga = saga;
}

void Pelicula::imprimir() {
    Video::imprimir();
}


