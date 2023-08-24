#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int fechaNac, fechaVot;

    cout << "Ingrese las fechas con formato aaaammdd." << endl;
    cout << "Ingrese la fecha de nacimiento: " << endl;
    cin >> fechaNac;

    cout << "Ingrese la fecha de votacion: " << endl;
    cin >> fechaVot;

    int edad = (fechaVot-fechaNac)/10000
;
    if (edad >= 18) {
        cout << "Puede votar" << endl;
    } else {
        cout << "No puede votar" << endl;
    }

    return 0;
}