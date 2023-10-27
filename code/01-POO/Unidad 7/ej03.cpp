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
    VectorDinamico(int s) {
        size = s;
        data = new T[size];

        for (int i=0; i < size; ++i) {
            //*(data+i) += 'A' + (rand()%('Z'-'A'));

            data[i] += 'A' + (rand()%('Z'-'A'));
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


int main() {
    srand(time(NULL));
    VectorDinamico<int> enteros(10);
    VectorDinamico<float> reales(10);
    VectorDinamico<string> cadenas(10);

    for (int i=0; i<10; ++i) {
        cout << setw(4) << enteros[i] << setw(4) << reales[i] << setw(4) << cadenas[i] << endl;
    }
    return 0;
}