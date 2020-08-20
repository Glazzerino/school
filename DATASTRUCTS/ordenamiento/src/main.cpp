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

//Funcion amiga
//Directa
template<class T>
inline T min(T a, T b) {
    return a < b ? a : b;
}

//Funcion amiga
//O*N
template<class T>
inline vector<T> mergeVectors(vector<T> first, vector<T> second) {
    size_t final_size = first.size() + second.size();
    vector<T> final;
    final.reserve(final_size);
    for (int i=0; i<final_size; i++) {
        if (second.size() == 0) {
            for (int j=first.size()-1; j>=0; j--) {
                final.push_back(first[j]);
            }
            break;
        }
        else if (first.size() == 0) {
            for (int j=second.size()-1; j>=0; j--) {
                final.push_back(second[j]);
            }
            break;
        }

        if (first.back() < second.back()) {
            final.push_back(first.back());
            first.pop_back();
        } else {
            final.push_back(second.back());
            second.pop_back();
        }

    }
    return final;
}

//Funcion amiga
// O*N
template<class T>
inline std::pair<vector<T>, vector<T>> splitVector(vector<T> list) {
    vector<T> first;
    vector<T> second;
    int mid = (list.size() / 2) + (list.size() % 2);
    for (int i=0; i < mid; i++) {
        first.push_back(list[i]);
    }

    for (int i=mid; i<list.size(); i++) {
        second.push_back(list[i]);
    }
    return std::pair<vector<T>, vector<T>> {first, second};
}

template<class T>
void mergesort(vector<T> list) {
    // int l = 0;
    // int m =  (list.size() / 2) + (list.size() % 2) - 1;
    // int r = m + 1;
    bool phase1done = false;
    vector<vector<T>> metalist;
    for (int i=0; i < list.size(); i+=2) {
        vector<T> cell;
        if (list.size() % 2 != 0 && i == list.size()-1 ) {
            cell.push_back(list[i]);
            // cout << "cunt";
        } else {
            cell.push_back(list[i]);
            cell.push_back(list[i+1]);
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
    vector<int> lista = {5,4,3,2,1};
    // bubble<int>(lista, iteraciones, comparaciones);
    // for (int x : lista) {
    //     cout << x << " ";
    // }
    // cout <<endl << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
    vector<int> test1 = {5,4};
    vector<int> test2 = {3};
    auto couple = splitVector(lista);
    vector<int> merged = mergeVectors<int>(couple.second, couple.first);
    for (int x : merged) {
        cout << x << " ";
    }
    cout << endl;
    // mergesort<int>(lista);
}