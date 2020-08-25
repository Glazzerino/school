#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <type_traits>
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
vector<T> randomVector(int n) {
    std::srand(time(nullptr));
    vector<T> rand_vector;
    rand_vector.reserve(n);
    int i;
    T temp;
    // bool is_float = ;
    cout << std::is_floating_point<T>::value << endl;
    for (i=0;i<n;i++) {
        // temp = (T) (rand()) / (T) (RAND_MAX);
        if (is_floating_point<T>::value) {
            temp = (T) (RAND_MAX)+(T)(rand()) / (T) (rand());
        }
        else {
            temp = rand();
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
void insertionSort(vector<T>& list) {
    Timer timer;
    int i;
    int x;
    T aux;
    bool swapped;
    for (x = 1; x < list.size(); x++) {
        swapped = false;
        if (list[x] < list[x-1]) {
            // swapped = true;
            for (i=0;i<x;i++) {
                if (list[i] > list[x]) {
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
void selectionSort(vector<T>& list) {
    Timer timer;
    int min;
    for (int i=0; i<list.size(); i++) {
        min = i;
        for (int j=i; j<list.size(); j++) {
            if (list[j] < list[min]) {
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

inline std::pair<char, int> configPromptSort() {
    int n;
    char t;
    do {
        cout << "Seleccione el tipo y el numero de elementos de la lista (tipo <espacio> numero): \n";
        cout << "f: Flotante    |   i: Entero\n";
        cout << "Entrada: \n";
        cin >> t >> n;
        if ((t == 'f' || t == 'i') && (n > 0)) {
            return std::pair<char,int>{t,n};
        } else {
            cout << "Entrada inválida, revisa que tu tipo sea \"f\" o \"i\" y que tu numero sea mayor a 0\n";
        }
    } while (true);
}

template<class T>
inline void displayVector(vector<T>& list) {
    for (T x : list) {
        cout << x << " ";
    }
    cout << "\n";
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
    
    switch (option) {
        case 'a': {
            char alg_choice;
            //TODO hacer que condifPromt pregunte por el algoritmo tambien
            // Este caso debe tener su propio switch case dentro
            auto config = configPromptSort(); // Se pregunta por configuracion de la lista
            cout << "Seleccione el algoritmo a utilizar: \n";
            cout << "a) Ordenamiento de intercambio\n";
            cout << "b) Ordenamiento de seleccion\n";
            cout << "c) Ordenamiento de burbuja\n";
            cout << "d) Ordenamiento de insercion\n";
            cout << "Entrada: ";
            cin >> alg_choice;
            cout << endl;

        }
    }
}