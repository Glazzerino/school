#include <vector>
#include <iomanip>
#include <ctime>
#include <math.h>
// #include <type_traits>
#include <stack>
#include "Timer.h"
#include <tuple>

// HACER MENU
// CONTAR CUANTAS COMPARACIONES SE HACEN
// CONTAR INTERCAMBIOS
// EVALUAR TIEMPO DE EJECUCION
using namespace std;

template<class T>
int partition(vector<T>& list, int start, int end, int& iters, int& comps) {
    int pivot = list[end];

    int pindex = start;

    for (int i = start; i < end; i++) {
        iters++;
        if (list[i] <= pivot) {
            comps++;
            swap(list[i], list[pindex]);
            pindex++;
        }
    }
    swap(list[pindex], list[end]);
    return pindex;
}

template<class T>
void quicksort(vector<T>& list, int &iters, int &comps) {
    Timer timer;
    stack<pair<T, T>> pairs;
    int end = list.size()-1;
    int start = 0;
    pairs.push(pair<T, T> {start, end});

    while(!pairs.empty()) {
        iters++;
        start = pairs.top().first;
        end = pairs.top().second;
        pairs.pop();
        int pivot = partition(list,start, end, iters, comps);
        if (pivot - 1 > start) {
            comps++;
            pairs.push(pair<T, T> {start, pivot - 1});
        }
        if (pivot +1 < end) {
            comps++;
            pairs.push(pair<T, T> {pivot+1, end});
        }
    }
    // return list;
}

void disp_vector(vector<int> list) {
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;
}




template<class T>
vector<T> randomVector(int n) {
    std::srand(time(nullptr));
    cout << "Numero de elementos: " << n << endl;
    vector<T> rand_vector;
    rand_vector.reserve(n);
    int i;
    T temp;
    // bool is_float = ;
    cout << std::is_floating_point<T>::value << endl;
    for (i=0; i<n; i++) {
        // temp = (T) (rand()) / (T) (RAND_MAX);
        if (is_floating_point<T>::value) {
            temp = ((T) ( rand() % 100) / (rand() % 100));
        }
        else {
            temp = rand() % 100;
        }
        rand_vector.push_back(temp);
    }
    return rand_vector;
}

//BUSQUEDA
template<class T>
size_t sequential(vector<T>& list, T query) {
    size_t x;
    for (x = 0; x < list.size(); x++) {
        if (list[x] == query) {
            return x;
        }
    }
    return -1;
}


//FINAL BUSQUEDA


int swaps = 0;
template<class T>
inline void swap(T* a,T* b) {
    T aux = b;
    b = a;
    a = aux;
}

template<class T>
void insertionSort(vector<T>& list, int& iter, int& comps) {
    Timer timer;
    int i;
    int x;
    T aux;
    bool swapped;
    for (x = 1; x < list.size(); x++) {
        iter++;
        swapped = false;
        if (list[x] < list[x-1]) {
            comps++;
            // swapped = true;
            for (i=0; i<x; i++) {
                iter++;
                if (list[i] > list[x]) {
                    comps++;
                    // aux = list[x];
                    list.emplace(list.begin()+i,list[x]);
                    list.erase(list.begin() + x+1);
                    break;
                }
            }
        }
    }
}


// O(n2)
template<class T>
void selectionSort(vector<T>& list, int& iters, int &comps) {
    Timer timer;
    int min;
    for (int i=0; i<list.size(); i++) {
        iters++;
        min = i;
        for (int j=i; j<list.size(); j++) {
            iters++;
            if (list[j] < list[min]) {
                comps++;
                min = j;
            }
        }
        swap(list[min], list[i]);
    }
}

