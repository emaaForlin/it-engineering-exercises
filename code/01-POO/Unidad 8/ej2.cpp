/*Escriba un programa que defina un vector dinámico de 30 enteros aleatorios
menores que 25. Luego:
a. Ordene en forma descendente los elementos ubicados entre las posiciones
10 y 20 inclusive, y muestre el vector.
b. Inserte en un nuevo vector los elementos que fueron ordenados en el
apartado anterior, y quítelos del vector original.
c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
dicho valor en el vector.
d. Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la
función remove. Responda: ¿Pueden las funciones globales de la STL
eliminar realmente los elementos (liberando la memoria de un contenedor)?*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rand25() { return rand()%25; }

int main() {
    vector<int> v(30);

    generate(v.begin(), v.end(), rand25);

    cout << endl;
    sort(v.begin()+10, v.begin()+21, greater<int>());
    
    vector<int> v1(10);
    for (auto it=v1.begin(); it != v1.end(); ++it) {
        *it = *next(v.begin(), 10);
    }
    v.erase(next(v.begin(),10), next(v.begin(),21));

    for (int a : v) { cout << a << " "; }

    int a;
    cout << endl << "Ingrese un numero: " << endl;
    cin >> a;

    int t = count(v.begin(), v.end(), a);

    cout << "Aparece " << t << " veces." << endl;
    v.erase(remove(v.begin(), v.end(), a), v.end()); // remove por si solo ordena los elementos a eliminar al final del contenedor 
                                                     // y devuelve un iterador al primero de esos elementos. Es decir, no los elimina.

    for (int a : v) { cout << a << " "; }

    return 0;
}