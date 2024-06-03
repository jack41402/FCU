#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

using namespace std;

int main(void) {
    int p, i, j;
    srand(time(NULL)); // Seed the random number generator with the current time
    cin >> p;

    // Ensure the value of p is within the valid range (0 < p <= 10)
    while(p <= 0 || p > 10) {
        cout << "Input again (0<p<=10): ";
        cin >> p;
    }

    SMatrix A(p);  // Declare square matrix A of size p
    Vector C(p), X(p);  // Declare vectors C and X of size p
    Matrix V(p, 1);  // Matrix V for verification purposes

    // Populate matrix A with random values
    for(i = 0; i < p; i++) {
        for(j = 0; j < p; j++) {
            A.setElement(i, j, rand() % 10001 / 10000.0);
        }
    }

    // Populate vector C with random values
    for(i = 0; i < p; i++) {
        C.setElement(i, 0, rand() % 10001 / 10000.0);
    }

    // Display the coefficient matrix A
    cout << "Coefficient matrix of the system of linear equations:" << endl << A;
    
    // Display the constant vector C
    cout << "Constant vector of the system of linear equations:" << endl << "  ";
    for(i = 0; i < p; i++) {
        cout << setw(8) << setiosflags(ios::fixed | ios::showpoint) << setprecision(4) << C.getElement(i, 0) << " ";
    }
    cout << endl << endl << "System of linear equations:" << endl;

    // Display the system of linear equations
    for(i = 0; i < p; i++) {
        cout << "    ";
        for(j = 0; j < p + 1; j++) {
            if(j != p) {
                if(j != 0) cout << "+";
                cout << setw(6) << setiosflags(ios::fixed | ios::showpoint) << setprecision(4) << A.getElement(i, j) << "X_" << j;
            } else {
                cout << "=" << C.getElement(i, 0) << endl;
            }
        }
    }

    // Solve the system of linear equations using Cramer's rule
    SMatrix R(p);
    for(i = 0; i < p; i++) {
        R = C.vector_replace(i, A);
        X.setElement(i, 0, (double) R.determinant() / A.determinant());
    }

    // Display the solution vector X
    cout << endl << "Solution of the linear equation system is:" << endl << "  ";
    for(i = 0; i < p; i++) {
        cout << setw(8) << setiosflags(ios::fixed | ios::showpoint) << setprecision(4) << X.getElement(i, 0) << " ";
    }
    cout << endl << endl << "Verify solution of the linear equation system:" << endl;

    // Verify the solution by calculating V = A * X - C
    V = A * X - C;
    for(i = 0; i < p; i++) {
        if(V.getElement(i, 0) < 0.0000001) {
            cout << "    Equation " << i << " passes." << endl;
        } else {
            cout << "    Equation " << i << " fails." << endl;
        }
    }
    cout << endl;
    return 0;
}

