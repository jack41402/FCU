#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"

using namespace std;

// Function to verify if the calculated roots are correct
bool verify(Complex root, double a, double b, double c)
{
    // Calculate the value of the quadratic equation at the root
    Complex result = a * root * root + b * root + c;
    // Check if the absolute value of the result is very close to zero
    if(result.abs() < 0.000001)
        return true; // If it is, consider the root correct
    else
        return false; // Otherwise, consider it incorrect
}

// Function to print the quadratic equation in a readable format
void prinfEquation(double a, double b, double c)
{
    // Print the quadratic equation in the form "ax^2 + bx + c = 0.0000"
    if(a != 0){
        if(a == 1){
            cout << "X**2";
        }
        else{
            cout << a << "X**2";
        }
    }
    cout << showpos;
    if(b != 0){
        if(b == 1){
            if(b > 0) cout << "+X";
            else cout << "-X";
        }
        else{
            cout << b << "X";
        }
    }
    if(c != 0){
        cout << c;
    }
    cout << "=0.0000";
}

int main(){
    Complex root1, root2;
    double a, b, c, dis;
    cout << fixed << setprecision(4); // Set precision for fixed-point notation with 4 decimal places
    cout << "Enter coefficients a, b, and c:";
    cin >> a >> b >> c;
    cout << "The two roots of quadratic equation ";
    prinfEquation(a, b ,c);
    cout << " are:" << endl;
    dis = b * b - 4 * a * c;

    // Calculate roots based on discriminant
    if(dis > 0){
        root1.setRe(double((-b + sqrt(dis)) / (2 * a)));
        root2.setRe(double((-b - sqrt(dis)) / (2 * a)));
    }
    else if(dis == 0){
        root1.setRe(double(-b / (2 * a)));
        root2.setRe(double(-b / (2 * a)));
    }
    else{
        root1.setRe(double(-b / (2 * a)));
        root2.setRe(double(-b / (2 * a)));
        root1.setIm(double(sqrt(-dis) / (2 * a)));
        root2.setIm(double(-(sqrt(-dis) / (2 * a))));
    }
    cout << "        " << root1 << " and " << root2 << endl;

    // Verify if the roots satisfy the quadratic equation
    if(verify(root1, a, b, c) && verify(root2, a, b, c))
        cout << "Verification of the two quadratic equation roots PASSES." << endl;
    else
        cout << "Verification the two quadratic equation roots NOT PASSES." << endl;

    return 0;
}

