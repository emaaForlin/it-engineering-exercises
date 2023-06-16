#include <iostream>
#include <vector>
using namespace std;

struct Usuario {
    string user;
    string pass;
};

bool validar_passwd(string p);

int buscar_usuario(string user, vector<Usuario> &usuarios);

int main() {
    vector<Usuario> usuarios;
    string user;
    string pass;

    cout << "Cargar usuarios validos: " << endl << "Usuario: " << endl;
    cin>>user;
    while (user != "ZZZ") {
        Usuario new_user;
        new_user.user = user;
        cout << "Ingrese una contraseña: " << endl;
        cin >> pass;

        while (!validar_passwd(pass)) {
            cout << "Esa contrasenia es muy facil, elegi otra: " << endl;
            cin >> pass;
        }        
        
        new_user.pass = pass;
        usuarios.push_back(new_user);
        
        cout << "Usuario: " << endl;
        cin >> user;
    }


    cout << "Por favor identifiquese: " << endl << "Usuario: ";
    cin >> user;
    
    unsigned int pos = buscar_usuario(user, usuarios);
    unsigned int n_intento=0;
    
    while (n_intento < 5) {
        cout << "Contraseña: ";
        cin >> pass; cout << endl;

        if (usuarios[pos].user != user || usuarios[pos].pass != pass) {
            cout << "Contraseña incorrecta, intente de nuevo.";
            n_intento++;
        } else {
            n_intento = 5;
        }

    }
    if (n_intento == 5) {
        cout << "Bienvenido " << user  << endl;
    } else {
        cout << "Sali de aca pt" << endl;
    }
    
}

bool validar_passwd(string p) {
    return p != "" && p != "asdf" && p != "1234" && p != "pass" && p != "tumama";
}
int buscar_usuario(string user, vector<Usuario> &usuarios) {
    for (size_t p=0; p<usuarios.size(); p++) {
        if (user == usuarios[p].user){
            return p;
        }
    }
    return -1;
}