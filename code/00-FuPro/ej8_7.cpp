#include <iostream>
using namespace std;

int validar_edad() {
    int edad;
    cin>>edad;
    while (edad<12||edad>90) {
        cout<<"Error. Ingrese una edad valida (12-90): ";
        cin>>edad;
    } 
    return edad;
}

int main(int argc, char *argv[]){
    string nombre, nombre_mayor;
    int edad, edad_mayor=0;

    for (int i=0;i<5;i++) { 
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"Edad: ";
        edad = validar_edad();

        if (edad > edad_mayor) {
            edad_mayor = edad;
            nombre_mayor = nombre;
        }
    }

    cout<<"El mayor de los integrantes es "<<nombre_mayor<<", tiene "<<edad_mayor<<" años."<<endl;
    
    return 0;
}