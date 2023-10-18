/*
Ejercicio 3
Se tiene un archivo “inscriptos.txt” con una lista de nombres de alumnos inscriptos
al cursado de Fundamentos de Programación. Se desea distribuir los estudiantes
en comisiones de práctica de no más de 30 alumnos. Escriba un programa que
determine cuantas comisiones deberían formarse de acuerdo a la cantidad de
inscriptos y reparta los alumnos en comisiones de igual tamaño, guardando la lista
de alumnos de cada comisión en archivo de texto “comision1.txt”, “comision2.txt”, …
“comisionN.txt”.
Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en un
string texto y números para formar los nombres de los archivos.
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string base_path = "ej03/";
    ifstream inscriptos_f(base_path+"inscriptos.txt");
    if (!inscriptos_f.is_open()) return 1;

    int n_inscriptos = 0;
    string a;
    vector<string> inscriptos;

    while (getline(inscriptos_f, a)) {
        inscriptos.push_back(a);
        ++n_inscriptos;
    }
    inscriptos_f.close();

    int apc = 10; // alumnos por comision
    int n_comisiones = n_inscriptos/apc; // comsiones de 10 alumnos como maximo.
    int alumnos_restantes = n_inscriptos%apc;
    cout << "Se dividiran en " << n_comisiones << " comisiones de 10 alumnos";
    if (alumnos_restantes != 0) { cout << " y una de " << alumnos_restantes << " alumnos."; }
    
    for (int i=1; i<n_comisiones+1; ++i) {
        string f = base_path+"comision"+to_string(i)+".txt";
        ofstream lista_comi(f);
        
        if (!lista_comi.is_open()) { return 1; }
        for (size_t j=0; j<apc; ++j) {
            lista_comi << inscriptos[((i-1)*apc)+j] << endl;
        }

        lista_comi.close();
    }
    
    if (alumnos_restantes != 0) {
        string f = base_path+"comision"+to_string(n_comisiones+1)+".txt";
        ofstream lista_comi(f);
        for (int k=0; k<alumnos_restantes; ++k) {
            lista_comi << inscriptos[k+apc*n_comisiones] << endl;
        }
        lista_comi.close();
    }
    
    return 0;
}