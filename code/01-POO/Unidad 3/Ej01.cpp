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
    int MeritoAcademico() { return m_promedio*m_materias_aprob; }
};

class Docente : public Persona {
private:
    int m_fecha_ingreso;
public:
    Docente(string nomb_comp, int dni, int fec_nac, bool es_casado, int fecha_ingreso) : Persona(nomb_comp, dni, fec_nac, es_casado) {
        m_fecha_ingreso = fecha_ingreso;
    }
    int Antiguedad(int fecha_hoy) { return (fecha_hoy - m_fecha_ingreso) / 10000; }
};

int main() {
    int fecha_hoy = 20230901;

    Alumno a("Emanuel Forlin", 45057139, 20030821, false, 68, 4);
    Docente d("Nanci Burella", 22017492, 19710923, true, 20000601);

    cout << "Edad: " << a.Edad(fecha_hoy) << " Merito academico: " << a.MeritoAcademico() << endl;
    cout << "Edad: " << d.Edad(fecha_hoy) << " Antiguedad: " << d.Antiguedad(fecha_hoy) << endl;

    return 0;
}