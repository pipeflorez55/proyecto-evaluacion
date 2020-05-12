
#include "funciones.h"

using namespace std;

int main()
{

    int venta;

    while (true) {

  cout<<"-----------------------------------------\n";
    int sele1=-1;
    string sudo=lectura("sudo.txt");  //cargamos archivos de inicios de sesion
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
          cout<<"Acceso concedido como administrador"<<endl<<"------------------"<<endl;
          cout<<"1 si desea agregar nueva pelicula"<<endl<<"2 si desea agregar nuevo ususario"<<endl<<"3 si desea ver ventas del dia"<<endl;
          while(sele3<1 || sele3>4) {
              cin>>sele3;
          }
          switch (sele3) {
          case 1:

            newmovie();


          break;

          case 2:

          break;

          case 3:

          break;


          default:

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
        if(valusu(sudo)){
            cout<<"ID|  nombre | genero  | duraccion | sala/hora | asientos disp | class  |"<<endl<<endl;
            string peliculas=lectura("peliculas.txt");       // leo peliculas actuales en la base de datos
            madepel(peliculas);                                // creo esas peliculas en sus respectivos mapas y objetos
            cout<<peliculas<<endl;
            int sele3=-1;
            cout<<"seleccione el ID de la pelicula que desea ver:" ;
            cin>>sele3;
            while(sele3<1 || sele3>10) {
                cout<<"selecione una de las ID existentes: "<<endl;
                cin>>sele3;
            }
            tipoasiento();
            seleasiento(sele3);
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
      cout<<"\n-----------------------------------------\n\n";
}
