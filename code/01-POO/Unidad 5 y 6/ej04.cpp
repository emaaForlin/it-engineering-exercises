/*
Ejercicio 4
Un conjunto de archivos de texto contiene información guardada en el formato que
se muestra en el recuadro, donde cada línea contiene el nombre de un campo y su
respectivo valor separados por el signo igual (=). Las líneas que comienzan con el
carácter '#' deben ser ignoradas.
Escriba una clase llamada ConfigFile que permita interpretar el contenido de estos
archivos. La clase debe poseer:
a) un constructor que reciba el nombre del archivo y cargue sus datos en un
vector de structs (cada elemento es struct con dos strings: campo y valor).
b) un método para consultar el valor asociado a un campo
c) un método para modificar el valor asociado a un campo
d) un método para guardar el archivo con los datos actualizados
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Config {
    string field;
    string value;
};

class ConfigFile {
private:
    string filepath;
    vector<Config> cfg;
public:
    ConfigFile(string file);
    ~ConfigFile();
    string Get(string field);
    void Set(string field, string val);
    void Save();
};

ConfigFile::ConfigFile(string file) {
    filepath = file;
    ifstream cfg_file(file);
    if (!cfg_file.is_open()) { exit(1); }

    string entry;
    while (getline(cfg_file, entry)) {
        if (!entry.empty() && entry.find("#") == string::npos) {
            int s = entry.find("=");
            string f = entry.substr(0, s);
            string v = entry.substr(s+1, entry.size()-s);
            
            Config c{f,v};
            cfg.push_back(c);
        }
    }
    cfg_file.close();
}

ConfigFile::~ConfigFile() { Save(); }

string ConfigFile::Get(string field) {
    size_t i=0;
    while (cfg[i].field != field && i<cfg.size()) { ++i; }
    if (i < cfg.size()) { 
        return cfg[i].value;
    }
    return "not found";
}

void ConfigFile::Set(string field, string val) {
    size_t i=0;
    while (cfg[i].field != field && i<cfg.size()) { i++; }

    if (i < cfg.size()) { 
        cfg[i].value = val;
    }

    Save();
    
}

void ConfigFile::Save() {
    ofstream file(filepath);
    if (!file.is_open()) { exit(1); }
    for (Config c: cfg) {
        string modstr;
        modstr = c.field + "=" + c.value;
        file << modstr << endl;
    }
    file.close();
}



int main() {
    string path = "config.txt";
    ConfigFile cfg(path);

    cfg.Set("universidad", "Universidad Nacional del Litoral");
    cfg.Save();

    cout << cfg.Get("carrera");
    
    return 0;
}