/*
Ejercicio 3
Programe una clase templatizada llamada VectorDinamico (similar a la de la guía
2). La clase debe poseer:
a. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria
necesaria.
b. Un destructor que se encargue de liberar la memoria reservada.
c. Una sobrecarga del operador[] que reciba el número de elemento, devuelva
su valor, y permita modificarlo.
d. Modifique o sobrecargue el constructor para que permita generar valores
aleatorios con los cuales inicializar las posiciones del arreglo que reserva.
e. Utilice la clase desde un programa cliente creando vectores aleatorios con
diversos tipos de datos (int,double,string, etc).
*/
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


template<typename T>
class VectorDinamico {
private:
    T *data;
    int size;
public:
    template<typename PFnc>
    VectorDinamico(int s, PFnc rand_gen) {
        size = s;
        data = new T[size];

        for (int i=0; i < size; ++i) {
            data[i] = rand_gen();
            //data[i] += 'A' + (rand()%('Z'-'A'));
        }
    }
    ~VectorDinamico() {
        delete []data;
        data = nullptr;
        size = 0;
    }
    T &operator[](int i) {
        return data[i];
    }
};

string rand_str() {
    string s;
    s += 'A' + (rand()%('Z'-'A'));
    return s;
}

int rand_int() {
    int a = rand();
    return a;
}

int main() {
    srand(time(NULL));
    VectorDinamico<int> enteros(10, rand_int);
    VectorDinamico<float> reales(10, rand);
    VectorDinamico<string> cadenas(10, rand_str);

    for (int i=0; i<10; ++i) {
        cout << setw(10) << enteros[i] << setw(20) << reales[i] << setw(10) << cadenas[i] << endl;
    }
    return 0;
}