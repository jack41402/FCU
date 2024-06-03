#include <iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iomanip>
#include"matrix.h"
#include"vector.h"
#include"smatrix.h"

using std::cout;
using std::cin;
using std::ios;
using std::endl;
//set matrix function with random number
void setMatrix(Matrix& n){
	int i, j;
	for (i = 0; i<n.getRow(); i++){
		for (j = 0; j<n.getCol(); j++){
			n.setElement(i, j, (rand() % 10000) / 10000.0);
		}
	}
}

int main(){
	int n, i, j, k;//loop variable
	do{
		cin>>n;
	}while(n<=0 || n>10);
	srand(time(NULL));
	Vector B(n);//const vector
	setMatrix(B);
	Matrix A(n, n), temp(n, n);//coefficient, temp matrix
	SMatrix deno(n), numer(n);//numerator, Denominator square matrix
	setMatrix(A);
	Vector sol(n);//solution vector
	double d, nu, verify = 0;
	

	cout<<"Coefficient matrix of the system of linear equation:"<<"\n"<<A<<"\n";//print out coefficient matrix
	cout<<"Constant vector of the system of linear equations:"<<"\n"<<"    ";
	//print out constant vector
	for (i = 0; i<n; i++){
		cout<<B.getElement(i, 0)<<"   ";
	}
	cout<<"\n";
	cout<<"\n"<<"System of linear equation:"<<"\n";
	//print out the linear equation
	for (i = 0; i<n; i++){
		cout<<"    ";
		for (j = 0; j<n; j++){
			if (j<n-1){
				cout<<A.getElement(i, j)<<"X_"<<j<<"+";
			}
			else{
				cout<<A.getElement(i, j)<<"X_"<<j<<"="<<B.getElement(i, 0);
			}
		}
		cout<<"\n";
	}
	cout<<"\n"<<"Solution of the linear equation:"<<"\n"<<"  ";
	//calculate and print out the soluation vector
	for (i = 0; i<n; i++){
		temp = B.vector_replace(i, A);
		for (j = 0; j<n; j++){
			for (k = 0; k<n; k++){
				deno.setElement(j, k, A.getElement(j, k));
				numer.setElement(j, k, temp.getElement(j, k));
			}
		}
		d = deno.determinant();
		nu = numer.determinant();
		sol.setElement(i, 0, nu/d);
		cout<<setw(8)<<sol.getElement(i, 0)<<" ";
	}
	cout<<"\n\n";
	cout<<"Verify solution of the linear equation system:"<<"\n"<<"    ";
	//verify the solution
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			verify += A.getElement(i, j)*sol.getElement(j, 0);
		}
		verify -= B.getElement(i, 0);
		if (verify>0.000001){
			cout<<"Equation failed"<<"\n";
		}
		else{
			cout<<"Equation "<<i<<" "<<"passes."<<"\n"<<"    ";
		}
	}
	
	return 0;
}
