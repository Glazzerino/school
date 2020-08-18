#include <iostream>
#include <string>
using namespace std;
int global = 0;
int factorial(int n) {
    return (n - 1);
}

int recurse(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return (num * factorial(num - 1));
    }
}

//Recibe el valor que se desea sumar
// Su complejidad es exactamente el numero que se le da
// N(O)
int sumaIterativa(int n) {
    int sum = 0;
    if (n > 0) {
        for (int i=1; i<n+1; i++) {
            sum += i;
        }
    }
    return sum;
}

// Recibe el valor que se desea sumar
// Su complejidad es exactamente el numero que se le da
// N(O)
int sumaRecursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n+sumaRecursiva(n-1);
    }
}

//Su complejidad es nula pues es una sola instruccion
int sumaDirecta(int n) {
    return ((n * (n+1))/2);
}
// Funcion auxiliar para la piramide
// Recibe el numero de iteraciones y el caracter a imprimir
void caracter(int iter, char c) {
    if (iter > 0) {
        cout << c << " ";
    } else {
        return;
    }
    caracter(iter-1,c);
}
// Funcion auxiliar para la piramide
// Solo imprime espacios
void espacio(int iter) {
    if (iter > 0) {
        cout << " ";
    } else {
        return;
    }
    espacio(iter-1);
}


/**
 * La cantidad de llamadas de funciones es 2*N + N donde N
 * es el numero de entrada
 * **/
void patronCaracteres(int n,char c) {
    if (global == 0) {
        global = n;
    }
    if (n == 0) {
        return;
    }
    espacio(n-1);
    caracter(global-n+1,c);
    cout << "\n";
    patronCaracteres(n-1,c);
}


int main() {
    int c;
    cin >> c;
    cout << "Suma iterativa:\n";
    cout << sumaIterativa(c) << endl;
    cout << "Suma recursiva:\n";
    cout << sumaRecursiva(c) << endl;
    cout << "Suma directa:\n";
    cout << sumaDirecta(c) << endl;
    cout << "Pirámide:\n";
    patronCaracteres(c,'*');
}