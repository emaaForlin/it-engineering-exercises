#include <iostream>

using namespace std;

class Racional {
    int num, den;
public:
    Racional(int n, int d) : num(n), den(d) {}
    int VerNum() const { return num; }    
    int VerDen() const { return den; }

    Racional operator+ (Racional s) {
        Racional aux = *this;

        aux.num = (aux.num * s.den)+(s.num * aux.den);
        aux.den *= s.den;
        return aux;
    }
    Racional operator* (Racional s) {
        Racional aux = *this;
        aux.num *= s.num;
        aux.den *= s.den;
        return aux;
    } 
    Racional operator* (int x) {
        Racional aux = *this;
        aux.num *= x;
        return aux;
    }
    Racional operator ++() {
        this->num += this->den;
        return *this; 
    }
    Racional operator ++(int) {
        Racional aux = *this;
        aux.num += aux.den;

        return aux;
    }
};

int main() {
    Racional a(3+6, 5+4), b(2, 3), c(0,1);
    cout << "a= " << a.VerNum() << "/" << a.VerDen() << endl;
    cout << "b= " << b.VerNum() << "/" << b.VerDen() << endl;
    cout << "c= " << c.VerNum() << "/" << c.VerDen() << endl;
    cout << endl << endl;

    c=a+b;
    cout << "c= " << c.VerNum() << "/" << c.VerDen() << endl << endl;

    c=a*b;
    cout << "c= " << c.VerNum() << "/" << c.VerDen() << endl << endl;

    c=a*2;
    cout << "c= " << c.VerNum() << "/" << c.VerDen() << endl << endl;

    a=a++;
    cout << "a= " << a.VerNum() << "/" << a.VerDen() << endl << endl;

    ++b;
    cout << "b= " << b.VerNum() << "/" << b.VerDen() << endl << endl;



    return 0;
}