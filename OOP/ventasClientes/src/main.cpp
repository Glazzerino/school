#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
   ifstream file;
   file.open("Data.txt");
   string line;
   bool isfirst = true;
   int day,clients,sales;
   int maxday, maxsales;
   int minday, minclients;
   while(file >> day >> clients >> sales) {
       if (isfirst) {
           maxday = day;
           minday = day;
           minclients = clients;
           maxsales = sales;
           isfirst = false;
       }
       else if (maxsales < sales) {
           maxsales = sales;
           maxday = day;
       }
       else if (minclients > clients) {
           minclients = clients;
           minday = day;
       }
   }
   cout << "Dia " << maxday << " Ventas Mayores " << maxsales << endl;
   cout << "Dia " << minday << " Menos Clientes " << minclients << endl;
}