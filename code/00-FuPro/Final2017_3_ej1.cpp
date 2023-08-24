#include <iostream>
#include <vector>

using namespace std;


struct Practica {
    unsigned int fecha;
    unsigned int t1, t2, t3;
};

int convertir_tiempo(int min, int sec);

int main() {
    unsigned int cant_practicas = 2;
    unsigned int fecha, min1, min2, min3, seg1, seg2, seg3;
    vector<Practica> practicas;

    for (int d=0; d<cant_practicas; d++) {
        Practica p;
        cout << "############################"<<endl;
        cout << "Fecha: "; 
        cin >> p.fecha; cout << endl;

        cout << "Tiempo tramo 1 (min y seg): ";
        cin >> min1 >> seg1; cout << endl;
        p.t1 = convertir_tiempo(min1, seg1);

        cout << "Tiempo tramo 2 (min y seg): ";
        cin >> min2 >> seg2; cout << endl;
        p.t2 = convertir_tiempo(min2, seg2);

        cout << "Tiempo tramo 3 (min y seg): ";
        cin >> min3 >> seg3; cout << endl;
        p.t3 = convertir_tiempo(min3, seg3);

        practicas.push_back(p);   
    }

    int mejor_tiempo=0;
    for (size_t p=0; p<practicas.size(); p++) {
        if (practicas[p].t1<practicas[mejor_tiempo].t1) mejor_tiempo = p;
    }
    cout << "Mejor tiempo t1: " << practicas[mejor_tiempo].t1 << " seg. ("<< practicas[mejor_tiempo].fecha << ")" << endl;

    for (size_t p=0; p<practicas.size(); p++) {
        if (practicas[p].t2<practicas[mejor_tiempo].t2) mejor_tiempo = p;
    }
    cout << "Mejor tiempo t2: " << practicas[mejor_tiempo].t2 << " seg. ("<< practicas[mejor_tiempo].fecha << ")" << endl;
    
    for (size_t p=0; p<practicas.size(); p++) {
        if (practicas[p].t3<practicas[mejor_tiempo].t3) mejor_tiempo = p;
    }
    cout << "Mejor tiempo t3: " << practicas[mejor_tiempo].t3 << " seg. ("<< practicas[mejor_tiempo].fecha << ")" << endl;
    
    vector<int> tiempoTotales (cant_practicas);
    for (size_t p=0; p<practicas.size(); p++) {
        float suma = 0;
        suma += practicas[p].t1 + practicas[p].t2 + practicas[p].t3;
        tiempoTotales[p] = suma;
        cout << "Promedio practica " << p <<": " << suma / 3 << endl;
    }

    int primero = 0; int segundo = 1;

    for (size_t t=0; t<tiempoTotales.size(); t++) {
        if (tiempoTotales[t] < tiempoTotales[primero]) {
            segundo = primero;
            primero = t;
        } else if (tiempoTotales[t] < tiempoTotales[segundo] && tiempoTotales[t] > tiempoTotales[primero]) {
            segundo = t;
        }
    }

    cout << "Mejor tiempo: " << tiempoTotales[primero] << " Fecha: " << practicas[primero].fecha << endl;
    cout << "Segundo mejor tiempo: " << tiempoTotales[segundo] << " Fecha: " << practicas[segundo].fecha << endl;
    return 0;
}


int convertir_tiempo(int min, int seg) {
    return (min*60) + seg;
}
