<<<<<<< HEAD
#include "CtaComision.h"
int main() {
    char tipo;
    int cant;
    int id;
    double saldo,com, dinero;
    char opc;
    CtaBanc *arr[100];
    cin >> cant;
    for (int i=0;i<cant;i++) {
        cin >> tipo;
        cin >> id;
        cin >> saldo;
        if (tipo == 'b') {
            arr[i] = new CtaBanc(id, saldo);
        } else if (tipo == 'c') {
            cin >> com;
            arr[i] = new CtaComision(id, saldo, com);
        }
    }
    do {
        cout << "a) deposita" << endl;
        cin >> opc;
        switch(opc) {
            case 'a': // depositar
                cout << "ingrese id" << endl;
                cin >> id;
                cout << "ingrese cantidad" << endl;
                cin >> dinero;
                for (int i=0;i<cant; i++) {
                    if (arr[i]->getNumCuenta() == id) {
                        arr[i]->deposita(dinero);
                        // cout <<  arr[i]->getSaldo() << endl;
                    }
                }
                break;                

            case 'b':
                cout << "ingrese id" << endl;
                cin >> id;
                cout << "ingrese cantidad" << endl;
                cin >> dinero;
                for (int i=0;i<cant; i++) {
                    if (arr[i]->getNumCuenta() == id && !arr[i]-> retira(dinero)) {
                        cout << "No se pudo realizar el retiro "<< endl;
                    }
                }
                break;
            
            case 'c':
                cout << "ingrese id" << endl;
                cin >> id;
                for (int i=0;i<cant; i++) {
                    arr[i]->getNumCuenta() == id ? arr[i]->mostrar();
                }
                break;
        }
    } while(opc != 'd');        
}
=======
#include "CtaComision.h"
int main() {
    char tipo;
    int cant;
    int id;
    double saldo,com, dinero;
    char opc;
    CtaBanc *arr[100];
    cin >> cant;
    for (int i=0;i<cant;i++) {
        cin >> tipo;
        cin >> id;
        cin >> saldo;
        if (tipo == 'b') {
            arr[i] = new CtaBanc(id, saldo);
        } else if (tipo == 'c') {
            cin >> com;
            arr[i] = new CtaComision(id, saldo, com);
        }
    }
    do {
        cin >> opc;
        switch(opc) {
            case 'a': // depositar
                // cout << "ingrese id" << endl;
                cin >> id;
                // cout << "ingrese cantidad" << endl;
                cin >> dinero;
                for (int i=0;i<cant; i++) {
                    if (arr[i]->getNumCuenta() == id) {
                        arr[i]->deposita(dinero);
                        // cout <<  arr[i]->getSaldo() << endl;
                    }
                }
                break;                

            case 'b':
                // cout << "ingrese id" << endl;
                cin >> id;
                // cout << "ingrese cantidad" << endl;
                cin >> dinero;
                for (int i=0;i<cant; i++) {
                    if (arr[i]->getNumCuenta() == id && !arr[i]->retira(dinero)) {
                        cout << "No se pudo realizar el retiro "<< endl;
                    }
                }
                break;
            
            case 'c':
                // cout << "ingrese id" << endl;
                cin >> id;
                for (int i=0;i<cant; i++) {
                    if (arr[i]->getNumCuenta() == id) {
                        arr[i]->mostrar();
                    }
                }
                break;
        }
    } while(opc != 'd');        
}
>>>>>>> 1a8e5a2615ebdec21556b8944ff9170e4718391a
