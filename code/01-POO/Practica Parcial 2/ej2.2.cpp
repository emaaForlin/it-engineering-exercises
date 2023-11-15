/*Ejercicio 2 (25pts) a) Escriba una función genérica mediana3 que reciba 3 valores de
un mismo tipo genérico y retorne la mediana (la mediana es uno de los 3, el que no es
ni el mínimo ni el máximo). b) Escriba un programa cliente que muestre la mediana
entre 3 flotantes que ingrese el usuario; y entre 3 fracciones. Las fracciones deben ser
del tipo: struct Fraccion { int num, den; };.*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T mediana3(T a, T b, T c) {
    vector<T> m = {a,b,c};
    sort(m.begin(), m.end());
    return *next(min_element(m.begin(), m.end()));
}

struct Fraccion {
    int num, den;
};

bool operator<(Fraccion a, Fraccion b) {
    return (a.num/a.den) < (b.num/b.den);
}
ostream &operator<<(ostream &o, Fraccion f) {
    o << f.num << "/" << f.den;
    return o;
}

int main() {
    float f1,f2,f3;
    Fraccion frac1, frac2, frac3;

    f1 = 34.567;
    f2 = 34.102;
    f3 = 33.189;

    frac1 = {11,3};
    frac2 = {5,2};
    frac3 = {1,1};
    
    cout << mediana3(f1, f2, f3) << endl;
    cout << mediana3(frac1, frac2, frac3) << endl;

    return 0;
}