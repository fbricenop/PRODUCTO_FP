#include <iostream>//si te preguntas el & trabajara con la variable original,pero permitiendo modificaciones
#include <string>
using namespace std; 
const int maxusuario = 100;//maximos usuarios que se pueden registrar
int numusuario = 0;
string nombres[maxusuario];//arreglo para almacenar los nombres 
string contrasenas[maxusuario];//arreglo para almacenar las contraseñas
void metododepago(double totalcompra);//funcion para elegir metodo de pago
bool inicio(double& totalCompra);//funcion para iniciar sesion el bool es para ver si da valores correctos o incorrectos
void registrocuenta(double& totalcompra);//funcion para registrarse
bool veriregistro(const string& nombre, int& usuarioh);//funcion para verificar si el usuario esta registrado
double aplicardescuento(double totalcompra);////funcion para aplicar el descuento del 10%
void realizarpago(double totalcompra);////funcion para realizar el pago
void mostrarbeneficios();//funcion para mostrar los beneficios
void mostrarmenuderegis(double& totalcompra);//funcion para mostrar el menú después de registrarse
int main() {//Fernando este es el main, pones el total de la compra
    double totalcompra;
    cout << "Ingrese el total de la compra: ";cin >> totalcompra;
    metododepago(totalcompra);
    return 0;
}
//funcion metodo de pago
void metododepago(double totalcompra) {
    int option;
    cout<<"Elija el metodo de pago : "<<endl;
    cout<<"1.Efectivo"<<endl;
    cout<<"2.Tarjeta de la tienda"<<endl;
    cin>>option;
    if(option==1){
        realizarpago(totalcompra);
    } else if(option==2){
        bool entrar=false;
        int eleccion;
        do{
            cout<<"1. Iniciar sesion"<<endl;
            cout<<"2. Registrarse"<<endl;
            cin>>eleccion;
            if(eleccion==1){
                entrar=inicio(totalcompra);
            } else if(eleccion==2) {
                registrocuenta(totalcompra);
                entrar=false;// despues de registrar no inicia sesion inmediatamente
            } else{
                cout<<"Opcion invalida."<<endl;
            }
        } while(!entrar);
        mostrarmenuderegis(totalcompra);
    } else {
        cout << "Opcion invalida."<<endl;
    }
}
bool inicio(double& totalcompra){//gestiona el proceso de autentificacion, si esta registrado o no 
    string nombre, contrasena;
    int usuarioh=-1;//se pone -1 porque no se encontro una lista de usuarios
    cout<<"Ingrese su nombre (usuario): ";cin>>nombre;
    // Verificar si el usuario esta registrado
    if (!veriregistro(nombre, usuarioh)) {
        cout << "El usuario no existe. Por favor, registrese."<<endl;
        return false; // no se pudo iniciar sesion 
    }
    cout << "Ingrese su clave: ";cin >> contrasena;
    // Verificar contraseña
    if (contrasenas[usuarioh] == contrasena) {
        cout << "Inicio de sesión exitoso.\n";
        return true; // para que diga que si inicio correctamente
    } else {
        cout << "Contraseña incorrecta. Intente nuevamente.\n";
        return false; // si el inicio de sesion fallo
    }
}
void registrocuenta(double& totalcompra) {//en caso exceda el numero de usuarios
    string nombre, contrasena;
    if (numusuario >= maxusuario) {
        cout << "Nose pueden registrar mas"<<endl;
        return;
    }
    cout<<"Ingrese su nombre (usuario): ";cin >> nombre;
    // Verificar si el usuario ya está registrado
    int usuarioh;
    if (veriregistro(nombre, usuarioh)) {
        cout<<"El usuario ya esta registrado."<<endl;
        return;
    }
    cout<<"Ingrese su contraseña : ";cin >> contrasena;
    // Guardar el usuario y contraseña
    nombres[numusuario] = nombre;
    contrasenas[numusuario] = contrasena;
    numusuario++;
    cout<<"Cuenta registrada exitosamente."<<endl;
}
bool veriregistro(const string& nombre, int& usuarioh) {//el & sirve para que los use de referencia y recibe cambios
    for(int i=0;i<numusuario;i++){
        if(nombres[i]==nombre){
            usuarioh=i;
            return true;
        }
    }
    return false;
}
double aplicardescuento(double totalcompra) {//aplica el descuento del 10%
    return totalcompra * 0.9;
}
void realizarpago(double totalcompra){
    cout<<"Total a pagar: $"<<totalcompra<<"endl";
    cout<<"Gracias por la compra"<<endl;
}
void mostrarbeneficios(){
    cout<<"Ahora que eres miembro disfrutas de 10% en todas tus compras"<<endl;
}
void mostrarmenuderegis(double& totalcompra) {
    int eleccion;
    do{
        cout<<"Menu: "<<endl;
        cout<<"1. Conocer sobre las promociones"<<endl;
        cout<<"2. Pagar aplicando un 10% de descuento"<<endl;
        cin>>eleccion;
        if(eleccion==1) {
            mostrarbeneficios();
        } else if(eleccion==2) {
            totalcompra=aplicardescuento(totalcompra);
            realizarpago(totalcompra);
        } else{
            cout<<"opcion incorrecta."<<endl;
        }
    } while(eleccion !=2);
}
