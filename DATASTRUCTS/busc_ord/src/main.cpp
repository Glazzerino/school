#include <vector>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <stack>
#include "Timer.h"
#include <tuple>
#include <set>

using namespace std;

template<class T>
vector<vector<T>> initial_split(vector<T> &list, int &iters, int &comps, int &swaps) {
    vector<vector<T>> final;
    int i = 0;
    vector<T> cell;
    while (i < list.size()) {

        cell.clear();
        if (i == 0 && ((list.size() % 2) != 0 && list.size() != 1)) {
//            vector<T> cell{list[i], list[i + 1], list[i + 2]};
            cell.push_back(list[i]);
            cell.push_back(list[i + 1]);
            cell.push_back(list[i + 2]);
            if (cell[0] > cell[1]) {
                swap(cell[0], cell[1]);
                swaps++;
                comps++;
            }
            if (cell[0] > cell[2]) {
                swap(cell[0], cell[2]);
                swaps++;
                comps++;
            }
            if (cell[1] > cell[2]) {
                swap(cell[1], cell[2]);
                swaps++;
                comps++;
            }
            i += 3;
//            display_vector(cell);
        } else if (list.size() > 1) {
            T a = list[i];
            T b = list[i + 1];
            if (a > b) {
                swaps++;
                comps++;
                swap(a, b);
            }
            cell.push_back(a);
            cell.push_back(b);
            i += 2;
        } else {
            cell.push_back(list[0]);
            final.push_back(cell);
            break;
        }
        final.push_back(cell);
    }
    return final;
}

template<class T>
inline void displayVector(vector<T> &list) {
    if (!list.empty()) {
        cout << "[";
        for (T x : list) {
            cout << x << " ";
        }
        cout << "]" << "\n";
    } else {
        cout << "empty" << endl;
    }

}

template<class T>
vector<T> merge(vector<T> a, vector<T> b, int &iters, int &comps, int &swaps) {
    int total = a.size() + b.size();
    int ac = 0;
    int bc = 0;
    int i = 0;
    vector<T> c;
    c.reserve(total);
    while (ac < a.size() && bc < b.size()) {
        iters++;
        if (a[ac] < b[bc]) {
            comps++;
            c.push_back(a[ac]);
            ac++;
        } else {
            c.push_back(b[bc]);
            bc++;
        }
        if (bc == b.size()) {
            comps++;
            for (int x = ac; x < a.size(); x++) {
                c.push_back(a[x]);
            }
            break;
        } else if (ac == a.size()) {
            comps++;
            for (int x = bc; x < b.size(); x++) {
                c.push_back(b[x]);
            }
            break;
        }
        i++;
    }
    return c;
}

template<class T>
void mergesort(vector<T> &list, int &iters, int &comps, int &swaps) {
    Timer timer;
    vector<vector<T>> temp;
    vector<vector<T>> heads;
    vector<vector<T>> metalist = initial_split(list, iters, comps, swaps);


    while (metalist.size() > 1) {
        iters++;

        for (int i = 0; i < metalist.size() - 1; i += 2) {
            temp.push_back(merge(metalist[i], metalist[i + 1], iters, comps, swaps));
        }
        if (metalist.size() % 2 != 0) {
            temp.push_back(metalist[metalist.size() - 1]);
        }

        swap(metalist, temp);
        temp.clear();
    }
    swap(list, metalist[0]);
//    temp.clear();
}

template<class T>
int partition(vector<T> &list, int start, int end, int &iters, int &comps, int &swaps) {
    T pivot = list[end];

    int pindex = start;

    for (int i = start; i < end; i++) {
        iters++;
        if (list[i] <= pivot) {
            comps++;
            swap(list[i], list[pindex]);
            swaps++;
            pindex++;
        }
    }
    swap(list[pindex], list[end]);
    swaps++;
    return pindex;
}

template<class T>
void quicksort(vector<T> &list, int &iters, int &comps, int &swaps) {
    Timer timer;
    stack<pair<T, T>> pairs;
    int end = list.size() - 1;
    int start = 0;
    pairs.push(pair<T, T>{start, end});

    while (!pairs.empty()) {
        iters++;
        start = pairs.top().first;
        end = pairs.top().second;
        pairs.pop();
        int pivot = partition(list, start, end, iters, comps, swaps);
        if (pivot - 1 > start) {
            comps++;
            pairs.push(pair<T, T>{start, pivot - 1});
        }
        if (pivot + 1 < end) {
            comps++;
            pairs.push(pair<T, T>{pivot + 1, end});
        }
    }
    // return list;
}

