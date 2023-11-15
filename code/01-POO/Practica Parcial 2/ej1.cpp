/*Ejercicio 1 (25 pts) Un archivo “discurso.txt” contiene la transcripción de un discurso
de un político importante. El político en cuestión tiene la mala costumbre de usar
palabrotas en su discurso. Sus asesores han decidido modificar la transcripción para
no molestar a los votantes más susceptibles. Para ello han generado un archivo
“palabrotas.txt”, con la lista de las que usa con más frecuencia. Escriba un programa
c++ que modifique el archivo del discurso reemplazando todas las palabrotas por
“***beep***”. No hay palabras cortadas en el texto y puede haber 2 o mas palabrotas
en una línea..*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void Censurar(string arch_en, string censurar) {
    vector<string> palabras_censuradas, arch_entrada;
    
    ifstream a_censurar(censurar);
    string aux;
    while (a_censurar >> aux) {
        palabras_censuradas.push_back(aux);
    }
    a_censurar.close();


    ifstream arch_in(arch_en);
    while (getline(arch_in, aux)) {  
        arch_entrada.push_back(aux);
    }
    arch_in.close();


    for (string &a : arch_entrada) {
        for (string &b : palabras_censuradas) {
            size_t pos = a.find(b);
            while (pos != string::npos) {
                a.replace(pos, b.length(), "***beep***");
                pos = a.find(b);
                cout << "Censurando: " << b << endl;
            }
        }
    }

    ofstream arch_out(arch_en, ios::trunc);
    for (string &b : arch_entrada) {
        arch_out << b << endl;
    }

    arch_out.close();
}


int main() {
    Censurar("discurso.txt", "lista_de_censuradas.txt");

    return 0;
}
