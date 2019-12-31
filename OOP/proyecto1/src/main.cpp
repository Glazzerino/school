#include <iostream>
#include <string>
#include"Vuelo.h"
using namespace std;

//Carga los pasajeros del archivo a la lista de vuelos
//Realiza una comparativa de IDs para anexar pasajero a su vuelo
void cargaDatosPasajeros(Vuelo vuelos[], int numDeVuelos) {
    int numDePasajeros;
    int id, vueloId;
    string nombre,salida, destino;
    ifstream data;
    data.open("data.txt");
    while(data >> nombre>>salida>>destino >> id >> vueloId) {
        for (int i=0;i < numDeVuelos;i++) {
            if (vuelos[i].getId() == vueloId) {
                // vuelos[i].setNumDePasajeros(vuelos[i].getNumDePasajeros() +1);
                // int index = vuelos[i].getNumDePasajeros() - 1;
                Pasajero temp(nombre, salida, destino,id, vueloId);
                vuelos[i].addPasajero(temp);
            }
        }
    }
    cout << "Pasajeros cargados con exito" <<  endl;
    data.close();
}
//Agrega un vuelo y regresa un booleano indicando si tuvo exito o no
bool agregarVuelo(Vuelo vuelos[], int &numDeVuelos) {
    string destino;
    string salida;
    int vueloId, h, m, duracion;
    cout << "Ingrese codigo IATA de salida: ";
    cin >> salida;
    cout << endl;
    cout << "Ingrese codigo IATA del destino: ";
    cin >> destino;
    cout << "Ingrese ID, hora de salida, minutos de salida y duracion todo separado por espacios: ";
    cin >> vueloId>> h >> m >> duracion;
    cout << endl;
    bool idUnico = true;
    for (int i = 0; i< numDeVuelos; i++) {
        if (vuelos[i].getId() == vueloId) {
            idUnico = false;
        }
    }
    if (idUnico) {
        numDeVuelos++;
        Vuelo nuevoVuelo;
        nuevoVuelo.setDestino(destino);
        nuevoVuelo.setDuracion(duracion);
        nuevoVuelo.setSalida(salida);
        nuevoVuelo.setId(vueloId);
        nuevoVuelo.setTiempoSalida(Tiempo(h,m));
        vuelos[numDeVuelos - 1] = nuevoVuelo;
        return true;
    }
    //no llega aqui en si el ID es unico
    return false;
}

bool agergaPasajero(Vuelo vuelos[], int numDeVuelos) {
    cout << endl;
    string nombre, salida, destino;
    int id, vueloId;
    cout << "Ingrese el nombre del pasajero: ";
    cin >> nombre;
    cout << endl;
    cout << "Ingrese ID unico de pasajero, seguido de un espacio y el ID del vuelo: ";
    cin >> id >> vueloId;
    cout << endl;
    for (int i = 0;i<numDeVuelos; i++) {
        cout << vuelos[i].getId() << endl;
        if (vuelos[i].getId() == vueloId) {
            bool idUnico = true;
            for (int x =0;x < vuelos[i].getNumDePasajeros();x++) {
                if (vuelos[i].getPasajero(x).getId() == id) {
                    idUnico = false;
                }
            }
            if (idUnico) {
                int numDePasajeros = vuelos[i].getNumDePasajeros();
                //vuelos[i].setNumDePasajeros(numDePasajeros+1);
                vuelos[i].addPasajero(Pasajero(nombre, vuelos[i].getSalida(), vuelos[i].getDestino(), 
                                        id, vueloId));
                return true;
            }
            else {
                cout << "ERROR: ID NO ES UNICO" << endl;
                return false;
            }
        }     
    }
    //En caso de exito esto no debe pasar
    return false;
}

void cargaAeropuertos(string aeropuertos[], int &numDeAeropuertos) {
    ifstream aeros;
    aeros.open("aeros.txt");
    numDeAeropuertos = 0;
    string nombre;
    while(aeros>>nombre) {
        aeropuertos[numDeAeropuertos] = nombre;
        numDeAeropuertos++;
    }
    cout << "Aeropuertos cargados exitosamente" << endl;
}

void muestraAeropuertos(string aeropuertos[],int numDeAeropuertos) {
    for (int i =0;i<numDeAeropuertos;i++) {
        cout << aeropuertos[i] << endl;
    }
}

