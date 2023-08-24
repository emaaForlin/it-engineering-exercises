#include <iostream>
#include "matrix"

using namespace std;

matrix<float> cargar_datos(matrix<float> &lluvias);
void mostrar(const matrix<float> &m);

int main() {
    int cant_dptos = 3;
    int cant_meses =3;
    matrix<float> lluvias(cant_dptos, cant_meses);

    lluvias = cargar_datos(lluvias);

    vector<float> prom_anual(cant_dptos,0);
    
    // calcula promedio de lluvia de cada dpto.
    for (size_t d=0; d<lluvias.size(0);d++) {
        int cont = 0;
        for (float l : lluvias[d]) {
            if (l >= 0) {
                cont++;
                prom_anual[d] += l;
            }
        }
        if (cont == 0) {
            prom_anual[d] = 0; 
        } else {
            prom_anual[d] /= cont;
        }
    }

    cout<<"Matriz original: "<<endl;
    mostrar(lluvias);

    // completar datos faltantes con el promedio correspondiente
    for (size_t d=0; d<lluvias.size(0); d++) {
        for (size_t m=0; m<lluvias.size(1); m++) {
            if (lluvias[d][m] < 0) {
                lluvias[d][m] = prom_anual[d];
            }
        }
    } 
    
    cout<<"Matriz modificada: "<<endl;
    mostrar(lluvias);

    // calcula totales anuales por dpto
    
    lluvias.resize(lluvias.size(0)+1, lluvias.size(1));
    for (size_t d=0; d<lluvias.size(0); d++) {
        float sum = 0;
        for (size_t m=0; m<lluvias.size(1); m++) {
            sum += lluvias[d][m];
        }
        lluvias[lluvias.size(0)-1][d] = sum;
    } 
    
    cout<<"Lluvias totales: ";
    for (size_t d=0; d<lluvias.size(0)-1; d++) {
        cout<<"Depto "<<d+1<<": "<<lluvias[lluvias.size(0)-1][d]<<endl;
    }

    return 0;
}

matrix<float> cargar_datos(matrix<float> &lluvias) {
    float mm;
    for (size_t d=0; d<lluvias.size(0); d++) {
        cout<<"Depto "<<d+1<<":"<<endl;
        for (size_t m=0; m<lluvias.size(1); m++) {
            cout<<"Lluvias del mes "<<m+1<<": ";
            cin>>mm; cout<<endl;
            lluvias[d][m] = mm;
        }
    }
    return lluvias;
}

void mostrar(const matrix<float> &m) {
    for (size_t f=0; f<m.size(0); f++) {
        for (size_t c=0; c<m.size(1); c++) {
            cout<<m[f][c]<<" ";
        }
        cout<<endl;
    }
}
