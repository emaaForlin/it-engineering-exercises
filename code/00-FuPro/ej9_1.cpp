#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> cargar_notas(unsigned int dimension);
void mostrar(const vector<unsigned int> &notas);
float calcular_promedio(const vector<unsigned int> &notas);

int main(){
    unsigned int cant_alumnos = 30;

    vector<unsigned int> notas(cant_alumnos); 
    notas = cargar_notas(cant_alumnos);

    mostrar(notas);

    float prom;
    prom = calcular_promedio(notas);

    // no se justifica hacer una funcion para comparar si un numero supera el promedio
    cout<<endl<<"Promedio: "<<prom<<endl;
    cout<<"Superan el promedio: "<<endl;
    for (unsigned int i=0;i<notas.size();i++) {
            if (notas[i]>prom) {
                cout<<notas[i]<<" ";
            }
    }
    return 0;
}

vector<unsigned int> cargar_notas(unsigned int dimension) {
    vector<unsigned int> notas(dimension);  
    for (unsigned int  i=0;i<notas.size();i++) {
        unsigned int n;
        //cin>>n;
        n = rand() % 11;    // asi se obtienen enteros aleatorios menores a 10
        notas[i] = n; 
    }
    return notas;
}

void mostrar(const vector<unsigned int> &notas) {
    for (unsigned int m : notas) {
        cout<<m<<" ";
    }
}

float calcular_promedio(const vector<unsigned int> &notas) {
    unsigned int suma = 0;
    for (unsigned int y : notas) {
        suma += y;
    }
    return ((float)(suma / notas.size()));
}