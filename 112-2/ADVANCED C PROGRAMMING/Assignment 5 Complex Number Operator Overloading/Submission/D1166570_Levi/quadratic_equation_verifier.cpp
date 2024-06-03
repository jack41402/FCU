#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"

using namespace std;

void solve(double a, double b, double c)
{
    Complex x1, x2;
    double dert = b * b - 4 * a * c;
    if (dert > 0) {
        x1 = Complex((-b + sqrt(dert)) / (2 * a), 0);
        x2 = Complex((-b - sqrt(dert)) / (2 * a), 0);
    }
    else {
        x1 = Complex(-b / (2 * a), sqrt(-dert) / (2 * a));
        x2 = Complex(-b / (2 * a), -sqrt(-dert) / (2 * a));
    }
    cout << fixed << setprecision(4);
    cout << "\nThe two roots of the quadratic equation ";
    if (a == 1) cout << "X**2";
    else if (a == -1) cout << "-X**2";
    else  cout << a << "X**2";
    if (b != 0) {
        if (b > 0) cout << "+";
        else cout << "-";
        if (fabs(b) == 1) cout << "X";
        else cout << fabs(b) << "X";
    }
    if (c != 0) {
        cout << (c > 0 ? "+" : "") << c;
    }cout << "=0.0000";
    
    cout<< " are:\n\t" << x1 << " and " << x2 << endl;

    if ((a * x1 * x1 + b * x1 + c).cabs() < 0.0001 &&
        (a * x2 * x2 + b * x2 + c).cabs() < 0.0001) {
        cout << "Verification of the two quadratic equation roots PASSES.\n";
    }
    else {
        cout << "Verification of the two quadratic equation roots FAILS.\n";
    }
}
int main() {
    double a, b, c;  // Coefficients for the quadratic equation ax^2 + bx + c = 0.
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}

