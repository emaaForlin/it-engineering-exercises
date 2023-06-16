#include <iostream>
#include <vector>

using namespace std;

struct Licencia {
    string nombre;
    string tipo;
    float costo;
};

float calcular_costos(const vector<int> &cant_compra, const vector<Licencia> &licencias);

int main() {
    int N;
    cout << "Cantidad de programas a cargar: ";
    cin >> N; cout << endl;

    vector<int> cantidades(N);
    vector<Licencia> licencias(N);

    for (size_t i=0; i<cantidades.size(); i++) {
        cout << "Nombre del programa: ";
        cin >> licencias[i].nombre; cout << endl;

        cout << "Tipo de licencia: ";
        cin >> licencias[i].tipo; cout << endl;

        cout << "Valor de la licencia: ";
        cin >> licencias[i].costo; cout << endl;

        cout<<"Cantidad a comprar del programa " << i <<": ";
        cin>>cantidades[i]; cout << endl;
    }

    cout << "Costo total: " << calcular_costos(cantidades, licencias);

    return 0;
}

float calcular_costos(const vector<int> &cant_compra, const vector<Licencia> &licencias){
    float total=0;
    for (size_t c=0; c<cant_compra.size(); c++) {
        cout << cant_compra[c] << "programas, * $" << licencias[c].costo << " " << endl;
        total+=cant_compra[c]*licencias[c].costo;
    }
    return total;
}


