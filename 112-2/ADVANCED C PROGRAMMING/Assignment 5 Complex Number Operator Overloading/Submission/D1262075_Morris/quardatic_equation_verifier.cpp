#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"
using namespace std;

void printequation(double a, double b, double c){
	if (a==1.0) cout << "X**2";
	else if (a==-1.0) cout << "-X**2";
	else cout << a << "X**2";
	
	if (b>0.0){
		if (b==1.0) cout << "+X";
		else cout << "+" << b << "X";
	}
	else if (b<0.0){
		if (b==-1.0) cout << "-X";
		else cout << b << "X";
	}
	if (c>0.0) cout << "+" << c;
	else if (c<0.0) cout << c;
	
	cout << "=0.0000";
}
int main(){
	double a,b,c;
	Complex r1,r2;
	double sqrtt;
	
	cout << fixed << setprecision(4);
	do {
		cout << "Enter coefficients a, b, and c: ";
		cin >> a >> b >> c;
		if (a==0.0) cout << "The coefficient a of x**2 cannot be zero.\n";
	} while (a==0.0);
	sqrtt = b * b - 4.0 * a * c;
	if (sqrtt>=0) { 
		r1.setComplex((-b+sqrt(sqrtt))/(2*a), 0.0);
		r2.setComplex((-b-sqrt(sqrtt))/(2*a), 0.0);
	}
	else { 
		r1.setComplex(-b/(2*a), sqrt(-sqrtt)/(2*a));
		r2.setComplex(-b/(2*a), -sqrt(-sqrtt)/(2*a));
	}
	cout <<"\nThe two roots of quadratic equation "; 
	printequation(a, b, c); 
	cout << " are:\n\t" << r1 << " and " << r2 << endl; 
	    
	if ((a*r1*r1+b*r1+c).cabs()<0.000001 && (a*r2*r2+b*r2+c).cabs()<0.000001)
	   	cout << "Verification of the two quadratic equation roots PASSES.\n";
	else
		cout << "Verification of the two quadratic equation roots FAILS.\n";

  return 0;
}
