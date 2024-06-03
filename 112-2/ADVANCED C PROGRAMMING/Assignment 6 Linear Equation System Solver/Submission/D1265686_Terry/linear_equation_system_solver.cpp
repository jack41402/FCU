#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

using namespace std;

int main(void) {
    
    int e; // Variable to hold the size of the matrix and vectors
    
    srand(time(NULL));
    
    // Read the size of the matrix and vectors from the user
    cin >> e;
    
    // Ensure the size is within the valid range
    while (e<=0 || e>10){
        
        cout<<"Iuput again (0<n<=10): ";
        cin>>e;
    }
    
    SMatrix A(e);
    
    Vector C(e), X(e);
    
    Matrix V(e, 1); 
    
    // Populate matrix A with random values
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<e;j++)
        {
            A.setElement(i, j, rand()%10001/10000.0);
        }
    }
    
    // Populate vector C with random values
    for(int i=0;i<e;i++)
    {
        C.setElement(i, 0, rand()%10001/10000.0);
    }
    
    cout<<"Coefficient matrix of the system of linear equations:"<<endl<<A;
    cout<<"Constant vector of the system of linear equations:"<<endl<<"  ";
    
    for(int i=0;i<e;i++)
    {
        cout<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<C.getElement(i, 0)<<" ";
    }
    
    cout<<endl<<endl<<"System of linear equations:"<<endl;
    
    
    for(int i=0;i<e;i++){
        cout<<"    ";
        for(int j=0;j<e+1;j++){
            if(j!=e){
                if(j!=0) cout<<"+";
                cout<<setw(6)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<A.getElement(i, j)<<"X_"<<j;
            }
            else cout<<"="<<C.getElement(i, 0)<<endl;
        }
    }
    
    SMatrix R(e); // Temporary matrix for Cramer's rule calculations
    
    // Use Cramer's rule to solve the system of linear equations
    for(int i=0;i<e;i++) {
        
        R=C.vector_replace(i , A); // Replace column i of A with C
        X.setElement(i, 0, (double) R.determinant()/A.determinant()); // Calculate the solution for X_i
        
    }
    
    cout<<endl<<"Solution of the linear equation system is:"<<endl<<"  ";
    
    for(int i=0;i<e;i++)
    {
        cout<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<X.getElement(i, 0)<<" ";
    }
    
    // Verify the solution by calculating A*X - C
    cout<<endl<<endl<<"Verify solution of the linear equation system:"<<endl;
    
    V=A*X-C;
    
    // Check if the residuals are close to zero
    for(int i=0;i<e;i++)
    {
        if(V.getElement(i, 0)<0.0000001) cout<<"    Equation "<<i<<" passes."<<endl;
        else cout<<"    Equation "<<i<<" fails."<<endl;
    }
    
    cout<<endl;
    
    return 0;
}

