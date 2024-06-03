#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"

using namespace std;
	
// Pretty printing of the quadratic equation.
void printEquation(double a, double b, double c) {
	if (a == 1.0) 
		cout << "X**2";
	else if (a == -1.0) 
		cout << "-X**2";
	else 
		cout << a << "X**2"; // Print coefficient a and X**2

	if (b > 0.0) {
		if (b == 1.0) 
			cout << "+X";
		else 
			cout << "+" << b << "X"; // Print positive coefficient b and X
	} else if (b < 0.0) {
		if (b == -1.0) 
			cout << "-X"; 
		else 
			cout << b << "X"; // Print negative coefficient b and X
	}
	  
	if (c > 0.0) 
		cout << "+" << c; // Print positive coefficient c
	else if (c < 0.0) 
		cout << c; // Print negative coefficient c
	    
	cout << "=0.0000"; // Print the constant 0 on the right side of the equation
}

int main() {
	double a, b, c;
	Complex root1, root2; // Define two complex roots
	double inSquareRoot;

	cout << fixed << setprecision(4); // Set the precision of floating point output to 4 decimal places
	do {
		cout << "Enter coefficients a, b, and c: ";
		cin >> a >> b >> c; // Input coefficients a, b, and c
		
		if (a == 0.0) 
			cout << "The coefficient a of x**2 cannot be zero.\n"; // a cannot be zero
	} while (a == 0.0); // Re-enter if a is zero
	inSquareRoot = b * b - 4.0 * a * c; // Calculate the discriminant
	
	if (inSquareRoot >= 0) { // If the discriminant is greater than or equal to 0
		root1.setComplex((-b + sqrt(inSquareRoot)) / (2 * a), 0.0); // Roots are real numbers
		root2.setComplex((-b - sqrt(inSquareRoot)) / (2 * a), 0.0);
	} else { // If the discriminant is less than 0
		root1.setComplex(-b / (2 * a), sqrt(-inSquareRoot) / (2 * a)); // Roots are complex numbers
		root2.setComplex(-b / (2 * a), -sqrt(-inSquareRoot) / (2 * a));
	}
	
	cout << "\nThe two roots of quadratic equation ";
	printEquation(a, b, c); // Print the quadratic equation
	cout << " are:\n\t" << root1 << " and " << root2 << endl; // Print the roots
	
	if ((a * root1 * root1 + b * root1 + c).cabs() < 0.000001 && 
	    (a * root2 * root2 + b * root2 + c).cabs() < 0.000001)
		cout << "Verification of the two quadratic equation roots PASSES.\n"; // Verification passed
	else
		cout << "Verification of the two quadratic equation roots FAILS.\n"; // Verification failed

	return 0;
}

