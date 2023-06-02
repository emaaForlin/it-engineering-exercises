#include <iostream>
#include <vector>
using namespace std;

vector<int> generar_vector_aleatorio(unsigned int dimension, int min, int max);
void mostrar(const vector <int> &v);
void insertar(vector <int> &v, int e, unsigned int pos);


int main(){
    int d = 6; 
    vector <int> elementos;
    elementos = generar_vector_aleatorio(d, 100, 150);
    mostrar(elementos);

    unsigned int pos;
    int numero;

    cout<<"Numero a insertar: ";
    cin>>numero;cout<<endl;
    cout<<"Posicion de insercion: ";
    cin>>pos;cout<<endl;


    insertar(elementos, numero, pos);
    mostrar(elementos);

    return 0;
}

vector<int> generar_vector_aleatorio(unsigned int dimension, int min, int max) {
    vector<int> v(dimension);
    for (unsigned int i=0; i<v.size();i++) {
        int r = min + rand() % (max-min+1);;
        v[i] = r;
    }
    return v;
}

void mostrar(const vector <int> &v) {
    for (int j : v) {
        cout<<j<<" ";
    }
    cout<<endl;
}

void insertar(vector <int> &v, int e, unsigned int pos) {
    v.resize(v.size()+1);
    for (int w=v.size()-1;w>=pos;w--) {
        v[w] = v[w-1];
    }
    v[pos-1] = e;
}


