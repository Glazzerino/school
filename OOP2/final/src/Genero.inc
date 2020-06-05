#pragma once
#include <string>
const unsigned int MAX_GENEROS = 5;
enum GENERO {
    DEFAULT,
    DRAMA,
    ACCION,
    MISTERIO,
    COMEDIA
};

const char* GENERO_STRING[] = {    
    "NA",
    "Drama",
    "Accion",
    "Misterio",
    "Comedia"
};

GENERO GENERO_FROM_STRING(std::string str) {
    for (int i=0; i<MAX_GENEROS; i++) {
        if (GENERO_STRING[i] == str) {
            return (GENERO) i;
        }
    }
    return GENERO::DEFAULT;
}