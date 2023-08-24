#include <iostream>

using namespace std;


int *genera(int n) {
    int *v= new int[n];
    for (size_t i=0; i<n; i++) {
        *(v+i) = rand()%501 + 1000;
    }
    return v;
}

int main() {
    // n = 10
    int *p = genera(10);

    for (size_t j=0; j<10;j++) {
        cout<<*(p+j)<<endl;
    }

    int *pos_max = p;
    for (size_t i=0; i<10; i++) {
        if (p[i] > *pos_max){
            *pos_max=i;
        }            
    }
    cout << "Mayor elemento: "<<p[*pos_max-1]<<" Direccion: "<<pos_max<<endl;

    delete [] p;
    return 0;
}