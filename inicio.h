#include <iostream>
#include "funciones.h"
using namespace std;
bool inicio(double& totalcompra) {
    string nombre, contrasena;
    int usuarioh = -1;
    cout << "Ingrese su nombre (usuario): "; cin >> nombre;
    // Verificar si el usuario está registrado
    if (!veriregistro(nombre, usuarioh)) {
        cout << "El usuario no existe. Por favor, registrese." << endl;
        return false; // No se pudo iniciar sesión
    }
    cout << "Ingrese su clave: "; cin >> contrasena;
    // Verificar contraseña
    if (contrasenas[usuarioh] == contrasena) {
        cout << "Inicio de sesión exitoso.\n";
        return true; // Indicar que el inicio de sesión fue exitoso
    } else {
        cout << "Contraseña incorrecta. Intente nuevamente.\n";
        return false; // Indicar que el inicio de sesión falló
    }
}
