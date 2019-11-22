#pragma once
#include <string>
#include <iostream>
using namespace std;
class SalaCine {
    public:
        SalaCine();
        SalaCine(int tics, string title);
        void setTitle(string input);
        void setTickets(int input);
        bool reserve(int input);
        string getTitle();
        int getTickets();
        void muestra();
    private:
        string title;
        int tickets;
};
/*Escribe la clase SalaCine que tenga lo siguiente:
* atributos para:
   - título de la película
   - cantidad de boletos disponibles
* constructor default
* métodos de acceso y modificación para cada uno de los atributos
* el método muestra que debe mostrar en la pantalla un mensaje como este:   
   "Película Guasón boletos disponibles 22"  <- Usando los datos del objeto
* el método reserva que recibe como parámetro cuántos boletos solicitó el estudiante y que regrese como valor de retorno true si se le puede entregar dicha cantidad de boletos y false en caso contrario (se debe revisar la cantidad de boletos disponibles de la sala y si hay suficientes, modificarla).
*/
//Default
SalaCine::SalaCine() : tickets(22), title(""){}
//Con 
SalaCine::SalaCine(int tics, string movie) : tickets(tics), title(movie) {}

void SalaCine::setTitle(string input) {
    this->title = input;
}

void SalaCine::setTickets(int input) {
    this->tickets = input;
}

string SalaCine::getTitle() {
    return this->title;
}

int SalaCine::getTickets() {
    return this->tickets;
}

bool SalaCine::reserve(int input) {
    if (this->tickets >= input) {
        this->tickets -= input;
        return true;
    } else {
        return false;
    }
}

void SalaCine::muestra() {
    cout << "Película " << this->title << " boletos disponibles " << this->tickets << endl;
}
