#include "funciones.h"


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
                while (claveG!=clave) {
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
                            return "salir";
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
void escribir(string info, string ar){
    ofstream archivo2(ar);
    archivo2<<info<<endl;
    archivo2.close();

}
void newmovie()                     //agregar nueva pelicula
{
    string peliculas=lectura("peliculas.txt");
    int I=5;
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
    getline(cin,nombre);
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
     if(false)flag=1;                                         //validar si la sala esta ocupada a esa hora
    else{
        flag=0;
    }

    }
    parte=parte+sala+'/'+hora+" | ";
    cout<<"ingrese tipo de sala:"<<endl;
    cin>>tipsalas;
    sillas="140";
    parte=parte + '0'+'/'+sillas+" | ";
    cout<<"ingrese clasificacion: "<<endl;
    cin>>clasif;
    parte=parte + clasif;
    peliculas += parte;
    escribir(peliculas,"peliculas.txt");
}