void muestraPasajeros(Vuelo vuelo) {
    cout << "> Mostrando pasajeros del vuelo " << vuelo.getId() <<" ";
    cout << "con salida de " << vuelo.getSalida() << " " << "y destino a ";
    cout << vuelo.getDestino()<< endl;
    for (int i=0;i<vuelo.getNumDePasajeros(); i++) {
        Pasajero &ctxpasajero = vuelo.getPasajero(i);
        cout << "Nombre: " << ctxpasajero.getNombre() << " | ";
        cout << "ID: " << ctxpasajero.getId() << " | ";
        cout << "ID de vuelo: " << ctxpasajero.getVueloId() << endl;
    }
    cout << "-------------------------" << endl;
}
//Muestra datos de los vuelos
void muestraVuelos(Vuelo vuelos[], int numDeVuelos) {
    for (int i=0;i<numDeVuelos;i++) {
        cout << "Destino: " << vuelos[i].getDestino() << " | ";
        cout << "Salida: " << vuelos[i].getSalida() << " | ";
        cout << "Id :" << vuelos[i].getId() << " | ";
        cout << "Tiempo de salida: "<< vuelos[i].getTiempoSalida().getHora() << ":";
        cout << vuelos[i].getTiempoSalida().getMin() << " | ";
        cout << "Duracion (minutos): " << vuelos[i].getDuracion() << " | ";
        cout << "Numero de pasajeros: " << vuelos[i].getNumDePasajeros() << endl;
    }
}
int getNumDeVuelos() {
    ifstream file;
    file.open("vuelos.txt");
    string line;
    int numOfVuelos = 0;
    while(getline(file,line)) {
        numOfVuelos++;
    }
    return numOfVuelos;
}
//Carga los datos de los vuelos a la lista
void cargaDatosVuelos(Vuelo vuelos[], int &numDeVuelos) {
   
   ifstream archivo;
   string salida;
   string destino;
   int hora, minuto;
   int duracion;
   int id;
   archivo.open("vuelos.txt");
   int i=0;
    while (archivo>>salida>>destino>>duracion>> id >> hora >> minuto) {
        vuelos[i].setDuracion(duracion);
        vuelos[i].setDestino(destino);
        vuelos[i].setId(id);
        vuelos[i].setSalida(salida);
        vuelos[i].setTiempo(hora,minuto);
        i++;
    }
    numDeVuelos = i;
    cout << "Numero de vuelos: " <<  numDeVuelos << endl;
    cout << "Datos de vuelos cargados" << endl;
    archivo.close();
}

bool agregaAeropuerto(string aeropuertos[], int numDeAeropuertos) {
    cout << "Ingrese nuevo codigo IATA: ";
    string input;
    cin >> input;
    for (char x : input) {
        x = toupper(x);
    }
    cout << "Su entrada fue: "<< input << endl;
    for (int i = 0;i<numDeAeropuertos; i++) {
        bool codigoUnico = true;
        if (aeropuertos[i] == input) {
            codigoUnico = false;
        }
        if (codigoUnico) {
            numDeAeropuertos++;
            aeropuertos[numDeAeropuertos - 1] = input;
            return true;
        }
        else {
            return false;
        }
    } return false;
}

int main() {

    int numDeVuelos = 0;
    Vuelo vuelos[30];
    string aeropuertos[40];
    int numDeAeropuertos = 0;
    cargaDatosVuelos(vuelos, numDeVuelos);
    cargaDatosPasajeros(vuelos, numDeVuelos);
    cargaAeropuertos(aeropuertos,numDeAeropuertos);
    cout << "Ingrese una de las siguientes opciones: " << endl;
    char input;
    //MAIN LOOP
    do {
        cout << "num de vuelos: " << numDeVuelos << endl;
        cout << "a) Mostrar vuelos | b) Agregar vuelos | ";
        cout << "c) Mostrar pasajeros | d) Agregar pasajero a un vuelo "<< endl;
        cout << "e) Mostrar aeropuertos | f) Agregar aeropuerto | " <<  "q) Salir del programa" << endl;
        cout << "> ";
        cin >> input;
        switch(input) {
            case 'a':
                muestraVuelos(vuelos,numDeVuelos);
                break;
            case 'b':
                if (agregarVuelo(vuelos, numDeVuelos)) {
                    cout << "Vuelo agregado!" << endl;
                }
                else {
                    cout << "No se pudo agregar el vuelo" << endl;
                }   
                break;
            case 'c':
                for (int i = 0;i<numDeVuelos;i++) {
                    muestraPasajeros(vuelos[i]);
                }
                break;
            case 'd':
                if (agergaPasajero(vuelos,numDeVuelos)) {
                    cout << "Pasajero agregado exitosamente" << endl;
                }
                else {
                    cout << "Error, no se pudo agregar el pasajero" << endl;
                }
                break;
            case 'e':
                muestraAeropuertos(aeropuertos,numDeAeropuertos);
                break;
            case 'f':
                if(agregaAeropuerto(aeropuertos,numDeAeropuertos)) {
                    cout << "Aeropuerto agregado exitosamente" << endl;
                }
                else {
                    cout << "Error, no se pudo agregar aeropuerto" << endl;
                }
                break;
            }
    } while(input != 'q');
    return 0;
}