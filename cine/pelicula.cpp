#include "pelicula.h"


void pelicula::agregarp(string pelicul)
{
    ID=atoi(&pelicul[0]);
    int cnt=0;
    string name,gen,dur,salat,dis,cl;
    int tam=pelicul.length();
    for(int i=0;i<tam-1;i++){
        if(pelicul[i]=='|'){
            cnt+=1;
        }
        if(cnt==1){
            if(pelicul[i]!='|'){
            name +=pelicul[i];
            }
        }
        if(cnt==2){
            if(pelicul[i]!='|'){

            gen+=pelicul[i];
            }

        }
        if(cnt==3){
            if(pelicul[i]!='|'&&pelicul[i]!='m' &&pelicul[i]!='i' &&pelicul[i]!='n'){
          dur+=pelicul[i];
            }
        }
        if(cnt==4){
            if(pelicul[i]!='|'){

           salat+=pelicul[i];
            }
        }
        if(cnt==5){
            if(pelicul[i]!='|'){

            dis+=pelicul[i];
            }
        }
        if(cnt==6){
            if(pelicul[i]!='|'){

           cl+=pelicul[i];
            }
        }

    }

    nombre=name;
    genero=gen;
     string w;
     int q=(dur.length()-1);
    for(int i=1;i<q;i++){
            w+=dur[i];
    }
    duracion = std::atoi(w.c_str());

    string sal,hour;
    q=salat.length();
    int star=0;
    for(int i =1;i<q;i++){

        if(salat[i]=='/'){
            star=1;

        }
        if(star==0){
            if(salat[i]!=' '){
            sal+=salat[i];
            }
        }
        if(star==1){
            if(salat[i]!=' ' && salat[i]!='/'){
            hour+=salat[i];
            }
        }
        sala = std::atoi(sal.c_str());
        hora= std::atoi(hour.c_str());
        q=dis.length();
        star=0;
        string sd,s;
        for(int i =1;i<q;i++){

            if(salat[i]=='/'){
                star=1;

            }
            if(star==0){
                if(salat[i]!=' '){
                sd+=salat[i];
                }
            }
            if(star==1){
                if(salat[i]!=' ' && salat[i]!='/'){
                s+=salat[i];
                }
            }
         disponibles = std::atoi(sd.c_str());
         sillas= std::atoi(sd.c_str());
         clase=cl;

    }
    }
}

bool pelicula::validh(int d, int s, int h)
{
    if(sala==s){
        int u=duracion/60+1;
        if((h+d)>=(hora)&&(h+d)<=(hora+u)){
            return true;
        }
        else{
            return false;

        }
    }
    else {
        return false;
    }
}




