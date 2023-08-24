#include <iostream>

using namespace std;

struct complejo {
    float real;
    float imag;
};

complejo sumar(complejo a, complejo b);
complejo multiplicar(complejo a, complejo b);
complejo restar(complejo a, complejo b);

int main() {
    cout<<"1) Suma"<<endl<<"2) Resta"<<endl<<"3) Multiplicacion"<<endl<<"Ingrese una opcion: ";
    int op;
    cin>>op;

    complejo a,b, resultado;
    
    cout<<"Ingrese el primer complejo: ";
    cin>>a.real>>a.imag;
    
    cout<<"Ingrese el segundo complejo: ";
    cin>>b.real>>b.imag;

    switch (op) {
    case 1:
        resultado = sumar(a,b);
        cout<<"("<<resultado.real<<"+"<<resultado.imag<<"i)";
        break;
    case 2:
        resultado = restar(a, b);
        cout<<"("<<resultado.real<<"+"<<resultado.imag<<"i)";
        break;
    case 3:
        resultado = multiplicar(a, b);
        cout<<"("<<resultado.real<<"+"<<resultado.imag<<"i)";
    default:
        cout<<"Opcion incorrecta";
        break;
    }
}


complejo sumar(complejo a, complejo b) {
    return {a.real+b.real, a.imag+b.imag};
}
complejo restar(complejo a, complejo b) {
    return {a.real-b.real, a.imag-b.imag};
}
complejo multiplicar(complejo a, complejo b) {
    return {(a.real*b.real)-(a.imag*b.imag),(a.real*b.imag)+(a.imag*b.real)};
}
