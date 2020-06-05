#pragma once
#include "Episodio.h"
#include "Contenedor.h"

class Serie : public Contenedor {
public:
    Serie();
    Serie(string nombre, string resumen, int num_episodios,int num_temporadas, double rating,GENERO genero);

    string& get_ref_nombre() { return nombre; };
    string& get_ref_resumen() {return resumen;};
    int& get_ref_num_temporadas() {return num_temporadas;};
    double& get_ref_rating() {return rating;};
    GENERO get_genero() {return genero;};
    int& get_ref_num_episodios(){return num_episodios;};
    virtual void imprimir(); // se usa "virtual" para señalar que se sobreescribe método padre
private:
    string nombre, resumen;
    int num_episodios, num_temporadas;
    double rating;
    GENERO genero;
};

Serie::Serie(): Contenedor("NA", false) {
    this->genero = GENERO::DEFAULT;
    this->resumen = "NA";
    this->num_episodios = 0;
    this->num_temporadas = 0;
    this->rating = 0;
}

Serie::Serie(string nombre, string resumen, int num_episodios,int num_temporadas, double rating,GENERO genero) : Contenedor(nombre,false) {
    this->resumen = resumen;
    this->genero = genero;
    this->num_episodios = num_episodios;
    this->num_temporadas = num_temporadas;
    this->rating = rating;
}

void Serie::imprimir() {
    cout << "Serie: " << Contenedor::nombre << endl;
    cout << "Rating: " << rating << endl;
    cout << resumen<< endl;
    cout << "Eps: " << num_episodios << endl;
    cout << "Temps:" << num_temporadas << endl;
    cout << "_____________" << endl;
}