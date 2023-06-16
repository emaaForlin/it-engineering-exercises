#include <iostream>
#include <vector>
using namespace std;

const int ACE=0; const int ENF=1; const int TG=2; const int DF=3; const int Q=4;

struct Evento { string tipo; int jugador; };

void agregar_evento(string tipo, int jugador, vector<Evento> &eventos);
vector<int> resumen_partido(const vector<Evento> &eventos, int jugador);

int main() {
    vector<Evento> eventos;

    string tipo;
    cout << "Tipo de evento" << endl;
    getline(cin, tipo);

    while (tipo != "") {
        int jugador;
        cout << "Nro. jugador" << endl; 
        cin >> jugador;
        cin.ignore();
        agregar_evento(tipo, jugador, eventos);
        
        cout << "Tipo de evento" << endl;
        getline(cin, tipo);
    }

    int nro_jugador;
    cout << "Nro. de jugador: " << endl;
    cin >> nro_jugador;
    
    vector<int> resumen = resumen_partido(eventos, nro_jugador);

    cout << "Resumen de eventos del jugador nro. " << nro_jugador << endl;
    cout << "ACE: " << resumen[ACE] << endl;
    cout << "Error no forzado: " << resumen[ENF] << endl;
    cout << "Tiro ganador: " << resumen[TG] << endl;
    cout << "Doble falta: " << resumen[DF] << endl;
    cout << "Quiebre: " << resumen[Q] << endl;
    
    return 0;
}

void agregar_evento(string tipo, int jugador, vector<Evento> &eventos) {
    Evento new_evento;
    new_evento.tipo = tipo;
    new_evento.jugador = jugador;
    eventos.push_back(new_evento);
}

vector<int> resumen_partido(const vector<Evento> &eventos, int jugador) {
    vector<int> resumen(5,0);
    
    for (size_t evento=0; evento<eventos.size(); evento++) {
        if (eventos[evento].jugador == jugador) {
            if (eventos[evento].tipo == "ace") {
                resumen[ACE]++;
            } else if (eventos[evento].tipo == "error no forzado") {
                resumen[ENF]++;   
            } else if (eventos[evento].tipo == "tiro ganador") {
                resumen[TG]++;
            } else if (eventos[evento].tipo == "doble falta") {
                resumen[DF]++;
            } else if (eventos[evento].tipo == "quiebre") {
                resumen[Q]++;
            }
        }
    }
    return resumen;
}