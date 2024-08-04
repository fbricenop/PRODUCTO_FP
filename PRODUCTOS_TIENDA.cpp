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

void mostrarBoleta(string carritoProductos[], int carritoCantidades[], double carritoPrecios[], int numAbarrotesEnCarrito, double precioTotal, bool descuentoAplicado) {
    cout << "\nBOLETA DE TODA LA COMPRA:\n";
    cout << "=========================\n";
    for(int i=0;i<numAbarrotesEnCarrito;++i) {
        double subtotal=carritoCantidades[i]*carritoPrecios[i];
        cout<<carritoProductos[i]<<" x"<<carritoCantidades[i]<<" - $"<<subtotal<<endl;
    }
    cout<<"======================\n";
    if(descuentoAplicado){
        cout<<"Descuento aplicado: 10%\n";
    }
    cout << "Precio Total: $" << precioTotal << endl;
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
                cout << "Lo lamento, no hay suficiente stock de este producto. Solo quedan "<<stock[seleccion - 1]<<" unidades."<<endl;
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

    char metodoPago;
    cout << "\n¿Desea pagar con tarjeta de la tienda(T) o en efectivo(E)?: ";
    cin >> metodoPago;

    if (metodoPago == 'T' || metodoPago == 't') {
        double descuento = precioTotal * 0.10;
        precioTotal -= descuento;
        mostrarBoleta(carritoProductos, carritoCantidades, carritoPrecios, numAbarrotesEnCarrito, precioTotal, true);
        cout << "¡Gracias por su compra!\n";
    } else {
        cout << "¡Gracias por su compra!\n";
    }

    return 0;
}
