#include <iostream>

using namespace std;

//Complejidad es igual a MESES
double inversion(int meses, double cant) {
    if(meses >0) {
        cant = cant+(cant*0.1875);
        return inversion(meses-1,cant);
    }
    else {
        return cant;
    }
}


// La complejidad es exactamente Y.
int potencia(int x, int y) {
    if (y <= 0) {
        return 1;
    } else {
        return x * potencia(x,y-1);
    }
}

//La complejidad de esta funcion es N*O + D donde D es la cantidad de Dias especificados
int bacteria2(int n, int current, int bacterias) {
    if (current == 0) {
        if(current != n) {
            return bacteria2(n,current+1,1);
        }
        else {
            return 1;
        }
    }
    else {
        bacterias = bacterias + (bacterias*1.44);
        if(current !=n) {
            return bacteria2(n,current+1,bacterias);
        }
        else {
            return bacterias;
        }
    }
}
//Su complejidad es F(N-1) + F(N-2) donde F(x) da las iteraciones necesarias para cada valor
int fibonacci(int n) {
    // if (n <= 2) {
    //     return 1;
    // } else {
    //     return fibonacci(n-1) + fibonacci(n-2);
    // }
    return n <= 2 ?  1 :  fibonacci(n-2) + fibonacci(n-1);
}


int main() {
    int n;
    cout << "ingrese indice de Fibonacci: " << endl;
    cin >> n;
    cout << "Resultado: ";
    cout << fibonacci(n);
    cout << endl;
    cout << "ingrese meses y dinero inicial de inversion" << endl;
    int months;
    float dinero;
    cin >> months >> dinero;
    cout << inversion(months, dinero);
    cout << endl;
    cout << "bacterias: " << endl;
    cout << bacteria2(5,0,0);
    cout << endl;
    cout << "Ingrese X y Y de potencia, donde la formula es X^Y" << endl;
    int x,y;
    cin >> x >> y;
    cout << potencia(x,y) << endl;
}