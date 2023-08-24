#include <iostream>
#include <cmath>

using namespace std;

int anios_diferencia(int f1, int f2) {
    int dif = (f1-f2)/10000;
    if (f1-f2 > 0) {
        return dif;
    } else {
        return -dif;
    }
}

int main(int argc, char *argv[]){
    int fecha1 = 20030821, fecha2 = 20230821;
    cout<<anios_diferencia(fecha1,fecha2)<<endl;
    return 0;
}