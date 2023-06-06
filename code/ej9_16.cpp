#include <iostream>
#include <vector>
using namespace std;


struct parciales {
    string apellido;
    string nombre;
	vector<int> examen={0,0};
	vector<int> recuperatorio={0,0};

};

struct resultado_final {
	string apellido;
	string nombre;
	string condicion_final;
	int nota_final;
};

resultado_final condicion(parciales p);

int main() {
	parciales parc;
	parc.nombre = "Emanuel";
	parc.apellido = "Forlin";
	parc.examen[0] = 20;
	parc.examen[1] = 40;
	parc.recuperatorio[0] = 10;
	parc.recuperatorio[1] = 20;
	
	resultado_final res;
	res = condicion(parc);
	
	cout<<res.nombre<<endl<<res.apellido<<endl<<res.condicion_final<<" "<<res.nota_final<<endl;
	
    return 0;
}

resultado_final condicion(parciales p) {
	resultado_final r;
	r.nombre = p.nombre;
	r.apellido = p.apellido;
	int nota1, nota2;
	
	if (p.examen[0]>p.recuperatorio[0]) {
		nota1 = p.examen[0];
	} else {
		nota1 = p.recuperatorio[0];
	}
	
	if (p.examen[1]>p.recuperatorio[1]) {
		nota2 = p.examen[1];
	} else {
		nota2 = p.recuperatorio[1];
	}
	
	float promedio = (nota1+2*nota2)/3.0;
	r.nota_final = promedio;
	
	if (((p.examen[0]>=60 || p.recuperatorio[0]>=60) && (p.examen[1]>=60 || p.recuperatorio[1]>=60) && promedio>=70)) {
		r.condicion_final = "Promocionado";
	} else if ((p.examen[0]>=40 || p.recuperatorio[0]>=40) && (p.examen[1]>=40 || p.recuperatorio[1]>=40)) {
			r.condicion_final = "Regular";
	} else  {
		r.condicion_final = "Libre";
	}
	return r;

}
