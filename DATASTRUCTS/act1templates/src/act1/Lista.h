//Francisco Zamora Treviño A01570484
//10 ago 2020
#include <vector>
#include <string>
using namespace std;
template <class T>
class Lista {
public:
    Lista<T>();
    void insert(T);
    void erase();
    T getData(T);
    T getSize();
    void print();

private:
    std::vector<T> data;
    const unsigned int MAX = 100;
};

template<class T>
Lista<T>::Lista() {
    data.reserve(100);
}

template<class T>
//Se debe proveer de un tipo de dato en el constructor
//complejidad mínima y lineal en el número de elementos introducidos
void Lista<T>::insert(T number) {
    if (data.size() < MAX) {
        data.push_back(number);
    } else {
        cout << "Límite excedido. Dato ignorado\n";
    }
}

//Borra el ultimo elemento del vector.
//complejidad mínima
template<class T>
void Lista<T>::erase() {
    if (!data.empty()) {
        cout <<"Dato a borrar: " << data[data.size()-1] << endl;
        data.pop_back();
    } else {
        cout << "NO HAY ELEMENTOS" <<  endl;
    }
}

//getter que funciona con indice para obtener un dato
//complejidad minima
template<class T>
T Lista<T>::getData(T index) {
    if (index > data.size() || index < 0) {
        throw runtime_error("VECTOR VACÍO");
    } else {
        return data[index];
    }
}

template<class T>
T Lista<T>::getSize() {
    return data.size();
}

//despliega los datos del vector
//complejidad lineal en el numero de elementos en el vector.  Maximo teoretico de 100(O)
template<class T>
void Lista<T>::print() {
    for (T i=0; i<data.size(); i++) {
        cout << "[" << i << "]" << "-" << data[i] << endl;
    }
}