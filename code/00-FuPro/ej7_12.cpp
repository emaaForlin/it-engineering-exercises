#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
    cout << "inciso a)" << endl;
    int n;
    bool primo;
    cout << "Ingrese un numero: " << endl;
    cin >> n;

    int i=2;
    while (i<=sqrt(n) || i==2) {
        if (n%i==0) {
            cout << n << " no es numero primo." << endl;
            primo = false;
        } else {
            primo = true;
        }
        i++;
    }
    if (primo) {
        cout << n << " es primo." << endl;
    }

    cout << "Inciso b)" << endl;

    return 0;
}