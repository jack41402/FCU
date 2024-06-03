#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "matrix.h"
#include "smatrix.h"
#include "vector.h"
using namespace std;

void setMatrix(Matrix& M) {
	for(int i = 0; i < M.getRow(); i++){
        for(int j = 0; j < M.getCol(); j++){
            M.setElement(i, j, (double)rand() / RAND_MAX);
        }
    }
}

int main() {
    int n;
    cout << "Enter the rank of the linear equation system: ";
    cin >> n;
    cout << endl;

    SMatrix A(n);
    Vector C(n);

    srand(time(NULL));
    setMatrix(A);
    setMatrix(C);

    cout << "Coefficient matrix of the system of linear equations:\n";
    cout << A;
    cout << "Constant vector of the system of linear equations:\n";
    cout << "    ";
    for(int i = 0; i < C.getRow(); i++) cout << fixed << setprecision(4) << C.getElement(i, 0) << "   ";
    cout << "\n\n";
    cout << "System of linear equations:\n";
    for(int i = 0; i < n; i++){
        cout << "    ";
        for(int j = 0; j < n; j++){
            cout << A.getElement(i, j) << "X_" << j;
            if(j != n-1) cout << '+';
        }
        cout << '=' << C.getElement(i, 0) << endl;
    }
    cout << endl;

    Vector X(n);
    for(int i = 0; i < n; i++){
        SMatrix Ai = C.vector_replace(i, A);
        X.setElement(i, 0, Ai.determinant() / A.determinant());
    }
    cout << "Solution of the linear equation system is:\n";
    cout << "    ";
    for(int i = 0; i < n; i++) cout << X.getElement(i, 0) << "   ";
    cout << "\n\n";

    cout << "Verify solution of the linear equation system:\n";
    Matrix sol = A * X - C;
    for(int i = 0; i < n; i++){
        if(sol.getElement(i, 0) == 0)
            cout << "    Equation " << i << " passes.\n";
        else
            cout << "    Equation " << i << " fails.\n";
    }
}
