#include <iostream>

using namespace std;

float mayor(float a, float b, float c=0.0) {
   if (a>b && a>c) {
    return a;
   } else if (b>a && b>c) {
    return b;
   } else {
    return c;
   }
}

int main(int argc, char *argv[]){
    float a=0.1,b=0.2,c=3;
    cout<<mayor(a,b,c)<<endl;
    return 0;
}