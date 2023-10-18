#include <iostream>
#include <cmath>

using namespace std;


struct Punto {
    float x,y;
};

class Recta {
private:
    Punto p,q;
public:
    Recta(Punto &a, Punto &b) : p(a), q(b) {}
    virtual ~Recta() {};
    virtual string ObtenerEq()=0;
    virtual bool Pertenece(Punto &p)=0;
};

class RectaExplicita : public Recta {
private:
    float m,b;
public:
    RectaExplicita(Punto &a, Punto &b) : Recta(a,b), m((b.y - a.y)/(b.x -a.x)), b((a.y - m*a.x)) {}
    string ObtenerEq() override;
    bool Pertenece(Punto &p) override;
};

string RectaExplicita::ObtenerEq() {
    return "y = " + to_string(m) + "x + " + to_string(b);
}

bool RectaExplicita::Pertenece(Punto &p) {
    return ( fabs(p.y - m*p.x - b) < 0.000001 );
}


class RectaGeneral : public Recta {
private:
    float a, b, c;
public:
    RectaGeneral(Punto &d, Punto &e) : Recta(d,e), a(e.y - d.y), b(d.x -e.x), c(-a*d.x -b*d.y) {}
    string ObtenerEq() override;
    bool Pertenece(Punto &p) override;
};

string RectaGeneral::ObtenerEq() {
    return to_string(a)+"x + " + to_string(b)+"y + " + to_string(c) + " = 0";
}

bool RectaGeneral::Pertenece(Punto &p) {
    return (fabs(a*p.x + b*p.y +c) < 0.000001);
}



int main() {
    Punto a,b;

    cout << "P1(x,y): " << endl;
    cout << "Ingrese x: "; cin >> a.x; cout << endl << "Ingrese y: " << endl; cin >> a.y; cout << endl;
    
    cout << "P2(x,y): " << endl;
    cout << "Ingrese x: "; cin >> b.x; cout << endl << "Ingrese y: " << endl; cin >> b.y; cout << endl;
    

    RectaExplicita *re = new RectaExplicita(a,b);
    RectaGeneral *rg = new RectaGeneral(a,b);
    
    cout << "Recta general: " << rg->ObtenerEq() << endl;
    cout << "Recta explicita: " << re->ObtenerEq() << endl;

    Punto p;
    
    cout << "P3(x,y): " << endl;
    cout << "Ingrese x: "; cin >> p.x; cout << endl << "Ingrese y: " << endl; cin >> p.y; cout << endl;
    cout << "P3 pertenece a la recta general?: " << rg->Pertenece(p) << endl;
    cout << "P3 pertenece a la recta explicita?: " << re->Pertenece(p) << endl; 

    delete re;
    delete rg;


    
    return 0;
}