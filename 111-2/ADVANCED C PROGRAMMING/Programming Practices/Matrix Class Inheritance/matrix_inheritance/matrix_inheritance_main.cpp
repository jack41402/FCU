#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix_inheritance.h"
#include "smatrix_inheritance.h"
#include "vector_inheritance.h"

void setMatrix(Matrix & M) {
	int i, j; // Loop variables.
	
	// Set a random floating point number between -1 and 1 (including) 
	// with 4 digits after the decimal point.
	for (i=0; i<M.getRow(); i++) // For all rows,
	  for (j=0; j<M.getCol(); j++) { // For all columns,
	  	M.setElement(i, j, (rand() % 20001 -10000) / 10000.0); // Set a random value.
		}
}

int main() {
	Matrix A(4,5), B(4, 5), C(4, 4), D(5, 5); // Matrices
	Vector U(4), V(4), W(5); // Vectors
	SMatrix R(4), S(4), T(5); // Square matrices
	double f, g; // Scalars
	
	srand(time(NULL));
	setMatrix(A);
	setMatrix(B);
	setMatrix(C);
	setMatrix(D);
	
	setMatrix(U);
	setMatrix(V);
	setMatrix(W);
	
	setMatrix(R);
	setMatrix(S);
	setMatrix(T);
	
	cout << "Input scalars f and g: ";
	cin >> f >> g;
	cout << endl;
	
	cout << "Matrix A: " << A.getRow() << " X " << A.getCol() << endl << A;
	cout << "Matrix B: " << B.getRow() << " X " << B.getCol() << endl << B;
	cout << "Matrix C: " << C.getRow() << " X " << C.getCol() << endl << C;
	cout << "Matrix D: " << D.getRow() << " X " << D.getCol() << endl << D;
	cout << "Vectro U: " << U.getRow() << " X " << U.getCol() << endl << U;
	cout << "Vectro V: " << V.getRow() << " X " << V.getCol() << endl << V;
	cout << "Vectro W: " << W.getRow() << " X " << W.getCol() << endl << W;
	cout << "Square Matrix R: " << R.getRow() << " X " << R.getCol() << endl << R;
	cout << "Square Matrix S: " << S.getRow() << " X " << S.getCol() << endl << S;
	cout << "Square Matrix T: " << T.getRow() << " X " << T.getCol() << endl << T;
	cout << "Scalars f and g: " << f << ", " << g << endl;
	cout << "======================================================" << endl;
	
	cout << "**** Expression A+B: " << endl << A+B;
	cout << "**** Expression A+f: " << endl << A+f;
	cout << "**** Expression g+A: " << endl << g+A;
	cout << "**** Expression A+C: " << endl;
	cout << A+C;
	
	cout << "**** Expression A-B: " << endl << A-B;
	cout << "**** Expression A-f: " << endl << A-f;
	cout << "**** Expression g-A: " << endl << g-A;
	cout << "**** Expression A-C: " << endl;
	cout << A-C;
	
	cout << "**** Expression A*D: " << endl << A*D;
	cout << "**** Expression A*f: " << endl << A*f;
	cout << "**** Expression g*A: " << endl << g*A;
	cout << "**** Expression A*C: " << endl;
	cout << A*C;
	
	cout << "**** Expression -A*B: " << endl << -A*B;
	cout << "**** Expression A*(-B): " << endl << A*(-B);
	cout << "======================================================" << endl;
	
	cout << "**** Expression -U*V: (" << U.getCol() << " X " << V.getCol() << " matrix)" << endl;
	cout << -U*V;
	cout << "**** Expression U*(-V): (" << U.getRow() << " X " << V.getRow() << " matrix)" << endl;
	cout << ((Matrix) U)*(-V);
	cout << "**** Expression U*V: (scalar) " << U*V << endl;
	cout << "======================================================" << endl;
	
	cout << "**** Expression S*A: (" << S.getRow() << " X " << A.getCol() << " matrix)" << endl;
	cout << S*A;
	cout << "**** Expression -A*S: (" << A.getCol() << " X " << S.getCol() << " matrix)" << endl;
	cout << -A*S;
	cout << "**** Expression S*(-S): (" << S.getRow() << " X " << S.getRow() << " matrix)" << endl;
	cout << S*(-S);
	cout << "**** Expression (-S)*S: (" << S.getCol() << " X " << S.getCol() << " matrix)" << endl;
	cout << (-S)*S;
	cout << "**** Expression A*T: (" << A.getRow() << " X " << T.getCol() << " matrix)" << endl;
	cout << A*T;
	cout << "======================================================" << endl;
	
	double a=R.determinant(), b=S.determinant(), c=(R*S).determinant();
	cout << "|R|=" << a << ", |S|=" << b << ", |R*S|=" << c << endl;
	if (abs(a*b-c)<0.0001) cout << "|R|*|S| is equal to |R*S|." << endl; 
	else cout << "|R|*|S| is not equal to |R*S|." << endl;
	cout << "======================================================" << endl;
	
	Matrix H;
	
	H = f*A+B*D;
	cout << "Execute statement \"H = f*A+B*D;\". Matrix H: ";
	cout << H.getRow() << " X " << H.getCol() << endl << H;
	
	H = D-(-A)*C*B;
	cout << "Execute statement \"H = D-(-A)*C*B;\". Matrix H: ";
	cout << H.getRow() << " X " << H.getCol() << endl << H;
	
	H = U*V*C*T.determinant();
	cout << "Execute statement \"H=U*V*C*|T|;\". Matrix H: ";
	cout << H.getRow() << " X " << H.getCol() << endl << H;
	
	system("pause");
}
