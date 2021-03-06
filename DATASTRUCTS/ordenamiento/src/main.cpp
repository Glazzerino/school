#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stack>

using namespace std;

int partition(vector<int> &list, int start, int end) {
    int pivot = list[end];

    int pindex = start;

    for (int i = start; i < end; i++) {
        if (list[i] <= pivot) {
            swap(list[i], list[pindex]);
            pindex++;
        }
    }
    swap(list[pindex], list[end]);
    return pindex;
}

void quicksort(vector<int> &list) {
    stack <pair<int, int>> pairs;
    int end = list.size() - 1;
    int start = 0;
    pairs.push(pair < int, int > {start, end});

    while (!pairs.empty()) {
        start = pairs.top().first;
        end = pairs.top().second;
        pairs.pop();
        int pivot = partition(list, start, end);
        if (pivot - 1 > start) {
            pairs.push(pair < int, int > {start, pivot - 1});
        }
        if (pivot + 1 < end) {
            pairs.push(pair < int, int > {pivot + 1, end});
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

int main() {
    vector<int> list = {6, -3, 5, 1, 9, 8, 3, 2, -6};
    // auto n = quicksort(list);
    quicksort(list);
    disp_vector(list);

}

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
    std::chrono::high_resolution_clock::time_point start, end;
};

//BUSQUEDA
template<class T>
size_t sequential(vector <T> &list, T query) {
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
inline void swap(T *a, T *b) {
    T aux = b;
    b = a;
    a = aux;
}

template<class T>
void insertionSort(vector <T> &list) {
    Timer timer;
    int i;
    int x;
    T aux;
    bool swapped;
    for (x = 1; x < list.size(); x++) {
        swapped = false;
        if (list[x] < list[x - 1]) {
            // swapped = true;
            for (i = 0; i < x; i++) {
                if (list[i] > list[x]) {
                    // aux = list[x];
                    list.emplace(list.begin() + i, list[x]);
                    list.erase(list.begin() + x + 1);
                    break;
                }
            }
        }

    }
}


// O(n2)
template<class T>
void selectionSort(vector <T> &list) {
    Timer timer;
    int min;
    for (int i = 0; i < list.size(); i++) {
        min = i;
        for (int j = i; j < list.size(); j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        swap(list[min], list[i]);
    }
}

// O(n2)
template<class T>
void intercambio(vector <T> &lista, int &iter, int &comps) {
    Timer time;
    for (int i = 0; i < lista.size(); i++) {
        iter++;
        comps++;
        // cout << "Current num: " << lista[i] << endl;
        for (int x = i + 1; x < lista.size(); x++) {
            iter++;
            comps++;
            if (lista[x] > lista[i]) {
                comps++;
                swap(lista[x], lista[i]);
            }
        }
    }
}

//(O*N^2)
template<class T>
void bubble(vector <T> &lista, int &iter, int &comps) {
    bool swapped = false;
    Timer timer;
    for (int i = 0; i < lista.size() - 1; i++) {
        iter++;
        for (int x = 0; x < lista.size() - i - 1; x++) {
            swapped = false;
            iter++;
            if (lista[x + 1] < lista[x]) {
                swapped = true;
                comps++;
                swap(lista[x + 1], lista[x]);
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
inline vector <T> mergeVectors(vector <T> first, vector <T> second) {
    size_t final_size = first.size() + second.size();
    vector <T> final;
    final.reserve(final_size);
    for (int i = 0; i < final_size; i++) {
        if (second.size() == 0) {
            for (int j = first.size() - 1; j >= 0; j--) {
                final.push_back(first[j]);
            }
            break;
        } else if (first.size() == 0) {
            for (int j = second.size() - 1; j >= 0; j--) {
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
inline std::pair <vector<T>, vector<T>> splitVector(vector <T> list) {
    vector <T> first;
    vector <T> second;
    int mid = (list.size() / 2) + (list.size() % 2);
    for (int i = 0; i < mid; i++) {
        first.push_back(list[i]);
    }

    for (int i = mid; i < list.size(); i++) {
        second.push_back(list[i]);
    }
    return std::pair < vector < T > , vector < T >> {first, second};
}

template<class T>
void mergesort(vector <T> list) {
    // int l = 0;
    // int m =  (list.size() / 2) + (list.size() % 2) - 1;
    // int r = m + 1;
    bool phase1done = false;
    vector <vector<T>> metalist;
    for (int i = 0; i < list.size(); i += 2) {
        vector <T> cell;
        if (list.size() % 2 != 0 && i == list.size() - 1) {
            cell.push_back(list[i]);
            // cout << "cunt";
        } else {
            cell.push_back(list[i]);
            cell.push_back(list[i + 1]);
        }
        metalist.push_back(cell);
    }

    for (vector <T> x: metalist) {
        for (T y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    int iteraciones = 0;
    int comparaciones = 0;
    vector<int> lista = {1, 4, 2, 3, 5, 100, 20, 0, 8};
    vector<float> fracciones = {0.2, 421.42, 6.4, 980.002};
    cout << sequential<float>(fracciones, 6.4) << endl;
    // bubble<int>(lista, iteraciones, comparaciones);
    // for (int x : lista) {
    //     cout << x << " ";
    // }
    // cout <<endl << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
    // vector<int> test1 = {5,4};
    // vector<int> test2 = {3};
    // auto couple = splitVector(lista);
    // vector<int> merged = mergeVectors<int>(couple.second, couple.first);
    // for (int x : lista) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // mergesort<int>(lista);
}