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

    void CargarCoefs(vector <float>);
    void ModCoef(int g, float c) { m_coef[g] = c; };
    float Evaluar(float x);
    float VerCoef(int g);
    int Grado(){ return m_grado; };
};

Polinomio::Polinomio(int grado) {
    m_grado = grado;
    for (int i=0; i<m_grado+1; i++) {
        m_coef.push_back(0);
    }
} 


void Polinomio::CargarCoefs(vector <float> c) {
    m_coef = c;
}

float Polinomio::Evaluar(float x) {
    float res = 0;
    for (size_t i=0; i< m_grado; i++) {
        res += pow(m_coef[i], i+1);
    }
    return res;
}

float Polinomio::VerCoef(int g) {
    return m_coef[g];
}


void MostrarPoli(Polinomio p) {
    for (size_t i=0; i<p.Grado(); i++) {
        cout << p.VerCoef(p.Grado()-i) << "(x^" << p.Grado()-i << ") +";
    }
    cout << endl;
}


Polinomio sumar(Polinomio p1, Polinomio p2) {
    Polinomio p3(p2.Grado());
    vector<float> c(p3.Grado()+1, 0);

    for (size_t i=0; i<p3.Grado(); i++) {
        c[i] = p1.VerCoef(i) + p2.VerCoef(i);
    }

    p3.CargarCoefs(c);
    return p3;
}

int main() {
    Polinomio p1(3), p2(3);

    vector<float> c1{1,3,7,1};
    vector<float> c2{1,2,6,4};

    p1.CargarCoefs(c1);
    p2.CargarCoefs(c2);

    MostrarPoli(p1);
    MostrarPoli(p2);


    Polinomio s = sumar(p1, p2);

    MostrarPoli(s);

    
    return 0;
}