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
int swaps = 0;
template<class T>
inline void swap(T* a,T* b) {
    T aux = b;
    b = a;
    a = aux;
}

// O(n2)
template<class T>
void intercambio(vector<T>& lista, int& iter, int& comps) {
    Timer time;
    for (int i=0; i<lista.size(); i++) {
        iter++;
        comps++;
        // cout << "Current num: " << lista[i] << endl;
        for (int x=i+1; x<lista.size(); x++) {
            iter++;
            comps++;
            if (lista[x] > lista[i]) {
                comps++;
                swap(lista[x],lista[i]);
            }
        }
    }
}

//(O*N^2)
template<class T>
void bubble(vector<T>& lista, int& iter, int& comps) {
    bool swapped = true;
    Timer timer;
    for (int i=0; i < lista.size()-1; i++) {
        iter++;
        for (int x=0; x < lista.size()-i-1; x++) {
            swapped=false;
            iter++;
            if (lista[x+1]< lista[x]) {
                swapped = true;
                comps++;
                swap(lista[x+1], lista[x]);
            }
        }
        if (!swapped) {
            break;
        }
    }
}


int main() {
    int iteraciones = 0;
    int comparaciones = 0;
    vector<int> lista = {8,7,6,5,4,3,2,};
    bubble<int>(lista, iteraciones, comparaciones);
    for (int x : lista) {
        cout << x << " ";
    }
    // mergeSort(lista);
    cout <<endl << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
}