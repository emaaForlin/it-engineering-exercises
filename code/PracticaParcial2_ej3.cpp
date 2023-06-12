#include <iostream>
#include "matrix"

using namespace std;

int main() {
    matrix<int> notas(201,36,0);

    // carga de notas 

    for (size_t alum=0; alum<notas.size(0)-1; alum++) {
        for (size_t mate=0; mate<notas.size(1)-1; mate++) {
            notas[alum][mate] = rand()%11;
            cout << "Alum: " << alum << " Materia: " << mate << " nota: " << notas[alum][mate] << endl;
        }
    }

    // promedio de cada alumno en nota[alumno][35]
    for (size_t alum=0; alum<notas.size(0); alum++) {
        for (size_t mate=0; mate<notas.size(1)-1;mate++) {
            notas[alum][35] += notas[alum][mate];
        }
        notas[alum][35] /= (notas.size(1)-1);
    }

    for (size_t mate=0; mate<notas.size(1)-1; mate++) {
        for (size_t alum=0; alum<notas.size(1); alum++) {
            notas[200][mate] += notas[alum][mate];
        }
        notas[200][mate] /= (notas.size(1)-1);
    }

    int mejor_promedio=0;
    for (size_t n=0; n<notas.size(0)-1;n++) {
        mejor_promedio=max(mejor_promedio, notas[n][35]);
    }

    cout<< "Mejor promedio: " << mejor_promedio << endl;
    
    int mater_menor_prom=0;
    for (size_t m=0; m<notas.size(1)-1; m++) {
        if (notas[200][m] < notas[200][mater_menor_prom]) {
            mater_menor_prom=m;
        }
    }
    cout << "Materia mas dificil: " << mater_menor_prom << endl;

    int mejor_nota_mater_dificil=0;
    for (size_t n=0; n<notas.size(1)-1;n++) {
        mejor_nota_mater_dificil=max(mejor_nota_mater_dificil, notas[200][n]);
    }
    cout << "Mejor nota en la materia mas dificil: " << mejor_nota_mater_dificil << endl;

}
