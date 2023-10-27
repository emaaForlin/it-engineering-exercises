/*
Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
desde un programa cliente con valores de tipo int, float y string.
a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
retorne el mayor elemento del mismo. Pruebe la función sobrecargada
desde un programa cliente con diversos tipos de datos.
b. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado
en el recuadro? Justifique su respuesta.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Alumno {
    string nom;
    string ape;
    int dni;
};

bool cmp_nom(const Alumno &a1, const Alumno &a2) {
    return a1.nom > a2.nom;
}
bool cmp_ape(const Alumno &a1, const Alumno &a2) {
    return a1.ape > a2.ape;
}
bool cmp_dni(const Alumno &a1, const Alumno &a2) {
    return a1.dni > a2.dni;
}


template<typename T>
T Mayor(const T &a, const T &b) {
    if (a > b) return a;
    else return b;
}

template<typename T>
T Mayor(const vector<T> &a) {
    T mayor = a[0];
    for (T e : a) {
        if (e > mayor) mayor = e;
    }
    return mayor;
}

template<typename T, typename PFnc>
T Mayor(const T &a, const T &b, PFnc comp) {
    if (comp(a,b)) return a;
    else return b;
}


int main() {
    string s1, s2;
    s1 = "AAA"; s2 = "BBB";

    int i1, i2;
    i1 = 200; i2 = 200;

    float f1, f2;
    f1 = 1.0; f2 = 1.1;

    cout << Mayor(s1, s2) << endl;
    cout << Mayor(i1, i2) << endl;
    cout << Mayor(f1, f2) << endl;

    vector<float> v={1.2, 3.14, 129.01, 0.0001, 2.9, 67.76};
    cout << Mayor(v) << endl;

    Alumno a1{"Emanuel", "Forlin", 45057900};
    Alumno a2{"Alejandro", "Forlin", 43003445};

    cout << Mayor(a1, a2, cmp_nom).nom << endl;
    cout << Mayor(a1, a2, cmp_ape).ape << endl;
    cout << Mayor(a1, a2, cmp_dni).dni << endl;


}