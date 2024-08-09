#include <iostream>//si te preguntas el double& trabajara con la variable original,pero permitiendo modificaciones
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
                entrar=true;// despues de registrar inicia sesion inmediatamente
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
    int usuarioh=-1;
    cout<<"Ingrese su nombre (usuario): ";cin>>nombre;

    // Verificar si el usuario esta registrado
    if (!veriregistro(nombre, usuarioh)) {
        cout << "El usuario no existe. Por favor, registrese."<<endl;
        return false; // no se pudo iniciar sesion 
    }

    cout << "Ingrese su contraseña (DNI): ";
    cin >> contrasena;

    // Verificar contraseña
    if (contrasenas[usuarioh] == contrasena) {
        cout << "Inicio de sesión exitoso.\n";
        return true; // Indicar que el inicio de sesión fue exitoso
    } else {
        cout << "Contraseña incorrecta. Intente nuevamente.\n";
        return false; // Indicar que el inicio de sesión falló
    }
}

void registrocuenta(double& totalCompra) {
    string nombre, contrasena;

    if (numusuario >= maxusuario) {
        cout << "No se pueden registrar más usuarios.\n";
        return;
    }

    cout << "Ingrese su nombre (usuario): ";
    cin >> nombre;

    // Verificar si el usuario ya está registrado
    int usuarioh;
    if (veriregistro(nombre, usuarioh)) {
        cout << "Este usuario ya está registrado. Intente iniciar sesión.\n";
        return;
    }

    cout << "Ingrese su contraseña (DNI): ";
    cin >> contrasena;

    // Guardar usuario y contraseña
    nombres[numusuario] = nombre;
    contrasenas[numusuario] = contrasena;
    numusuario++;

    cout << "Cuenta registrada exitosamente.\n";
}

bool veriregistro(const string& nombre, int& usuarioh) {
    for (int i = 0; i < numusuario; i++) {
        if (nombres[i] == nombre) {
            usuarioh = i;
            return true;
        }
    }
    return false;
}

double aplicardescuento(double totalCompra) {
    return totalCompra * 0.9;
}

void realizarpago(double totalCompra) {
    cout << "Total a pagar: $" << totalCompra << "\n";
    cout << "Gracias por su compra.\n";
}

void mostrarbeneficios() {
    cout << "Como miembro, disfrutas de un 10% de descuento en todas tus compras usando la tarjeta de la tienda.\n";
}

void mostrarmenuderegis(double& totalCompra) {
    int eleccion;
    do {
        cout << "Menú:\n";
        cout << "1. Conocer sobre las promociones\n";
        cout << "2. Pagar aplicando un 10% de descuento\n";
        cin >> eleccion;

        if (eleccion == 1) {
            mostrarbeneficios();
        } else if (eleccion == 2) {
            totalCompra = aplicardescuento(totalCompra);
            realizarpago(totalCompra);
        } else {
            cout << "opcion incorrecta."<<endl;
        }
    } while (eleccion != 2);
}
