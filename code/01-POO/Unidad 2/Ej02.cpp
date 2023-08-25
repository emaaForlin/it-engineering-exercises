#include <iostream>
#include <cmath>


using namespace std;

class EcuacionCuadratica {
private:
    float m_a, m_b, m_c;
    float disc();

    bool es_real = true;

public:
    EcuacionCuadratica(float a, float b, float c);
    bool TieneRaicesReales();
    float VerRaiz1();
    float VerRaiz2();
    float VerParteReal();
    float VerParteImag();
};

EcuacionCuadratica::EcuacionCuadratica(float a, float b, float c) { m_a = a; m_b = b; m_c = c; es_real = (disc()>=0); }

float EcuacionCuadratica::disc() { return (m_b*m_b-4*m_a*m_c); }

bool EcuacionCuadratica::TieneRaicesReales() { return es_real; }

float EcuacionCuadratica::VerRaiz1() { return (-m_b+sqrt(disc()))/(2*m_a); }

float EcuacionCuadratica::VerRaiz2() { return (-m_b-sqrt(disc()))/(2*m_a); }

float EcuacionCuadratica::VerParteReal() { return -m_b/(2*m_a); }

float EcuacionCuadratica::VerParteImag() { return sqrt(-disc())/(2*m_a); }

int main() {
   while (true) {
        cout << "Ingrese los coeficientes del polinomio (ax^2 +bx +c) presione (Enter) despues de cada uno: "; 
        float a,b,c;
        cin >> a >> b >> c; cout << endl;
        EcuacionCuadratica eq(a,b,c);
        if (eq.TieneRaicesReales()) {
            cout << "x1 = " << eq.VerRaiz1() << endl;
            cout << "x2 = " << eq.VerRaiz2() << endl;
        } else {
            float i = eq.VerParteImag();

            cout << "x1 = " << eq.VerParteReal() << " - " << i << "i"<< endl;
            cout << "x2 = " << eq.VerParteReal() << " + " << i << "i" << endl;
        }
    }
    
    return 0;
}