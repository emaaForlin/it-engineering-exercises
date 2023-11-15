/*Ejercicio 2 [25 pts] Se dispone de un archivo de textos USUARIOS.TXT donde cada línea contiene el
código, sector, el apellido y el nombre . El código es un número entero y el sector es una sola palabra, y
cada usuario tiene un solo nombre y apellido separado por un espacio en blanco. Escriba una clase que
posea entre sus métodos: a) la función GeneraPassword(), encargada de crear un password
concatenando el sector con la primer letra del nombre y el apellido completo de cada usuario y otra
función CreaBinario( ) que genere un archivo binario que contenga los datos referentes al código,
nombre, apellido y password generado de cada usuario. Programa los métodos adicionales que
considere necesarios.*/

#include <fstream>
#include <iostream>
#include <vector>
//#include <string>
#include<cstring>

using namespace std;

struct DatosIn {
    string cod, sec, ape, nom, pass;
};
struct DatosOut {
    int cod;
    char ape[32];
    char nom[32];
    char pass[64];
};

class Usuarios {
private:
    string fname;
    vector<DatosIn> datos_in;
public:
    Usuarios(string f) : fname(f) {
        ifstream file(fname);
        DatosIn d;
        string cod, sec, ape, nom;
        while(file >> d.cod >> d.sec >> d.ape >> d.nom) {
            datos_in.push_back(d);
        }
    }
    void GeneraPassword() {
        for (DatosIn &d : datos_in) {
            d.pass = d.sec + d.nom[0] + d.ape;
        }
    }

    void CreaBinario() {
        ofstream file("usuarios.dat", ios::binary|ios::trunc);
        for (DatosIn &d : datos_in) {
            DatosOut datos_out;
            datos_out.cod = stoi(d.cod);
            strcpy(datos_out.ape, d.ape.c_str());
            strcpy(datos_out.nom, d.nom.c_str());
            strcpy(datos_out.pass, d.pass.c_str());

            file.write(reinterpret_cast<char*>(&datos_out), sizeof(DatosOut));
        }
        
    }
};

int main() {
    return 0;
}