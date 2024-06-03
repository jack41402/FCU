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

void setMatrix(Matrix & M) {
    int i, j; // Loop variables.
    for (i = 0; i < M.getRow(); i++) // For all rows,
        for (j = 0; j < M.getCol(); j++) { // For all columns,
            M.setElement(i, j, (rand() % 20001 - 10000) / 10000.0); // Set a random value.
        }
}

void printSystem(const SMatrix& A, const Vector& C) {
    int n = A.getRow();
    for (int i = 0; i < n; ++i) {
    	cout << "    ";
        for (int j = 0; j < n; ++j) {
            cout << A.getElement(i, j);
            if (j < n - 1) cout << "X_" << j << " + ";
            else cout << "X_" << j << " = ";
        }
        cout << C.getElement(i, 0) << endl;
    }
    cout << endl;
}

void printVector(const Vector& C){
	int n = C.getRow();
	cout << "    ";
	for (int i = 0; i < n; ++i){
		cout << C.getElement(i, 0) << "   ";
	}
	cout << "\n" << endl;
}

Vector solveSystem(const SMatrix& A, const Vector& C) {
    int n = A.getRow();
    double detA = A.determinant();
    if (detA == 0) {
        cout << "no unique solution exists." << endl;
        return Vector(n);
    }

    Vector X(n);
    for (int i = 0; i < n; ++i) {
        Matrix Ai = C.vector_replace(i, A);
        SMatrix Si(Ai); 
        double detAi = Si.determinant();
        X.setElement(i, 0, detAi / detA);
    }
    return X;
}

bool verifySolution(const SMatrix& A, const Vector& X, const Vector& C) {
    Matrix AX_matrix = A*X;
    Vector AX(AX_matrix, 0);  
    Matrix AX_minus_C_matrix = AX - C;
    Vector AX_minus_C(AX_minus_C_matrix, 0);
    
    int n = AX_minus_C.getRow();
    for (int i = 0; i < n; ++i) {
        if (abs(AX_minus_C.getElement(i, 0)) < 1e-6) {
            cout << "    Equation " << i << " passes." << endl; 
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    int n;
    while(n <= 0 || n > 10){
    	cout << "Enter the number of variables (n): ";
    	cin >> n;
	}

    SMatrix A(n);
    Vector C(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A.setElement(i, j, static_cast<double>(rand()) / RAND_MAX);
        }
        C.setElement(i, 0, static_cast<double>(rand()) / RAND_MAX);
    }

    cout << "Coefficient matrix of the system of linear equations:" << endl;
    cout << A << endl;

    cout << "Constant vector of the system of linear equations:" << endl;
    printVector(C);

    cout << "System of linear equations:" << endl;
    printSystem(A, C);

    Vector X = solveSystem(A, C);

    cout << "Solution vector of the system is:" << endl;
    printVector(X);
	
	cout << "Verify solution of linear equation system:" << endl;
    verifySolution(A, X, C);

    return 0;
}

