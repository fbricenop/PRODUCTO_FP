#include <iostream>
#include <string>
using namespace std;

const int maxusuario = 100;
int numusuario = 0;
string nombres[maxusuario];
string contrasenas[maxusuario];

void mostrarTitulo(const string& titulo) {
    int longitud = titulo.length();
    for (int i = 0; i < longitud + 4; ++i) {
        cout << "*";
    }
    cout << endl;
    cout << "* " << titulo << " *" << endl;
    for (int i = 0; i < longitud + 4; ++i) {
        cout << "*";
    }
    cout << endl;
}

void mostrarBoleta(string carritoProductos[], int carritoCantidades[], double carritoPrecios[], int numAbarrotesEnCarrito, double precioTotal, bool descuentoAplicado) {
    cout << "\nBOLETA DE TODA LA COMPRA:\n";
    cout << "=========================\n";
    for(int i=0;i<numAbarrotesEnCarrito;++i) {
        double subtotal = carritoCantidades[i] * carritoPrecios[i];
        cout << carritoProductos[i] << " x" << carritoCantidades[i] << " - $" << subtotal << endl;
    }
    cout << "======================\n";
    if(descuentoAplicado){
        cout << "Descuento aplicado: 10%\n";
    }
    cout << "Precio Total: $" << precioTotal << endl;
}

bool inicio(double& totalcompra);
void registrocuenta(double& totalcompra);
bool veriregistro(const string& nombre, int& usuarioh);
double aplicardescuento(double totalcompra);
void realizarpago(double totalcompra);
void mostrarbeneficios();
void mostrarmenuderegis(double& totalcompra);
void metododepago(double& totalcompra);

int main() {
    string titulo = "Menu de Productos de la Tienda de Abarrotes:";
    mostrarTitulo(titulo);

    const int numAbarrotes = 15;
    string productos[numAbarrotes] = {
        "Arroz", "Harina", "Leche", "Aceite", "Atun",
        "Lentejas", "Fideos", "Yogurt", "Trigo", "Avena",
        "Azucar", "Semola", "Pomarola", "Quinua", "Soya"
    };
    double precios[numAbarrotes] = {
        4.50, 3.50, 3.50, 8, 4.50,
        7.50, 4.50, 5, 3.50, 3.50,
        4.50, 3.50, 1.80, 10, 4
    };
    int stock[numAbarrotes] = {
        40, 50, 30, 40, 50,
        40, 50, 30, 40, 50,
        40, 50, 30, 40, 50
    };

    const int maxAbarrotes = 100;
    string carritoProductos[maxAbarrotes];
    int carritoCantidades[maxAbarrotes] = {0};
    double carritoPrecios[maxAbarrotes] = {0.0};
    int numAbarrotesEnCarrito = 0;

    for (int i = 0; i < numAbarrotes; ++i) {
        cout << i + 1 << ". " << productos[i] << " - $" << precios[i] << " (Stock: " << stock[i] << ")" << endl;
    }
    cout << "================================\n";

    int seleccion;
    while (true) {
        cout << "Seleccione el numero del producto que desea (0 para terminar la compra, -1 para eliminar un producto): ";
        cin >> seleccion;

        if (seleccion == 0) {
            break;
        }
        if (seleccion == -1) {
            cout << "Seleccione el numero del producto en el carrito que desea eliminar: ";
            cin >> seleccion;
            if (seleccion > 0 && seleccion <= numAbarrotesEnCarrito) {
                stock[seleccion - 1] += carritoCantidades[seleccion - 1];
                for (int i = seleccion - 1; i < numAbarrotesEnCarrito - 1; ++i) {
                    carritoProductos[i] = carritoProductos[i + 1];
                    carritoCantidades[i] = carritoCantidades[i + 1];
                    carritoPrecios[i] = carritoPrecios[i + 1];
                }
                numAbarrotesEnCarrito--;
            } else {
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
            continue;
        }
        if (seleccion > 0 && seleccion <= numAbarrotes) {
            int cantidad;
            cout << "Ha seleccionado: " << productos[seleccion - 1] << endl;
            cout << "Ingrese la cantidad comprada: ";
            cin >> cantidad;

            if (cantidad <= stock[seleccion - 1]) {
                carritoProductos[numAbarrotesEnCarrito] = productos[seleccion - 1];
                carritoCantidades[numAbarrotesEnCarrito] = cantidad;
                carritoPrecios[numAbarrotesEnCarrito] = precios[seleccion - 1];
                numAbarrotesEnCarrito++;

                stock[seleccion - 1] -= cantidad;
            } else {
                cout << "Lo lamento, no hay suficiente stock de este producto. Solo quedan " << stock[seleccion - 1] << " unidades." << endl;
            }
        } else {
            cout << "Opcion incorrecta, intente de nuevo." << endl;
        }
    }

    double precioTotal = 0;
    for (int i = 0; i < numAbarrotesEnCarrito; ++i) {
        precioTotal += carritoCantidades[i] * carritoPrecios[i];
    }

    mostrarBoleta(carritoProductos, carritoCantidades, carritoPrecios, numAbarrotesEnCarrito, precioTotal, false);
    metododepago(precioTotal);

    return 0;
}

void metododepago(double& totalcompra) {
    int option;
    cout << "\nElija el metodo de pago : " << endl;
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
                entrar = false; // Después de registrarse, no inicia sesión inmediatamente
            } else {
                cout << "Opcion invalida." << endl;
            }
        } while (!entrar);
        mostrarmenuderegis(totalcompra);
    } else {
        cout << "Opcion invalida." << endl;
    }
}

