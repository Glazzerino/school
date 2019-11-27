#pragma once
class Tiempo {
    public:
        Tiempo();
        Tiempo(int h, int m);
        int getHora();
        int getMin();
        void setHora(int h);
        void setMin(int m);
        Tiempo getTiempoFinal(int duracion);
    private:
        int hora;
        int minuto;
};

Tiempo::Tiempo(int h, int m) : hora(h), minuto(m){};

Tiempo::Tiempo() {
    hora = 0;
    minuto = 0;
}

int Tiempo::getHora() {
    return this->hora;  
}
//Crea una nueva instancia de Tiempo con la suma de duracion dada a la funcion
Tiempo Tiempo::getTiempoFinal(int duracion) {
    int newH = duracion / 60;
    int newM = duracion % 60;
    return Tiempo(newH, newM);
}

void Tiempo::setHora(int h) {
    this ->hora = h;
}

int Tiempo::getMin() {
    return this->minuto;
}

void Tiempo::setMin(int m) {
    this->minuto = m;
}