#include <iostream>
#include <vector>

using namespace std;

struct AlumnoCursado {
    string nombre;
    int parc1, parc2, recu1, recu2;
};

struct AlumnoFinal {
	string nombre;
	string apellido;
	string condicion;
	int nota_final;
};

vector<AlumnoFinal> condicion(const vector<AlumnoCursado> &alumnos);

vector<AlumnoCursado> cargar_datos();

int main() {
    vector<AlumnoCursado> alumnos_cursado = cargar_datos();
    vector<AlumnoFinal> alumnos_final(alumnos_cursado.size()); 
	alumnos_final = condicion(alumnos_cursado);



    for (size_t f=0; f<alumnos_final.size(); f++) {
		cout<<alumnos_final[f].nombre<<" "<<alumnos_final[f].condicion<<endl;
		
	}
    return 0;
}

vector<AlumnoCursado> cargar_datos() {
    AlumnoCursado alumno;
    vector<AlumnoCursado> alumnos;

	string nombre;
	cout<<"Apellido y nombre: ";
    getline(cin, nombre);

    while (nombre != "") {
		alumno.nombre = nombre;

        cout<<"Nota parcial 1: ";
        cin>>alumno.parc1; cout<<endl;
        
        cout<<"Nota recuperatorio 1: ";
        cin>>alumno.recu1; cout<<endl;

        cout<<"Nota parcial 2: ";
        cin>>alumno.parc2; cout<<endl;

        cout<<"Nota recuperatorio: ";
        cin>>alumno.recu2; cout<<endl;
        
		alumnos.push_back(alumno);
	
	    cin.ignore();
		cout<<"Nombre: ";
        getline(cin,nombre);
		alumno.nombre = nombre;

    }

    return alumnos;
}

vector<AlumnoFinal> condicion(const vector<AlumnoCursado> &alumnos) {
	vector<AlumnoFinal> alumnos_final(alumnos.size());
    AlumnoFinal r;

    for (size_t a=0; a<alumnos.size(); a++) {
		r.nombre = alumnos[a].nombre;
		//r.apellido = alumnos[a].apellido;

		int nota1, nota2;
		
		if (alumnos[a].parc1>alumnos[a].recu1) {
			nota1 = alumnos[a].parc1;
		} else {
			nota1 = alumnos[a].recu1;
		}
		
		if (alumnos[a].parc2>alumnos[a].recu2) {
			nota2 = alumnos[a].parc2;
		} else {
			nota2 = alumnos[a].recu2;
		}
		
		float promedio = ((0.5+nota1) + (2*nota2)) / 3.0;
		r.nota_final = promedio;
		
		if (((alumnos[a].parc1>=60 || alumnos[a].recu1>=60) && (alumnos[a].parc2>=60 || alumnos[a].recu2>=60) && promedio>=70)) {
			r.condicion = "Promocionado";
		} else if ((alumnos[a].parc1>=40 || alumnos[a].recu1 >= 40) && (alumnos[a].parc2>=40 || alumnos[a].recu2 >=40)) {
				r.condicion = "Regular";
		} else  {
			r.condicion = "Libre";
		}
		alumnos_final.push_back(r);
	}
    
	return alumnos_final;

}