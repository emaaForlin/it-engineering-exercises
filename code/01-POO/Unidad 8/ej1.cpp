/*Ejercicio 8.1
Escriba un programa que permita al usuario ingresar 15 valores por teclado, los
almacene en un vector y luego:
a. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes.
    1. utilizando el operador []
    2. utilizando iteradores
    3. utilizando el for basado en rangos
    4. ¿en qué caso es conveniente utilizar cada mecanismo?
b. Calcule y muestre
    1. los valores de los elementos máximo y mínimo
    2. la suma de todos los elementos del arreglo
    3. el promedio y la mediana de los elementos del arreglo
c. Permita al usuario ingresar un valor, e informe si se encuentra en el vector, 
y en caso afirmativo, en qué posición.*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v(15);
    cout << "Ingrese un valor: ";
    for(vector<int>::iterator i=v.begin(); i!=v.end(); ++i) {
        cin >> *i;
    }

    cout << "a.1" << endl;
    for (size_t i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "a.2" << endl;
    for (vector<int>::iterator i=v.begin(); i!=v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "a.3" << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    

    cout << "Maximo: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Minimo: " << *min_element(v.begin(), v.end()) << endl;
    int s = accumulate(v.begin(), v.end(), 0);
    cout << "Suma: " << s << endl;
    cout << "Promedio: " << s/(float)v.size() << endl;
    cout << "Mediana: " << *(v.end()-v.size()/2) << endl;

    cout << "Dato a consultar: ";
    int o;
    cin >> o;
    cout << "Ese numero ";
    auto pos_it = find(v.begin(), v.end(), o);


    if (pos_it != v.end()) {
        cout << "esta en la pos " << distance(v.begin(), pos_it) << endl;
    } else {
        cout << "no se encuentra" << endl;
    }
}