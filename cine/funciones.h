#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H
#include <iostream>
#include <iostream>
#include<string>
#include<stdlib.h>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <limits>
#include "cine.h"

using namespace std;

string lectura(string ar);
int knowid(string info);
int IDre(string pelicula);
int tipoasiento(int IDas,string *vents);
int LocSIL(string pelicul,int *r,int *disp);
int LocPRES(string pelicul);
bool valadmin(string info);
bool valusu(string info,string *vent);
bool peliculafull(int sele3);
bool validh(string dur,string sal,string hour);
void agregarasiento();
void agregarusuario();
void madepel(string info);
void makesill(int i,int sillas);
void seleasiento(int sele3,string *vents);
void renewcartelera(int sele3);
void escribir(string info, string ar);
template<class T>
void vueltos(T a,T b);
void newmovie();
void newestreno();




