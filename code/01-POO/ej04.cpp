#include <iostream>

using namespace std;

struct vector_int_dinamico {
    int *v;
    int size;
};

void redimensionar(vector_int_dinamico &a, int c);

int main() {
    vector_int_dinamico arr;
    arr.size = 5;
    arr.v = new int[arr.size]{1,2,3,4,5};

    // recorre el arreglo
    cout<<"Arreglo: "<<arr.size<<endl;
    for (int i=0; i<arr.size; i++) {
        cout<<*(arr.v+i)<<" ";
    }
    cout<<endl;

    redimensionar(arr, 10);

    // recorre el arreglo
    cout<<"Arreglo final: "<<arr.size<<endl;
    for (int i=0; i<arr.size; i++) {
        cout<<*(arr.v+i)<<" ";
    }
    cout<<endl;
}

void redimensionar(vector_int_dinamico &a, int c) {
    int *n_arr = new int[c];

    for(int i=0; i<c; i++) {
        if (i>a.size) {
            n_arr[i] = 0;
        } else {
            n_arr[i] = a.v[i];
        }
    }
    delete [] a.v;
    a.v = n_arr;
    a.size = c;
}