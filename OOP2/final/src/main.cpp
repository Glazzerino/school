#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "PeliculaWrap.h"
#include "../externo/json.hpp" // <- lib externa usada para leer JSONs
#include <fstream>
#include <sstream>
using json = nlohmann::json;
int main() {
    ifstream file;
    vector<Serie> series;
    file.open("data/videos.json");
    stringstream file_contents;
    char c;
    while(file.get(c)) {
        file_contents << c;
    }
    // cout << file_contents.str() << endl;
    json test = json::parse(file_contents.str());
    cout << (string)test["series"][0]["nombre"] << endl;
    
}

// void cargar_series(vector<Serie>& series, json file) {
//     for (int i = 0; i < )
// }