#include "funciones.h"

cine b;
string lectura(string ar){
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


bool valadmin(string info){
    string psw,admin;
    char a;
    cout<<"ingrese pasword de 4 digitos: "<<endl;
      while(psw.length()!=4){
          cin>>psw;
      }

    for(int i=0;i<4;i++){                       //iterar sobre las 4 primeras posiciones del string generador del archivo
        a=info[i];
        admin=admin+a;
    }
    if(admin==psw){
        return true;
    }
    else{
        return false;
    }

}
bool valusu(string info){
    cout<<"ingrese su cedula:  "<<endl;
     while (true) {
    long tam=info.length();
    char a;
    int s=-1;
    string parte,cedula,claveG,clave="";
    cin>>cedula;
    for(int i=0;i<tam;i++){                                           //iterar sobre el archivo de login
        a=info[i];
        if(a==','){                                                   //identificar los separadores de informacion
            s=-1;
            if(parte==cedula){
                cout<<"usuario valido"<<endl;
                for(int j=(i+1);j<(i+5);j++){
                    char b=info[j];
                    claveG +=b;
                    int p=j;
                }
                while (claveG!=clave) {             //comparar si es la correcta
                    cout<<"ingrese su clave 4 digitos: "<<endl;
                    cin>>clave;
                    if(clave==claveG){
                        cout<<"acesso concedido"<<endl;
                        return true;

                    }
                    else{
                        char op;
                        cout<<"Pasword incorrecta"<<endl;
                        cout<<"desea volver a intentar s/n :  "<<endl;
                        cin>>op;
                        if(op=='n'){
                            return false;
                        }
                    }

                }
            }
        }
        if(s==1){
            parte =parte+a;
        }
        if(a=='\n'){                //identificar salto de linea para reiniciar variables y comparar siguiente ususario
            s=1;
        }

    }
    cout<<"Cliente no encontrado"<<endl;
    cout<<"desea intentar otra vez s/n"<<endl;
    char again='e';
    while(again!='s' && again!='n'){
        cin>>again;
    }
    if(again=='n'){
        cout<<"ingreso fallido"<<endl;
        return false;
    }
    cout<<"Vuelva a ingresar cedula:  "<<endl;
    }
}
void escribir(string info, string ar){    //escribir una iformacion en un archivo deseado
    ofstream archivo2(ar);
    archivo2<<info<<endl;
    archivo2.close();

}
void newmovie()                     //agregar nueva pelicula
{
    string peliculas=lectura("peliculas.txt");
    madepel(peliculas);
    int I=knowid(peliculas);
    int flag=1;
    int duracion;
    char ID[1];
    int tipsalas;
    string nombre,genero,duracions,sala,hora,sillas,clasif;
    string parte;
    I+=1;
    itoa(I,ID,10);
    parte = parte + ID+" | ";
    cout<<"ingrese el nombre de la pelicula:"<<endl;
    cin.ignore();
    getline(cin,nombre);                                                               // poder ingresar un nombre largo con espacios uso getline con ignore para borrar el buffer
    parte = parte + nombre+" | ";
    cout<<"ingrese el genero de la pelicula:"<<endl;
    cin>>genero;
    while ( getchar ( ) != '\n' ) ;
    parte = parte + genero+" | ";
    cout<<"ingrese la duracion(min) de la pelicula:"<<endl;
    cin>>duracion;
   duracions=to_string(duracion);
    parte = parte + duracions+ " min"+" | ";
    while(flag==1){
    cout<<"ingrese la sala de la pelicula:"<<endl;
    cin>>sala;
    cout<<"ingrese la hora de la pelicula(sistema 24hrs):"<<endl;
    cin>>hora;
     if(validh(duracions,sala,hora))flag=1;                                         //validar si la sala esta ocupada a esa hora
    else{
        flag=0;
    }

    }
    parte=parte+sala+'/'+hora+" | ";
    cout<<"ingrese tipo de sala:"<<endl;
    cout<<"tipo 1= 50 sillas  \ntipo 2 = 140 sillas \n tipo 3= 100 sillas"<<endl;
    cin>>tipsalas;
    switch (tipsalas) {                                                         // seleccionar entre unas salas ya prediseñadas
     case 1:
        sillas="50";
        break;
    default:
        sillas="140";
        break;
     case 3:
        sillas="100";
        break;
    }

    parte=parte + sillas+'/'+sillas+" | ";
    cout<<"ingrese clasificacion: "<<endl;
    cin>>clasif;
    parte=parte + clasif;
    peliculas += parte;
    madepel(peliculas);
    int z;
     z = std::atoi(sillas.c_str());
    makesill(I,z);
    escribir(peliculas,"peliculas.txt");

}

int knowid(string info){                    // saber el ultimo ID creado en la cartelera para no repetirlo
    int tam = info.length();
    for(int i=(tam-2);i>0;i--){             // comienzo a iterar desde el ultimo enter  hasta el siguiente
        if(info[i]=='\n'){                  // le sumo uno asi consigo el ultimo ID y lo guardo para retornar
            char *a= &info[i+1];
            int b=atoi(a);
            return  b;
        }
    }
    return 0;
}

bool validh(string dur,string sal,string hour){
     int d= std::atoi(dur.c_str());
     int s= std::atoi(sal.c_str());
     int h= std::atoi(hour.c_str());
     d=(d/60)+1;
     return b.validh(d,s,h);


}

void madepel(string info){

    int tam=info.length();
    string pelicula;
    for(int i=0;i<tam;i++){
        if(info[i]!='\n'){
        pelicula+=info[i];
        }
        if(info[i]=='\n'){
         b.agregar(pelicula);
         pelicula="";
       }

    }
}

void makesill(int i,int sillas){      // crear archivo de sillas  reservadas en una NUEVA pelicula
    std::string s = std::to_string(i);  // consigo su ID
    s +=".txt";
    string info;
    int filas=sillas/10;
    for(int k=0;k<filas;k++){           //creo las filas necesarias para el total de asientos
        for(int j=1;j<=10;j++){         // reparto 10 sillas en cada fila
            std::string u = std::to_string(j);
            info += u;
            info += " ";
        }
        info += "\n";
    }

    ofstream archivo2(s);

    archivo2<<info;
    archivo2.close();

}


void seleasiento(int sele3)
{
    b.seleasiento( sele3);
}
