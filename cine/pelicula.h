#include <iostream>
#include<string>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <fstream>



using namespace std;

class pelicula{ //Prototipo de la clase, es decir, la forma que tiene la clase
    public:
    bool valas(char a,int num);
    int pos(char a,int num);
    void agregarp (string pelicul);
    bool validh(int d,int s,int h);
    void seleasiento(string *vents);
    void makesill(int i);
    void escribirR(string info,string ar);
    void genvector(int Y);
    void visuasientos();
    string codifica2(string palabra);
    string decodifica2(string palabra);
    string lectura(string ar);

    private:

    string nombre,clase,genero;
    int sala,hora,duracion,disponibles,sillas;
    int ID;
    map <char,vector<int> > ss;
    map <char,vector<int>>::iterator rs;

};
