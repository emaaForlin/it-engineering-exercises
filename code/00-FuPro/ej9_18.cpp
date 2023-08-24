#include <iostream>
#include <vector>

using namespace std;

struct Paciente {
    string apellido;
    string nombre;
    unsigned int dni;
    string diagnostico;
    unsigned int habitacion; 
};

void agregar_paciente(vector<Paciente> &lista_pacientes);

int buscar_paciente(string nombre, string apellido, const vector<Paciente> &lista_pacientes); 
unsigned int buscar_paciente_habitacion(unsigned int habitacion, const vector<Paciente> &lista_pacientes);


int main() {
    unsigned int nro_pacientes;

    cout << "Cantidad de pacientes: ";
    cin >> nro_pacientes; cout << endl;

    vector<Paciente> pacientes;

    // item b
    for (unsigned int p=0; p<nro_pacientes; p++) {
        agregar_paciente(pacientes);
    }
    
    // item c
    string ape, nom;
    cout << "Buscar paciente: " << endl;
    cout << "Apellido: ";
    cin >> ape; cout << endl;
    cout << "Nombre: ";
    cin >> nom; cout << endl;
    int posicion = buscar_paciente(nom, ape, pacientes);

    cout << endl << ape << " " << nom << " se encuentra en la habitacion " << pacientes[posicion].habitacion << endl;

    // item d 
    int cont=0;
    for (size_t p=0; p<pacientes.size(); p++) {
        if (pacientes[p].diagnostico == "apendicitis") {
            cont++;
        }
    }

    cout << "Hay " << cont << " pacientes con apendicitis." << endl;

    // item e
    posicion = buscar_paciente_habitacion(101, pacientes);

    cout << "Paciente de la habitacion 101: " << endl;
    cout << "Apellido: " << pacientes[posicion].apellido << endl;
    cout << "Nombre: " << pacientes[posicion].nombre << endl;
    cout << "DNI: " << pacientes[posicion].dni << endl;
    cout << "Diagnostico: " << pacientes[posicion].diagnostico << endl;

    return 0;
}

void agregar_paciente(vector<Paciente> &lista_pacientes) {
    Paciente new_paciente;
    cout << "Nuevo paciente: " << endl;
    cout << "Apellido: ";
    cin >> new_paciente.apellido;
    cout << "Nombre: ";
    cin >> new_paciente.nombre;
    cout << "DNI: ";
    cin >> new_paciente.dni;
    cout << "Numero de habitacion: ";
    cin >> new_paciente.habitacion;
    cout << "Diagnostico: ";
    cin >> new_paciente.diagnostico;

    lista_pacientes.push_back(new_paciente);

}

int buscar_paciente(string nombre, string apellido, const vector<Paciente> &lista_pacientes) {
    size_t p=0;
    while (p<lista_pacientes.size()) {
        if (lista_pacientes[p].nombre == nombre and lista_pacientes[p].apellido == apellido) {
            return p;
        }
        p++;
    }
    return -1;
}

unsigned int buscar_paciente_habitacion(unsigned int habitacion, const vector<Paciente> &lista_pacientes) {
    size_t p=0;
    while (p<lista_pacientes.size()) {
        if (lista_pacientes[p].habitacion == habitacion) {
            return p;
        }
        p++;
    }
    return -1;
}