
// Deja la constante afuera de la clase
const double PI = 3.1416;
class Circulo {
    public:
        void setRadio(int r);
        double getRadio();
        double calcArea();
        double calcPerim();
    private:
        double radius;
};
void Circulo::setRadio(int r) {
    this->radius = r;
};
double Circulo::getRadio(){
    return this->radius;
};
double Circulo::calcArea() {
    return this->radius * this->radius * PI;
};
double Circulo::calcPerim() {
    return 2 * PI * this->radius;
};
// INSTRUCCIONES: 
// Escribe la clase Circulo de acuerdo con 
// los comentarios que se encuentran enseguida


// Nombre de la clase: Circulo
// parte pública
     // método de modificación para radio
     // método de acceso para radio
     // método que calcula el área ( PI * radio al cuadrado )
     // método que calcula el perímetro ( 2 * PI * radio )
// parte privada
    // atributo radio

// implementa los métodos

