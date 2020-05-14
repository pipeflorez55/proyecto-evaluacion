
#include "funciones.h"

using namespace std;

int main()
{
    string ven,vents;
    char venta='r';
    cout<<"es un nuevo dia s/n?"<<endl;
    while(venta!='s'&&venta!='n'){
        cin>>venta;
    }
    if(venta=='s'){
        string ventas="";
        escribir(ventas,"ventas.bin");
        string info=lectura("peliculasRN.bin");
        escribir(info,"peliculas.bin");
        info=lectura("1R.bin");
        escribir(info,"1.bin");
        info=lectura("2R.bin");
        escribir(info,"2.bin");
        info=lectura("3R.bin");
        escribir(info,"3.bin");
        info=lectura("4R.bin");
        escribir(info,"4.bin");
        info=lectura("5R.bin");
        escribir(info,"5.bin");
    }

   else{
        vents=lectura("ventas.bin");
    }
    while (true) {

  cout<<endl<<"-----------------------------------------"<<endl<<endl;
    int sele1=-1;
    string sudo=lectura("sudo.bin");  //cargamos archivos de inicios de sesion
    cout<<"desea ingresar como administrador marque 1"<<endl<<
          "desea ingrear como usuario marque 0"<<endl;
    while(sele1!=1  && sele1!=0){                                     //seleccionar tipo de ingreso
        cin>>sele1;
    }
    if (sele1==1){
      while (true) {
        char sele2='e';
      if(valadmin(sudo)){
          int sele3=-1;
          cout<<"Acceso concedido como administrador"<<endl<<endl<<"------------------"<<endl<<endl;
          cout<<"1 si desea agregar nueva pelicula"<<endl<<"2 si desea agregar nuevo ususario"<<endl<<"3 si desea ver ventas del dia"<<endl<<"4 si desea agregar un nuevo tipo de asiento"<<endl<<"5 agregar nuevo estreno"<<endl;
          while(sele3<1 || sele3>5) {
              cin>>sele3;
          }
          switch (sele3) {
          case 1:

            newmovie();


          break;


          case 2:
           agregarusuario();
          break;

          case 3:
           cout<<"las ventas del dia fueron: "<<endl<<lectura("ventas.bin")<<endl;
          break;


          case 4:
           agregarasiento();
           break;
          case 5:

            newestreno();


          break;
          }

          break;
      }
      else{
        cout<<"desea inter otra vez s/n"<<endl;
        while(sele2!='s' && sele2!='n'){                //verificacion de ingreso de dato
            cin>>sele2;
        }
        if (sele2=='n'){
            break;
        }
       }
      }
     }
    else{
        while (true) {
          char sele2='e';
        if(valusu(sudo,&vents)){
            cout<<endl<<"-----------------------------------------------------"<<endl;
            cout<<"ID|  nombre | genero  | duraccion | sala/hora | asientos disp | class  |"<<endl<<endl;
            string peliculas=lectura("peliculas.bin");       // leo peliculas actuales en la base de datos
            madepel(peliculas);                                // creo esas peliculas en sus respectivos mapas y objetos
            cout<<"-----------------------------------------------------"<<endl;
            cout<<peliculas<<endl;
            cout<<endl<<"-----------------------------------------------------"<<endl;
            cout<<"  PROXIMOS EXTRENOS "<<endl;
             string estrenos=lectura("estrenos.bin");
             cout<<estrenos<<endl;
             cout<<endl<<"-----------------------------------------------------"<<endl;
            int sele3=-1;
            cout<<endl<<"seleccione el ID de la pelicula que desea ver:" ;
            cin>>sele3;
            while(sele3<1 || sele3>knowid(peliculas)) {
                cout<<endl<<"selecione una de las ID existentes: "<<endl;
                cin>>sele3;
            }
           int sele4=-1;
            cout<<endl<<"que tipo de asiento desea comprar:"<<endl;
            string asiento = lectura("asientos.bin");        // cargo los tipos de asientos
           cout<<endl<<"-----------------------------------------------------"<<endl;
            cout<< asiento<<endl;                            // los muestro en pantalla
          cout<<endl<<"-----------------------------------------------------"<<endl;
            cout<<"selecione el ID del asiento: ";
            cin>>sele4;
           while(sele4<1 || sele4>knowid(asiento)) {
                 cout<<"selecione una de las ID existentes: "<<endl;
                  cin>>sele4;
               }

            tipoasiento(sele4,&vents);
            string IDST=to_string(sele3);
            vents=vents+IDST+" | ";
            cout<<endl<<"-----------------------------------------------------"<<endl;
            seleasiento(sele3,&vents);
            escribir(vents,"ventas.bin");
            cout<<endl<<"-----------------------------------------------------"<<endl;

           break;

        }
        else{
          cout<<"desea inter otra vez s/n"<<endl;
          while(sele2!='s' && sele2!='n'){              //verificacion de ingreso de dato
              cin>>sele2;
          }
          if (sele2=='n'){
              break;
          }
         }
        }
       }

    }
      cout<<"\n-----------------------------------------"<<endl<<endl;
}
