
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"

using namespace std;
	
	// Pretty printing of the quadratic equation. 
	void printEquation(double a, double b, double c) {
		// Print coefficient a.
		if (a==1.0) cout << "X**2"; 
		else if (a==-1.0) cout << "-X**2"; 
		else cout << a << "X**2"; 
	    
	  if (b>0.0) // For positive b, 
		  if (b==1.0) cout << "+X"; 
		  else cout << "+" << b << "X"; 
	  else if (b<0.0) 
	    if (b==-1.0) cout << "-X"; 
	    else cout << b << "X"; 
	   
	      
	  if (c>0.0) cout << "+" << c; 
	  else if (c<0.0) cout << c; 
	 
	    
	  cout << "=0.0000"; 
	}

int main() {
		double a, b, c; 
		Complex root1, root2; 
		double inSquareRoot; 

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
		
	  cout <<"\nThe two roots of quadratic equation ";
	  printEquation(a, b, c); 
	  cout << " are:\n\t" << root1 << " and " << root2 << endl; 
	    
	  if ((a*root1*root1+b*root1+c).cabs()<0.000001 && 
		    (a*root2*root2+b*root2+c).cabs()<0.000001)
	   	cout << "Verification of the two quadratic equation roots PASSES.\n";
	  else
		  cout << "Verification of the two quadratic equation roots FAILS.\n";

  return 0;
}