#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"
using namespace std;

int main(void) {
    Complex r1, r2;// Declare two complex variables.
    double a, b, c, D;
    int ver;
    cout<<"Enter coefficients a, b, and c: ";
    cin>>a>>b>>c;
    cout << fixed << setprecision(4);
    while(a==0){
        cout<<"Enter coefficients a, b, and c again: ";
        cin>>a>>b>>c;
    }
    cout<<endl<<"The two roots of quadratic equation ";
    if(a==1) cout<<"X**2";
    else if(a==-1) cout<<"-X**2";
    else cout<<a<<"X**2";
    if(b==1) cout<<"+X";
    else if(b==-1) cout<<"-X";
    else if(b>0) cout<<"+"<<b<<"X";
    else if(b<0) cout<<b<<"X";
    if(c>0) cout<<"+"<<c<<"=0.0000 are:"<<endl;
    else if(c<0) cout<<c<<"=0.0000 are:"<<endl;
    D=b*b-4*a*c;
    if(D<0){
        r1.setIm(sqrt(abs(D))/(2*a));
        r1.setRe(-b/(2*a));
        r2.setIm(-sqrt(abs(D))/(2*a));
        r2.setRe(-b/(2*a));
    }
    else{
        r1=(-b+sqrt(b*b-4*a*c))/(2*a);
        r2=(-b-sqrt(b*b-4*a*c))/(2*a);
    }
    cout<<"        "<<r1<<" and "<<r2<<endl;
    ver=((a*r1*r1+b*r1+c).cabs()<0.000001 && (a*r2*r2+b*r2+c).cabs()<0.000001)?1:0;
    if(ver) cout<<"Verification of the two quadratic equation roots PASSES."<<endl<<endl<<endl;
    else cout<<"Verification of the two quadratic equation roots FAILS."<<endl<<endl<<endl;
    return 0;
}
