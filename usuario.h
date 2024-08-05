#include "libreriascomunes.h"
using namespace std;
void g(){
    string saludo="   HOLA USUARIO";
    string catal="CATALOGO DE PRODUCTOS";
    int longitud =catal.length(),opcion_usario;
    cout<<"\t";
    for(int i=0; i<longitud+2; i++){
        cout<<"*";
    }
    cout<<endl<<"\t"<<"*  "<<saludo<<"    *"<<endl;
    cout<<"\t""*"<<catal<<"*"<<endl;
    cout<<"\t";
    for (int i=0;i<longitud+2;i++){
        cout<<"*";
    }
    cout<<endl;
    struct producto{
        string nombre;
        int precio;
        int cantidad;
    };

    vector <producto> anaqueles={
        {"1)Arroz (1KG)",13,60},{"2)Harina(500 g)",2,50}, {"3)Leche (6 pack )",14,100}, {"4)Aceite (1L)",11,70}, 
        {"5)Atun (x3)",9,120},{"6)Lentejas (1KG)",7,60}, {"7)Fideos (1KG)",4,70}, {"8)Yogurt (1KG)",8,60}, 
        {"9)Trigo (1KG)",10,80},{"10)Avena (500 g)",5,60},{"11)Azucar (1KG)",9,30}, {"12)Semola",5,50}, 
        {"13)Pomarola",5,80},{"14)Quinua",4,30}, {"15)Soya",5,60}
        };
  
    for (size_t i=0; i<anaqueles.size()-5; i++){
        cout<<anaqueles[i].nombre<<"\t"<<anaqueles[i].precio<<" SOLES "<<"\t"<<anaqueles[i].cantidad<<" EN STOCK"<<endl;
    }     
    cout<<"SELECCIONE UNA OPCION: \n 1)AÑADIR AL CARRITO\t2)ELIMINAR DEL CARRITO\t3)SALIR DE LA TIENDA";
    cin>>opcion_usario;
    switch (opcion_usario){
        int numero,cantidad;
        case 1:{
            cout<<"SELECCIONA EL PRODUCTO QUE DESEAS AÑADIR: ";
            cin>>numero;
            do{
                if(numero==0 || numero<0 || numero>anaqueles.size()){
                    cout<<"INGRESE OPCIONES VALIDAS";
                }

            }while()
            
            
        }
    }
}
