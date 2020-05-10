#include <iostream>
#include<string>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <map>

using namespace std;

class pelicula{ //Prototipo de la clase, es decir, la forma que tiene la clase
    public:
    void agregarp (string pelicul);
    bool validh(int d,int s,int h);

    private:
    string nombre,clase,genero;
    int sala,hora,duracion,disponibles,sillas;
    int ID;


};
