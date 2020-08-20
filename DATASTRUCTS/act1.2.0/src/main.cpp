#include <iostream>
#include <vector>
using namespace std;

void suma_pares(vector<int> list, int& suma) {
    if (list.back() % 2 == 0) {
        suma += list.back();
    }
    list.pop_back();
    if (list.size() == 0) {
        return;
    }
    suma_pares(list,suma);
}

int main() {
    vector<int> list = {1,2,3,4,5,6};
    int suma = 0;
    suma_pares(list, suma);
    cout << suma;
}