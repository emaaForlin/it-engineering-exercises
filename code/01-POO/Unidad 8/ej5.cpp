/*Ejercicio 8.5
Diseñe y programe una clase para manipular datos del tipo que se muestra en el
recuadro.
struct FichaMedico{
    string nombreMedico;
    vector <long> dniPacientes;
};
La clase será utilizada para administrar los pacientes de una clínica. La clínica está
conformada por 6 médicos y cada uno de ellos atiende a un número variable de
pacientes.
Crear una clase llamada Clinica que posea funciones para:
a. Incorporar nuevos pacientes indicando el número de médico y el DNI del
paciente.
b. Listar el nombre de cada médico y los DNI de los pacientes que atiende.
c. Eliminar un paciente indicando solamente su DNI.
Utilice la clase desarrollada desde un programa cliente.*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct FichaMedico {
    string nombreMedico;
    vector<int> dniPacientes;
};

class Clinica {
private:
    int n_medicos;
    vector<FichaMedico> medicos;
public:
    Clinica(const vector<FichaMedico> &meds) : medicos(meds) { n_medicos = medicos.size(); }

    void NuevoPaciente(int m, int dni) {
        medicos[m].dniPacientes.push_back(dni);
    }
    void Listar() {
        for (FichaMedico m : medicos) {
            cout << m.nombreMedico << ":" << endl;
            for (int p : m.dniPacientes) {
                cout << setw(10) << p << endl;
            }
        }
    }

    void EliminarPaciente(int dni) {
        for (FichaMedico m : medicos) {
            m.dniPacientes.erase(m.dniPacientes.begin() , remove(m.dniPacientes.begin(), m.dniPacientes.end(), dni));
        }
    }
};

int main() {
    vector<FichaMedico> medicos(3);
    medicos[0].nombreMedico = "Alejandro";
    medicos[1].nombreMedico = "Rocio";
    medicos[2].nombreMedico = "Pablo";

    Clinica c(medicos);

    c.NuevoPaciente(0, 43008932);
    c.NuevoPaciente(0, 43028922);
    c.NuevoPaciente(0, 43038731);

    c.NuevoPaciente(1, 45048991);
    c.NuevoPaciente(1, 43072936);
    c.NuevoPaciente(1, 46108033);

    c.NuevoPaciente(2, 45055134);
    c.NuevoPaciente(2, 43059136);
    c.NuevoPaciente(2, 43387976);

    c.Listar();

    c.EliminarPaciente(43028922);
    c.EliminarPaciente(46108033);
    c.EliminarPaciente(45055134);

    c.Listar();

    return 0;
}