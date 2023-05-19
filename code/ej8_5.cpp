#include <iostream>
#include <cmath>

using namespace std;

void intercambia(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}
void intercambia(float &a, float &b) {
    float aux = a;
    a = b;
    b = aux;
}
void intercambia(char &a, char &b) {
    char aux = a;
    a = b;
    b = aux;
}

int main(int argc, char *argv[]){
    int a=1,b=7;
    float c=45.67,d=78.23;
    char e='m',f='c';

    cout<<"a: "<<a<<" b: "<<b<<endl;
    cout<<"c: "<<c<<" d: "<<d<<endl;
    cout<<"e: "<<e<<" f: "<<f<<endl;
    
    intercambia(a,b);
    intercambia(c,d);
    intercambia(e,f);

    cout<<"a: "<<a<<" b: "<<b<<endl;
    cout<<"c: "<<c<<" d: "<<d<<endl;
    cout<<"e: "<<e<<" f: "<<f<<endl;
    return 0;
}