    #pragma once
    #include <string>
    using namespace std;
    class Pasajero {
        private:
            int id;
            int vueloId;
            string destino;
            string salida;
            string nombre;
        public:
            Pasajero();
            Pasajero(string nombre, string salida, string destino,int id, int vueloId);
            void setId(int id);
            void setVueloId(int vueloId);
            int getVueloId();
            int getId();
            void setDestino(string destino);
            string getDestino();
            void setSalida(string inicio);
            string getSalida();
            void setNombre(string nombre);
            string getNombre();
    };

    Pasajero::Pasajero() {
        this->nombre = "null";
        this->salida = "DEFAULT";
        this->destino = "DEFAULT";
        this->id = 0;
    }
    void Pasajero::setNombre(string nombre) {
        this->nombre = nombre;
    }

    string Pasajero::getNombre() {
        return this->nombre;
    }


    Pasajero::Pasajero(string nombre, string salida, string destino, int id, int vueloId) {
        this->nombre = nombre;
        this->salida = salida;
        this->destino = destino;
        this->id = id;
        this->vueloId = vueloId;
    }
    int Pasajero::getVueloId() {
        return this->vueloId;
    }

    void Pasajero::setVueloId(int input) {
        this->vueloId = input;
    }

    void Pasajero::setId(int id) {
        this->id = id;
    }

    int Pasajero::getId() {
        return this->id;
    }

    void Pasajero::setDestino(string idDestino) {
        this->destino = idDestino;
    }

    string Pasajero::getDestino() {
        return this->destino;
    }

    void Pasajero::setSalida(string inicio) {
        this->salida = inicio;
    }

    string Pasajero::getSalida() {
        return this->salida;
    }

