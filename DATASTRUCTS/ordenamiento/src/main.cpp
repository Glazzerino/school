#include <iostream>
#include <vector>
#include <chrono>
// HACER MENU
// CONTAR CUANTAS COMPARACIONES SE HACEN
// CONTAR INTERCAMBIOS
// EVALUAR TIEMPO DE EJECUCION
using namespace std;


class Timer {
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    };
    
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        auto timestep = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        cout << "Execution time: " << timestep << " nanoseconds" << endl;
    };
private:
    std::chrono::high_resolution_clock::time_point start,end;
};

template<class T>
inline void swap(vector<T>& lista, int a, int b) {
    int aux = lista[b];
    lista[b] = lista[a];
    lista[a] = aux;
}

// O(n2)
template<class T>
void intercambio(vector<T>& lista, int& iter, int& comps) {
    Timer time;
    for (int i=0; i<lista.size(); i++) {
        iter++;
        comps++;
        cout << "Current num: " << lista[i] << endl;
        for (int x=i+1; x<lista.size(); x++) {
            iter++;
            comps++;
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
    int iteraciones = 0;
    int comparaciones = 0;
    vector<int> lista = {4,6489, 1000, 100, 9,8};
    intercambio<int>(lista, iteraciones, comparaciones);
    for (int x : lista) {
        cout << x << " ";
    }
    cout << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
}