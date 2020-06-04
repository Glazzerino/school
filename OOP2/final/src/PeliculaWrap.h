//Implementacion de Contenedor para Pelicula
#pragma once
#include "Pelicula.h"
#include "Contenedor.h"
class PeliculaWrap : public Contenedor {
public:
    PeliculaWrap();
    PeliculaWrap(Pelicula* pelicula);
    virtual void imprimir();
};

PeliculaWrap::PeliculaWrap() : Contenedor("pelicula", "NA", true){}

PeliculaWrap::PeliculaWrap(Pelicula* pelicula) : Contenedor("pelicula", pelicula->get_nombre(), true) {
    if (!Contenedor::agregar(pelicula)) {
        cout << "Error! contenedor lleno para pelicula. Esto no debió pasar" << endl;
    }
}

void PeliculaWrap::imprimir() {
    Contenedor::get_contenido()[0]->imprimir();
}