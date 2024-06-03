#include "complex_overloading.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double a, b, c;
    cout << "Enter cofficients a, b, and c: ";
    cin >> a >> b >> c;

    cout << "\nThe two roots of quadratic equation ";
    if(a == 1) cout << "X**2";
    else if(a == -1) cout << "-X**2";
    else cout << fixed << setprecision(4) << a << "X**2";

    if(b == 1) cout << "+X";
    else if(b == -1) cout << "-X";
    else if(b > 0) cout << "+" << fixed << setprecision(4) << b << "X";
    else if(b < 0) cout << "-" << fixed << setprecision(4) << -b << "X";

    if(c > 0) cout << "+" << fixed << setprecision(4) << c;
    if(c < 0) cout << "-" << fixed << setprecision(4) << -c;

    cout << "=0.0000 are:\n";

    double tmp = b * b - 4 * a * c;
    Complex c1, c2;
    if(tmp >= 0) {
        c1.setRe( (-b + sqrt(tmp)) / (2 * a) );
        c2.setRe( (-b - sqrt(tmp)) / (2 * a) );
    }
    else {
        c1.setRe( -b / (2 * a) );
        c1.setIm( sqrt(-tmp) / (2 * a) );
        c2.setRe( -b / (2 * a) );
        c2.setIm( -sqrt(-tmp) / (2 * a) );
    }
    cout << "        " << c1 << " and " << c2 << "\n";
    
    Complex ans1(c1), Tmp;
    ans1 *= c1;
    ans1 *= a;

    Tmp = b * c1;
    ans1 += Tmp;
    ans1 += c;
    
    Complex ans2(c2);
    ans2 *= c2;
    ans2 *= a;
    
    Tmp = b * c2;
    ans2 += Tmp;
    ans2 += c;

    double t = 0.000001;
    if(ans1.absComplex() < t && ans2.absComplex() < t) {
        cout << "Verification of the two quadratic equation roots PASSES.\n\n";
    }
}
