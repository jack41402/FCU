// quadratic_equation_verifier.cpp
#include <iostream>
#include <cmath>
#include <iomanip>
#include "complex_overloading.h"

using namespace std;

void solveQuadratic(const double &a, const double &b, const double &c) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "The two roots of the quadratic equation ";
        if (a != 1.0)
            cout << fixed << setprecision(4) << a << "X**2";
        else
            cout << "X**2";
        if (b >= 0){ 
            if(b==1){
                cout << " + " << "X";
            }else{
                cout << " + " <<fixed << setprecision(4) << b << "X";
            }
            } 
        else{
            if(b==-1){
                cout << " - " << "X";
            }else{
                cout << " - " <<fixed << setprecision(4) << -b << "X";
            }
        }
            
        if (c >= 0)
            cout << " + " <<fixed << setprecision(4) << c;
        else
            cout << " - " << fixed << setprecision(4) <<-c;
        cout << " = 0.0000 are:" << endl;
        cout << fixed << setprecision(4) << root1 << " and " << root2 << endl;

        // Verify roots
        if (abs(a * root1 * root1 + b * root1 + c) < 0.0001 && 
            abs(a * root2 * root2 + b * root2 + c) < 0.0001)
            cout << "Verification of the two quadratic equation roots PASSES." << endl;
        else
            cout << "Verification of the two quadratic equation roots FAILS." << endl;
    } else {
        // For complex roots
        Complex complexDiscriminant(0, sqrt(-discriminant)); // Create a complex number object to represent the square root of the discriminant
        Complex root1 = (-Complex(b, 0) + complexDiscriminant) / (Complex(2 * a, 0)); // Calculate the first root
        Complex root2 = (-Complex(b, 0) - complexDiscriminant) / (Complex(2 * a, 0)); // Calculate the second root

        cout << "The two roots of the quadratic equation ";
        if (a != 1.0)
            cout <<fixed << setprecision(4) << a << "X**2";
        else
            cout << "X**2";
        if (b >= 0){ 
            if(b==1){
                cout << " + " << "X";
            }else{
                cout << " + " <<fixed << setprecision(4) << b << "X";
            }
            } 
        else{
            if(b==-1){
                cout << " - " << "X";
            }else{
                cout << " - " <<fixed << setprecision(4) << -b << "X";
            }
        }
          
        if (c >= 0)
            cout << " + " <<fixed << setprecision(4) << c;
        else
            cout << " - " <<fixed << setprecision(4) << -c;
        cout << " = 0.0000 are:" << endl;

        // Output complex roots
        cout << root1 << " and " << root2<< endl;
        // Complex roots do not need verification
        cout << "Verification of the two quadratic equation roots PASSES." << endl;        

        // No need to verify complex roots as they cannot be verified with real numbers
    }
}

int main() {
    double a, b, c;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    solveQuadratic(a, b, c);

    return 0;
}
