#include <iostream>
#include "matrix"

using namespace std;


void mostrar(const matrix <int> &m);
void mostrar(const vector <int> &v);


int main() {
    int N = 3; // cantidad de alumnos
    vector<int> alumnos(N);
    
    //carga de dni

    for (unsigned int alu=0;alu<N;alu++) {
        cout<<"Ingrese el dni del alumno: ";
        cin>>alumnos[alu];
    }

    matrix<int> compe(N,3);

    int n_particip, cod_prueba;

    for (int i=0;i<N*3;i++) { 
        cout<<"Numero de participante: ";
        cin>>n_particip;cout<<endl;
        
        cout<<"Codigo de actividad: ";
        cin>>cod_prueba;cout<<endl;
        
        cout<<"Puntaje: ";
        cin>>compe[n_particip-1][cod_prueba-1];cout<<endl;
    }
    mostrar(compe);
    vector<int> puntajes(N,0);

    for (size_t f=0;f<compe.size(0);f++) {
        for (size_t c=0;c<compe.size(1);c++) {
            puntajes[f] += compe[f][c]; 
        }
    }

    int primero, segundo;
    primero = 0;
    segundo = 1;

    for (size_t p=0; p<puntajes.size(); p++) {
        if (puntajes[p] > puntajes[primero]) {
            segundo = primero;
            primero = p;
        } else if (puntajes[p] > puntajes[segundo] && puntajes[p]<puntajes[primero]) {
            segundo = p;
        }
    }

    // item a
    cout<<"DNI del primero: "<<alumnos[primero]+1<<endl<<", con "<<puntajes[primero]<<" puntos."<<endl;
    
    // item b
    cout<<"DNI del segundo: "<<alumnos[segundo]+1<<endl<<", con "<<puntajes[segundo]<<" puntos."<<endl;
    
    // item c
    cout<<"Puntajes del ganador en computacion: "<<compe[primero][2]<<endl;



    return 0;
}

void mostrar(const matrix <int> &m) {
    for (size_t f=0;f<m.size(0);f++) {
        for (size_t c=0;c<m.size(1);c++) {
            cout<<m[f][c] <<" ";
        }
        cout<<endl;
    }
}    
void mostrar(const vector <int> &v) {
    for (int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
}   