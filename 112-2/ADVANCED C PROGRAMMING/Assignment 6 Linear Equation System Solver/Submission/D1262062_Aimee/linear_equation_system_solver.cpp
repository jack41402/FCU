#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

using namespace std;
//Solve the linear equation
void solve(const SMatrix& A, const Vector& C) {
	int i;
    double detA = A.determinant();
    int n = A.getRow();
    if (fabs(detA) < 1e-6) {
        cout << ("The system has no unique solution (det(A) is zero).");
    }
    Vector X(n);
    for (i=0; i<n; i++) {
		SMatrix Ai = C.vector_replace(i, A);
        double detAi = Ai.determinant();
        X.setElement(i, 0, (double) detAi / detA);
    }
    cout << "\nSolution of the linear equation system is:\n  ";
    for(i=0; i<n; i++) cout << setw(8) << setiosflags(ios::fixed | ios::showpoint) << setprecision(4) << X.getElement(i, 0) << " ";
    cout << endl;
    // Verify the solution
    cout << "\nVerify solution of the linear equation system:" << endl; 
    Matrix AX(n, 1);
	AX = A*X-C;
    for (i=0; i<n; i++) {
        if (fabs(AX.getElement(i, 0)) > 1e-6)  cout << "    Equation " << i << " failed" << endl; 
        else cout << "    Equation " << i << " passes" << endl; 
    }
}

int main(void) {
	int i, j;
    srand(time(NULL));
    int n;
    do{
    	cout << "Enter the rank of the linear equation system: ";
    	cin >> n;
	}while( n <= 0 || n > 10);
    SMatrix A(n);
    Vector C(n);
    Vector X(n);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            double elemA = static_cast<double>(rand()) / RAND_MAX; 
            A.setElement(i, j, elemA);
        }
        double elemC = static_cast<double>(rand()) / RAND_MAX;
        C.setElement(i, 0, elemC);
    }
    cout << "\nCoefficient matrix of the system of linear equation: \n" << A;
    cout << "Constant vector of the system of linear equation: \n  ";
    for(i=0; i<n; i++) cout << setw(8) << setiosflags(ios::fixed | ios::showpoint) << setprecision(4) << C.getElement(i, 0) << " ";
    cout << "\n\nSystem of linear equations: \n";
    for(i=0; i<n; i++) {
    	cout << "    ";
    	for(j=0; j<n; j++) {
        	cout << A.getElement(i, j) << "X_" << j;
        	if (j < n - 1) cout << "+";
    	}
    	cout << "=" << C.getElement(i, 0) << endl;
	}
	solve(A, C);
    return 0;
}
