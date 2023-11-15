/*Ejercicio 8.4
Declare un arreglo estático de 20 elementos enteros (int v[20];) y luego:
a. Implemente una función int rand10() que genere un entero aleatorio entre
-10 y 10, y utilícela como argumento para generate para inicializar el arreglo
con valores aleatorios.
b. Implemente una función bool es_par(int x) que retorne true si el entero que
recibe es par; y utilícela en combinación con count_if para contar cuantos
elementos pares hay en el contenedor generado.
c. Implemente una función bool menor_abs(int a, int b) que reciba dos enteros
y retorne verdadero cuando el valor absoluto del primero sea menor que el
valor absoluto del segundo; y utilice esta función en como argumento de
sort para ordenar el vector por valor absoluto.
d. Elimine los elementos repetidos utilizando los algoritmos genéricos de la
STL, y luego muestre el arreglo resultante.*/

#include <algorithm>
#include <iostream>

using namespace std;

int rand10() {
    return -10 + rand()%21;
}

bool es_par(int x) { return x%2 == 0; } 

bool menor_abs(int a, int b) { 
    return abs(a) < abs(b);
}



int main() {
    int v[20];
    generate(begin(v), end(v), rand10);
    for (int j : v) { cout << j << " "; } 
    cout << endl;

    cout << "Hay " << count_if(begin(v), end(v), es_par) << " numeros par." << endl;

    sort(begin(v), end(v), menor_abs);

    unique(begin(v), end(v));

    for (int j : v) { cout << j << " "; }
    return 0;
}