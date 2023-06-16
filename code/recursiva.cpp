#include <iostream>

using namespace std;

int recursiva(int a) {
    if (a==0) return 1;
    return a*recursiva(a-1);
}


int main() {
    cout << recursiva(10);
    return 0;
}  

