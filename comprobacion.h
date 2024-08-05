#include "libreriascomunes.h"
#include "comprobacion_xnumero.h"
using namespace std;

int comprobacion_administrador(int a){
    string contraseña ="my_0nline_shop",contra;
    int intentos;
    do{
        cout<<"INGRESE LA CONTRASEÑA DE LA CUENTA DE ADMINISTRADOR: ";
        cin>>contra;
        if(contra==contraseña){
            cout<<"VERIFICACION EXITOSA"<<endl;
            intentos=3;
            if(intentos==3){
                numaleatorio(a);
            }else{
                break;
                //regrese a la interfaz de usuario
            }
            
            //funcion de generar nuemeros aleatorios para comprobar que no sea un robot (?
            //return
            //llama a la interfaz del administrador
            
        }else{
            cout<<"NO COINCIDE. ";
            intentos++;
        }
    }while(intentos<3);

}
