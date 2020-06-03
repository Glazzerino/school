#include <string>

enum GENERO {
    DEFAULT,
    DRAMA,
    ACCION,
    MISTERIO,
    COMEDIA
};

class Video {
private:
    Video();
    Video(std::string, std::string ,std::string, int, int, double, GENERO);

    std::string get_nombre(){return nombre;};
    void set_nombre(std::string nombre){this->nombre = nombre;};

    std::string get_estudio(){return estudio;};
    void set_estudio(std::string s){this->estudio=s;};

    std::string get_resumen(){return resumen;};
    void set_resumen(std::string res){resumen=res;};

    GENERO get_genero(){return genero;};
    void set_genero(GENERO gen){genero=gen;};

protected:
    double rating;
    std::string nombre, resumen, estudio;
    GENERO genero;
    int id, duracion;

};