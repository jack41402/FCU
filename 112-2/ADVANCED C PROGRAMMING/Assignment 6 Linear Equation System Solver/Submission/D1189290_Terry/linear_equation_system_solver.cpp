#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"

using namespace std;

void generateRandomMatrix(SMatrix &mat) {
    int n = mat.getRow();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            mat.setElement(i, j, static_cast<double>(rand()) / RAND_MAX);
        }
    }
}

void generateRandomVector(Vector &vec) {
    int n = vec.getRow();
    for(int i = 0; i < n; ++i) {
        vec.setElement(i, 0, static_cast<double>(rand()) / RAND_MAX);
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Input n as the rank of the linear equation system, 0 < n <= 10: ";
    cin >> n;

    if(n <= 0 || n > 10) {
        cout << "Invalid rank. Program will exit." << endl;
        return 1;
    }

    SMatrix A(n);
    generateRandomMatrix(A);

    Vector C(n);
    generateRandomVector(C);

    cout << "Coefficient matrix of the system of linear equations:" << endl;
    cout << fixed << setprecision(4); // Set precision to 4 decimal places
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << setw(8) << A.getElement(i, j);
        }
        cout << endl;
    }

    cout << "Constant vector of the system of linear equations:" << endl;
    for(int i = 0; i < n; ++i) {
        cout << setw(8) << C.getElement(i, 0);
    }
    cout << endl << endl;

    cout << "System of linear equations:" << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << setw(8) << A.getElement(i, j) << "X_" << j;
            if(j < n - 1) {
                cout << " + ";
            }
        }
        cout << " = " << C.getElement(i, 0) << endl;
    }
    cout << endl;

    Vector X(n);
    double detA = A.determinant();
    cout << "Determinant of A: " << detA << endl; // Debugging statement
    if(detA == 0) {
        cout << "The system has no unique solution (determinant is zero)." << endl;
        return 1;
    }

    for(int i = 0; i < n; ++i) {
        SMatrix Ai = A;
        Ai = X.vector_replace(i, A);
        double detAi = Ai.determinant();
        cout << "Determinant of A with column " << i << " replaced: " << detAi << endl; // Debugging statement
        X.setElement(i, 0, detAi / detA);
    }

    cout << "Solution of the linear equation system is:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(8) << X.getElement(i, 0);
    }
    cout << endl << endl;

    cout << "Verify solution of the linear equation system:" << endl;
    for(int i = 0; i < n; ++i) {
        double sum = 0;
        for(int j = 0; j < n; ++j) {
            sum += A.getElement(i, j) * X.getElement(j, 0);
        }
        if(fabs(sum - C.getElement(i, 0)) < 1e-6) {
            cout << "Equation " << i + 1 << " passes." << endl;
        } else {
            cout << "Equation " << i + 1 << " fails." << endl;
        }
    }

    return 0;
}

