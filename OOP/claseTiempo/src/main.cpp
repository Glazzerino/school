
#include <iostream>
#include <cmath>

using namespace std;

#include "Tiempo.h"

int main() {

    int h1, m1, h2, m2;
    Tiempo t2;
    
    //cout << "Teclea horas y minutos de la hora inicial ";
    cin >> h1 >> m1;
    
    // Crea el objeto t1 de la clase Tiempo usando el constructor con parámetros con los valores h1 y m1
    Tiempo t1{h1,m1};
    //cout << "Teclea horas y minutos de la hora final ";
    cin >> h2 >> m2;
    
    // pon los valores h2 y m2 al objeto t2 usando los métodos set
    t2.setHora(h2);
    t2.setMinu(m2);
    cout << "Hora inicio " << t1.getHora() << ":" << t1.getMinu() << endl;
    cout << "Hora fin " << t2.getHora() << ":" << t2.getMinu() << endl;
    
    cout << "La duración es: " << t1.diferencia(t2);
    // muestra la duración, para calcularla llama al método diferencia de la clase Tiempo
    
    return 0;
}
