#pragma once
#include "Video.h"

class Episodio : public Video {
public:
    Episodio();
    Episodio(string, string , int, int, double, GENERO, string,int,int,bool espeli);

    void set_temporada(int temporada){this->temporada=temporada;};
    int get_temporada(){return this->temporada;};

    void set_serie(string serie){this->serie=serie;};
    string get_serie(){return serie;};


    void imprimir();
private:
    int temporada;
    int num;
    string serie;
};

Episodio::Episodio() : Video(){}

Episodio::Episodio(string nombre, string resumen, int id, int duracion, double rating, 
GENERO genero, string serie, int temporada, int num,bool espeli) : Video( nombre,  resumen,  id,  duracion,  rating, 
 genero,espeli) {
    this->temporada = temporada;
    this->num = num;
    this->serie = serie;
 }

 void Episodio::imprimir() {
     Video::imprimir();
     cout << "E:" << num << "S:"<< temporada << endl;
 }


