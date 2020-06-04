#pragma once
#include "Genero.inc"
#include <iostream>
using namespace std;
class Video {
public:
    Video();
    Video(std::string, std::string ,std::string, int, int, double, GENERO);

    std::string get_nombre() { return nombre; };
    void set_nombre(std::string nombre){this->nombre = nombre;};

    std::string get_estudio() { return estudio; };
    void set_estudio(std::string estudio){this->estudio = estudio;};

    std::string get_resumen() { return resumen; };
    void set_resumen(std::string resumen){resumen = resumen;};

    GENERO get_genero() { return genero; };
    void set_genero(GENERO gen){genero=genero;};
    
    void set_rating(double);
    double get_rating() {return rating;};

    void set_id(int id) { this->id = id;};
    int get_id() { return id; };

    void set_duracion(int duracion) { this->duracion = duracion;};
    int get_duracion() { return this->duracion;};

    virtual void imprimir();
protected:
    double rating;
    std::string nombre, resumen, estudio;
    GENERO genero;
    int id, duracion;

    const int MAX_RATING = 5;
};

Video::Video() {
    rating = 0.0;
    nombre = "NA";
    resumen =" NA";
    estudio = "NA";
    genero = GENERO::DEFAULT;
    id = 0;
    duracion = 0;
}
Video::Video(std::string nombre, std::string resumen,std::string estudio, int id, int duracion, double rating, GENERO genero) {
    this->nombre = nombre;
    this->resumen = resumen;
    this->estudio = estudio;
    this->id = id;
    this->duracion = duracion;
    this->rating = rating;
    this->genero = genero; 
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
    std::cout << "-- " << nombre << " --\n";
    std::cout << "Rating: " << rating << "/" << MAX_RATING << "\n"; 
    std::cout << "Estudio: " << estudio << "\n";
    std::cout << "Duración: " << duracion << "\n";
    std::cout << GENERO_STRING[genero] << "\n";
}