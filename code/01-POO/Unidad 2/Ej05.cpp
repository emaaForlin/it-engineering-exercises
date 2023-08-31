#include <iostream>
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    float nota;
};

class Curso {
private:
    string m_materia;
    int m_cant_alu;
    vector<Alumno> m_alumnos;

public:
    Curso(string nom, int cant_alu) {
        m_materia = nom;
        m_cant_alu = cant_alu;
    }
    void Agregar(Alumno &a) {
        m_alumnos.push_back(a);
    }
    float Promedio() {
        float sum = 0;
        for (size_t i=0; i<m_cant_alu; ++i) {
            sum += m_alumnos[i].nota;
        }
        return sum/m_cant_alu;
    }
    Alumno CalificacionMasAlta() {
        int j=0;
        for (size_t i=0; i<m_cant_alu; ++i) {
            if (m_alumnos[i].nota > m_alumnos[j].nota) {
                j = i;
            }
        }
        return m_alumnos[j];
    }
};

int main() {
    Alumno a1, a2, a3;
    a1.nombre = "Juan"; a1.nota = 7;
    a2.nombre = "Paco"; a2.nota = 10;
    a3.nombre = "Pedro"; a3.nota = 8.5;
    
    Curso c("Calculo I", 3);
    c.Agregar(a1); c.Agregar(a2); c.Agregar(a3);

    cout << c.Promedio() << " " << c.CalificacionMasAlta().nombre << " " << c.CalificacionMasAlta().nota << endl;
    

    return 0;
}