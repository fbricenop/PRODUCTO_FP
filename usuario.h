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
    struct buycar{
        string nombre_producto;
        int cantidad;

    };
    struct producto{
        string nombre;
        string medidas;
        int precio;
        int cantidad;
    }anaquele;
    vector <buycar> carrocompras;
    vector <producto> anaqueles={
        {"Arroz","(1KG)",13,60},{"Harina","(500 g)",2,50}, {"Leche", "(6 pack )",14,100}, {"Aceite", "(1L)",11,70}, 
        {"Atun", "(x3)",9,120},{"Lentejas", "(1KG)",7,60}, {"Fideos", "(1KG)",4,70}, {"Yogurt" ,"(1KG)",8,60}, 
        {"Trigo", "(1KG)",10,80},{"Avena", "(500 g)",5,60},{"Azucar", "(1KG)",9,30}, {"Semola","",5,50}, 
        {"Pomarola","80g",5,80},{"Quinua","",4,30}, {"15)Soya","",5,60}
        };
  
    for (size_t i=0; i<anaqueles.size()-5; i++){
        cout<<anaqueles[i].nombre<<"\t"<<anaqueles[i].precio<<" SOLES "<<"\t"<<anaqueles[i].cantidad<<" EN STOCK"<<endl;
    }     
    do{
        cout<<"SELECCIONE UNA OPCION: \n 1)AÑADIR AL CARRITO\t2)ELIMINAR DEL CARRITO\t3)SALIR DE LA TIENDA"<<endl;
        cin>>opcion_usario;
        cin.ignore();
        string nameproducto;
        switch (opcion_usario){
            case 1:{
                cout<<"SELECCIONA EL PRODUCTO QUE DESEAS AÑADIR (NOMBRE EXACTO): ";
                getline(cin,nameproducto);
                for(size_t i=0;i<anaqueles.size();i++){
                    if(nameproducto==anaqueles[i].nombre){ //verficia si el nombre dado esta dentro del registo-arreglo en el apratado .nombre
                        int cantidad;
                        cout<<"INGRESA LA CANTIDAD"<<endl;
                        cin>>cantidad;
                        cin.ignore();
                        if(cantidad>anaqueles[i].cantidad){ //verifica si la cantidad pedida del producto es mayor a la que esta guardada ene le registro-arreglo en el apartado .cantidad
                            cout<<"STOCK INSUFICIENTE POR: "<<cantidad-anaqueles[i].cantidad<<endl;
                        }else{// en caso sea V que la cantidad pedida del es menor a la que hay en inventario, entonces se actualiza el registro-vector "buycar" 
                            for (size_t j=0;j<carrocompras.size();j++){
                                if(carrocompras[j].nombre_producto==nameproducto){
                                    carrocompras[i].cantidad+= cantidad;//actualizacion de la cantidad de ese prodcuto en el carrito de compras 
                                }
                            }
                             anaqueles[i].cantidad-=cantidad;
                            cout<<"AÑADIDO EXITOSAMENTE AL CARRITO"<<endl;
                        }
                       
                    }
                }
                break;
            }
            case 2:{
                cout<<"ESCRIBA EL NOMBRE DEL PRODUCTO QUE DESEA ELIMINAR DE SU CARRITO";
                for(size_t i=0;i<carrocompras.size();i++){
                    cout<<carrocompras[i].nombre_producto<<": "<<carrocompras[i].cantidad; //mostrar los elementos en el registro-vector carro de compras
                }
                getline(cin,nameproducto);
                for(size_t i=0;i<carrocompras.size();i++){
                    if(nameproducto==carrocompras[i].nombre_producto){
                        
                    }
                }
                break;
            }
            case 3:{
                //mostrar la boleta;
                break;

            }
            }
    }while(opcion_usario!=3);
}
