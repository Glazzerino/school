#pragma once
#include "Genero.inc"
#include <iostream>
using namespace std;
class Video {
public:
    Video();
    Video(string, string , int, int, double, GENERO,bool);

    string get_nombre() { return nombre; };
    void set_nombre(string nombre){this->nombre = nombre;};

    string get_resumen() { return resumen; };
    void set_resumen(string resumen){resumen = resumen;};

    GENERO get_genero() { return genero; };
    void set_genero(GENERO gen){genero=genero;};

    void set_es_pelicula(bool x) { es_pelicula = x;};
    bool get_es_pelicula() { return es_pelicula;};

    void set_rating(double);
    double get_rating() {return rating;};

    void set_id(int id) { this->id = id;};
    int get_id() { return id; };

    void set_duracion(int duracion) { this->duracion = duracion;};
    int get_duracion() { return this->duracion;};

    virtual void imprimir();
protected:
    double rating;
    string nombre, resumen;
    GENERO genero;
    int id, duracion;
    bool es_pelicula;
    const int MAX_RATING = 5;
};

Video::Video() {
    rating = 0.0;
    nombre = "NA";
    resumen =" NA";
    genero = GENERO::DEFAULT;
    id = 0;
    es_pelicula = false;
    duracion = 0;
}
Video::Video(string nombre, string resumen, int id, int duracion, double rating, GENERO genero, bool peli) {
    this->nombre = nombre;
    this->resumen = resumen;
    this->id = id;
    this->duracion = duracion;
    this->rating = rating;
    this->genero = genero; 
    this->es_pelicula = peli;
}

void Video::set_rating(double rating) {
    if (rating >  MAX_RATING) {
        rating = MAX_RATING;
    } 
    else if (rating < 0) {
        rating = 0;
    }
    this->rating = rating;
}

void Video::imprimir() {
    cout << "-- " << nombre << " --" << endl;
    cout << "Rating: " << rating << "/" << MAX_RATING << endl;
    cout << "Duración: " << duracion  << " minutos" << endl;
    cout << "Resumen: " << resumen << endl;
    cout << "Genero: " << GENERO_STRING[genero] << endl;
    cout << "\n";
}