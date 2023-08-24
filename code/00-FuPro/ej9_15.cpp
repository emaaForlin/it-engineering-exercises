#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


struct complejo {
    float real;
    float imag;
};
struct raices {
    float r1;
    float r2;
    complejo r_comp1;
    complejo r_comp2;
};

float discriminante(float a, float b, float c);
raices calcular_raices(float a, float b, float c);

int main(int argc, char *argv[]){
    float a,b,c;
    cout<<"a= ";cin>>a;cout<<"b= ";cin>>b;cout<<"c= ";cin>>c;cout<<endl;
    
    float disc = discriminante(a, b, c);
    
    raices r = calcular_raices(a, b, c);
   
    if (disc < 0) {
        cout<<"x1= "<<"("<<r.r_comp1.real<<"+"<<r.r_comp1.imag<<"i)"<<endl;
        cout<<"x2= "<<"("<<r.r_comp2.real<<"+"<<r.r_comp2.imag<<"i)"<<endl;
    } else if (disc > 0) {
        cout<<"x1= "<<r.r1<<endl;
        cout<<"x2= "<<r.r2<<endl;
    } else {
        cout<<"x = "<<r.r1<<endl;
    }
    return 0;
}

raices calcular_raices(float a, float b, float c) {
    float disc = discriminante(a, b, c);
    raices raices_calculadas;

    if (disc < 0) {
        complejo num_comp;
        
        num_comp.real = -b/2*a;
        num_comp.imag = sqrt(-disc)/2*a;
        
        raices_calculadas.r_comp1 = num_comp;
        num_comp.imag*=-1;
        raices_calculadas.r_comp2=num_comp;

    } else if (disc > 0) {
        raices_calculadas.r1 = (-b+sqrt(discriminante(a,b,c)))/(2.0*a);
        raices_calculadas.r2 = (-b-sqrt(discriminante(a,b,c)))/(2.0*a);
    } else {
        raices_calculadas.r1 = (-b+sqrt(discriminante(a,b,c)))/(2.0*a);
    }
    return raices_calculadas;
}
float discriminante(float a, float b, float c) {
    return (b*b)-(4*a*c);
}
