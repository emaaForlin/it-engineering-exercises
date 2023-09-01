#include <iostream> 

using namespace std;

class Point {
public:
    Point(float x, float y) { this->x = x; this->y = y; }
    float x, y;
};

class Rectangulo {
private:
    float m_base, m_altura;

public:
    Rectangulo(float b, float h) {
        m_base = b;
        m_altura = h;
    }
    Rectangulo(Point v1, Point v2) {
        m_base = v2.x - v1.x;
        m_altura = v2.y - v1.y;
        if (m_base < 0) m_base *= -1;
        if (m_altura < 0) m_altura *= -1;
    }
    
    float Area() { return m_base*m_altura; }
    float Perimetro() { return 2*m_base + 2*m_altura; }
    bool EsCuadrado() { return m_base==m_altura; }
};

int main() {
    Point p1(6, 4);
    Point p2(2, 5);
    
    Rectangulo *r1 = new Rectangulo(5, 7);
    Rectangulo *r2 = new Rectangulo(p1, p2);
    Rectangulo *r3 = new Rectangulo(10,10);

    cout << "R1: Area: " << r1->Area() << " Perimetro: " << r1->Perimetro() << " Es cuadrado?... "; 
    if (r1->EsCuadrado()) {cout << "Si." << endl; } else { cout << "No." << endl; }

    cout << "R2: Area: " << r2->Area() << " Perimetro: " << r2->Perimetro() << " Es cuadrado?... ";
    if (r2->EsCuadrado()) {cout << "Si." << endl; } else { cout << "No." << endl; }

    cout << "R3: Area: " << r3->Area() << " Perimetro: " << r3->Perimetro() << " Es cuadrado?... ";
    if (r3->EsCuadrado()) {cout << "Si." << endl; } else { cout << "No." << endl; }



    delete r1;
    delete r2;
    delete r3;

}