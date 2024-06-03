#include"matrix.h"
#include"smatrix.h"
#include"vector.h"
#include<ctime>
#include<iomanip>
#include<cmath>

const double TOLERANCE = 1e-6;

void showSystemOfLinearEquations(SMatrix A, Vector C) {
	for (int i = 0; i < A.getRow(); i++) {
		cout << "   ";
		for (int j = 0; j < A.getCol(); j++) {
			cout << fixed << setprecision(4);
			cout << A.getElement(i, j) << "X_" << j;
			if (j != A.getCol() - 1)cout << "+";
		}
		cout << "=" << C.getElement(i, 0)<<"\n";
	}
	cout << "\n";
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int n;
	cout << "Input n as the rank of the linear equation system, 0 < n ¡Ü 10:";
	cin >> n;
	SMatrix A(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double v= static_cast<double>(rand()) / RAND_MAX;
			A.setElement(i, j, v);
		}
	}
	cout << "Coefficient matrix of the system of linear equations:\n";
	cout << A << "\n";
	cout << "Constant vector of the system of linear equations:\n";
	Vector C(n);
	for (int i = 0; i < n; i++) {
		double v = static_cast<double>(rand()) / RAND_MAX;
		C.setElement(i,0,v);
	}
	cout << C << "\n";
	cout << "System of linear equations:\n";
	showSystemOfLinearEquations(A, C);
	Vector X(n);
	cout << "Solution of the linear equation system is:\n";
	double A_value= A.determinant();
	for (int i = 0; i < n; i++) {
		SMatrix tA = C.vector_replace(i, A);
		double x = tA.determinant() / A_value;
		X.setElement(i, 0,x);
	}
	cout << X << "\n";
	cout << "Verify solution of the linear equation system:\n";
	Matrix AX = A * X;
	for (int i = 0; i < AX.getRow(); i++) {
		if (abs(C.getElement(i, 0) - AX.getElement(i, 0)) <= TOLERANCE) {
			cout << "   Equation " << i << " passes.\n";
		}
		else {
			cout << "   Equation " << i << " unpasses.\n";
		}
	}

}