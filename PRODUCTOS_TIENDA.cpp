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
return 0;
}
