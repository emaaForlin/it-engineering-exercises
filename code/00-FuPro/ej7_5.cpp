#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    cout<<"Inciso a)"<<endl;
    int y = 100;
    int z = --y;
    cout<< z << " " << y<<endl;

    cout<<"Inciso b)"<<endl;
    y = 100;
    z = y--;
    cout<< z << " " << y<<endl;

    cout<<"Inciso c)"<<endl;
    int x = 50;
    cout<< x++ <<endl;
    cout<< x << endl;

    cout<<"Inciso d)"<<endl;
    int m = 50;
    cout<< ++m <<endl;
    cout<< m << endl;
    return 0;
}