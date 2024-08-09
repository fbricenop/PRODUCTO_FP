#include <iostream>
#include "funtarjetaoefec.h"
using namespace std;
void registrocuenta(double& totalcompra) {
    string nombre, contrasena;
    if (numusuario >= maxusuario) {
        cout << "No se pueden registrar más usuarios." << endl;
        return;
    }
    cout << "Ingrese su nombre (usuario): "; cin >> nombre;
    // Verificar si el usuario ya está registrado
    int usuarioh;
    if (veriregistro(nombre, usuarioh)) {
        cout << "El usuario ya está registrado. Intente iniciar sesión." << endl;
        return;
    }
    cout << "Ingrese su contraseña: "; cin >> contrasena;
    // Guardar usuario y contraseña
    nombres[numusuario] = nombre;
    contrasenas[numusuario] = contrasena;
    numusuario++;
    cout << "Cuenta registrada exitosamente." << endl;
}
