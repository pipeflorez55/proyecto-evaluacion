#include "cine.h"
pelicula c;
void cine::agregar(string pelicul){
    char *num=&pelicul[0];
    int b=atoi(num);
    ff.insert(pair<int, pelicula>(b,a)); // creo la clave del ID de la pelicual y creo su objeto dentro del map
    r=ff.find(b);

    r->second.agregarp( pelicul);

}

void cine::seleasiento(int sele3,string *vents)
{
    r=ff.find(sele3);       //llevar al iterador el iD de la pelicula
    r->second.seleasiento( vents); //entro en la pelicula para  bscar el asiento
}

void cine::visualizar()
{
    r=ff.find(1);
    cout<<r->first<<endl;

}

bool cine::validh(int d, int s, int h)
{

  for(r=ff.begin();r!=ff.end();r++){        // itero entre todas las peliculas en el map
       if(r->second.validh(d,s,h)){
           return true;

       }

    }
  return false;


}
