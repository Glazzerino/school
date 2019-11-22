#pragma once
#include <iostream>
using namespace std;

class Tiempo {
    public:
        Tiempo();
        Tiempo(int h, int m);
        int getMinu();
        int getHora();
        void setMinu(int inp);
        void setHora(int hor);
        int diferencia(Tiempo final);
    private:
        int horas, minutos;
};
Tiempo::Tiempo() : horas(0), minutos(0) {}
Tiempo::Tiempo(int h, int m) : horas(h), minutos(m) {}
int Tiempo::getMinu() {
    return this->minutos;
}
int Tiempo::getHora() {
    return this->horas;
}
void Tiempo::setMinu(int inp) {
    this->minutos = inp;
}
void Tiempo::setHora(int h) {
    this->horas = h;
}
int Tiempo::diferencia(Tiempo final) {
    int totalFinal = final.getMinu() + (final.getHora() * 60);
    int inicio = this->getMinu() + (this->getHora() * 60);
    int duracion = totalFinal - inicio;
    return duracion;
}


// Nombre de la clase: Tiempo
// parte pública
     // constructor default que inicialice la hora con 0 horas y 0 minutos
     // constructor con parámetros que recibe hora y minutos (en ese orden)
     // métodos de acceso y de modificación para los 2 atributos
     // método duracion, que recibe como parámetro un objeto de tipo tiempo y regresa un entero
     // calcula la duración de un evento que tiene como hora de inicio la del objeto actual
     // y como hora de terminación la del objeto que se recibe como parámetro
     // sugerencia, para calcular la diferencia convierte ambos tiempos a minutos 
// parte privada
    // atributos hora, minu

// implementa los métodos

