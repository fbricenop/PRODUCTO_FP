#include <iostream>
#include "funtarjetaoefec.h"

using namespace std;

void mostrarmenuderegis(double& totalcompra) {
    int eleccion;
    do {
        cout << "Menú: " << endl;
        cout << "1. Conocer sobre las promociones" << endl;
        cout << "2. Pagar aplicando un 10% de descuento" << endl;
        cin >> eleccion;
        if (eleccion == 1) {
            mostrarbeneficios();
        } else if (eleccion == 2) {
            totalcompra = aplicardescuento(totalcompra);
            realizarpago(totalcompra);
        } else {
            cout << "Opción incorrecta." << endl;
        }
    } while (eleccion != 2);
}
