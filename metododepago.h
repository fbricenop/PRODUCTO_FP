#include <iostream>
#include "funtarjetaoefec.h"
using namespace std;
void metododepago(double totalcompra) {
    int option;
    cout << "Elija el metodo de pago : " << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta de la tienda" << endl;
    cin >> option;
    if (option == 1) {
        realizarpago(totalcompra);
    } else if (option == 2) {
        bool entrar = false;
        int eleccion;
        do {
            cout << "1. Iniciar sesion" << endl;
            cout << "2. Registrarse" << endl;
            cin >> eleccion;
            if (eleccion == 1) {
                entrar = inicio(totalcompra);
            } else if (eleccion == 2) {
                registrocuenta(totalcompra);
                entrar = false; // Después de registrar, no inicia sesión inmediatamente
            } else {
                cout << "Opcion invalida." << endl;
            }
        } while (!entrar);
        mostrarmenuderegis(totalcompra);
    } else {
        cout << "Opcion invalida." << endl;
    }
}
