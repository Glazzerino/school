//

//  Complejo.h

//  ejerComplejos

//

//  Created by Yolanda Martinez on 02/06/20.

//  Copyright © 2020 com.itesm. All rights reserved.

//

#pragma once
#include<cmath>
class Complejo

{

public:
    Complejo() {
        real = 0;
        imag = 0;
    };

    Complejo(double r, double i) {
        real = r;
        imag = i;
    };

    void setReal(double r) { real = r; };

    void setImag(double i) { imag = i; };

    double getReal() { return real; };

    double getImag() { return imag; };

    void muestra();

    Complejo suma(Complejo c1);
    Complejo operator*(int n);
    Complejo operator+(Complejo c2);
    
    Complejo operator*(Complejo c2);
    bool operator >=(Complejo c2);
    Complejo operator-(Complejo c2);

    bool operator>(Complejo c2);
    

    Complejo operator++();
    Complejo operator--();
    bool operator==(Complejo otro);

protected:
    double real, imag;
};

Complejo Complejo::suma(Complejo c1)
{

    Complejo res;

    res.real = this->real + c1.real;

    res.imag = this->imag + c1.imag;

    return res;
}

Complejo Complejo::operator*(Complejo c2)  {
    return( Complejo(real*c2.real- imag*c2.imag, real*c2.imag + imag*c2.real) );
}

bool Complejo::operator>(Complejo c2) {
    return (sqrt(pow(real,2)+pow(imag,2)) > sqrt(pow(c2.real,2) > pow(c2.imag,2)) );
}

Complejo Complejo::operator*(int n) {
    return (Complejo(real*n, imag*n));
}

void Complejo::muestra() {
    cout << real << " + " << imag << "i ";
}

bool Complejo::operator>=(Complejo c2) {
    return (*this > c2 || *this == c2);
}

Complejo Complejo::operator--() {
    *this = *this - Complejo(1,1);
    return *this;
}

Complejo Complejo::operator+(Complejo c2) {
    int realN = this->real + c2.real;
    int imagN = this->imag + c2.imag;
    Complejo nuevo(realN, imagN);
    return nuevo;
}

Complejo Complejo::operator-(Complejo c2)
{

    int realN = real - c2.real;

    int imagN = imag - c2.imag;

    Complejo nuevo(realN, imagN);

    return nuevo;
}

Complejo Complejo::operator++()
{

    this->real++;

    this->imag++;

    return *this;
}

bool Complejo::operator==(Complejo otro)
{

    if (real == otro.real && imag == otro.imag)

        return true;

    else

        return false;
}