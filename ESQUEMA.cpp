#include "libreriascomunes.h"
#include "comprobacion.h"
#include "usuario.h"

//lamada a archivos .h
//#include "comprobacion.h";
using namespace std;
int main(){
    srand(time(0));
    int categoria,n;
    g();
    /*/
    interfaz de usuario
    */
    //UNA VEZ TERMINE EL BUCLE DEL USUARIO AL PRESIONAR "CUENTA DIFERNTE".
    cout<<endl<<"__ESCRIBA {1} SI ES ADMINISTRADOR O {0} PARA SALIR__";//tambien puede ser 0 para volver a interfz usuario;
    cin>>categoria;
    if(categoria==1){
        comprobacion_administrador(categoria);
    }
    return 0;
    }