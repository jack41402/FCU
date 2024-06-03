#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"

using namespace std;

// Function to format and print the quadratic equation.
void printEquation(double a, double b, double c) {
    if (a == 1.0) {
        cout << "X^2";
    } else if (a == -1.0) {
        cout << "-X^2";
    } else {
        cout << a << "X^2";
    }

    if (b != 0.0) {
        cout << (b > 0 ? "+" : "");
        if (fabs(b) == 1.0) {
            cout << "X";
        } else {
            cout << b << "X";
        }
    }

    if (c != 0.0) {
        cout << (c > 0 ? "+" : "") << c;
    }
    cout << "=0";
}

int main() {
    double a, b, c;  // Coefficients for the quadratic equation ax^2 + bx + c = 0.
    Complex root1, root2;  // Potential complex roots.
    double discriminant;  // Calculated discriminant (b^2 - 4ac).

    cout << fixed << setprecision(4);
    do {
        cout << "Enter coefficients a, b, and c: ";
        cin >> a >> b >> c;
        if (a == 0.0) {
            cout << "Coefficient 'a' cannot be zero as it would not be a quadratic equation. Please re-enter all coefficients.\n";
        }
    } while (a == 0.0);

    discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        root1.setComplex((-b + sqrt(discriminant)) / (2 * a), 0.0);
        root2.setComplex((-b - sqrt(discriminant)) / (2 * a), 0.0);
    } else {
        root1.setComplex(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        root2.setComplex(-b / (2 * a), -sqrt(-discriminant) / (2 * a));
    }

    cout << "\nThe two roots of the quadratic equation ";
    printEquation(a, b, c);
    cout << " are:\n\t" << root1 << " and " << root2 << endl;

    if ((a * root1 * root1 + b * root1 + c).cabs() < 0.0001 &&
        (a * root2 * root2 + b * root2 + c).cabs() < 0.0001) {
        cout << "Verification of the two quadratic equation roots PASSES.\n";
    } else {
        cout << "Verification of the two quadratic equation roots FAILS.\n";
    }

    return 0;
}

