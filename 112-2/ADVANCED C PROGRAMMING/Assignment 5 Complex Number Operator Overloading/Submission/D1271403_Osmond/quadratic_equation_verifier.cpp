#include <iostream>
#include <cmath>
#include <iomanip>
#include "complex_overloading.h"  

using namespace std;

void print_equ(float a, float b, float c) {
    cout << endl << "The two roots of quadratic equation ";
    if (a == 1) cout << "X^2";
    else if (a == -1) cout << "-X^2";
    else cout << fixed << setprecision(4) << a << "X^2";
    
    if (b == 1) cout << "+X";
    else if (b == -1) cout << "-X";
    else if (b > 0) cout << fixed << setprecision(4) << "+" << b << "X";
    else if (b < 0) cout << fixed << setprecision(4) << b << "X";
    
    if (c > 0) cout << fixed << setprecision(4) << "+" << c;
    else if (c < 0) cout << fixed << setprecision(4) << c;
    cout << " are:" << endl;
}

bool verifier(const Complex& root1, const Complex& root2, double a, double b, double c) {
    const double epsilon = 0.000001;
    Complex plug_in_value1 = a * root1 * root1 + b * root1 + c;
    Complex plug_in_value2 = a * root2 * root2 + b * root2 + c;
    return plug_in_value1.cabs() <= epsilon && plug_in_value2.cabs() <= epsilon;
}

int main() {
    float a, b, c;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;    

    if (a == 0) {
        cout << "Not a quadratic equation.";
        return 0;
    }

    print_equ(a, b, c);
    Complex root1, root2;

    double discriminant = b*b - 4*a*c;
    if (discriminant >= 0) {
        root1.setRe((-b + sqrt(discriminant)) / (2 * a));
        root2.setRe((-b - sqrt(discriminant)) / (2 * a));
    } else {
        root1.setRe(-b / (2 * a));
        root1.setIm(sqrt(-discriminant) / (2 * a));
        root2.setRe(-b / (2 * a));
        root2.setIm(-sqrt(-discriminant) / (2 * a));
    }

    cout << "    " << fixed << setprecision(4) << root1 << " and " << root2 << endl;

    cout << "Verification of quadratic equation roots ";
    if (verifier(root1, root2, a, b, c)) cout << "PASSES.";
    else cout << "FAILS";
    
    return 0;
}

