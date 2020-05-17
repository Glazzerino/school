// Escribe aquí la clase Vendedor

// usa estos cout para mostrar los datos de un vendedor
//    cout << "Id de empleado " << ident;
//    cout << " sueldo $" << sueldo;
//    cout << " %comision " << porcentajeComision;
//    cout << " ventas " << ventas << endl;
#include <iostream>
#include "Empleado.h"
#pragma once
using namespace std;
class Vendedor: public Empleado {
    public:
        Vendedor();
        Vendedor(int id, double sueldo, double porcentaje, int ventas);
        double getPorcentaje() {return porcentaje;};
        void setPorcentaje(double n) {porcentaje = n;};
        int getVentas() {return ventas;};
        void setVentas(int n) {ventas = n;};
        double calculaPago();  
        void muestra();
    private:
        double porcentaje;
        int ventas;
};
    
    Vendedor::Vendedor() : Empleado(),porcentaje(0),ventas(0) {}
    
    Vendedor::Vendedor(int id, double sueldo, double porcentaje, int ventas) : Empleado::Empleado(id,sueldo) {
        this->porcentaje = porcentaje;
        this->ventas = ventas;
    }
    
    void Vendedor::muestra() {
        cout << "Id de empleado " << Empleado::ident;
        cout << " sueldo $" << Empleado::sueldo;
        cout << " %comision " << this->porcentaje;
        cout << " ventas " << this->ventas << endl;
    }
    
    double Vendedor::calculaPago() {
        double pago = Empleado::sueldo + (this->porcentaje * this->ventas);
        return pago;
    }