template<class T>
vector<T> randomVectorUnsorted(int n, int limit, bool ischar) {
    std::srand(time(nullptr));
    cout << "Numero de elementos: " << n << endl;
    vector<T> rand_vector;
    rand_vector.reserve(n);
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};
    int i;
    T temp;


    for (i = 0; i < n; i++) {
        // temp = (T) (rand()) / (T) (RAND_MAX);

        if (is_floating_point<T>::value) {
            temp = ((T) (rand() % limit) / (rand() % limit));
        } else if (ischar) {
            temp = alphabet[rand() % 26];
        } else {
            temp = rand() % limit;
        }
        rand_vector.push_back(temp);
    }
    displayVector(rand_vector);
    return rand_vector;
}

//BUSQUEDA
template<class T>
int sequential(vector<T> &list, int query, int &iters, int &comps) {
    size_t x;
    for (x = 0; x < list.size(); x++) {
        iters++;
        comps++;
        if (list[x] == list[query]) {
            return x;
        }
    }
    return -1;
}

template<class T>
int binary_search(vector<T>& list, int query ,int& iters, int& comps) {
    int r = list.size()-1;
    int l = 0;
    int m = (r) / 2;
    while(l <= r) {
        iters++;
        int m = l + (r - l) / 2;
        if (list[m] == list[query]) {
            comps++;
            return m;
        }
        else if (list[m] < list[query]) {
            comps++;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int swaps = 0;

template<class T>
inline void swap(T *a, T *b) {
    T aux = b;
    b = a;
    a = aux;
}

template<class T>
void insertionSort(vector<T> &list, int &iter, int &comps, int &swaps) {
    Timer timer;
    int i;
    int x;
    T aux;
    bool swapped;
    for (x = 1; x < list.size(); x++) {
        iter++;
        swapped = false;
        if (list[x] < list[x - 1]) {
            comps++;
            // swapped = true;
            for (i = 0; i < x; i++) {
                iter++;
                if (list[i] > list[x]) {
                    comps++;
                    // aux = list[x];
                    list.emplace(list.begin() + i, list[x]);
                    swaps++;
                    list.erase(list.begin() + x + 1);
                    break;
                }
            }
        }
    }
}


// O(n2)
template<class T>
void selectionSort(vector<T> &list, int &iters, int &comps, int &swaps) {
    Timer timer;
    int min;
    for (int i = 0; i < list.size(); i++) {
        iters++;
        min = i;
        for (int j = i; j < list.size(); j++) {
            iters++;
            if (list[j] < list[min]) {
                comps++;
                min = j;
            }
        }
        swap(list[min], list[i]);
        swaps++;
    }
}

// O(n2)
template<class T>
void intercambio(vector<T> &lista, int &iter, int &comps, int &swaps) {
    Timer time;
    for (int i = 0; i < lista.size(); i++) {
        iter++;
        // cout << "Current num: " << lista[i] << endl;
        for (int x = i + 1; x < lista.size(); x++) {
            iter++;
            comps++;
            if (lista[x] < lista[i]) {
                comps++;
                swaps++;
                swap(lista[x], lista[i]);
            }
        }
    }
}

//(O*N^2)
template<class T>
void bubble(vector<T> &lista, int &iter, int &comps, int &swaps) {
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
                swaps++;
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


template<class T>
unsigned int get_query(vector<T> &list) {
    unsigned int query = 0;
    bool control = false;
    do {
        cout << "Seleccione un elemento de la lista" << endl;
        for (int i = 0; i < list.size() * 2; i++) {
            if (i < list.size()) {
                cout << list[i] << " ";
            } else {
                if (!control) {
                    cout << endl;
//                    cout << " ";
                    control = true;
                }
                cout << i - list.size() << " ";
            }
        }
        cout << endl;
        cout << "Entrada: ";
        cin >> query;
    } while (query > list.size());

    return query;
}

template<class T>
void display_search_positon(vector<T> &list, int search) {
//    displayVector(list);
    for (int i = 0; i < list.size(); i++) {
        if (i == search) {
            cout << "[" << list[i] << "] ";
        } else {
            cout << list[i] << " ";
        }
    }
    cout << endl;
}

template<class T>
vector<T> randomVectorSorted(int n, bool is_char) {
    vector<T> temp;
    std::srand(time(nullptr));
    T last = 0;
    T head = 0;
    temp.reserve(n);
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};
    if (n > 26 && is_char) {
        n = 26;
    }
    if (is_char) {
        for (int i = 0; i < n; i++) {
            temp.push_back(alphabet[i]);

        }
    } else if (is_floating_point<T>::value) {
        for (int i = 0; i < n; i++) {
            head = (T) (rand() % 100) / (rand() % 100);
            temp.push_back(head + last);
            last = temp[i];
        }

    } else {
        for (int i = 0; i < n; i++) {

            temp.push_back(rand() % 100 + last);
            last = temp[i];
        }
    }
    return temp;
}


int main() {

    int comparaciones = 0;
    int iteraciones = 0;
    char option;
    int n; // N en lista

    cout << "BÚSQUEDAS Y ORDENAMIENTO\n";
    cout << "Opciones: \n";
    cout << "a) Ordenamiento\n";
    cout << "b) Busqueda \n";
    cout << "Entrada: ";
    cin >> option;

    char type, algorithm;
    bool clean_input;

    vector<int> intvec;
    vector<float> floatvec;
    vector<char> charvec;
    vector<double> doublevec;

    do {
        cout << "Ingrese tipo de dato para el vector, seguido del numero de elementos" << endl;
        cout << "c: char | i: int | f:  float | d: double" << endl;
        cout << "Entrada: ";
        cin >> type >> n;
        cout << endl;
        clean_input = (n > 0 && n < 1000000 && (type == 'i' || type == 'f' || type == 'c' || type == 'd'));
        if (!clean_input) {
            cout << "Entrada invalida. Intenta otra vez" << endl;
        }
    } while (!clean_input);
    switch (type) {
        case 'i': {
            intvec = randomVectorUnsorted<int>(n, 100, false);
            break;
        }
        case 'f': {
            floatvec = randomVectorUnsorted<float>(n, 100, false);
            break;
        }
        case 'd': {
            doublevec = randomVectorUnsorted<double>(n, 100, false);
            break;
        }
        case 'c': {
            charvec = randomVectorUnsorted<char>(n, 26, true);
            break;
        }
        default: {
            throw;
        }
    }

    if (option == 'a') {

//        int num;
        int n;

        clean_input = false;
        do {
            cout << "Seleccione el algortimo a utilizar: \n";
            cout << "a) Intercambio\n";
            cout << "b) Seleccion\n";
            cout << "c) Burbuja\n";
            cout << "d) Insercion\n";
            cout << "e) Mergesort\n";
            cout << "f) Quicksort\n";
            cout << "Selección: ";
            cin >> algorithm;
            clean_input = (algorithm >= 'a' && algorithm <= 'f');
        } while (!clean_input);

//        displayVector(floatvec);
//        displayVector(intvec);
//        displayVector(doublevec);
//        displayVector(charvec);

        cout << "Vector en bruto: \n";
        switch (algorithm) {


            case 'a': {

//                Intercambio
                if (type == 'f') {

                    displayVector(floatvec);
                    intercambio(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {

                    displayVector(doublevec);
                    intercambio(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {

                    displayVector(charvec);
                    intercambio(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {

                    displayVector(intvec);
                    intercambio(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                break;
            }
            case 'b': {
//                Seleccion sort
                if (type == 'f') {
                    displayVector(floatvec);
                    selectionSort(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {
                    displayVector(doublevec);
                    selectionSort(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {
                    displayVector(charvec);
                    selectionSort(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {
                    displayVector(intvec);
                    selectionSort(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                break;
            }
            case 'c': {
//                Bubble sort
                if (type == 'f') {
                    displayVector(floatvec);
                    bubble(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {
                    displayVector(doublevec);
                    bubble(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {
                    displayVector(charvec);
                    bubble(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {
                    displayVector(intvec);
                    bubble(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                break;
            }
            case 'd' : {
//                Insertion sort
                if (type == 'f') {
                    displayVector(floatvec);
                    insertionSort(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {
                    displayVector(doublevec);
                    insertionSort(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {
                    displayVector(charvec);
                    insertionSort(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {
                    displayVector(intvec);
                    insertionSort(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                break;
            }
            case 'e' : {
//                Mergesort
                if (type == 'f') {
                    displayVector(floatvec);
                    mergesort(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {
                    displayVector(doublevec);
                    mergesort(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {
                    displayVector(charvec);
                    mergesort(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {
                    displayVector(intvec);
                    mergesort(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                break;
            }
            case 'f' : {

                if (type == 'f') {
                    displayVector(floatvec);
                    quicksort(floatvec, iteraciones, comparaciones, swaps);
                    displayVector(floatvec);
                } else if (type == 'd') {
                    displayVector(doublevec);
                    quicksort(doublevec, iteraciones, comparaciones, swaps);
                    displayVector(doublevec);
                } else if (type == 'c') {
                    displayVector(charvec);
                    quicksort(charvec, iteraciones, comparaciones, swaps);
                    displayVector(charvec);
                } else if (type == 'i') {
                    displayVector(intvec);
                    quicksort(intvec, iteraciones, comparaciones, swaps);
                    displayVector(intvec);
                }
                cout << "Intercambios: " << swaps << " ";
//                break;
                break;

            }

        }

    } else if (option == 'b') {

        do {
            cout << "Seleccione algortimo de busqueda: \n";
            cout << "s) Secuencial\n";
            cout << "b) Binario\n";
            cin >> algorithm;
            clean_input = (algorithm == 's' || algorithm == 'b');
        } while (!clean_input);

        int query;
        int search;

        switch (algorithm) {
            case 's': {
                switch (type) {
                    case 'f' : {
                        floatvec = randomVectorSorted<float>(n, false);
                        query = get_query(floatvec);
                        search = sequential(floatvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << floatvec[search] << endl;
                        }
//                        displayVector(floatvec);
                        display_search_positon(floatvec, search);
                        break;
                    }
                    case 'i' : {
                        intvec = randomVectorSorted<int>(n, false);
                        query = get_query(intvec);
                        search = sequential(intvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << intvec[search] << endl;
                        }
                        display_search_positon(intvec, search);

                        break;
                    }
                    case 'd' : {
//                        double
                        doublevec = randomVectorSorted<double>(n, false);
                        query = get_query(doublevec);
                        search = sequential(doublevec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << doublevec[search] << endl;
                        }
//                        displayVector(doublevec);
                        display_search_positon(doublevec, search);
                        break;
                    }
                    case 'c' : {
                        charvec = randomVectorSorted<char>(n, true);
//                        mergesort(charvec,iteraciones, comparaciones, swaps);
                        query = get_query(charvec);
                        search = sequential(charvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << charvec[search] << endl;
                        }
                        displayVector(charvec);
                        display_search_positon(charvec, search);
                        break;
                    }
                }
                break;
            }
            case 'b': {
                switch (type) {
                    case 'f' : {
                        floatvec = randomVectorSorted<float>(n, false);
                        query = get_query(floatvec);
                        search = binary_search(floatvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << floatvec[search] << endl;
                        }
//                        displayVector(floatvec);
                        display_search_positon(floatvec, search);
                        break;
                    }
                    case 'i' : {
                        intvec = randomVectorSorted<int>(n, false);
                        query = get_query(intvec);
                        search = binary_search(intvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << intvec[search] << endl;
                        }
                        display_search_positon(intvec, search);

                        break;
                    }
                    case 'd' : {
//                        double
                        doublevec = randomVectorSorted<double>(n, false);
                        query = get_query(doublevec);
                        search = binary_search(doublevec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << doublevec[search] << endl;
                        }
//                        displayVector(doublevec);
                        display_search_positon(doublevec, search);
                        break;
                    }
                    case 'c' : {
                        charvec = randomVectorSorted<char>(n, true);
//                        mergesort(charvec,iteraciones, comparaciones, swaps);
                        query = get_query(charvec);
                        search = binary_search(charvec, query, iteraciones, comparaciones);
                        if (search >= 0) {
                            cout << "Indice: " << search << " Elemento: " << charvec[search] << endl;
                        }
                        displayVector(charvec);
                        display_search_positon(charvec, search);
                        break;
                    }
                }
                break;
            }
        }

    }
    cout << "Iteraciones: " << iteraciones << " Comparaciones: " << comparaciones << endl;
    // Alg benchmark
}