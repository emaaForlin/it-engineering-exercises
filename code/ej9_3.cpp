#include <iostream>
#include <vector>
using namespace std;

unsigned int busca_pos(string palabra_nueva, const vector <string> &lista);
void insertar(string palabra, unsigned int pos, vector <string> &lista);
void mostrar(const vector<string> &l);

int main(){
    vector<string> lista = {"aaaa", "bbbb", "cccc", "eeee"};
    string palabra = "dddd";
    mostrar(lista);

    unsigned int pos = busca_pos(palabra, lista);
    cout<<"pos: "<<pos<<endl;

    insertar(palabra, pos, lista);
    mostrar(lista);

    return 0;
}

unsigned int busca_pos(string palabra_nueva, const vector <string> &lista) {
    int pos_elem = 0;
    while (lista[pos_elem]<palabra_nueva) {
        pos_elem++;
    }
    return pos_elem;
}
void insertar(string palabra, unsigned int pos, vector <string> &lista) {
    lista.resize(lista.size()+1);
    for (unsigned int iter=lista.size()-1;iter>pos;iter--) {
        lista[iter] = lista[iter-1];
    }

    lista[pos] = palabra;
}
void mostrar(const vector <string> &l) {
    for (string j : l) {
        cout<<j<<" ";
    }
}

