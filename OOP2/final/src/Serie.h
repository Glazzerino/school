#pragma once
#include "Episodio.h"
#include "Contenedor.h"

class Serie : public Contenedor {
public:
    Serie();
    Serie(string nombre, string resumen, int num_episodios,int num_temporadas, double rating);

    string& get_ref_nombre() { return nombre; };
    string& get_ref_resumen() {return resumen;};
    int& get_ref_num_temporadas() {return num_temporadas;};
    double& get_ref_rating() {return rating;};
    int& get_ref_num_episodios(){return num_episodios;};
    virtual void imprimir(); // se usa "virtual" para señalar que se sobreescribe método padre
private:
    string nombre, resumen;
    int num_episodios, num_temporadas;
    double rating;
};

Serie::Serie(): Contenedor("serie","NA", false) {
    
    this->resumen = "NA";
    this->num_episodios = 0;
    this->num_temporadas = 0;
    this->rating = 0;
}

Serie::Serie(string nombre, string resumen, int num_episodios,int num_temporadas, double rating) : Contenedor("serie",nombre,false) {
    this->resumen = resumen;
    this->num_episodios = num_episodios;
    this->num_temporadas = num_temporadas;
    this->rating = rating;
}

void Serie::imprimir() {
    cout << "Serie: " << Contenedor::nombre << endl;
    cout << "      " << rating << endl;
    cout << "_____________" << endl;
    cout << resumen<< endl;
    cout << "Eps: " << num_episodios << endl;
    cout << "Temps:" << num_temporadas << endl;
}