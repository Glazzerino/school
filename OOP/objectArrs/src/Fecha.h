//
//  Fecha.h
//  departamentosYEmpleados
//
//  Created by Yolanda Martinez on 11/21/19.
//  Copyright © 2019 com.itesm. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h

class Fecha {
public:
    Fecha();
    Fecha(int d, int m, int a);
    void setDd(int d);
    void setMm(int m);
    void setAa(int a);
    int getDd();
    int getMm();
    int getAa();
private:
    int dd, mm, aa;
};

Fecha::Fecha() {
    dd = 1;
    mm = 1;
    aa = 2000;
}

Fecha::Fecha(int d, int m, int a) {
    dd = d;
    mm = m;
    aa = a;
}

void Fecha::setDd(int d) {
    dd = d;
}

void Fecha::setMm(int m) {
    mm = m;
}

void Fecha::setAa(int a) {
    aa = a;
}

int Fecha::getDd() {
    return dd;
}

int Fecha::getMm() {
    return mm;
}

int Fecha::getAa() {
    return aa;
}

#endif /* Fecha_h */
