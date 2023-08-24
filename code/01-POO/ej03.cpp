#include <iostream>

using namespace std;

int *buscar(int *v, int s, int n) {
    for (int i=0; i<s; i++) {
        if (v[i] == n) return &v[i];
    }
    return nullptr;
}


int main() {
    int n=10;

    int b = 876; // num a buscar
    int *a = new int[10]{34, 56, 876, 90, 45, 43, 23, 9, 5, 4};
    
    int *d = buscar(a, n, b);

    if (d != nullptr) {
        cout<<d<<": "<<*d<<endl;
        cout<<"el indice donde se encuentra "<<*d<<" es "<<d-a<<endl;
    } else {
        cout<<"No se encontro "<<b<<" en el arreglo."<<endl;
    }

    delete [] a;

    return 0;
}