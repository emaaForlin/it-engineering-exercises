#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "a)" << endl;
    if (n%2 == 0) {
        cout << n << " es par." << endl;
    } else {
        cout << n << " es impar." << endl;
    }

    cout << "b)" << endl;
    if (n%3 == 0 && n%5 == 0) {
        cout << n << " es multiplo de 3 y de 5." << endl;
    } else {
        cout << n << " no es multiplo de 3 y 5 a la vez." << endl;
    }

    return 0;
}