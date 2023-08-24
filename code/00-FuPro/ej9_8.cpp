#include <iostream>
#include "matrix"

using namespace std;

void mostrar(const matrix<int> &m);


int main() {
    int cant_suc = 4;
    int cant_art = 25;

    matrix<int> distrib(cant_suc, cant_art, 0);
    vector<int> ventas_art(3,0);      // vector de ventas por articulo
    int ventas;

    // carga de datos
    for (size_t suc=0; suc<distrib.size(0); suc++) {
        cout<<"Sucursal "<<suc+1<<endl;
        for (size_t prod=0; prod<distrib.size(1); prod++) {
            cout<<"Cod. producto: "<<endl;
            //cin>>distrib[suc][prod];
            distrib[suc][prod] = rand() % 101;

        }
    }

    cout<<"Matriz de ventas"<<endl;
    mostrar(distrib);

    int suma = 0;
    for (size_t art=0; art<distrib.size(1);art++) {
        suma = 0;
        for (size_t suc=0; suc<distrib.size(0); suc++) {
            suma += distrib[suc][art];
        }
        ventas_art[art] = suma;
    }

    //item a
    for (int e : ventas_art) {
        cout<<"Ventas articulo: "<<e<<endl; 
    }

    // item b
    suma = 0;
    for (size_t art=0; art<distrib.size(1); art++) {
        suma+=distrib[2][art]; 
    }
    cout<<"Ventas de la sucursal 3: "<<suma<<endl;

    // item c
    cout<<"Ventas del art. 6 en la sucursal 1: "<<distrib[0][5];

    // item d
    int pos_mayor = 0;

    for (size_t pos=0; pos<distrib.size(0); pos++) {
        if (distrib[pos][7] > distrib[pos_mayor][7]) {
            pos_mayor = pos;
        }
    }

    cout<<"Sucursal con mas ventas del articulo 8: "<<pos_mayor+1<<" con "<<distrib[pos_mayor][7]<<" ventas."<<endl;
    return 0;
}

void mostrar(const matrix<int> &m) {
    for (size_t f=0; f<m.size(0); f++) {
        for (size_t c=0; c<m.size(1); c++) {
            cout<<m[f][c]<<" ";
        }
        cout<<endl;
    }
}