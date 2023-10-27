/*
Ejercicio 4
Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
y atributos para manipular un archivo binario que contenga registros del tipo de
dato especificado por el parámetro. La clase debe poseer métodos para:
a. Abrir un archivo binario y cargar los registros en memoria.
b. Obtener el registro en una posición especificada por el usuario.
c. Modificar el registro en una posición determinada.
d. Actualizar la información del archivo con los cambios.
e. Utilice la clase desde un programa cliente para leer los registros escritos en
el archivo binario generado en el ejercicio 6.5.
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class FileManager {
private:
    string filename;
    fstream file;
    vector<T> data;
    
    void load() {
        T tmp;
        while( file.read(reinterpret_cast<char*>(&tmp), sizeof(T)) ) {
            data.push_back(tmp);
        }
    }

public:
    FileManager(string f) {
        filename = f;
        if (!file.is_open()) {
            file.open(filename, ios::binary|ios::trunc);
            file.close();
        }
        file.open(filename, ios::binary|ios::in|ios::out);
        load();
    }
    ~FileManager() {
        Save();
    }
    T Read(int i) {
        return data[i];
    }

    void Write(int i, T e) {
        data.push_back(e);
        //Save();
    }

    void Save() {
        for(int i=0; i<data.size(); ++i) {
            file.write(reinterpret_cast<char*>(&data[i]), sizeof(T));
        }
    }
};

int main() {
    FileManager<int> fm("ej04.dat");
    for (int i=0; i<10; ++i) {
        fm.Write(i, i*7);
    }
    fm.Save();
    
    for (int i=0; i<10; ++i) {
        cout << fm.Read(i) << endl;
    }

    return 0;
}