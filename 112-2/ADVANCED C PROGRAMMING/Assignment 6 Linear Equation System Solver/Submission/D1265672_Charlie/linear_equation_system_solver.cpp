#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"
using namespace std;

int main(void) {
    int n, i, j;
    srand(time(NULL));
    cout<<"Iuput n (0<n<=10): ";
    cin>>n;
    while(n<=0 || n>10){
        cout<<"Iuput again (0<n<=10): ";
        cin>>n;
    }
    
    SMatrix A(n);
    Vector C(n), X(n);
    Matrix V(n, 1);// V is used to verify.
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) { A.setElement(i, j, rand()%10001/10000.0); }
    for(i=0;i<n;i++) { C.setElement(i, 0, rand()%10001/10000.0); }
    
    cout<<"Coefficient matrix of the system of linear equations:"<<endl<<A;
    cout<<"Constant vector of the system of linear equations:"<<endl<<"  ";
    
    for(i=0;i<n;i++) cout<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<C.getElement(i, 0)<<" ";
    cout<<endl<<endl<<"System of linear equations:"<<endl;
    
    for(i=0;i<n;i++){
        cout<<"    ";
        for(j=0;j<n+1;j++){
            if(j!=n){
                if(j!=0) cout<<"+";
                cout<<setw(6)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<A.getElement(i, j)<<"X_"<<j;
            }
            else cout<<"="<<C.getElement(i, 0)<<endl;
        }
    }
    
    SMatrix R(n);
    
    for(i=0;i<n;i++) {
        R=C.vector_replace(i , A);
        X.setElement(i, 0, (double) R.determinant()/A.determinant());
    }
    cout<<endl<<"Solution of the linear equation system is:"<<endl<<"  ";
    
    for(i=0;i<n;i++) cout<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<X.getElement(i, 0)<<" ";
    cout<<endl<<endl<<"Verify solution of the linear equation system:"<<endl;
    
	V=A*X-C;
    for(i=0;i<n;i++){
        if(V.getElement(i, 0)<0.0000001) cout<<"    Equation "<<i<<" passes."<<endl;
        else cout<<"    Equation "<<i<<" fails."<<endl;
    }
    cout<<endl;
    
    return 0;
}
