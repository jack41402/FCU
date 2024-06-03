#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Matrix.h"
#include "smatrix.h"
#include "vector.h"
using namespace std;

void print_equation(const SMatrix& A, const Vector& C, int n){//Print the linear equations
	int i, j;
	for(i=0; i<n; i++){
		cout<<"    ";
		for(j=0; j<n; j++){
			cout<<A.getElement(i, j)<<"X_"<<j;
			if(j==n-1) cout<<"=";
			else cout<<"+";
		}
		cout<<C.getElement(i, 0)<<endl;
	}
}

Vector solver(const SMatrix& A, const Vector& C, int n){//Solve the linear equation system
	int i;
	Vector X(n);
	SMatrix Ai;
	
	for(i=0; i<n; i++){
		Ai=C.vector_replace(i, A);
		X.setElement(i, 0, Ai.determinant()/A.determinant());
	}
	
	return X;
}

void verifier(const SMatrix& A, const Vector& C, const Vector& X, int n){//Verify the solutions
	const double epsilon=pow(10, -6);//Define epsilon
	
	int i;
	Matrix verification=A*X-C;//compute AX-C
	
	for(i=0; i<n; i++){
		cout<<"    Equation "<<i;
		
		//Check wheter the result is less than epsilon
		if(verification.getElement(i, 0)<=epsilon) cout<<" passes."<<endl;
		else cout<<" fails."<<endl;
	}
}

int main() {
	srand(time(NULL));
	
	int n, i, j;
	SMatrix A;
	Vector C, X;
	
	do{
		cout<<"Input n as the rank of the linear equation system, (0 < n <= 10): ";
		cin>>n;
	}while(n<0||n>10);//Check if user input is out of bound
	cout<<endl;
	
	A.setSize(n);//Set the size of SMatrix A
	C.setSize(n);//Set the size of Vector C
	
	for(i=0; i<n; i++){
		C.setElement(i, 0, (rand()%10000+1)/10000.0);//Set element for C
		for(j=0; j<n; j++){
			A.setElement(i, j, (rand()%10000+1)/10000.0);//Set element for A
		}
	}
	
	
	cout<<"Coefficient matrix of the system of linear equations:"<<endl;
	cout<<A;
	
	cout<<endl<<"Constant vector of the system of linear equations:"<<endl;
	cout<<-C;//Print the transposed matrix of C
	
	cout<<endl<<"System of linear equations:"<<endl;
	print_equation(A, C, n);
	
	X=solver(A, C, n);
	cout<<endl<<"Solution of the linear equation system is:"<<endl;
	cout<<-X;//Print the transposed matrix of X
	
	cout<<endl<<"Verify solution of the linear equation system:"<<endl;
	verifier(A, C, X, n);
	

	return 0;
}
