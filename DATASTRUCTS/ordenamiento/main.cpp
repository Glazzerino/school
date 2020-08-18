#include <iostream>
#include <vector>
// HACER MENU
// CONTAR CUANTAS COMPARACIONES SE HACEN
// CONTAR INTERCAMBIOS
// EVALUAR TIEMPO DE EJECUCION
using namespace std;

template<class T>
inline void swap(vector<T>& lista, int a, int b) {
    int aux = lista[b];
    lista[b] = lista[a];
    lista[a] = aux;
}

// O(n2)
template<class T>
void intercambio(vector<T>& lista) {
    for (int i=0; i<lista.size(); i++) {
        cout << "Current num: " << lista[i] << endl;
        for (int x=i+1; x<lista.size(); x++) {
            if (lista[x] > lista[i]) {
                swap(lista,x,i);
            }
        }
    }
}

template<class T>
void bubble(vector<T>& lista) {
    for (int i=0; i< lista.size()-1; i++) {
        for (int x=0; x<lista.size()-i-1; x++) {

        }
    }
}

int main() {
    vector<int> lista = {4,5, 2, 3, 1,8};
    intercambio<int>(lista);
    for (int x : lista) {
        cout << x << " ";
    }
    cout << endl;
}