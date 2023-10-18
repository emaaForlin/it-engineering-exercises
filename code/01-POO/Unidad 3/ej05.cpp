/*
Ejercicio 5
Proponga un struct Punto con atributos para definir un punto en el plano
(coordenadas x e y). Luego, proponga la clase RectaExplicita para definir la
ecuación de la recta y=mx+b a partir de dos puntos. La declaración de dicha clase
se muestra en el recuadro siguiente.
El método obtenerEcuacion() debe retornar una cadena de texto con la ecuación
explícita de la recta, mientras que el método pertenece(p) debe determinar si el
punto p está o no sobre la recta (si satisface la ecuación).
Ayuda 1: las ecuaciones para obtener m y b a partir de dos puntos P y Q son:
m = (Qy-Py) / (Qx-Px) b = Py - m Px
Ayuda 2: la función string to_string(float) le permitirá convertir los coeficientes a
strings; y además es posible concatenar strings con el operador + (s=s1+s2).
*/

#include <iostream>
#include <cmath>

using namespace std;

struct Punto {
    float x,y;
};

class RectaExplicita {
private:
    float m,b;
public:
    RectaExplicita(Punto p, Punto q);
    float VerM();
    float VerB();
    string ObtenerEq();
    bool Pertenece(Punto p);
};

RectaExplicita::RectaExplicita(Punto p, Punto q) {
    m = (q.y - p.y)/(q.x -p.x);
    b = (p.y - m*p.x);
}

float RectaExplicita::VerM() { return m; }
float RectaExplicita::VerB() { return b; }
string RectaExplicita::ObtenerEq() { 
    return "y= " + to_string(m) + "x + " + to_string(b); 
}
bool RectaExplicita::Pertenece(Punto p) { return fabs(m*p.x +b - p.y) < 0.000001; }


int main() {
    Punto p1{2,0}, p2{4,2};
    RectaExplicita r(p1, p2);

    cout << r.ObtenerEq() << endl;
    cout << "Pendiente: " << r.VerM() << endl;
    cout << "Ordenada al origen: " << r.VerB() << endl;
    cout << "(0,-2) pertenece a la recta?: ";
    if (r.Pertenece(Punto{0,-2})) { cout << "Si." << endl; } else
    cout << "no" << endl;



    return 0;
}