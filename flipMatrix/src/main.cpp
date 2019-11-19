#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int x,y;
   cin >> x >> y;
   int mat[x][y];
   for (int i=0;i<y;i++) {
     for (int c=0;c<x;c++) {
       int n;
       cin >> n;
       mat[c][i] = n;
     }
   }
    // fliping
    for (int j = 0; j < y; j++) {
      for (int i =0; i < x /2; i++) {
        int swap = mat[i][j];
        mat[i][j] = mat[x -1 - i][j];
        mat[x -1 - i][j] = swap;
      }
    }
    bool first = true;
   for (int i =0 ;i<y;i++) {
     for (int n=0;n<x;n++) {
       cout << mat[n][i] << " ";
     }
     cout << endl;
   } 
} 