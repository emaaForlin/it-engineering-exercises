#include <iostream>
#include <cmath>
using namespace std;


// item a
long facto(unsigned int n) {
    if (n==0) {
        return 1;
    } else {
        return n*facto(n-1);
    }
}

// item b
float hipot(float cateto_mayor, float cateto_menor) {
    return sqrt((cateto_mayor*cateto_mayor) + (cateto_menor*cateto_menor));
}

bool es_primo(int num) {
    int i=2;
    bool es_primo = true;
    while ((i<sqrt(num) || num==2) && es_primo) {
        if (num%i == 0) {
             es_primo = false;
        } else {
            i++;
        }
    }
    return es_primo;
}

pair<int,int> division_con_resto(int dividendo, int divisor) {
    return {dividendo/divisor, dividendo%divisor};
}

int main(int argc, char *argv[]){
    // item a)
    
    int numero;
    cout<<"a) Ingrese un numero: "<<endl; cin>>numero;
    cout<<numero<<"! = "<<facto(numero)<<endl;

    // item b)
    float a,b;
    cout<<"b) Ingrese los catetos mayor y menor de un triangulo rectangulo: "<<endl; cin>>a; cin>>b;
    cout<<"La hipotenusa es: "<<hipot(a,b)<<endl;
    
    // item c)
    int c;
    cout<<"Ingrese un numero: "<<endl; cin>>c;

    if (es_primo(c)) {
        cout<<"Es primo"<<endl;
    } else {
        cout<<"No es primo"<<endl;    
    }
    
    // item e)
    float dividendo, divisor;
    cout<<"Ingrese el dividendo, luego el divisor: "<<endl; cin>>dividendo; cin>>divisor;
    int cociente = division_con_resto(dividendo, divisor).first;
    int resto = division_con_resto(dividendo, divisor).second;
    cout<<"La division tiene cociente "<<cociente<<" y resto "<<resto<<endl;
    
    // item f)
    // item g)

    return 0;
}