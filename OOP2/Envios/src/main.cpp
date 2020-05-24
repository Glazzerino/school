#include "Paquete.h"
#include <fstream>

int main() {
    Envio *envios[20];
    ifstream file("../src/data.txt");
    char type;
    int counter = 0;
    double peso, largo, ancho, 
    costo_kg,costo, cargo_adicional;
    string nombre_r, estado_d, ciudad_d,ciudad_r,estado_r, cp_r, cp_d, nombre_d;
    while(file >> type >> nombre_r >> estado_r >> ciudad_r >> cp_r >> nombre_d >> estado_d >> ciudad_d >> cp_d >> costo) {
        Persona rem(nombre_r,estado_r,ciudad_r,cp_r);
        Persona des(nombre_d,estado_d,ciudad_d,cp_d);

        if (type == 'p') {
            file >> peso >> costo_kg;
            envios[counter++] = new Paquete(rem,des,costo,peso, costo_kg);
        }
        else if (type == 's') {
            file >> largo >> ancho >> cargo_adicional;
        }
    }
    cout << "lol"<< endl;
}