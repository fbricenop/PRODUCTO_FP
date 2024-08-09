#include "funtarjetaoefec.h"

using namespace std;

bool veriregistro(const string& nombre, int& usuarioh) {
    for (int i = 0; i < numusuario; i++) {
        if (nombres[i] == nombre) {
            usuarioh = i;
            return true;
        }
    }
    return false;
}
