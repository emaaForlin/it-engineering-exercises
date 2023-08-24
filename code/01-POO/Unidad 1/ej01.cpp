#include <iostream>

using namespace std;

int main() {
    int s = 10;
    int *d = new int;

    cout<<"Ingrese un numero: "<<endl;
    cin >> *d;

    cout<<s<<": "<<&s<<endl;
    cout<<*d<<": "<<&d<<endl;

    delete d;
    return 0;
}