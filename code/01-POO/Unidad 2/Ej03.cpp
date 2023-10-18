/*
Ejercicio 3
Diseñe una clase Polinomio cuyos atributos sean el grado (entero) y los
coeficientes de los términos (hasta 20 términos; utilice un vector estático o la clase
vector, pero no new/delete). La clase debe tener:
a. un constructor que reciba el grado el polinomio e inicialice sus coeficientes
en 0.
b. un método que permita cambiar un coeficiente.
c. un método evaluar que permita evaluar el polinomio para un valor dado de
la variable x.
d. el/los métodos que considere necesarios para poder mostrar un polinomio
desde un programa cliente.
e. una función que permita sumar dos polinomios retornando un tercer
polinomio con el resultado (ej. p_res=Sumar(p1,p2);). ¿Cómo variaría si en
lugar de ser una funciń libre fuera un método de la clase?
Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polinomio {
private:
    int m_grado;
    vector<float> m_coef;
public:
    Polinomio(int grado);

    void CargarCoefs(vector<float> &c);
    void ModCoef(int g, float c) { m_coef[g] = c; };
    float Evaluar(float x);
    float VerCoef(int g);
    int Grado(){ return m_grado; };
    void Sumar(Polinomio &p);
};

Polinomio::Polinomio(int grado) {
    for (int i=0; i<m_grado+1; i++) {
        m_coef.push_back(0);
    }
    m_grado = m_coef.size()-1;
} 

void Polinomio::CargarCoefs(vector<float> &c) {
    m_coef = c;
    m_grado = m_coef.size()-1;
}

float Polinomio::Evaluar(float x) {
    float res = 0;
    for (size_t i=0; i<m_grado+1; i++) {
        res += (m_coef[i] * pow(x, i));
    }
    return res;
}

float Polinomio::VerCoef(int g) {
    return m_coef[g];
}

void Polinomio::Sumar(Polinomio &p) {
    for (size_t i=0; i < this->Grado()+1; i++) {
        this->m_coef[i] += p.VerCoef(i);
    }
}


void MostrarPoli(Polinomio &p) {
    for (size_t i=p.Grado()+1; i>0; i--) {
        if (i != 1 ) {
            cout << p.VerCoef(i-1) << "(x^" << i-1 << ") +";
        } else {
            cout << p.VerCoef(i-1) << "(x^" << i-1 << ")";
        }
    }
    cout << endl;
}



int main() {
    Polinomio p1(3), p2(3);

    vector<float> c1{1,3,7,1};
    vector<float> c2{1,2,6,4};

    p1.CargarCoefs(c1);
    p2.CargarCoefs(c2);

    cout << "P1: ";  MostrarPoli(p1); cout << endl;
    cout << "P2: ";  MostrarPoli(p2); cout << endl;
    
    p1.Sumar(p2);

    MostrarPoli(p1);

    int x;
    cout << "Ingrese el valor de x para evaluar el polinomio: ";
    cin >> x; cout << endl << "P("<< x << ") = " << p1.Evaluar(x) << endl;

    
    return 0;
}