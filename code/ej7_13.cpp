#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int cantOperarios = 3;
    float precioHora = 890;
    
    float min;
    float max=0;

    float prom;

    
    for (int i=1;i<=cantOperarios;i++) {
        cout << "Horas trabajados del operario " << i <<":"<<endl;
        float horas, salario;
        cin >> horas;
        if (horas <= 40) {
            salario = horas*precioHora;
        } else {
            salario = 40*precioHora+(horas-40)*precioHora*1.5;
        }

        if (salario > max) {
            max = salario;
        }
        if (i==1) {
            min = salario; 
        }

        if (salario < min) {
            min = salario;
        }
        prom+=salario;
        cout << "Salario del operario " << i << ": $" << salario << endl;
    }
    cout << "Salario maximo: " << max << endl;
    cout << "Salario minimo: " << min << endl;

    prom /= cantOperarios;
    cout << "Salario promedio: " << prom; 

    return 0;
}