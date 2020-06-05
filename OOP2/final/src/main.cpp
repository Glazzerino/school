#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "PeliculaWrap.h"
#include "../externo/json.hpp" // <- lib externa usada para leer JSONs
#include <fstream>
#include <sstream>
using json = nlohmann::json;

void cargar_series(vector<Contenedor*>& series, json file) {
    for (int i = 0; i < file["series"].size(); i++) {

        series.push_back( new Serie(
                              file["series"][i]["nombre"],
                              file["series"][i]["resumen"],
                              file["series"][i]["num_episodios"],
                              file["series"][i]["num_temporadas"],
                              file["series"][i]["rating"],
                              GENERO_FROM_STRING(
                                  (string) file["series"][i]["genero"]
                              )
                          )
                        );
    }
}

void cargar_videos(vector<Contenedor*>& series, vector<Video*>& videos_temp, json file) {


    for (int i=0; i<file["episodios"].size(); i++) {
        videos_temp.push_back(new Episodio(
                                  file["episodios"][i]["nombre"],
                                  file["episodios"][i]["resumen"],
                                  file["episodios"][i]["id"],
                                  file["episodios"][i]["duracion"],
                                  file["episodios"][i]["rating"],
                                  GENERO_FROM_STRING(
                                      (string) file["episodios"][i]["genero"]
                                  ),
                                  file["episodios"][i]["serie"],
                                  file["episodios"][i]["temporada"],
                                  file["episodios"][i]["num"],
                                  false
                              ));
    }
    //ineficiente
    //agregar episodios a series
    for (int c=0; c<series.size(); c++) {
        if (!series[c]->es_pelicula()) {
            for (int x=0; x<videos_temp.size(); x++) {
                //casting para verificar si el video (episodio) pertenece a la serie
                if (!videos_temp[x]->get_es_pelicula()) {
                    if (series[c]->get_nombre() == ((Episodio *)videos_temp[x])->get_serie()) {
                        cout << (series[c]->agregar(videos_temp[x]) ? "": "Error, no se pudo agregar\n");
                    }

                }
            }
        }
    }
    //carga de peliculas
    for (int x=0; x<file["peliculas"].size(); x++) {

        videos_temp.push_back( new Pelicula(
                                   file["peliculas"][x]["nombre"],
                                   file["peliculas"][x]["resumen"],
                                   file["peliculas"][x]["id"],
                                   file["peliculas"][x]["duracion"],
                                   file["peliculas"][x]["rating"],
                                   GENERO_FROM_STRING(
                                       (string)file["peliculas"][x]["genero"]
                                   ),
                                   file["peliculas"][x]["oscar"],
                                   file["peliculas"][x]["saga"],
                                   true //es peli
                               ));
    }
    // agregar peliculas a contenedores
}

int main() {
    ifstream file;
    vector<Video*> videos;
    vector<Contenedor*> series;
    file.open("data/datos.json");
    stringstream file_contents;
    char c;
    while(file.get(c)) {
        file_contents << c;
    }
    json parsed_file = json::parse(file_contents.str());

    cargar_series(series, parsed_file);
    // series[2]->imprimir();
    cargar_videos(series,videos, parsed_file);
    // cout << parsed_file["episodios"].size() << endl;
    // int sum =0;
    // cout << videos.size() << endl;
    // for (int i=0; i < videos.size(); i++) {
    //         if (videos[i]->get_es_pelicula()) {
    //             // sum++;
    //             cout << "Dawdawd"<< endl;
    //             videos[i]->imprimir();
    //         }
    // }
    // cout << sum;
    char input;
    do {
        cout << "\n\n";
        cout << "a) Mostrar películas\n";
        cout << "b) Mostrar lista de series\n";
        cout << "c) Mostrar videos con cierta calificación\n";
        cout << "d) Mostrar videos de cierto género\n";
        cout << "e) Mostrar episodios de una serie\n";
        cout << "f) Mostrar películas con cierta calificación\n";
        cout << "g) Salir del programa\n";
        cout << "\n"<<"\n";
        cout << "Entrada: ";

        cin >> input;
        cout << "\n\n";
        switch(input) {
        case 'a': {
            for (int x=0; x<videos.size(); x++) {
                if (videos[x]->get_es_pelicula()) {
                    videos[x]->imprimir();
                    cout << "\n";
                }
            }
            break;
        }
        case 'b':
    {   for (int x=0; x<series.size(); x++) {
                series[x]->imprimir();
            }
            break;
        }
        case 'c': {
            double calif_min;
            cout << "Ingrese calificación mínima\n";
            cin >> calif_min;
            cout << "Calificación mínima: " << calif_min << endl;
            for (int x=0; x<videos.size(); x++) {
                if (videos[x]->get_rating() >= calif_min) {
                    videos[x]->imprimir();
                }
            }
            break;
        }
        case 'd': {
            cout << "Ingrese género de filtro\n";
            unsigned int genero_filtro;
            for (int g=1; g<MAX_GENEROS; g++) {
                cout << g << ")" << GENERO_STRING[g] << endl;
            }
            do {
                cout << "Selección: ";
                cin >> genero_filtro;
            } while(genero_filtro > MAX_GENEROS);

            for (int i=0; i<videos.size(); i++) {
                if (videos[i]->get_genero() == genero_filtro) {
                    videos[i]->imprimir();
                }
            }
            break;
        }
        case 'e': {
            cout << "Desplegando series: \n" ;
            unsigned int seleccion_serie;
            for (int c=0; c<series.size(); c++) {
                cout << c+1<<")" << series[c]->get_nombre() << endl;
            }
            do {
                cin >> seleccion_serie;
            } while(seleccion_serie > series.size());
            int seleccion_size = series[seleccion_serie]->get_contenido().size();
            for (int c=0; c<seleccion_size; c++) {
                series[seleccion_size - 1]->get_contenido()[c]->imprimir();
            }
            break;
        }
        case 'f': {
            double calif_min;
            cout << "Ingrese calificación mínima\n";
            cin >> calif_min;
            cout << "Calificación mínima: " << calif_min << endl;
            for (int c=0; c<videos.size(); c++) {
                if (videos[c]->get_es_pelicula() && videos[c]->get_rating()>=calif_min) {
                    videos[c]->imprimir();
                }
            }
            break;
        }
        }
    } while(input != 'g');
}


