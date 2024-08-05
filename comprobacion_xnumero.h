#include "libreriascomunes.h"
using namespace std;

void numaleatorio(int a){
    int s,intento;
    for(int i=0; i<3;i++){
        s= rand()%(200 +1 -0);
        cout<<"DIGITE EL SIGUIENTE NUMERO ALEATORIO : ";
        cout<<s<<endl;
        cout<<"ACÁ EL NUMERO: ";
        cin>>intento;
        if(intento==s){
            cout<<"ULTIMO CHEKEO COMPLETADO"<<endl;
            i=3;
        }else if(i==2){
            cout<<"INTENTOS ACABADOS"<<endl;
            break;
            //regresar a la interfaz de usario
        }
    }
}