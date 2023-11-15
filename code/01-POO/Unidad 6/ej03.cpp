/*
Ejercicio 3
Escriba un programa que genere un archivo binario con una lista de 100 enteros
ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba
otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
vectores auxiliares.
*/

#include <fstream>
#include <iostream>

using namespace std;

class BinFile {
private:
    fstream f;
    int bytesize;
public:
    BinFile(string p) {
        if (!f.is_open()) {
            f.open(p, ios::in|ios::out|ios::trunc|ios::binary);
        }
        f.seekg(0, ios::end);
        bytesize = f.tellg();
        f.seekg(0);
    }

    int Read(int pos) {
        int a;
        f.seekg(pos*sizeof(int));
        f.read(reinterpret_cast<char*>(&a), sizeof(int));
        return a;
    }

    void Write(int pos, int e) {
        f.seekg(pos*sizeof(int));
        f.write(reinterpret_cast<char*>(&e), sizeof(int));
    }

    void Insert(int pos, int e) {
        for (int i=bytesize/sizeof(int); i>pos; --i) {
            f.seekp((i+1)*sizeof(int));
            f.write(reinterpret_cast<char*>(&e), sizeof(int));
        }
        f.seekp(pos*sizeof(int));
        f.write(reinterpret_cast<char*>(&e), sizeof(int));
    }

};

int main() {
    BinFile f("ej03.dat");
    
    for (int i=0; i<10; ++i) {
        f.Write(i, i*5);
    }


    cin 
    int may_pos=0;
    for (int i=0; i<10; ++i) {
        int n = pos;
        if (f.Read(pos) > f.Read(may_pos)) {
            may_pos = pos;
        }
    }
    


    return 0;
}