#include "cine.h"
void cine::agregar(string pelicul){
    char *num=&pelicul[0];
    int b=atoi(num);
    ff.insert(pair<int, pelicula>(b,a));
    r=ff.find(b);

    r->second.agregarp( pelicul);

}

void cine::visualizar()
{
    r=ff.find(1);
    cout<<r->first<<endl;
}

bool cine::validh(int d, int s, int h)
{

  for(r=ff.begin();r!=ff.end();r++){
       if(r->second.validh(d,s,h)){
           return true;

       }

    }
  return false;


}
