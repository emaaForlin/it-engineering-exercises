/*Ejercicio 4
Con un software de tratamiento de imagenes llamado WellDesign se han generado
78 archivos con los nombres "design1.wds", "design2.wds", … "design78.wds". El
software fue creado para Windows XP. Estos archivos presentan el problema que
en el nuevo sistema operativo Windows 10 al tratar de abrirlos con WellDesign
presentan un molesto mensaje. Al consultar al soporte tecnico de la empresa que
desarrollo WellDesign nos mencionan que si se modifica la cabecera de cada
archivo se soluciona el problema. A partir del byte 178 se debe reemplazar "mswxp"
por "msw10", y a partir del byte 239 reemplazar el valor entero 2003 por el valor
2016. Escriba un programa en C++ que realice esas correcciones en los 78
archivos almacenados.*/

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void GenFiles() {
    for (int i=1; i<79;++i) {
        string filename = "./ej04/design" + to_string(i) + ".wds";
        ofstream file(filename, ios::binary|ios::trunc);

        // char header_cstr[5] = "mswxp";
        string header_str = "mswxp";

        char header_cstr[5];
        strcpy(header_cstr, header_str.c_str());

        file.seekp(178);
        file.write(header_cstr, sizeof(header_cstr));
        file.close();
    }
}

bool IsCompatible(string &f, string &h) {
    ifstream file(f, ios::binary);
    char header[10];
    file.seekg(178);
    file.read(header, sizeof(h));
    file.close();
    return h.c_str() == header;
}

bool UpdateHeader(string &f, string &header) {
    fstream file(f, ios::binary|ios::in|ios::out);
    char h[10];

    file.seekg(178);
    file.read(h, sizeof(h));

    char header_cstr[5];
    strcpy(header_cstr, header.c_str());

    cout << "Old: " << h << endl;

    if (h != header) {
        file.seekp(178);
        file.write(header_cstr, sizeof(header_cstr));
        cout << "New: " << header_cstr << endl;
    }
    file.close();
    return IsCompatible(f, header);
}


int main() {
    GenFiles(); // Generate the initial files.

    for(int i=1; i<79; ++i) {
        string filepath = string("./ej04/design") + to_string(i) + string(".wds");
        string h = "msw10";
        UpdateHeader(filepath, h);
    }



    return 0;
}