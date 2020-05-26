#include "Paquete.h"
#include "Sobre.h"
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    Envio *envios[100];
    ifstream file("datosEnvios.txt");
    char type;
    int counter = 0;
    double total_envios = 0;
    double peso, largo, ancho,
           costo_kg,costo, cargo_adicional;
    string nombre_r, estado_d, ciudad_d,ciudad_r,estado_r, cp_r, cp_d, nombre_d;
    while(file >> type >> nombre_r >> estado_r >> ciudad_r >> cp_r >> nombre_d >> estado_d >> ciudad_d >> cp_d >> costo) {
        Persona rem(nombre_r,estado_r,ciudad_r,cp_r);
        Persona des(nombre_d,estado_d,ciudad_d,cp_d);
        // cout << type << endl;
        if (type == 'p') {
            file >> peso >> costo_kg;
            // std::cout << peso << " " << costo_kg << endl;
            envios[counter++] = new Paquete(rem,des,costo,peso, costo_kg);
        }
        else {
            file >> largo >> ancho >> cargo_adicional;
            //  cout << largo << ancho << cargo_adicional << endl;
            envios[counter++] = new Sobre(rem,des,costo,largo, ancho, cargo_adicional);
        }
    }
    for (int i=0; i<counter; i++) {
        cout << "Remitente:" << endl;
        envios[i]->getRemitente().Imprimir();
        cout << "Destinatario:" << endl;
        envios[i]->getDestinatario().Imprimir();
        cout << "Costo: " << envios[i]->calculaCosto() << endl;
        total_envios += envios[i]->calculaCosto();
    }
    cout << "Total envios: " << total_envios << endl;
}