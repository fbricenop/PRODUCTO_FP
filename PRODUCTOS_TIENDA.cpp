#include <iostream>
#include <string>
using namespace std;

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
    int carritoCantidades[maxAbarrotes];
    double carritoPrecios[maxAbarrotes];
    int numAbarrotesEnCarrito = 0;
    for (int i = 0; i < numAbarrotes; ++i) {
        cout << i + 1 << ". " << productos[i] << " - $" << precios[i] << " (Stock: " << stock[i] << ")" << endl;
    }
    cout << "================================\n";
     int seleccion;
    while (true) {
        cout << "Seleccione el numero del producto que ha comprado (0 para terminar la compra): ";
        cin >> seleccion;

        if (seleccion == 0) {
            break;
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
                cout << "Lo siento, no hay suficiente stock para ese producto. Solo quedan " << stock[seleccion - 1] << " unidades." << endl;
            }
        } else {
            cout << "Esa opcion es invalida. Por favor, intente de nuevo." << endl;
        }
    }
    double precioTotal = 0;
    cout << "\nBOLETA DE TODA LA COMPRA:\n";
    cout << "=========================\n";
    for (int i = 0; i < numAbarrotesEnCarrito; ++i) {
        double subtotal = carritoCantidades[i] * carritoPrecios[i];
        cout << carritoProductos[i] << " x" << carritoCantidades[i] << " - $" << subtotal << endl;
        precioTotal += subtotal;
    }
    cout << "======================\n";
    cout << "Precio Total: $" << precioTotal << endl; 
return 0;
}
