#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int a,b,c;
    cout << "Ingrese a,b y c: " << endl;
    cin >> a;cin >> b;cin >> c;

    if (a>b && a>c) {
        cout << "El mayor es " << a << endl;
    } else {
        if (b>c) {
            cout << "El mayor es " << b << endl;
        } else {
            cout << "El mayor es " << c << endl;
        }
    }

    return 0;
}