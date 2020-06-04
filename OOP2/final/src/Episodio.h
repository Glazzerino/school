#pragma once
#include "Video.h"

class Episodio : public Video {
public:
    Episodio();
    Episodio(string, string ,string, int, int, double, GENERO, bool, string,int,int);

    void set_temporada(int temporada){this->temporada=temporada;};
    int get_temporada(){return this->temporada;};

    void set_serie(string serie){this->serie=serie;};
    string get_serie(){return serie;};

    bool get_emision(){return emision;};
    void imprimir();
private:
    int temporada;
    int num;
    bool emision;
    string serie;
};

Episodio::Episodio() : Video(){}

Episodio::Episodio(string nombre, string resumen,string estudio, int id, int duracion, double rating, 
GENERO genero,bool emision, string serie, int temporada, int num) : Video( nombre,  resumen, estudio,  id,  duracion,  rating, 
 genero) {
    this->temporada = temporada;
    this->num = num;
    this->serie = serie;
 }

 void Episodio::imprimir() {
     Video::imprimir();
     cout << "E:" << num << "S:"<< temporada << endl;
 }


