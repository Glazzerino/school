#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Pasajero.h"
#include "Tiempo.h"
using namespace std;
class Vuelo {
    private:
        string salida;
        string destino;
        Tiempo tiempo;
        Pasajero pasajeros[10];
        int duracion;
    public:
        Vuelo();
        Vuelo(string salida, string destino);
        void setSalida(string salida);
        string getsalida();
        void setDestino(string destino);
        string getDestino();
        void setTiempo();
        Tiempo getTiempo();
        void setDuracion(int duracion);
};