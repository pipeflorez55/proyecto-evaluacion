#include "funciones.h"

cine b;
string lectura(string ar){
    string palabra;
    string t="../archivo/";
    ar=t+ar;
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
bool valusu(string info,string *vent){
    string parte,cedula,claveG,clave="";
    int pol=-1;
    while (pol!=1 &&pol!=0) {     // sistema de mebresia para una funcionalidad de puntos no implementada
   cout<<"Si tiene usuario marque 1, si no marque 0 para entrar como invitado"<<endl;
   cin>>pol;
    }
    if(pol==1){
    cout<<"ingrese su cedula:  "<<endl;
     while (true) {
    long tam=info.length();
    char a;
    int s=-1;
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

                }
                while (claveG!=clave) {             //comparar si es la correcta
                    cout<<"ingrese su clave 4 digitos: "<<endl;
                    cin>>clave;
                    if(clave==claveG){
                        cout<<"acesso concedido"<<endl;
                        *vent=*vent+cedula+" | ";

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
    else{
        cout<<"ingreso como invitado"<<endl;
        cedula="invitado";
        cedula=cedula+" | ";
        *vent=*vent+cedula;
        return true;


    }
}
void escribir(string info, string ar){    //escribir una iformacion en un archivo deseado
    string t="../archivo/";
    ar=t+ar;
    ofstream archivo2(ar);
    archivo2<<info<<endl;
    archivo2.close();

}
void newmovie()                     //agregar nueva pelicula
{
    string peliculas=lectura("peliculas.txt");
    madepel(peliculas);                // uso la funcion para crear los contenedores de las peliculas
    int I=knowid(peliculas);          // uso la funcion creada para saber mi ultimo ID
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
    int z;
     z = std::atoi(sillas.c_str());
    makesill(I,z);
    madepel(peliculas);
    escribir(peliculas,"peliculas.txt");

}

int knowid(string info){                   // saber el ultimo ID creado en la cartelera para no repetirlo
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

bool validh(string dur,string sal,string hour){   // validar hora disponible
     int d= std::atoi(dur.c_str());
     int s= std::atoi(sal.c_str());
     int h= std::atoi(hour.c_str());
     d=(d/60)+1;
     return b.validh(d,s,h);


}
void agregarasiento(){  // agregar un nuevo tipo de asiento
    string asientos=lectura("asientos.txt");   // cargo el string
    string nombre;
    string costo;
    int id=knowid(asientos);       // utilizo mi funcion para saber cual es el ultimo id usado
     id ++;
     string ids=to_string(id);
     cout<<"ingrese nombre del asiento"<<endl;
     cin.ignore();
     getline(cin,nombre);
     cout<<"ingrese el costo"<<endl;
     int caso=0;
     cin>>costo;
     int tam=costo.length();
     while(caso!=1){
     for(int i=0 ; i<tam;i++){
         char j=costo[i];
         if(j!='0'&& j!='1'&& j!='2'&& j!='3'&& j!='4'&& j!='5'&& j!='6'&& j!='7'&& j!='8'&& j!='9'){
             caso=0;
             break;
         }
         else{
             caso=1;
         }
     }
     if(caso==0){
         cout<<"Ingrese saldo del cliente (Recuerde que deben ser solo números): "<<endl;
         cin>>costo;
          tam=costo.length();
     }
     }

     asientos=asientos+ids+" | "+nombre+" | $"+costo;
     escribir(asientos,"asientos.txt");
}
void madepel(string info){        // crea el cine y agregos las peliculas (en resumen paso lo del archivo a los contenedores y logica del programa)

    int tam=info.length();
    string pelicula;
    for(int i=0;i<tam;i++){         // separo cada lines (pelicula) para ir agregandola
        if(info[i]!='\n'){
        pelicula+=info[i];
        }
        if(info[i]=='\n'){
         b.agregar(pelicula);      // uso la funcion del cine para agregarla al objeto
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
        for(int j=0;j<=9;j++){         // reparto 10 sillas en cada fila
            std::string u = std::to_string(j);
            info += u;
            info += " ";
        }
        if(k!=filas-1){
        info+='\n';
        }

    }
    escribir(info,s);

}
template<class T>
void vueltos(T a,T b){
    T num=b-a;
    int cnt;
    if(num==0){
        cout<<endl<<"Completo"<<endl;
    }
    else{
    cnt=num/50000;                      // hago las divisiones enteras para saber cuanto de cad billetes y monedas toca devolver
    cout<<"BILLETES"<<endl;
     cout<<"50000: "<<cnt<<endl;
     num=num-50000*cnt;
     cnt=num/20000;
     cout<<"20000: "<<cnt<<endl;
     num=num-20000*cnt;
     cnt=num/10000;
     cout<<"10000: "<<cnt<<endl;
     num=num-10000*cnt;
     cnt=num/5000;
     cout<<"5000: "<<cnt<<endl;
     num=num-5000*cnt;
     cnt=num/2000;
     cout<<"2000: "<<cnt<<endl;
     num=num-2000*cnt;
     cnt=num/1000;
     cout<<"MONEDAS"<<endl;
     cout<<"1000: "<<cnt<<endl;
     num=num-1000*cnt;
     cnt=num/500;
      cout<<"500: "<<cnt<<endl;
     num=num-500*cnt;
     cnt=num/200;
     cout<<"200: "<<cnt<<endl;
     num=num-200*cnt;
     cnt=num/100;
     cout<<"100: "<<cnt<<endl;
     num=num-100*cnt;
     cnt=num/50;
    cout<<"50: "<<cnt<<endl;
     num=num-50*cnt;
     cout<<"para las donaciones";
      cout<<cnt<<endl;

    }

   // cout<<endl<<"sus vueltos son: "<<vueltos<<endl;

}

void seleasiento(int sele3,string *vents)
{
    if(peliculafull( sele3)){
        cout<<"pelicula esta full"<<endl;
    }
    else{
    b.seleasiento( sele3,vents);   //seleciono el asiento dentro del objeto pelicula
    renewcartelera(sele3);   // y renuevo la dsiponibilidad en la cartelera
    }
}
int tipoasiento(int IDas,string *vents){     // elegir tipo de siento
    string info=lectura("asientos.txt");
    int tam=info.length();
    int pres,dinerous=0;
    string pelicula,num;
    for(int i=0;i<tam;i++){
        if(info[i]!='\n'){
        pelicula+=info[i];
        }
        if(info[i]=='\n'){
        int nume=IDre( pelicula);    //conseguir ID de la linea
         if(IDas==nume){             // si coincide con la pelicula donde se compro haga..
           pres=LocPRES(pelicula);
         }
         pelicula="";
       }


    }
    string precio=to_string(pres);
   *vents=*vents+"$"+precio+" | ";
    cout<<"----------------------"<<endl<<"usted va pagar: "<<"$"<<precio<<endl<<"----------------------"<<endl;
    cout<<"ingese cantidad con la cual va a pagar:   ";
    cin>>dinerous;
    while (dinerous<pres) {
       cout<<"dinero insuficente"<<endl<<"ingres de nuevo cantidad: ";
       cin>>dinerous;
    }
    vueltos(pres,dinerous);

    return  IDas;
}
bool peliculafull(int sele3){
    string info=lectura("peliculas.txt");
    int tam=info.length();
    int anc,disp;
    string pelicula,num;
    for(int i=0;i<tam;i++){
        if(info[i]!='\n'){
        pelicula+=info[i];
        }
        if(info[i]=='\n'){
        int nume=IDre( pelicula);    //conseguir ID de la linea
         if(sele3==nume){             // si coincide con la pelicula donde se compro haga..
          int pos=LocSIL(pelicula,&anc,&disp);
          if(disp!=0){
             return false ;
          }
          else{
              return  true;
          }
         }
         pelicula="";
       }

    }
}
void renewcartelera(int sele3){    // cambiar sillas disponibles en la cartelera
    string info=lectura("peliculas.txt");
    int tam=info.length();
    int anc,disp;
    string pelicula,num;
    for(int i=0;i<tam;i++){
        if(info[i]!='\n'){
        pelicula+=info[i];
        }
        if(info[i]=='\n'){
        int nume=IDre( pelicula);    //conseguir ID de la linea
         if(sele3==nume){             // si coincide con la pelicula donde se compro haga..
          int pos=LocSIL(pelicula,&anc,&disp);
          int anpeli=pelicula.length();

          pos=i-(anpeli-pos);
          disp --;
          string dispo=to_string(disp);
          info.replace(pos,anc,dispo);
          ofstream archivo2("../archivo/peliculas.txt");
          archivo2<<info;
          archivo2.close();

             return ;
         }
         pelicula="";
       }

    }
}

int IDre(string pelicula){    // sacar el ID de una pelicula
    string num;
     int nume;
    int tm=pelicula.length();
    for(int j=0;j<tm;j++){
        if(pelicula[j]!=' '){ // guarde hasta encontrar el primer espacio
             num +=pelicula[j];
        }
        else{ // si se llega al espacio convertir entero y retornar
             nume=  std::atoi(num.c_str());
             return nume;
        }
    }
    return 0;
}

int LocPRES(string pelicul){    // localisar silla
    int tam=pelicul.length();
     int cnt=0;
     string dis;
    for(int i=0;i<tam;i++){      // itero en el tamaño del  string
        if(pelicul[i]=='|'){   // aumento contador a cambiar de lugar despues de |
            cnt+=1;

        }

        if(cnt==2){

            if(pelicul[i]!='|'&&pelicul[i]!=' '&&pelicul[i]!='$'){
            dis+=pelicul[i];    // guardo asientos
            }
        }


    }
    int d= std::atoi(dis.c_str());
    return d;                    // retorno la poscion por la funcion
}

int LocSIL(string pelicul,int *r,int *disp){    // localisar silla
    int tam=pelicul.length();
    int pos;
     int cnt=0,anc=0;
     string dis;
    for(int i=0;i<tam-1;i++){      // itero en el tamaño del  string
        if(pelicul[i]=='|'){   // aumento contador a cambiar de lugar despues de |
            cnt+=1;
            if(cnt==5){
                pos=i+2;
            }
        }

        if(cnt==5){

            if(pelicul[i]!='|'){
            dis+=pelicul[i];    // guardo asientos
            }
        }


    }
    int q=dis.length();
    int star=0;

    string sd;
    for(int i =1;i<q;i++){  // itero para encontrar el ancho de la seccion de disponibles

        if(dis[i]=='/'){
            star=1;
            *r=anc;         // retorno el ancho por puntero
        }
        if(star==0){
            if(dis[i]!=' '){
            sd+=dis[i];
            anc++;
            }
        }
    }
    *disp=std::atoi(sd.c_str());   // retorno el numero de sillas disponibles por puntero
    return pos;                    // retorno la poscion por la funcion
}

void agregarusuario()
{
    string usuario=lectura("sudo.txt");
    string cedula,clave;
    cout<<"Ingrese la cedula del usuario a registrar: "<<endl;
    cin>>cedula;
    cout<<"Ingrese nueva clave de 4 digitos para el usuario registrado : "<<endl;
    cin>>clave;
    while(clave.length()!=4){
        cin>>clave;
    }
    usuario=usuario+cedula+","+clave;
    escribir(usuario,"sudo.txt");

}


void newestreno()
{
    string peliculas=lectura("estrenos.txt");
    int I=knowid(peliculas);          // uso la funcion creada para saber mi ultimo ID
    int duracion,mes=0,dia=0;
    char ID[1];
    string nombre,genero,duracions,clasif,year;
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
    cout<<"  enter movie premiere year "<<endl;
    cin>>year;
    cout<<"ingrese  mes de estreno "<<endl;
    while (mes<1||mes>12) {
    cin>>mes;
    }
    string mess=to_string(mes);
    cout<<"ingrese  dia de estreno "<<endl;
    while (dia<1||dia>31) {
    cin>>dia;
    }
     string diaa=to_string(dia);
    parte=parte+diaa+"/"+ mess+"/"+year+" | ";
    cout<<"ingrese clasificacion: "<<endl;
    cin>>clasif;
    parte=parte + clasif;
    peliculas += parte;
    madepel(peliculas);
    escribir(peliculas,"estrenos.txt");


}
