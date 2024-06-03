//
//  main.cpp
//  Assignment_5_D1265065
//
//  Created by Corrine  on 2024/5/13.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"
using namespace std;
// Square root method
complex sqrt(const complex c){
    double r = sqrt(hypot(c.getRe(), c.getIm())); // magnitude of the complex number
    double theta = atan2(c.getIm(), c.getRe()) / 2; // half the argument of the complex number
    return complex(r * cos(theta), r * sin(theta));
}
// Function to print the quadratic equation
void printEqation(double a, double b, double c){

        if(a == 1) cout << "";
        else if(a == -1) cout << "-";
        else cout << a;
        
        if(a == 0)cout << "";
        else cout << "X**2";
        
        if(b == 1) cout << "";
        else if(b == -1) cout << "-";
        else if(b > 0) cout << "+" << b;
        else if(b < 0) cout << b;
        
        if(b == 0) cout << "";
        else cout << "X";
        
        if(c == 1) cout << "";
        else if(c > 0) cout << "+" << c;
        else if(c < 0) cout << c;
        cout << "=0.0000 are:" << endl;
}

int main(int argc, const char * argv[]) {
    complex r1, r2, V1, V2;//Create structures to save complex numbers.
    double a, b, c, D;
    // Input coefficients ensuring they are non-zero
    do{
        cout << "Enter coefficients a, b, and c: ";
        cin >> a >> b >> c;
    }while(a==0||b==0||c==0);
        cout << endl << "The two roots of quadratic equation " << fixed << setprecision(4);
        printEqation(a, b, c);
    // Calculate the discriminant
    D = pow(b, 2)-4*a*c;
    // Determine roots based on the discriminant
    if (D >= 0) {
        r1.setRe((-b+sqrt(D)) / (2*a));
        r1.setIm(0);
        r2.setRe((-b-sqrt(D)) / (2*a));
        r2.setIm(0);
    } else {
        r1.setRe(-b / (2*a));
        r1.setIm(sqrt(-D) / (2*a));
        r2.setRe(-b / (2*a));
        r2.setIm(-sqrt(-D) / (2*a));
    }
    
    cout << "         " << r1 << " and " << r2 << endl;

    // Verification of roots
    V1 = (a * r1 * r1) + (b * r1) + c;
    V2 = (a * r2 * r2) + (b * r2) + c;

        if (abs(V1.getRe()) < 0.000001 && abs(V1.getIm()) < 0.000001 &&
            abs(V2.getRe()) < 0.000001 && abs(V2.getIm()) < 0.000001) {
            cout << "Verification of the two quadratic equation roots PASSES." << endl;
        } else {
            cout << "Verification of the two quadratic equation roots FAILS." << endl;
        }
    return 0;
}
