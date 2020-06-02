#pragma once
#include <sstream>
class Complejo {
    public:
        Complejo();
        Complejo(int r, int i);
        void setReal(int r);
        void setImaginario(int i);
        int getReal();
        int getImaginario();
        Complejo suma(Complejo& num2);
        std::string muestra();
    private:
        int real, imaginario;
};

Complejo::Complejo() : real(0), imaginario(0){}

Complejo::Complejo(int r, int i) : real(r), imaginario(i){};

void Complejo::setImaginario(int i) {
     this->imaginario = i;
}
void Complejo::setReal(int r) {
    this->real = r;
}
int Complejo::getReal() {
    return this->real;
}
int Complejo::getImaginario() {
    return this->imaginario;
}

Complejo Complejo::suma(Complejo& num2) {
    return Complejo{real+num2.real, imaginario + num2.imaginario};
}

std::string Complejo::muestra() {
    std::stringstream ans;
    ans << this->real << " + " << this->imaginario << "i";
    return ans.str(); 
}