#include<iostream>
#include<string>
#include"Vuelo.h"
using namespace std;

void cargaDatosPasajeros(Vuelo vuelos[], int numDeVuelos) {
    int numDePasajeros;
    ifstream data;
    data.open("data.txt");
    for (int i=0;i<numDeVuelos;i++) {
        string salida, destino, nombre;
        int id;
        int counter = 0;
        Pasajero pasajeroTemp;
        while(data >> nombre >> salida>>destino>>id) {
            pasajeroTemp.setDestino(destino);
            pasajeroTemp.setNombre(nombre);
            pasajeroTemp.setId(id);
            pasajeroTemp.setSalida(salida);
            vuelos[i].addPasajero(pasajeroTemp,counter);
            counter++;
        }
        vuelos[i].setNumDePasajeros(counter);
    }
}

void muestraVuelos(Vuelo vuelos[], int numDeVuelos) {
    for (int i=0;i<numDeVuelos;i++) {
        cout << "Destino: " << vuelos[i].getDestino() << " ";
        cout << "Salida: " << vuelos[i].getSalida() << " ";
        cout << "Id :" << vuelos[i].getId() << " ";
        cout << "Tiempo de salida: "<< vuelos[i].getTiempoSalida().getHora() << ":";
        cout << vuelos[i].getTiempoSalida().getMin() << " ";
        cout << "Numero de pasajeros: " << vuelos[i].getNumDePasajeros() << endl;
    }
}
int getNumDeVuelos() {
    ifstream file;
    file.open("vuelos.txt");
    string line;
    int numOfVuelos;
    while(getline(file,line)) {
        numOfVuelos++;
    }
    return numOfVuelos;
}
void cargaDatosVuelos(Vuelo vuelos[], int &numDeVuelos) {
   
   ifstream archivo;
   string salida;
   string destino;
   int hora, minuto;
   int duracion;
   int id;
   archivo.open("vuelos.txt");
   int i=0;
    while (archivo>>salida>>destino>>duracion>> id >> hora >> minuto) {
        vuelos[i].setDuracion(duracion);
        vuelos[i].setDestino(destino);
        vuelos[i].setId(id);
        vuelos[i].setSalida(salida);
        vuelos[i].setTiempo(hora,minuto);
        i++;
    }
    numDeVuelos = i;
    cout << "Datos de vuelos cargados" << endl;
    archivo.close();
}

int main() {
    cout << "program start" << endl;
    int numDeVuelos;
    Vuelo vuelos[30];
    cargaDatosVuelos(vuelos, numDeVuelos);

    return 0;
}