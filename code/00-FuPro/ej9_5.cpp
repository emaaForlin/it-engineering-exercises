#include <iostream>
#include <vector>
using namespace std;

void mostrar(const vector<int> &l);
void cargar_datos(vector<int> &l);
vector<int> buscar(int busq, vector<int> &lista);
void eliminar(int pos_elim, vector<int> &lista);


int main(){
    unsigned int dimension;
    cout<<"Cantidad de elementos: ";
    cin>>dimension;

    vector<int> lista(dimension);
    cargar_datos(lista);

    int busc;
    cout<<"Eliminar: ";
    cin>>busc;

    vector<int> posiciones;
    posiciones = buscar(busc, lista);

    for (size_t pos=posiciones.size()-1; pos>0; pos--) {
        cout<<"Eliminar posicion "<<posiciones[pos]<<endl;
        eliminar(posiciones[pos], lista);
    }

    cout<<"Lista final"<<endl;
    mostrar(lista);

    return 0;
}

void eliminar(const vector<int> &lista_elim, vector<int> &lista) {
    for (size_t pos_elim=0; pos_elim<lista_elim.size(); pos_elim++) {
        for (size_t pos_lista=lista_elim[pos_elim]; pos_lista<lista.size(); pos_lista++) {
                lista[pos_lista] = lista[pos_lista+1];
            }
    }
    lista.resize(lista.size()-1); 
}

vector<int> buscar(int busq, vector<int> &lista) {
    vector<int> posiciones;
    for (int pos = 0; pos<lista.size(); pos++) {
        if (busq == lista[pos]) {
            posiciones.resize(posiciones.size()+1);
            posiciones[posiciones.size()-1] = pos; 
        } 
    }
    return posiciones;
}

void mostrar(const vector <int> &l) {
    for (int j : l) {
        cout<<j<<" ";
    }
}

void cargar_datos(vector<int> &l) {
    for (int j=0;j<l.size();j++) {
        int elem;
        cout<<"Ingrese un numero: ";
        cin>>elem;
        l[j]=elem;
    }
}

