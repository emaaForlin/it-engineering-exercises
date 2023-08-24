#include <iostream>
#include <cmath>

using namespace std;

bool es_primo(int num) {
    unsigned int i=2;
    bool es_primo = true;

    while ((i<=sqrt(num)) && es_primo) {
        if (num%i == 0) {
             return false;
        } else {
            i++;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    int cont_num_primos = 0;
    int iterador = 2;
    while (cont_num_primos<1000) {
        if (es_primo(iterador)) {
            cont_num_primos++;
            cout<<iterador<<" ";
        }
        iterador++;
    }
    return 0;
}