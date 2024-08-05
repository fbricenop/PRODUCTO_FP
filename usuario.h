#include "libreriascomunes.h"
using namespace std;
void g(){
    string saludo="   HOLA USUARIO";
    string catal="CATALOGO DE PRODUCTOS";
    int longitud =catal.length();
    for(int i=0; i<longitud+2; i++){
        cout<<"*";
    }
    cout<<endl<<"*  "<<saludo<<"    *"<<endl;
    cout<<"*"<<catal<<"*"<<endl;
    for (int i=0;i<longitud+2;i++){
        cout<<"*";
    }
    struct producto{
        string nombre;
        int precio;
        int cantidad;
    };
    vector <producto> anaqueles={
        {"Arroz (1KG)",13,60},{"Harina(500 gramos)",2,50}, {"Leche (6 pack )",14,100}, {"Aceite (1L)",11,70}, 
        {"Atun (x3)",9,120},{"Lentejas (1KG)",7,60}, {"Fideos (1KG)",4,70}, {"Yogurt (1KG)",8,60}, 
        {"Trigo (1KG)",10,80},{"Avena (500 gramos)",5,60},{"Azucar (1KG)",9,30}, {"Semola",5,50}, 
        {"Pomarola",5,80},{"Quinua",4,30}, {"Soya",5,60}
        };
      
}
