#include "libreriascomunes.h"
#include "comprobacion.h"
#include "usuario.h"
//lamada a archivos .h
//#include "comprobacion.h";
using namespace std;
int main(){
    srand(time(0));
    int categoria,opcion_administrador;
    g();
    
    /*
    interfaz de usuario
    */
    //UNA VEZ TERMINE EL BUCLE DEL USUARIO AL PRESIONAR "CUENTA DIFERNTE".
    cout<<endl<<"__ESCRIBA {1} SI ES ADMINISTRADOR O {0} PARA SALIR__";//tambien puede ser 0 para volver a interfz usuario;
    cin>>categoria;
    comprobacion_administrador(categoria);
    //int comprobacion_administrador(int categoria);
    switch(categoria){
        case 1:{
            cout<<"REALIZA LA ACCION QUE DESEA HACER: "<<endl<<"1)AGREGAR PRODUCTOS \n2)PRECIO DE LOS PRODUCTOS\n3)QUITAR PRODUCTOS \n4)VER INVENTARIO"<<endl;
            cin>>opcion_administrador;
            switch(opcion_administrador){
                case 1:{
                    //array de los productos 
                    break;
   
                }
            }
            break;
        }
    return 0;
    }
}  