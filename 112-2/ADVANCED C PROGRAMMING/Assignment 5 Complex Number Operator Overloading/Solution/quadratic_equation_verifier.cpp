// Application main program for rantioal number class with overloaded operators. 
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"

using namespace std;
	
	// Pretty printing of the quadratic equation. 
	void printEquation(double a, double b, double c) {
		// Print coefficient a.
		if (a==1.0) cout << "X**2"; // otherwise, a is 1, omit the coefficient.
		else if (a==-1.0) cout << "-X**2"; // If a is -1 print the "-" sign only.
		else cout << a << "X**2"; // If a is nor 1 neither -1, print the coefficient.
	    
	  if (b>0.0) // For positive b, 
		  if (b==1.0) cout << "+X"; // If b is 1, print the "+" sign only.
		  else cout << "+" << b << "X"; // If b is not 1, print b with "+" sign.
	  else if (b<0.0) // For negative b,
	    if (b==-1.0) cout << "-X"; // If b is -1, print the "-" sign only.
	    else cout << b << "X"; // if b is not 1, print b only because it has a "-" sign.
	    // If b is 0, omit the entire one-degree term, i.e., do not print any thing.
	      
	  if (c>0.0) cout << "+" << c; // If c is positive, print c with a "+" sign.
	  else if (c<0.0) cout << c; // If c is negative, print c only.
	  // If c is 0, omit the entire constant term.
	    
	  cout << "=0.0000"; // Print the right-hand-side of the equation.
	}

int main() {
		double a, b, c; // Coefficients of quadratic equation a*x^2+b*x+c=0.
		Complex root1, root2; // Two roots of quadratic equation.
		double inSquareRoot; // The term in square root: b**2-4ac.

	  cout << fixed << setprecision(4); 
		do {
			cout << "Enter coefficients a, b, and c: ";
			cin >> a >> b >> c;
			
			if (a==0.0) cout << "The coefficient a of x**2 cannot be zero.\n";
		} while (a==0.0);
		inSquareRoot = b * b - 4.0 * a * c;
		
		if (inSquareRoot>=0) { // Two real roots.
			root1.setComplex((-b+sqrt(inSquareRoot))/(2*a), 0.0);
			root2.setComplex((-b-sqrt(inSquareRoot))/(2*a), 0.0);
		}
		else { // Two complex roots.
		  root1.setComplex(-b/(2*a), sqrt(-inSquareRoot)/(2*a));
			root2.setComplex(-b/(2*a), -sqrt(-inSquareRoot)/(2*a));
		}
		
	  cout <<"\nThe two roots of quadratic equation "; // Print equation message.
	  printEquation(a, b, c); // Print the equation.
	  cout << " are:\n\t" << root1 << " and " << root2 << endl; // Print the real roots.
	    
	  if ((a*root1*root1+b*root1+c).cabs()<0.000001 && 
		    (a*root2*root2+b*root2+c).cabs()<0.000001)
	   	cout << "Verification of the two quadratic equation roots PASSES.\n";
	  else
		  cout << "Verification of the two quadratic equation roots FAILS.\n";

  return 0;
}
