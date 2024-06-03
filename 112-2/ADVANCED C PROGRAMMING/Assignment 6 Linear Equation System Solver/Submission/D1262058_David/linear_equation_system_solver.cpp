#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

void setMatrix(Matrix & M) {
	int a, i, j; // Loop variables.
	
	// Set a random floating point number between -1 and 1 (including) 
	// with 4 digits after the decimal point.
	for (i=0; i<M.getRow(); i++) // For all rows,
	  for (j=0; j<M.getCol(); j++) { // For all columns,
	  	M.setElement(i, j, (rand() % 10000) / 10000.0); // Set a random value.
		}
}

int main() {
	int a, i, j; // loop variable
	int n; // matrix size
	double det, odet;
	double vrfy = 0;
	do{
		cin >> n;
	}while(n<0 || n>10);

	Vector C(n); // Vectors
	Vector ans(n);
	Matrix A(n, n); // Square matrices
	SMatrix B(n);
	Matrix temp(n, n);
	SMatrix stemp(n);

	srand(time(NULL));
	setMatrix(A);
	setMatrix(C);
	
	//print cosfficients
	cout << "Coefficient matrix of the system of linear equations: " << endl;
	cout << A;
	cout << "Constant vector of the sysyem of linear equations: " << endl << "    ";
	for(i=0; i<n; i++){
		cout << C.getElement(i, 0) << "   " ;
	}
	cout << endl << endl;
	
	//print equation
	cout << "System of linear equations: "<< endl;
	for(i=0; i<n; i++){
		cout << "    ";
		for(j=0; j<n; j++){
			cout << A.getElement(i, j) << "X_" << j;
			if(j < n-1) cout << "+";
		}
		cout << "=" << C.getElement(i, 0) << endl;
	}
	cout << endl;
	
	//calculate and print solution
	cout << "Solution of the linear equation system is: " << endl <<" ";
	for(a=0; a<n; a++){
		temp = C.vector_replace(a, A);
		//creat square matrix with replaced column
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				B.setElement(i, j, A.getElement(i, j));
				stemp.setElement(i, j, temp.getElement(i, j));
			}
		}
		odet = B.determinant();
		det = stemp.determinant();
		ans.setElement(a, 0, det/odet);
		cout << setw(9) << ans.getElement(a, 0);
	}
	cout << endl << endl;
	
	//verify
	cout << "Verify solution of the linear equation system:" << endl;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			vrfy += A.getElement(i, j)*ans.getElement(j, 0);
		}
		vrfy -= C.getElement(i, 0);
		if(vrfy<0.000001){
			cout << "    " << "Equation " << i << " passes." << endl;
		}
		else{
			cout << "verification failed";
			return 0;
		}
	}
}
