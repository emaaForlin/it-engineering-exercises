/*Escriba una función genérica para buscar y reemplazar un dato dentro de
un archivo binario. La función debe recibir el nombre del archivo y dos datos (A y B) del tipo
genérico. Suponiendo que el archivo contiene elementos de dicho tipo, buscar todas las
ocurrencias de A, y reemplazarlas por B. No utilice arreglos, vectores ni otros contenedores
auxiliares (trabaje directamente sobre el archivo).*/
#include <fstream>

using namespace std;

template<typename T> 
void Reemplazar(string fname, T a, T b) {
    fstream file(fname, ios::binary|ios::in|ios::out);
    T aux;
    while (file.read(reinterpret_cast<char*>(&aux), sizeof(aux))) {
        if (aux == a) {
            file.seekp(file.tellp());
            file.write(reinterpret_cast<char*>(&b), sizeof(b));
        }
    }
}

int main() {
    return 0;
}