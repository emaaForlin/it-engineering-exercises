#include <iostream>
using namespace std;

int mcd(int a, int b){
    if (a>b) {
        return mcd(a-b,b);
    } else if (a<b) {
        return mcd(a,b-a);
    } else {
        return a;
    }
}

int main(int argc, char *argv[]){
    int a,b;
    cout<<"Ingrese dos numeros para calcular el MCD: ";
    cin>>a;cin>>b;
    int max_com_div = mcd(a,b);
    cout<<max_com_div<<endl;

    return 0;
}