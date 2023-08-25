#include <iostream>
#include <cmath>

using namespace std;


class Cilindro {
private:
    float m_r;
    float m_h;
    float pi = 3.14159;
public:
    Cilindro(float r, float h);
    float ObtenerVolumen() { return pi*m_r*m_r*m_h; }
};

Cilindro::Cilindro(float r, float h){
    m_r = r;
    m_h = h;
}

int main() {
    float r,h;
    cout << "Radio: " << endl;
    cin >> r;
    cout << "Altura: " << endl; 
    cin >> h;

    // c1.AsignarDatos(r,h);
    // c2.AsignarDatos(5.3, 10.2);

    Cilindro c1(r,h), c2(5.3, 10.2);
    cout << c1.ObtenerVolumen() << endl << c2.ObtenerVolumen() << endl;
}

