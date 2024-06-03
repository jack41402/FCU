//
//  main.cpp
//  Assignment6_D1265065
//
//  Created by Corrine  on 2024/5/20.
//
#include "matrix.h"
#include "vector.h"
#include "smatrix.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
// Function to generate a random number between 0 and 1
double random_double() {
    return static_cast<double>(rand()) / RAND_MAX;
}

Vector solveLinearSystem(SMatrix& A, Vector& C){
    int n = A.getRow();
        Vector X(n);
        // Gaussian elimination (without pivoting for simplicity)
        for(int i = 0; i < n; ++i) {
            // Scale the row to make the diagonal element 1
            double scale = A.getElement(i, i);
            for(int j = 0; j < n; ++j) {
                A.setElement(i, j, A.getElement(i, j) / scale);
            }
            C.setElement(i, 0, C.getElement(i, 0) / scale);


            // Eliminate the current column from rows below
            for(int k = i + 1; k < n; ++k) {
                double factor = A.getElement(k, i);
                for(int j = i; j < n; ++j) {
                    A.setElement(k, j, A.getElement(k, j) - factor * A.getElement(i, j));
                }
                C.setElement(k, 0, C.getElement(k, 0) - factor * C.getElement(i, 0));
            }
        }
    // Back substitution
        for(int i = n - 1; i >= 0; --i) {
            X.setElement(i, 0, C.getElement(i, 0));
            for(int j = i + 1; j < n; ++j) {
                X.setElement(i, 0, X.getElement(i, 0) - A.getElement(i, j) * X.getElement(j, 0));
            }
        }
        return X;
}

bool verifySolution(SMatrix& A, Vector& X, Vector& C) {
    int n = A.getRow();
    Vector result(n);
    for(int i = 0; i < n; ++i) {
        double sum = 0.0;
        for(int j = 0; j < n; ++j) {
            sum += A.getElement(i, j) * X.getElement(j, 0);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(fabs(result.getElement(i, 0) - C.getElement(i, 0)) > 1e-6) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    srand(time(NULL));// Seed the random number generator with the current time
    int n;// Prompt the user to enter the rank of the linear equation system
    cout << "Enter the rank of the linear equation system (0 < n <= 10): ";
    cin >> n;
    // Validate the input rank
    if (n < 0 || n > 10){
        cout << "Invalid rank. Must be between 1 and 10." << endl;
        return 1;// Exit the program
    }
    // Create an n x n sparse matrix A and a vector C of length n
    SMatrix A(n);
    Vector C(n);
    // Fill the elements of matrix A and vector C with random values
    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A.setElement(i, j, random_double());// Set elements of matrix A
            }
            C.setElement(i, 0, random_double());// Set elements of vector C
        }
    // Output the coefficient matrix A
    cout << "Coefficient matrix of the system of linear equations:"<< endl;
    cout << A;
    // Output the constant vector C
    cout << "Constant vector of the system of linear equations:"  << endl;
    cout << " ";
    for (int i = 0; i < n; ++i) {
        cout <<"   "<< C.getElement(i, 0) ;
    }
    cout << endl << endl;
    // Output the system of linear equations
    cout << "System of linear equations:" << endl;
    for (int i = 0; i < n; i++){
        cout << "    ";
        for (int j = 0; j < n; j++){
            cout << A.getElement(i, j) << "X_" << j;
            if (j == n-1) {
                cout << "=";
                cout << C.getElement(i, 0);
            }
            else cout << "+";
        }
        cout << endl;
    }
    cout << endl;
    // Solve the system of linear equations and store the result in vector X
    Vector X = solveLinearSystem(A, C);
    // Output the solution vector X
    cout << "Solution of the linear equation system is:" << endl;
    cout << " ";
    for (int i = 0; i < n; ++i) {
    cout <<"   "<< X.getElement(i, 0) ;
    }
    cout << endl << endl;
    bool allPass = true;
    // Verify the correctness of the solution vector X
    cout << "Verify solution of the linear equation system:" << endl;
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        cout << "    ";
        for (int j = 0; j < n; ++j) {
            sum += A.getElement(i, j) * X.getElement(j, 0);
        }
        // Check if the difference between sum and the corresponding element in vector C is within the allowable error margin
        double diff = sum - C.getElement(i, 0);
        if (fabs(diff) > 1e-6) {
            cout << "Equation " << i << " fails." << endl;
            allPass = false;
        } else {
            cout << "Equation " << i << " passes." << endl;
        }
    }
    return 0;
}
