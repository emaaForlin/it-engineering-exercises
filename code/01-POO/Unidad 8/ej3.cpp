/*Ejercicio 8.3
Cree un programa que lea valores flotantes por teclado y los inserte en una lista.
Luego:
a. Muestre dicha lista.
b. Inserte en medio de cada par de elementos contiguos el promedio de
dichos elementos y guarde la lista resultante en un archivo de texto llamado
“listafloat.txt”.
c. Responda: ¿es posible ordenar solamente una porción de la lista de la
misma manera que se hizo con el vector en el ejercicio 8.2?*/

#include <list>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    cout << "Carga de datos: " << endl;
    list<float> l;

    float d;
    cin >> d;
    while(d != -1) {
        l.push_back(d);
        cin >> d;
    }

    for (float f : l) { cout << f << " "; } cout << endl;

    for (auto it=next(l.begin()); it!=l.end(); ++it) {
        l.insert(it, accumulate(prev(it), next(it), 0)/2);
    }

    ofstream l_fl("listafloat.txt", ios::trunc);
    for (float f : l) { 
            cout << f << " ";
            l_fl << f << " ";
        } 
        cout << endl;

    return 0;
}