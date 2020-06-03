//

//  main.cpp

//  ejerComplejos

//

//  Created by Yolanda Martinez on 02/06/20.

//  Copyright © 2020 com.itesm. All rights reserved.

//


 

#include <iostream>

using namespace std;


 

#include "Complejo.h"


 

int main() {


 

    Complejo c1(3, 2), c2(5, 6), c3, c4;

       

       cout << "valores originales "<< endl;

       cout << "C1 = ";

       c1.muestra();

       cout << endl;

       cout << "C2 = ";

       c2.muestra();

       cout << endl;

       cout << "C3 = ";

       c3.muestra();

       cout << endl;

       cout << "C4 = ";

       c4.muestra();

       cout << endl;

       cout << endl;

       

       if (c3 == c4)
           cout << "c3 y c4 son iguales"<< endl;

        if (c4 >  c3) {
            cout << "C4 es mayor a C3" << endl;
        } else {
            cout << "C3 es mayor a C4" << endl;
        }
           

       cout << "La suma de c1 + c2 " << endl;

  

       c3 = c1 * c2;

       cout << "C1 = ";

       c1.muestra();

       cout << endl;

       cout << "C2 = ";

       c2.muestra();

       cout << endl;

       cout << "C3 = ";

       c3.muestra();

       cout << endl;

    

    return 0;

}