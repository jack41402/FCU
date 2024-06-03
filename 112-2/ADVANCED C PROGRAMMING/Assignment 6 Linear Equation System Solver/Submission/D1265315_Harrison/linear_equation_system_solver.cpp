#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "vector.h"
#include "smatrix.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(void) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    Matrix m, equ, x;
    double ans;
    int i, j, n;

    // Input validation for the rank of the linear equation system
    do {
        cout << "Input n as the rank of the linear equation system (0 < n <= 10) : ";
        cin >> n;
    } while (n > 10 || n < 1);

    // Set the size of the coefficient matrix and fill it with random values
    m.setSize(n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m.setElement(i, j, (rand() % 9999 + 1) / 10000.0);
        }
    }

    // Display the coefficient matrix
    cout << "\nCoefficient matrix of the system of linear equations:\n";
    cout << m << "Constant vector of the system of linear equations:\n    ";

    // Set the size of the constant vector and fill it with random values
    equ.setSize(n, 1);
    for (i = 0; i < n; i++) {
        equ.setElement(i, 0, (rand() % 9999 + 1) / 10000.0);
        cout << fixed << setprecision(4) << equ.getElement(i, 0) << "   ";
    }
    cout << "\n\nSystem of linear equations:\n";

    // Display the system of linear equations
    for (i = 0; i < n; i++) {
        cout << "    ";
        for (j = 0; j < n; j++) {
            cout << fixed << setprecision(4) << m.getElement(i, j) << "X_" << j;
            if (j != n - 1) cout << "+";
        }
        cout << "=" << fixed << setprecision(4) << equ.getElement(i, 0) << '\n';
    }

    // Create an SMatrix object from the coefficient matrix
    SMatrix s(m);

    // Set the size of the solution vector
    x.setSize(n, 1);

    // Create a Vector object from the constant vector
    Vector v(equ, 0);

    // Calculate the solution using Cramer's rule
    for (i = 0; i < n; i++) {
        Matrix temp(m);
        temp = v.vector_replace(i, m);
        SMatrix stemp(temp);
        stemp.determinant();
        x.setElement(i, 0, stemp.determinant() / s.determinant());
    }

    // Display the solution of the linear equation system
    cout << "\nSolution of the linear equation system is:\n  ";
    for (i = 0; i < n; i++) cout << setw(8) << x.getElement(i, 0) << " ";
    cout << "\n\nVerify solution of the linear equation system:\n";

    // Verify the solution by substituting back into the equations
    for (i = 0; i < n; i++) {
        ans = 0.0;
        for (j = 0; j < n; j++) {
            ans = ans + m.getElement(i, j) * x.getElement(j, 0);
        }
        // Check if the solution satisfies the equation
        if (ans - equ.getElement(i, 0) < 0.000001 && ans - equ.getElement(i, 0) > -0.000001) {
            cout << "    Equation " << i << " passes.\n";
        } else {
            cout << "    Equation " << i << " not passes.\n";
        }
    }
    return 0;
}

 
