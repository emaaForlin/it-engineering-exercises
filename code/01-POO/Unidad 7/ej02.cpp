/*
Ejercicio 2
Implemente una función Clamp(...) que reciba como parámetros una variable (por
referencia) y dos valores indicando los límites superior e inferior para el valor de
dicha variable. Si el valor de la variable supera su máximo, este debe ajustarse al
máximo valor permitido. De la misma forma si el valor es inferior al mínimo. Pruebe
la función templatizada desde un programa cliente
*/

#include <iostream>

using namespace std;

template<typename T>
void Clamp(T &a, T l_sup, T l_inf) {
    if (a > l_sup) {
        a = l_sup;
    }
    if (a < l_inf) {
        a = l_inf;
    }
}

int main() {
    /*
    int d, l1, l2; // l1: cota superior l2: cota inferior
    d = 16; //d = 128;
    l1 = 64;
    l2 = 32;
    */
   string d = "DDD";
   string l1 = "CCC";
   string l2 = "AAA";

    Clamp(d, l1, l2);

    cout << d << endl;

    return 0;
}