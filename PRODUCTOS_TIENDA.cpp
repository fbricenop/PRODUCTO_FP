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
return 0;
}
