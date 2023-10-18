#include <iostream>
#include <vector>

using namespace std;

// ejercicio anterior

class Persona {
private: 
    string m_nombre_comp;
    int m_dni;
    int m_fecha_nac;
    bool m_es_casado;
public:
    Persona(string nombre_comp, int fecha_nac) : m_nombre_comp(nombre_comp), m_dni(0), m_fecha_nac(fecha_nac), m_es_casado(false) {
        cout << "Persona creada";
    }

    int Edad(int fecha_hoy) { return (int)((fecha_hoy-m_fecha_nac)/10000); } 
};

class Alumno : public Persona {
private:
    float m_promedio;
    int m_materias_aprob;
public:
    Alumno(string nomb_comp, int fecha_nac, int prom, int materias_aprob) : Persona(nomb_comp, fecha_nac) {
        m_promedio = prom;
        m_materias_aprob = materias_aprob;
    }
    int MeritoAcademico() { return m_promedio*m_materias_aprob; }
    float Promedio() { return m_promedio; }
};

class Docente : public Persona {
private:
    int m_fecha_ingreso;
public:
    Docente(string nomb_comp, int fec_nac, int fecha_ingreso) : Persona(nomb_comp, fec_nac) {
        m_fecha_ingreso = fecha_ingreso;
    }
    
    int Antiguedad(int fecha_hoy) { 
        return (fecha_hoy - m_fecha_ingreso) / 10000; 
    }
    
};

// fin ejercicio anterior

class Curso {
private:
    string m_nombre_curso;
    Docente m_docente;
    vector<Alumno> m_alumnos;
    int m_alumnos_reg;
    int m_limite_alumnos;
public:
    Curso(string curso, Docente docente, int max_alum) : m_docente(docente) {
        m_nombre_curso = curso;
        m_alumnos_reg = 0;
        m_limite_alumnos = max_alum;
    }
    void AgregarAlumno(Alumno &a) {
        if (m_alumnos_reg < m_limite_alumnos) { 
            m_alumnos.push_back(a);
            ++m_alumnos_reg;
        }
    }
    Alumno MejorPromedio() {
        int pos_mejor_prom = 0;
        for (size_t i=0; i<m_alumnos.size(); ++i) {
            if (m_alumnos[i].Promedio() > m_alumnos[pos_mejor_prom].Promedio()) {
                pos_mejor_prom = i;
            }
        }
        return m_alumnos[pos_mejor_prom]; 
    }
};

int main() {
    Docente d("Nanci", 19710923, 20010301);
    Alumno a1("Emanuel Forlin", 20030821, 70, 5), a2("Alejandro Forlin", 20010111, 80, 10);

    Curso calculoI("Calculo", d, 50);

    Alumno mejor_alumno = calculoI.MejorPromedio();

    cout << mejor_alumno.MeritoAcademico();

    return 0;
}