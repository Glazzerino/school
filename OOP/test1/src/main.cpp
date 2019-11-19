#include <iostream>
#include <fstream>
using namespace std;
int main() {
   ifstream file;
   int day, clientes;
   double ventas;
   file.open("src/datos.txt");
   while(file >> day >> clientes >> ventas) {
       cout << day << " " << clientes << " " << ventas << endl;
   }
   file.close();
   return 0;
}