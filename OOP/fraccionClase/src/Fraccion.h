// Escribe la clase Fracción de acuerdo con los comentarios
#include<iostream>
using namespace std;
// Clase Fraccion
// publico
    // constructor default
    // constructor con parámetros para numerador y denominador
    // métodos de acceso para todos los atributos
    // métodos de modificación para todos los atributos
    // método calcValorReal que regresa el valor en decimal de la fracción
    // por ejemplo si la fracción es 1/2 regresa 0.5
// privado
    // atributos enteros num y den
  class Fraccion {
    public:
      Fraccion(int n, int d);
      Fraccion();
      float getDen();
      float getNum();
      void setDen(int n);
      void setNum(int n); 
      float calcValorReal();
    private:
      int den, num;
  };
Fraccion::Fraccion(){
    den = 1;
    num = 1;
};
Fraccion::Fraccion(int n, int d) : den(d), num(n) {}
float Fraccion::getDen() {
  return (float)den;
}
void Fraccion::setDen(int n) {
  den = n;
}
void Fraccion::setNum(int n) {
  num = n;
}
float Fraccion::getNum() {
  return (float)num;
}
float Fraccion::calcValorReal() {
    float ans = (float) num / (float) den;
    return ans;
}

// implementa los métodos
