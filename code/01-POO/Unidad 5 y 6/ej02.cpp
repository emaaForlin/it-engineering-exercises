#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Alumno {
    string nombre;
    float nota1;
    float nota2;
};

bool modificar(vector<Alumno> &a, string nom, int n1, int n2) {
    ofstream out_file("lista_ej2.txt");
    if (!out_file.is_open()) {
        return 1;
    }

    int i=0;
    while (i < a.size()) {
        if (a[i].nombre != nom) {
            out_file << a[i].nombre << endl << a[i].nota1 << " " << a[i].nota2 << endl;
            ++i;
        }
        out_file << a[i].nombre << endl << n1 << " " << n2 << endl;
        a[i].nota1 = n1;
        a[i].nota2 = n2;
        ++i;
    }
    out_file.close();
    
    return 0;
}

int main() {
    ifstream in_file("lista_ej2.txt");

    if (!in_file.is_open()) {
        return 1;
    }

    string nom;
    vector<Alumno> alumnos;
    while (getline(in_file, nom)) {
        float n1, n2;
        in_file >> n1 >> n2;
        in_file.ignore();

        Alumno a{nom, n1, n2};
        alumnos.push_back(a);
    }

    in_file.close();
    string nombre;
    float n1, n2;
    cout << "Alumno con notas a modificar: "; getline(cin, nombre);
    cin.ignore();
    cout << "Nuevas notas: "; cin >> n1 >> n2;

    modificar(alumnos, nombre, n1, n2);

    return 0;
}