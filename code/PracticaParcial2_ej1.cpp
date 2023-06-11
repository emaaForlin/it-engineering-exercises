#include <iostream>
#include <vector>
using namespace std;

struct Tiempo {
    int min;
    int seg;
};

struct Competidor {
    string nombre_completo;
    Tiempo T1;
    Tiempo T2;
    Tiempo T3;
    Tiempo T_Total;
};

Tiempo sumar_tiempos(Tiempo T1, Tiempo T2, Tiempo T3);

int main() {
    // ingresar competidores
    int nro_competidores;
    cout << "Cantidad de competidores: ";
    cin >> nro_competidores;

    vector<Competidor> competidores(nro_competidores);

    for (size_t c=0; c<competidores.size(); c++) {
        cout << "Nombre completo: ";
        cin >> competidores[c].nombre_completo;
        
        cout << "T1 min: " << "T1 seg: ";
        cin >> competidores[c].T1.min >> competidores[c].T1.seg;

        cout << "T2 min: " << "T2 seg: ";
        cin >> competidores[c].T2.min >> competidores[c].T2.seg;
        
        cout << "T3 min: " << "T3 seg: ";
        cin >> competidores[c].T3.min >> competidores[c].T3.seg;

        competidores[c].T_Total = sumar_tiempos(competidores[c].T1, competidores[c].T2, competidores[c].T3);
    }
    int pos_ganador=0;
    for (size_t c=0; c<competidores.size(); c++) {
        if ((competidores[c].T_Total.min < competidores[pos_ganador].T_Total.min) or (competidores[c].T_Total.min == competidores[pos_ganador].T_Total.min && competidores[c].T_Total.seg < competidores[pos_ganador].T_Total.seg)) {
            pos_ganador = c;
        }
    }

    cout << competidores[pos_ganador].nombre_completo << endl;
    cout << competidores[pos_ganador].T_Total.min << "min " << competidores[pos_ganador].T_Total.seg << "seg." << endl;

    return 0;

}
// T1 2:32
// T2 1:34
// T 3+1 6

Tiempo sumar_tiempos(Tiempo T1, Tiempo T2, Tiempo T3) {
    Tiempo suma;
    int suma_min = T1.min + T2.min + T3.min;
    int suma_seg = T1.seg + T2.seg + T3.seg;
    suma.min = suma_min + (suma_seg/60);
    suma.seg = suma_seg % 60;
    
    return suma;
}