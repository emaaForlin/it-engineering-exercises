#include <iostream>
#include <cmath>


using namespace std;

float discriminante(float a, float b, float c) {
    return (b*b)-(4*a*c);
}

pair<float,float> raices_reales(float a, float b, float c) {
    return {(-b+sqrt(discriminante(a,b,c)))/(2.0*a),(-b-sqrt(discriminante(a,b,c)))/(2.0*a)};
}

pair<float, float> raices_comp(int a, int b, int c) {
    float r, i;
    float disc = discriminante(a,b,c);
    
    r = -b/2*a;
    i = sqrt(-disc)/2*a;

    return {r,i}; 
}


int main(int argc, char *argv[]){
    float a,b,c;
    cout<<"a= ";cin>>a;cout<<"b= ";cin>>b;cout<<"c= ";cin>>c;cout<<endl;
    float dis = discriminante(a,b,c);
    if (dis >= 0) {
        pair<float,float> reales = raices_reales(a,b,c);
        cout<<"R1: "<<reales.first<<endl<<"R2: "<<reales.second<<endl;
    } else {
        pair<float,float> comp = raices_comp(a,b,c);
        cout<<"R1: "<<comp.first<<" + "<<comp.second<<"i"<<endl<<"R2: "<<comp.first<<" - "<<comp.second<<"i"<<endl;
    }
    return 0;
}