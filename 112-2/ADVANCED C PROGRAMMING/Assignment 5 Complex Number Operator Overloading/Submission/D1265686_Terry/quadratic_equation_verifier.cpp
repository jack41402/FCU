#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "complex_overloading.h"
using namespace std;

int main(void) {
    
    double a, b, c, r;
    
    Complex root1, root2;
    
    int t;
    
    while(1){
        
        
        cout<<"Enter coefficients a, b, and c: ";
        cin>>a>>b>>c;
        
        //determine whether a is 0
        while(a==0){
            cout<<"Enter coefficients a, b, and c again: ";
            cin>>a>>b>>c;
        }
        
        
        cout<<endl<<"The two roots of quadratic equation ";
        
        //Perform a series of judgments to meet the program’s output requirements
        if(a==1)
        {
            cout<<"X**2";
        }
        else if(a==-1)
        {
            cout<<"-X**2";
        }
        else
        {
            cout<< fixed << setprecision(4)<<a<<"X**2";
        }
        
        if(b==1)
        {
            cout<<"+X";
        }
        
        else if(b==-1) 
        {
            cout<<"-X";
        }
        else if(b>0)
        {
            cout<< fixed << setprecision(4)<<"+"<<b<<"X";
        }
        else if(b<0)
        {
            cout<< fixed << setprecision(4)<<b<<"X";
        }
        
        if(c>0)
        {
            cout<< fixed << setprecision(4)<<"+"<<c<<"=0.0000 are:"<<endl;
        }
        else if(c<0)
        {
            cout<< fixed << setprecision(4)<<c<<"=0.0000 are:"<<endl;
        }
        
        r = b*b -4 * a * c;
        
        if(r<0){
            
            root1.setIm(sqrt ( fabs(r) ) / (2 * a));
            
            root1.setRe( -b / (2*a) );
            
            root2.setIm( -sqrt (fabs(r)) / (2*a));
            
            root2.setRe(-b / (2 * a));
            
        }
        
        else{
            
            root1=( -b + sqrt (b*b-4*a*c)) / (2*a);
            root2=( -b - sqrt (b*b-4*a*c)) / (2*a);
            
        }
        
        cout<<"        "<<root1<<" and "<<root2<<endl;
        
        t=(( a * root1 * root1 + b * root1 + c ).cabs() < 0.000001 && (a * root2 * root2 + b * root2+ c).cabs()<0.000001)?1:0;
        
        if(t) cout<<"Verification of the two quadratic equation roots PASSES."<<endl<<endl<<endl;
        
        else cout<<"Verification of the two quadratic equation roots FAILS."<<endl<<endl<<endl;
    }
    return 0;
}

