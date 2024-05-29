#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

int main() {
	SMatrix A; // Coefficient matrix.
	Vector C; // Constant vector.
	Vector X; // Solution vector. 
	int n; // Rank of the linear equation system.
	int i, j; // Loop variables.

	srand(time(NULL));
	
	cout << "Enter rank n of the linear equation system (0<n<=10): ";
	cin >> n; 
	cout << endl;
	
	A.setSize(n); // Set the size of the coefficient matrix. 
	C.setSize(n); // Set the size of the constant vector.
	X.setSize(n); // Set the size of the solution vector.
	
	for (i=0; i<n; i++) {
		// Set element values of the coefficient matrix.
		for (j=0; j<n; j++) A.setElement(i, j, (rand()%10000)/10000.0);
		C.setElement(i, 0, (rand()%10000)/10000.0); // Set element values of the constant vector.
	}
	
	cout << "Coefficient matrix of the system of linear equations:" << endl;
	cout << A; 
	
	cout << "Constant vector of the system of linear equations:" << endl; 
	cout << -C;
	
	cout << "System of linear equations:" << endl;
	for (i=0; i<n; i++) {
		cout << "    "; 
		for (j=0; j<n; j++) {
			cout << A.getElement(i,j) << "X_" << j;
			if (j<n-1) cout << "+";
			else cout << "=";
		}
		cout << C.getElement(i, 0) << endl;		
	}
	cout << endl;
	
	double det = A.determinant(); // Determinant of the coefficient matrix.
	// Computer the solution vector.
	for (i=0; i<n; i++) X.setElement(i, 0, (((SMatrix) C.vector_replace(i, A)).determinant())/det);
	cout << "Solution of the linear equation system is:" << endl;
	cout << -X;
	
	cout << "Verify solution of the linear equation system:" << endl;
	Matrix check = A * X - C;
	for (i=0; i<n; i++)
		if (abs(check.getElement(i, 0))<0.000001) cout << "    Equation " << i << " passes." << endl;
		else cout << "    Equation " << i << " fails." << endl;
}
