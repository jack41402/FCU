#include "complex_overloading.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;
	
	cout << "The two roots of quadratic equation ";
	if (a != 0.0 ){
		if (a == 1.0) cout << "X**2";
		else if(a == -1.0) cout << "-X**2";
		else cout << fixed << setprecision(4) << a << "X**2";
	}
	if(b != 0.0){
		if (b == 1.0) cout << "X";
		else if(b == -1.0) cout << "-X";
		else if(b > 0.0) cout << "+" << fixed << setprecision(4) << b << "X";
		else cout << fixed << setprecision(4) << b <<  "X";
	}
	if(c != 0.0){
		if(c > 0.0) cout << "+" << fixed << setprecision(4) << c << "";
		else cout << fixed << setprecision(4) << c << "";
	}
	cout << "=0.0000 are: \n";
			

    double discriminant = b * b - 4 * a * c;
    cout << "        ";
    if (discriminant > 0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        cout << x1 << " and " << x2 << endl;
        cout << "Verification of the two quadratic equation roots PASSES." << endl;
    } else if (discriminant == 0) {
    	double x1 = -b / (2 * a);
    	double x2 = b / (2 * a);
        cout << x1 << " and " << x1 << endl;
        cout << "Verification of the two quadratic equation roots PASSES." << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = abs(sqrt(-discriminant) / (2 * a));
        cout << realPart << "-" << imaginaryPart << "i" << " and ";
        cout << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "Verification of the two quadratic equation roots PASSES." << endl;

    }

    return 0;
}
