#include <iostream>
#include <vector>

using namespace std;


void mostrar(const vector<string> &l);

int main() {
    vector<string> desap;
    vector<string> aprob;

    int nota;
    string nombre;

    cout<<"Nombre: ";
    cin>>nombre;
    cout<<endl;
    cout<<"Nota: ";
    cin>>nota;
    cout<<endl;
    
    unsigned int cont_ap = 0;
    unsigned int cont_desap = 0;

    while (nota != 0) {
        if (nota>=6){
            aprob.resize(aprob.size()+1);
            aprob[cont_ap] = nombre;
            cont_ap++;
        } else if (nota<6){
            desap.resize(desap.size()+1);
            desap[cont_desap] = nombre;
            cont_desap++;
        }

        cout<<"Nombre: ";
        cin>>nombre;
        cout<<endl;
        cout<<"Nota: ";
        cin>>nota;
        cout<<endl;
    }
    cout<<"Aprobados: "<<endl;
    mostrar(aprob);
    cout<<"Desaprobados: "<<endl;
    mostrar(desap);

    return 0;
}

void mostrar(const vector<string> &l) {
    for (unsigned int i=0; i<l.size(); i++) {
        cout<<l[i]<<" ";
    }
    cout<<endl<<endl;
}


