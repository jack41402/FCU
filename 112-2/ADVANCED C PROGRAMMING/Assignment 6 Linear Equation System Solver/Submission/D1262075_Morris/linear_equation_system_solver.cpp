#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "matrix.h"   
#include "smatrix.h"  
#include "vector.h"

using namespace std;

int main() {
    srand(time(0));  // Set random seed based on current time

    int n;
    cout << "Enter the rank of the linear equation system (1-10): ";
    cin >> n;
    cout << endl;
    cout << fixed << setprecision(4);  // Set output precision to 4 decimal places
    if (n < 1 || n > 10) {
        cerr << "Invalid rank." << endl;  // Print error message and exit if rank is invalid
        return 1;
    }

    SMatrix A(n);    // Create a random n x n special matrix A
    Vector C(n);     // Create a random n-dimensional vector C

    // Initialize elements of matrix A and vector C with random values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A.setElement(i, j, static_cast<double>(rand()) / RAND_MAX);
        }
        C.setElement(i, 0, static_cast<double>(rand()) / RAND_MAX);
    }

    // Print coefficient matrix of the linear equation system
    cout << "Coefficient matrix of the system of linear equations:" << endl << A;
    cout << endl;
    // Print constant vector of the linear equation system
    cout << "Constant vector of the system of linear equations:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "    " << C.getElement(i, 0);
    }    
    
    cout << endl;
    // Print the system of linear equations
    cout << "System of linear equations:" << endl;
    for (int i = 0; i < n; ++i) {
    	cout << "    ";
        for (int j = 0; j < n; ++j) {
            cout << A.getElement(i, j) << "X_" << j;
            if (j < n - 1) cout << " + ";
        }
        cout << " = " << C.getElement(i, 0) << endl;
    }
    cout << endl;
    
    double detA = A.determinant();
    if (fabs(detA) < 1e-6) {
        cerr << "The system has no unique solution." << endl;
        return 1;
    }

    Vector X(n);
    // Solve the linear equation system using Cramer's rule
    for (int i = 0; i < n; ++i) {
        SMatrix Ai = C.vector_replace(i, A);
        X.setElement(i, 0, Ai.determinant() / detA);
    }
    cout << endl;
    
    // Print the solution of the linear equation system
    cout << "Solution of the linear equation system is:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "    " << X.getElement(i, 0);
    } 
    cout << endl;
    
    bool allPass = true;
    
    // Verify the solution of the linear equation system
    cout << "Verify solution of the linear equation system:" << endl;
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            sum += A.getElement(i, j) * X.getElement(j, 0);
        }
        double diff = sum - C.getElement(i, 0);
        if (fabs(diff) > 1e-6) {
            cout << "    Equation " << i << " fails." << endl;
            allPass = false;
        } else {
            cout << "    Equation " << i << " passes." << endl;
        }
    }

    return 0;
}
