#include <iostream>
#include "matrix"

using namespace std;

float calcular_promedio(int s, matrix<int> &d);

int main() {
    matrix<int> datos(10, 3, -1);
    vector<string> sist = {"shield", "halo", "ghost"};
    int cod_equip;

    cout << "Ingrese cod equipo (1-10): ";
    cin >> cod_equip;
    while (cod_equip != 0) {
        int sistema;
        cout << "Sistema (1-3): " << endl;
        cin >> sistema;
        cout << "Calificacion obtenida (1-5 o -1 si no se probo): " << endl;
        cin >> datos[cod_equip-1][sistema-1];

        cout << "Ingrese cod equipo: ";
        cin >> cod_equip;
    }

    bool flag;
    for (size_t e=0; e<datos.size(0);e++) {
        for (size_t s=0; s<datos.size(1); s++) {
            if (datos[e][s] == -1) flag=true;
        }
        cout << "Equipo: " << e << endl;
        if (!flag) for (int calif : datos[e]) cout << calif << " ";
        cout << endl;
        flag=false;
    }

    float mayor_prom = 0;
    for (size_t s=0; s<datos.size(1); s++) {
        if (calcular_promedio(s, datos) > calcular_promedio(mayor_prom, datos)) mayor_prom = s;
    }
    cout << "El sistema mas efectivo fue el " << sist[mayor_prom] << endl;
    return 0;
}

float calcular_promedio(int s, matrix<int> &d) {
    float sum = 0;
    for (size_t f=s; f<d.size(1); f++) if (d[f][s] != -1) sum+= d[f][s];
    return sum /= d.size(1);
}