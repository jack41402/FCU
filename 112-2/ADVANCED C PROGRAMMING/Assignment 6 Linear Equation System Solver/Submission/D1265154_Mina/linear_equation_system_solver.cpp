#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "matrix.h"
#include "vector.h"
#include "smatrix.h"

using namespace std;
// Function to print the system of linear equations
void printEquations(const Matrix &A, const Vector &C)
{
	int i, j;
	for(i=0;i<A.getRow();i++)
	{
		cout << "   ";
		for(j=0;j<A.getCol();j++)
		{
			cout << setw(6) << A.getElement(i, j) << "X_" << j;
			if(j < A.getCol() - 1) cout << "+";
		}
		cout << "=" << C.getElement(i, 0) << endl;
	}
}
// Function to solve for X using determinant method
double solveX(const Matrix &A, const Vector &C, int n)
{
	SMatrix deno(A), mole(C.vector_replace(n, A));
	return mole.determinant() / deno.determinant();
}
// Function to verify the solution
bool verify(const Matrix &A, const Vector &S, double d, int n)
{
	int i;
	double sum = 0;
	for(i=0;i<A.getCol();i++)
	{
		sum += A.getElement(n, i) * S.getElement(i, 0);
	}
	if(sum - d <= 0.000001) return true;
	else return false;
}

int main()
{
	srand(time(NULL));
	cout << fixed << setprecision(4);
	int i, j, n;
	Matrix A;
	Vector C, S;
	do// Input validation for matrix size
	{
		cout << "Input n as the rank of the linear equation system(0 < n <= 10): ";
		cin >> n;
	}while(!(n>0&&n<=10));
	// Setting sizes for matrices and vectors
	A.setSize(n, n);
	C.setSize(n); 
	S.setSize(n);
	// Generating random elements for A and C
	for(i=0;i<A.getRow();i++)
	{
		for(j=0;j<A.getCol();j++)
		{
			A.setElement(i, j, double(rand()%10000) / 10000);
		}
		C.setElement(i, 0, double(rand()%10000) / 10000);
	}
	// Printing the coefficient matrix and constant vector
	cout << endl << "Coefficient matrix of the system of linear equations:" << endl << A << endl;
	cout << "Constant vector of the system of linear equations:" << endl << C << endl; 
	cout << "System of linear equations:" << endl;
	printEquations(A, C);
	cout << endl;
	// Solving the linear equations
	for(i=0;i<S.getRow();i++)
	{
		S.setElement(i, 0, solveX(A, C, i));
	}
	// Printing the solution vector
	cout << "Solution of the linear equations system is:" << endl << S << endl;
	cout << "Verify solutions of the linear equations system:" << endl;
	for(i=0;i<S.getRow();i++)
	{
		if(verify(A, S, C.getElement(i, 0), i))
		{
			cout << "   " << "Equation " << i << " passes." << endl; 
		}
		else
		{
			cout << "   " << "Equation " << i << " not passes." << endl; 
		}
	}
	return 0;
}
