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
void selectionSort(vector<T>& list) {
    Timer timer;
    for (int i=0; i<list.size()-1; i++) {
        int min = list[i];
        for (int j=i; j<list.size(); j++) {
            if (list[j] < min) {
                min = list[j];
            }
            if (j == list.size()-1) {
                swap(list[j], list[i]);
            }
        }
    }
}



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

//Funcion amiga
//O*N
template<class T>
inline vector<T> mergeVectors(vector<T> first, vector<T> second) {
    vector<T> final = first;
    final.push_back(second);
    return final;
}

//Funcion amiga
// O*N
template<class T>
inline std::pair<vector<T>, vector<T>>splitVector(vector<T> list) {
    vector<T> right;
    vector<T> left;
    int mid = (list.size() / 2) + (list.size() % 2);
    for (int i=0; i < mid; i++) {
        right.push_back(list[i]);
    }

    for (int i=mid; i<list.size(); i++) {
        left.push_back(list[i]);
    }
    return std::pair<vector<T>, vector<T>> {left, right};
}

template<class T>
void mergesort(vector<T> list) {
    int l = 0;
    int m =  (list.size() / 2) + (list.size() % 2) - 1;
    int r = m + 1;
    // cout << l << " " << m << " " << r << endl;
    bool phase1done = false;
    vector<vector<T>> metalist;
    for (int i=0; i < list.size(); i+=2) {
        vector<T> cell;
        if (list.size() % 2 != 0 && i == list.size()-3 ) {
            cell.push_back(list[i]);
            cout << "cunt";
        } else {
            cell.push_back(list[i]);
            cell.pop_back(list[i+1]);
        }
        metalist.push_back(cell);
    }

    for (vector<T> x: metalist) {
        for (T y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    int iteraciones = 0;
    int comparaciones = 0;
    vector<int> lista = {8,7,6,5,4};
    // bubble<int>(lista, iteraciones, comparaciones);

    selectionSort(lista);
    for (int x : lista) {
        cout << x << " ";
    }
    // cout <<endl << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;

    // mergesort<int>(lista);
    
}