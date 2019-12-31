#pragma once
using namespace std;
#include <fstream>
#include <string>
#include <iostream>
#include "Pasajero.h"
#include "Tiempo.h"

class Vuelo {
    private:
        string salida;
        string destino;
        Tiempo tiempo;
        Pasajero pasajeros[40];
        int duracion;
        int id;
        int numDePasajeros;
    public:
        Vuelo();
        Vuelo(string des, string sal, int dura, Tiempo tiem, int numPersonas);
        void setSalida(string salida);
        string getSalida();
        void setDestino(string destino);
        string getDestino();
        void setTiempo(int h, int m);
        Tiempo getTiempoSalida();
        void setTiempoSalida(Tiempo input);
        void setDuracion(int duracion);
        int getDuracion();
        void setId(int input);
        int getId();
        void setNumDePasajeros(int num);
        int getNumDePasajeros();
        void addPasajero(Pasajero usuario);
        Pasajero getPasajero(int index);
};

Vuelo::Vuelo() {
    this->destino = "MTY";
    this->salida = "CDM";
    this->duracion = 120;
    this->tiempo = Tiempo(0,0);
    this->numDePasajeros = 0;
}

int Vuelo::getId() {
    return this->id;
}
Pasajero Vuelo::getPasajero(int index) {
    return this->pasajeros[index];
}

int Vuelo::getNumDePasajeros() {
    return this->numDePasajeros;
}

void Vuelo::addPasajero(Pasajero usuario) {
    this->numDePasajeros++;
    this->pasajeros[numDePasajeros - 1] = usuario;
}

void Vuelo::setNumDePasajeros(int n) {
    this->numDePasajeros = n;
}

Vuelo::Vuelo(string des, string sal, int dura, Tiempo tiem,int numPersonas) : 
destino(des), salida(sal), duracion(dura), tiempo(tiem), numDePasajeros(numPersonas) {
}

string Vuelo::getDestino() {
    return this->destino;
}

void Vuelo::setDestino(string input) {
    this->destino = input;
} 

void Vuelo::setSalida(string input) {
    this->salida = input;
}

string Vuelo::getSalida() {
    return this->salida;
}

void Vuelo::setDuracion(int input) {
    this->duracion = input;
}

int Vuelo::getDuracion() {
    return this->duracion;
}
Tiempo Vuelo::getTiempoSalida() {
    return this->tiempo;
}
void Vuelo::setTiempoSalida(Tiempo input) {
    this->tiempo = input;
}

void Vuelo::setTiempo(int h,int m) {
    this->tiempo.setHora(h);
    this->tiempo.setMin(m);
}

void Vuelo::setId(int input) {
    this->id = input;
}