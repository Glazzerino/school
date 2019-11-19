#include "CtaBanc.h"
#include <iostream>
using namespace std;
int main() {
    CtaBanc cuenta;
    cuenta.muestra();
    cout << " Opctiones: \n";
    char input = '\n';
    while (input != 'd') {
        cout << "a) depositar b) retirar c) consultar d) terminar" << endl;
        cin >> input; 
        switch (input) {
            case 'a':
                cout << "Cantidad? " << endl;
                double cantidad;
                cin >> cantidad;
                cuenta.deposita(cantidad);
                    break;
            case 'b':
                cout << "Cantidad a retirar? " << endl;
                double retiro;
                cin >> retiro;
                if (cuenta.retira(retiro)) {
                    cout << "Movimiento exitoso" << endl;
                } else {
                    cout << "Fondos insuficientes" << endl;
                }
                    break;
            case 'c':
                cout << "Saldo actual: $"<< cuenta.getSaldo() << endl;
                    break;
                }
            }
    return 0;
}