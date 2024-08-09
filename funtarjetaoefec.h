#ifndef FUNTARJETAOEFEC_H
#define FUNTARJETAOEFEC_H
#include <string>
using namespace std;
const int maxusuario = 100; // Maximos usuarios que se pueden registrar
extern int numusuario; // Numero actual de usuarios registrados
extern string nombres[maxusuario]; // Arreglo para almacenar los nombres
extern string contrasenas[maxusuario]; // Arreglo para almacenar las contraseñas
// Funcion para elegir metodo de pago
void metododepago(double totalcompra);
// Funcion para iniciar sesion
bool inicio(double& totalCompra);
// Funcion para registrarse
void registrocuenta(double& totalcompra);
// Funcion para verificar si el usuario esta registrado
bool veriregistro(const string& nombre, int& usuarioh);
// Funcion para aplicar el descuento del 10%
double aplicardescuento(double totalcompra);
// Funcion para realizar el pago
void realizarpago(double totalcompra);
// Funcion para mostrar los beneficios
void mostrarbeneficios();
// Funcion para mostrar el menu despues de registrarse
void mostrarmenuderegis(double& totalcompra);
#endif // FUNTARJETAOEFEC_H

