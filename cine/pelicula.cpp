#include "pelicula.h"

void pelicula::agregarp(string pelicul)     // llenar ls variables de la pelicula
{
    string num;
     int nume;
    int tm=pelicul.length();
    for(int j=0;j<tm;j++){
        if(pelicul[j]!=' '){
             num +=pelicul[j];
        }
        else{
             nume=  std::atoi(num.c_str());

        }
    }
    ID=nume;   //guardo el ID
    int cnt=0;               // lo uso par saber  en que parte del archivo esta por ejemplo sla , genero ,etc
    string name,gen,dur,salat,dis,cl;
    int tam=pelicul.length();
    for(int i=0;i<tam-1;i++){      // itero en el tamaño del  string
        if(pelicul[i]=='|'){   // aumento contador a cambiar de lugar despues de |
            cnt+=1;
        }
        if(cnt==1){
            if(pelicul[i]!='|'){
            name +=pelicul[i];    // guardo el nombre
            }
        }
        if(cnt==2){
            if(pelicul[i]!='|'){

            gen+=pelicul[i];      // guardo genero
            }

        }
        if(cnt==3){
            if(pelicul[i]!='|'&&pelicul[i]!='m' &&pelicul[i]!='i' &&pelicul[i]!='n'){  // le quito el min
          dur+=pelicul[i];       // guardo duracion
            }
        }
        if(cnt==4){
            if(pelicul[i]!='|'){

           salat+=pelicul[i];   // guardo sala
            }
        }
        if(cnt==5){
            if(pelicul[i]!='|'){

            dis+=pelicul[i];    // guardo asientos
            }
        }
        if(cnt==6){
            if(pelicul[i]!='|'){

           cl+=pelicul[i];    //guardo clase
            }
        }

    }

    nombre=name; // llevo el nombre a la pelicula
    genero=gen;  // llevo el genero a la pelicula
     string w;
     int q=(dur.length()-1);
    for(int i=1;i<q;i++){
            w+=dur[i];  // saco solo los numeros de duracion
    }
    duracion = std::atoi(w.c_str());  // los convierto en entero y se los paso a pelicula

    string sal,hour;
    q=salat.length();
    int star=0;
    for(int i =1;i<q;i++){  // separo la sala y hora

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

            if(dis[i]=='/'){
                star=1;

            }
            if(star==0){
                if(dis[i]!=' '){
                sd+=dis[i];
                }
            }
            if(star==1){
                if(dis[i]!=' ' && dis[i]!='/'){
                s+=dis[i];
                }
            }
         disponibles = std::atoi(sd.c_str());
         sillas= std::atoi(sd.c_str());
         clase=cl;
         genvector(ID);
         if(sillas==50){
             char letra='A';
             vector<int> sill;
             for(int i=0;i < 5;i++){
                 ss.insert(pair<char, vector<int>>(letra,sill));
                 letra ++;
               }
             for(rs=ss.begin();rs!=ss.end();rs++){
             for (int i=1; i<=10; i++)rs->second.push_back(i);
             }


         }

    }
    }
}

bool pelicula::validh(int d, int s, int h)   // valido si la hora y sala estan disponibles para una pelicula
{
    if(sala==s){ // comparo sala
        int u=duracion/60+1;
        if((h+d)>=(hora)&&(h+d)<=(hora+u)){// si la sala es igual debo mirar si hora y duracion se solapan con un margen de una hora mas para arreglar la sala
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
void pelicula::genvector(int Y){       // crear vector de asientos disponibles
    std::string s = std::to_string(Y);
    s +=".txt";
    string info=lectura(s);
    string fila;
    int tam=info.length();
    int flg=0;
    char A='A';
    vector<int> sill;
    for(int i=0;i<tam;i++){
        if(info[i]=='\n'){
            flg=1;
            ss.insert(pair<char,vector<int>>(A,sill)); //se crea en el map la clave de la fila y el vector dentro
        }
        if(flg==0){
            if(info[i]!=' '&&info[i]!='\n'&&info[i]!='/'){   // lleno el vector con los asientos disponibles
                int o =atoi(&info[i]);
               sill.push_back(o);
            }

         }
        if(flg==1){
             sill.erase (sill.begin(),sill.begin()+sill.size());  // inicialiso el vector
             A++;
            flg=0;
        }

    }

}
void pelicula::visuasientos(){                 // muestro la sala
    cout<<"       PANTALLA      \n\n";
    std::string s = std::to_string(ID);
    s +=".txt";
    string tr=lectura(s);                     // abro el archivo de asientos del ID respectivo
    char a='A';

    int tm=tr.length();
    cout<<a<<" ";
    for(int i=0;i<tm-1;i++){                     // grafico la fila correspondiente con las sillas de ella
        if(tr[i]=='\n'){

            a++;

            cout<<endl<<a<<" ";
        }

        if(tr[i]!='\n'){
          cout<<tr[i];
        }
    }
    cout<<endl;
}
void pelicula::seleasiento()
{

        visuasientos();         // muestro asientos
        int flg=0,num;
        char fila;
        while(flg==0){
        cout<<"ingrese la fila: "<<endl;
        cin>>fila;
        fila=toupper(fila);
        cout<<"ingrese numero de la sillas:"<<endl;
        cin>>num;
        if(valas(fila,num)){            // valido si estan disponibles
          cout<<"asiento no disponible "<<endl;

        }
        else{
            flg=1;
        }
       }



}
string pelicula::lectura(string ar){
    string palabra;
    ifstream archivo(ar);
    while(!archivo.eof()){              //leer y guardarhasta encontrar caracter fin de texto
    char a=archivo.get();
     if(!archivo.eof()){
    palabra=palabra+a;                  // guardarlo en un string
     }
    }
    archivo.close();
    return  palabra;
}

bool pelicula::valas(char a,int num){     // validar y reserva asiento en una pelicula
        rs=ss.find(a);                  // encuentro la fila
        if(rs!=ss.end()){
        int tam= rs->second.size();      // el tamaño del vector
        for(int i=0;i<tam;i++){         // itero dentro del vector
            if(num==rs->second[i]){     // verifico si tengo el numero de asiento disponible
                rs->second.erase(rs->second.begin()+(i-1));   //si esta lo borro del vector
                std::string s = std::to_string(ID);            // consigo el ID de la pelicula
                s +=".txt";
                string info=lectura(s);                         // leo el archivo de asientos de esa pelicula
                int c=pos( a, num);                             // encuentro la posicion de ese asiento
                info.replace(c,1,"/");                          // lo remplazo por  el simbolo de silla ocupada (/)
                disponibles --;                                 // le resto uno a las sillas disponibles
                escribirR(info,s);                              // y lo escribo en el archivo

                return false;
            }
        }
        }
        else{
            return true;
        }

}

int pelicula::pos(char a,int num){     // saber la posicion del asiento deseado dentro del string
    int t;

    int j=a-'A';
    j=j*20;
        switch(num){
        case 0:
            t=j+0;
            break;
        case 1:
            t=j+2;
            break;
        case 2:
            t=j+4;
            break;
        case 3:
            t=j+6;
            break;
        case 4:
            t=j+8;
            break;
        case 5:
            t=j+10;
            break;
        case 6:
            t=j+12;
            break;
        case 7:
            t=j+14;
            break;
        case 8:
            t=j+16;
            break;
        case 9:
            t=j+18;
            break;

        }
        return  t;

}
void pelicula::escribirR(string info,string ar){   // funcion de escrbir dentro de pelicula p

    ofstream archivo2(ar);
    archivo2<<info;
    archivo2.close();
}







