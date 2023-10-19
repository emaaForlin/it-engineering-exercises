/*
Ejercicio 2
Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al
usuario que ingrese un entero, un flotante y una posición. El programa debe
sobrescribir el par en la posición ingresada por el usuario por el nuevo par. Luego
muestre la lista de datos en consola mostrando un par por línea.
*/

#include <fstream>
#include <iostream>

using namespace std;

struct Par {
    int entero;
    float real;
};

int main() {
    fstream f("grupo.dat", ios::binary|ios::ate|ios::in|ios::out);

    int pos;
    Par p;
    
    int bytes_size = f.tellg();
    int elementos = bytes_size/sizeof(Par);

    cout << "Ingrese una posicion para reemplazar: "; cin >> pos; cout << endl;
    cout << "Ingrese los datos nuevos (entero, despues flotante): " << endl;
    cin >> p.entero >> p.real;

    f.seekp(pos*sizeof(p));
    f.write(reinterpret_cast<char*>(&p), sizeof(p));

    f.seekg(0);
    for (int i = 0; i < elementos; i++) {
        f.read(reinterpret_cast<char*>(&p), sizeof(p));
        cout << p.entero << ": " << p.real << endl;
    }
    f.close();

    


}