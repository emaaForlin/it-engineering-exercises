#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> lista;
    ifstream i_file("lista_ej1.txt");

    if (!i_file.is_open()) {
        exit(1);
    }
    string aux;
    int n = 0;
    while (getline(i_file, aux)) {
        lista.push_back(aux);
        n++;
    }
    i_file.close();

    cout << "Hay " << n << " palabras en el archivo." << endl;
    sort(lista.begin(), lista.end());

    ofstream o_file("lista_ej1.txt", ios::trunc);
    if (!o_file.is_open()) {
        exit(1);
    }

    for (string a : lista) {
        o_file << a << endl;
    }

    o_file.close();

    return 0;
}

