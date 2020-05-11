#include <iostream>
#include<string>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <map>
#include "pelicula.h"
using namespace std;

class cine{ //Prototipo de la clase, es decir, la forma que tiene la clase
    public:

    void agregar(string pelicul);
    void seleasiento(int sele3);
    void visualizar();
    bool validh(int d,int s,int h);

    private:
    map <int, pelicula> ff;
    map <int, pelicula>::iterator r;
    pelicula a;

};
