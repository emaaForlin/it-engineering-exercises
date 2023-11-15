/*Ejercicio 1 [25 pts] Escriba una función genérica para cualquier tipo de elemento llamada
vector_a_lista(...) que reciba un std::vector y retorne una std::list que contenga los elementos del vector
de entrada, sin repetidos. Debe mantener el orden del vector. Escriba un programa cliente que genere
un vector con 40 enteros aleatorios, utilice la función para pasarlos a una lista, y muestre la lista en
pantalla.*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
list<T> vector_a_lista(vector<T> &v) {
    list<T> l_from_v;

    for(T &a : v) {
        if (find(l_from_v.begin(), l_from_v.end(), a) == l_from_v.end()) {
            // cout << "Agregando elemento: " << a << endl;
            l_from_v.push_back(a);
        } else {
            // cout << "Elemento repetido: " << a << endl;
        }
    }
    return l_from_v;
}

int gen10() {
    return rand()%11;
}

int main() {
    vector<int> entrada(40);
    generate(entrada.begin(), entrada.end(), gen10);

    for (int &a : entrada) {
        cout << a << " ";
    }
    cout << endl;

    list<int> salida = vector_a_lista(entrada);

    for (int &a : salida) {
        cout << a << " ";
    } 

    return 0;
}
