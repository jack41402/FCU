#include "complex_overloading.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Complex sqrt(const Complex& c) {// get the sqrt value of a complex number
    double r = sqrt(c.getRe() * c.getRe() + c.getIm() * c.getIm());
    double real = sqrt((r + c.getRe()) / 2);
    double imag = sqrt((r - c.getRe()) / 2);
    if (c.getIm() < 0) {
        imag = -imag;
    }
    return Complex(real, imag);
}

void solveQuadratic(double a, double b, double c) {// solve the roots of the equation and verify the roots
    Complex D = Complex(b * b - 4 * a * c, 0);
	Complex R1 = (-b + sqrt(D))/(2*a);
	Complex R2 = (-b-sqrt(D))/(2*a);
	cout << "        " << R1 << " and " << R2 << endl;
	Complex verify1 = a * R1 * R1 + b * R1 + c;
	Complex verify2 = a * R2 * R2 + b * R2 + c;
	if(abs(verify1.getRe()) < 0.000001 && abs(verify2.getRe()) < 0.000001) cout << "Verification of the two qudratic equation roots PASSES.\n" << endl;
	else cout << "Verification of the two qudratic equation roots are FAILED.\n" << endl;
}

void printa(double a) {// print the first term of the equation
    cout << fixed << setprecision(4);
    if (a == 1) {
        cout << "X**2";
    } 
	else if (a == -1) {
        cout << "-X**2";
    } 
	else {
        cout << a << "X**2";
    }
}

void printb(double b) {// print the second term of the equation
    cout << fixed << setprecision(4);
    if (b == 1) {
        cout << "+X";
    } else if (b == -1) {
        cout << "-X";
    } 
	else if (b > 0) {
        cout << "+" << b << "X";
    }
    else if (b == 0) {
    	cout << "";
	}
    else {
        cout << b << "X";
    }
}

int main() {
    double a, b, c;
	while(1){
    	do{ 
    		cout << "Enter coefficients a, b, and c: ";
			cin >> a >> b >> c;
		}while(a==0);
	    cout << fixed << setprecision(4);
	    cout << "\nThe two roots of the quadratic equation ";
		printa(a);
		printb(b);
	    if(c>0) cout << "+" << c << "=0.0000 are:" << endl;
	    else if(c<0) cout << c << "=0.0000 are:" << endl;
	    else cout << "=0.0000 are:" << endl;
	    solveQuadratic(a, b, c);
	}
    return 0;
}

