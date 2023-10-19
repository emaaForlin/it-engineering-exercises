/*
Ejercicio 1
Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado
por un conjunto de 200 pares de números generados aleatoriamente. Cada par de
datos se conforma por un entero y un flotante.
*/
#include <fstream>
#include <iostream>

using namespace std;

struct Par {
    int entero;
    float real;
};

int main() {
    ofstream f("grupo.dat", ios::binary|ios::trunc);

    for (int i=0; i<20; ++i) {
        Par p;
        p.entero = rand() % 11;
        p.real = (rand() % 1001) / 100.0;
        f.write(reinterpret_cast<char*>(&p), sizeof(p));
        cout << p.entero << ": " << p.real << endl;
    }
    f.close();

    return 0;
}