// O(n2)
template<class T>
void intercambio(vector<T>& lista, int& iter, int& comps) {
    Timer time;
    for (int i=0; i<lista.size(); i++) {
        iter++;
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
    bool swapped = false;
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

inline std::tuple<char, int, char> configPromptSort() {
    int n;
    char t, alg;
    do {
        cout << "Seleccione el tipo y el numero de elementos de la lista (tipo <espacio> numero): \n";
        cout << "f: Flotante    |   i: Entero\n";
        cout << "Entrada: \n";
        cin >> t >> n;

        cout << "Seleccione el algoritmo a utilizar: \n";
        cout << "a) Ordenamiento de intercambio\n";
        cout << "b) Ordenamiento de burbuja\n";
        cout << "c) Ordenamiento de insercion\n";
        cout << "d) Ordenamiento de seleccion\n";
        cout << "e) Quicksort\n";
        cout << "Entrada: ";
        cin >> alg;

        if ((t == 'f' || t == 'i') && (n > 0)) {
            return std::tuple<char,int,char>(t,n,alg);
        } else {
            cout << "Entrada inválida, revisa que tu tipo sea \"f\" o \"i\" y que tu numero sea mayor a 0\n";
        }
    } while (true);
}

template<class T>
inline void displayVector(vector<T>& list) {
    cout << "[";
    for (T x : list) {
        cout << x << " ";
    }
    cout << "]" << "\n";
}

int main() {
        
    int iteraciones = 0;
    int comparaciones = 0;
    char option;
    int n; // N en lista
    cout << "BÚSQUEDAS Y ORDENAMIENTO\n";
    cout << "Opciones: \n";
    cout << "a) Ordenamiento\n";
    cout << "b) Busqueda \n";
    cout << "Entrada: ";
    cin >> option;

    if (option == 'a') {
        int comparaciones = 0;
        int iteraciones = 0;

        auto config = configPromptSort(); // Se pregunta por configuracion de la lista
        char alg = get<2>(config);
        char tipo = get<0>(config);
        int n = get<1>(config);
        
        switch(alg) {

            case 'a' :{
                if (tipo == 'f') {
                    vector<float> list = randomVector<float>(n);
                    displayVector<float>(list);
                    intercambio<float>(list,iteraciones, comparaciones);
                    displayVector<float>(list);
                }
                else {
                    vector<int> list = randomVector<int>(n);
                    displayVector<int>(list);
                    intercambio<int>(list,iteraciones, comparaciones);
                    displayVector<int>(list);
                }
                break;
            }
            case 'b' : {
                // burbuja
                 if (tipo == 'f') {
                    vector<float> list = randomVector<float>(n);
                    displayVector<float>(list);
                    bubble<float>(list,iteraciones, comparaciones);
                    displayVector<float>(list);
                }
                else {
                    vector<int> list = randomVector<int>(n);
                    displayVector<int>(list);
                    bubble<int>(list,iteraciones, comparaciones);
                    displayVector<int>(list);
                }
                break;
            }
            case 'c': {
                // insertion
                if (tipo == 'f') {
                    vector<float> list = randomVector<float>(n);
                    displayVector<float>(list);
                    insertionSort<float>(list,iteraciones, comparaciones);
                    displayVector<float>(list);
                }
                else {
                    vector<int> list = randomVector<int>(n);
                    displayVector<int>(list);
                    insertionSort<int>(list,iteraciones, comparaciones);
                    displayVector<int>(list);
                }
                break;
            }
            case 'd' :{
                // selection
                if (tipo == 'f') {
                    vector<float> lista = randomVector<float>(n);
                    displayVector(lista);
                    selectionSort<float>(lista, iteraciones, comparaciones);
                    displayVector(lista);
                }
                else {
                    vector<int> lista = randomVector<int>(n);
                    displayVector(lista);
                    selectionSort<int>(lista, iteraciones, comparaciones);
                    displayVector(lista);
                }
                break;
            }
            case 'e': {
                // quicksort
                if (tipo == 'f') {
                    vector<float> lista = randomVector<float>(n);
                    displayVector(lista);
                    quicksort<float>(lista, iteraciones, comparaciones);
                    displayVector(lista);
                }
                else {
                    vector<int> lista = randomVector<int>(n);
                    displayVector(lista);
                    quicksort<int>(lista, iteraciones, comparaciones);
                    displayVector(lista);
                }
                break;
            }
        }
        cout << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
    }

        // Alg benchmark
        
    }




