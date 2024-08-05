#include "libreriascomunes.h"
using namespace std;
void g(){
    string saludo="HOLA USUARIO";
    string catal="CATALOGO DE PRODUCTOS";
    int longitud =catal.length();
    for(int i=0; i<longitud+2; i++){
        cout<<"*";
    }
    cout<<endl<<"*  "<<saludo<<"  *"<<endl;
    cout<<"*"<<catal<<"*"<<endl;
    for (int i=0;i<longitud+2;i++){
        cout<<"*";
    }
    struct anaqueles{
        vector <string> tienda_productos={"Arroz", "Harina", "Leche", "Aceite", "Atun","Lentejas", "Fideos", "Yogurt", "Trigo", "Avena","Azucar", "Semola", "Pomarola", "Quinua", "Soya"};
        double preciosxproducto[15]={};
    };
      
}
