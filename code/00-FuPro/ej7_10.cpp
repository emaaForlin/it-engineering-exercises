#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int n;
    cout << "Ingresar un numero para obtener sus pares menores: " << endl;
    cin >> n;

    bool asc;
    cout << "Mostrar: " << endl << "1) Ascendente"<< endl << "0) Descendente" << endl;
    cin >> asc;

    if (asc) {
        for (int i=0;i<n;i++) {
            if (i%2==0) {
                cout << i << endl;
            }
        }
    } else {
        for (int j=n-1;j>0;j--) {
            if (j%2==0) {
                cout << j << endl;
            }
        }
    }
    return 0;
}