/* En el programa main debes:
1) Pedir al usuario el título de la película disponible
2) Crear un objeto de tipo SalaCine con el título dado y con 50 lugares disponibles
3) Luego en una repetición se debe hacer lo siguiente:
   - mostrar los datos de la película disponible (usando el método muestra de la sala)
   - preguntar al usuario cuantos boletos quiere
   - llamar al método correspondiente para hacer la reservación; en caso de que no haya suficientes boletos, mostrar el mensaje "No hay suficientes boletos"
   - preguntar si quiere hacer otra reservación
   - leer la clave (s o n) y repetir el proceso solamente si el usuario contesta s
4) Cuando el usuario ya no quiera repetir el proceso el programa debe mostrar por última vez los datos de la sala de cine usando el método muestra.
*/ 
#include <iostream>
#include <string>
#include "SalaCine.h"
using namespace std;

int main ()  {
	string titulo;
	int cantBoletos;
	bool hayBoletos;
	char resp;
	
	//cout << "Pelicula disponible ";
	getline(cin, titulo);
	
	// Crea el objeto de tipo SalaCine
    SalaCine cine;
    cine.setTitle(titulo);
    do	{
        // muestra la información de la película llamando al método muestra
		cine.muestra();
		//cout << "Cuantos boletos? ";
		cin >> cantBoletos;
		
        
        // realiza la reservación llamando al método reserva
        if (!cine.reserve(cantBoletos)) {
            cout << "No hay suficientes boletos" << endl;
        }
        // si se puede reservar no muestres nada
        // si no se puede reservar muestra el mensaje "No hay suficientes boletos"
		
		//cout << " otra reservacion? ";
		cin >> resp;		
	}while (resp == 's');
	
    // muestra la información de la película llamando al método muestra
    cine.muestra();
   
    return 0;
}