bool inicio(double& totalcompra) {
    string nombre, contrasena;
    int usuarioh = -1;
    cout << "Ingrese su nombre (usuario): "; cin >> nombre;
    if (!veriregistro(nombre, usuarioh)) {
        cout << "El usuario no existe. Por favor, registrese." << endl;
        return false;
    }
    cout << "Ingrese su clave: "; cin >> contrasena;
    if (contrasenas[usuarioh] == contrasena) {
        cout << "Inicio de sesion exitoso.\n";
        return true;
    } else {
        cout << "Clave incorrecta. Intente nuevamente.\n";
        return false;
    }
}

void registrocuenta(double& totalcompra) {
    string nombre, contrasena;
    if (numusuario >= maxusuario) {
        cout << "No se pueden registrar mas usuarios." << endl;
        return;
    }
    cout << "Ingrese su nombre (usuario): "; cin >> nombre;
    int usuarioh;
    if (veriregistro(nombre, usuarioh)) {
        cout << "El usuario ya esta registrado." << endl;
        return;
    }
    cout << "Ingrese su clave: "; cin >> contrasena;
    nombres[numusuario] = nombre;
    contrasenas[numusuario] = contrasena;
    numusuario++;
    cout << "Cuenta registrada exitosamente." << endl;
}

bool veriregistro(const string& nombre, int& usuarioh) {
    for(int i = 0; i < numusuario; i++){
        if(nombres[i] == nombre){
            usuarioh = i;
            return true;
        }
    }
    return false;
}

double aplicardescuento(double totalcompra) {
    return totalcompra * 0.9;
}

void realizarpago(double totalcompra) {
    cout << "Total a pagar: $" << totalcompra << endl;
    cout << "Gracias por la compra." << endl;
}

void mostrarbeneficios() {
    cout << "Ahora que eres miembro disfrutas de 10% en todas tus compras." << endl;
}

void mostrarmenuderegis(double& totalcompra) {
    int eleccion;
    do {
        cout << "Menu: " << endl;
        cout << "1. Conocer sobre las promociones" << endl;
        cout << "2. Pagar aplicando un 10% de descuento" << endl;
        cin >> eleccion;
        if(eleccion == 1) {
            mostrarbeneficios();
        } else if(eleccion == 2) {
            totalcompra = aplicardescuento(totalcompra);
            realizarpago(totalcompra);
            // Mostrar boleta después de aplicar el descuento
            string carritoProductos[] = {}; // Aquí deberías pasar las variables reales
            int carritoCantidades[] = {};
            double carritoPrecios[] = {};
            int numAbarrotesEnCarrito = 0;
            mostrarBoleta(carritoProductos, carritoCantidades, carritoPrecios, numAbarrotesEnCarrito, totalcompra, true);
        } else {
            cout << "Opcion incorrecta." << endl;
        }
    } while(eleccion != 2);
}
