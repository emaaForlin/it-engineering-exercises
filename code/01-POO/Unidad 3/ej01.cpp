/*
Diseñe una clase Persona que contenga los siguientes atributos: apellido y
nombre, DNI, fecha de nacimiento y estado civil. La clase debe poseer, además, un
método Edad(...) que calcule la edad actual de la persona en base a la fecha de
nacimiento y la fecha actual (que recibe como argumento).
Implemente una clase Alumno para contener la siguiente información de un
alumno: apellido y nombre, DNI, año de nacimiento, estado civil, promedio y
cantidad de materias aprobadas. La clase debe poseer, además, un método
MeritoAcademico() que devuelve el mérito académico del alumno (éste se calcula
como el producto entre el promedio y la cantidad de materias aprobadas).
Cree, también, una clase Docente para modelar un docente a partir de la siguiente
información: apellido y nombre, DNI, año de nacimiento, estado civil y fecha de
ingreso. La clase debe poseer, además, un método Antiguedad() que calcule la
antigüedad del docente en base a su fecha de ingreso y la fecha actual.
Proponga una jerarquía de clases adecuada para evitar repetir atributos.
Implemente constructores y métodos extra que considere adecuados. Codifique un
programa cliente que cree instancias de Alumno y Docente y utilice sus funciones.
*/
#include <iostream>
using namespace std;

class Persona {
private: 
    string m_nombre_comp;
    int m_dni;
    int m_fecha_nac;
    bool m_es_casado;
public:
    Persona(string nombre_comp, int dni, int fec_nac, bool es_casado) {
        m_nombre_comp = nombre_comp;
        m_dni = dni;
        m_fecha_nac = fec_nac;
        m_es_casado = es_casado;
    }
    Persona(string nombre_comp, int fecha_nac) {
        m_nombre_comp = nombre_comp;
        m_fecha_nac = fecha_nac;
        m_es_casado = false;
        m_dni = 0;
    }

    int Edad(int fecha_hoy) { return (int)((fecha_hoy-m_fecha_nac)/10000); } 
};

class Alumno : public Persona {
private:
    float m_promedio;
    int m_materias_aprob;
public:
    Alumno(string nomb_comp, int dni, int fec_nac, bool es_casado, int prom, int materias_aprob) : Persona(nomb_comp, dni, fec_nac, es_casado) {
        m_promedio = prom;
        m_materias_aprob = materias_aprob;
    }
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
    Docente(string nomb_comp, int dni, int fec_nac,  int fecha_ingreso) : Persona(nomb_comp, fec_nac) {
        m_fecha_ingreso = fecha_ingreso;
    }
    Docente(string nomb_comp, int fecha_nac, int fecha_ingreso) : Persona(nomb_comp, fecha_nac) {
        m_fecha_ingreso = fecha_ingreso;
    }
    
    int Antiguedad(int fecha_hoy) { 
        return (fecha_hoy - m_fecha_ingreso) / 10000; 
    }
    
};

int main() {
    int fecha_hoy = 20230901;

    Alumno a("Emanuel Forlin", 45057139, 20030821, false, 68, 4);
    Docente d("Nanci Burella", 22017492, 19710923, 20000601);

    cout << "Edad: " << a.Edad(fecha_hoy) << " Merito academico: " << a.MeritoAcademico() << endl;
    cout << "Edad: " << d.Edad(fecha_hoy) << " Antiguedad: " << d.Antiguedad(fecha_hoy) << endl;

    return 0;
}
