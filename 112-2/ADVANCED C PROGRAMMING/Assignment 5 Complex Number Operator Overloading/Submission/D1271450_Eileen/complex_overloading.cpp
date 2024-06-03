#include <iostream>
#include <cmath>
#include <iomanip>
#include "complex_overloading.h"

double calculateDiscriminant(double a, double b, double c) {//calculate discriminants
    return std::pow(b, 2) - 4 * a * c;//return b^2-4*a*c
}
void printEquation(double a, double b, double c) {//print the equation
	std::cout << std::fixed << std::setprecision(4);//set so that it would be printed with four decimal places
    //pretty format
	if (a == 1) {
        std::cout << "X**2";
    } else if (a == -1) {
        std::cout << "-X**2";
    } else {
        std::cout << a << "X**2";
    }
    if (b > 0) {
        std::cout << "+" << b << "X";
    } else if (b == -1) {
        std::cout<<"-X";
    }else if (b == 1){
    	std::cout<<"X";
	}else{
		std::cout << b << "X";
	}
    if (c > 0) {
        std::cout << "+" << c;
    } else if (c == -1) {
        std::cout<<"-1.0000";
    }else if (c == 1){
    	std::cout<<"1.0000";
	}else{
		std::cout<<c;
	}
    std::cout << "=0.0000 are: " << std::endl;
}
void findRealRoots(double a, double b, double c, double discriminant) {//calculate the two real roots of the quadratic equation
    double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "        "<<root1 <<" and " <<root2 << std::endl;//print root1 and root2
    double verificationLimit = 0.000001;//define the tolerance for verification
    double equationValue1 = a * root1 * root1 + b * root1 + c;//calculate the values of the quadratic equation of root1
    double equationValue2 = a * root2 * root2 + b * root2 + c;//calculate the values of the quadratic equation of root2
    if (std::abs(equationValue1) < verificationLimit && std::abs(equationValue2) < verificationLimit) {//if the roots satisfies the quadratic equation within the tolerance
        std::cout << "Verification of the two quadratic equation roots PASSES." << std::endl;//print out Verification of the two quadratic equation roots PASSES.
    } else {//if not
        std::cout << "Verification of the two quadratic equation roots FAILS." << std::endl;//print out Verification of the two quadratic equation roots FAILS.
    }
}
void findComplexRoots(double a, double b, double c, double discriminant) {//calculate the two complex roots of the quadratic equation
    double realPart = -b / (2 * a);//calculate the real part of the complex roots
    double imaginaryPart = std::sqrt(-discriminant) / (2 * a);//calculate the imaginary part of the complex roots
    Complex root1(realPart, imaginaryPart);//create the complex root1 using the real and imaginary parts
    Complex root2(realPart, -imaginaryPart);//create the complex root2 using the real and imaginary parts
    std::cout << "        " << root1 << " and " << root2 << std::endl;//print the complex roots
    double verificationLimit = 0.000001;//define the tolerance for verification
    Complex equationValue1 = a * root1 * root1 + b * root1 + c;//calculate the values of the quadratic equation of root1
    Complex equationValue2 = a * root2 * root2 + b * root2 + c;//calculate the values of the quadratic equation of root2
    if (std::abs(equationValue1.getRe()) < verificationLimit && std::abs(equationValue2.getRe()) < verificationLimit) {//if the roots satisfies the quadratic equation within the tolerance
        std::cout << "Verification of the two quadratic equation roots PASSES." << std::endl;//print out Verification of the two quadratic equation roots PASSES.
    } else {//if not
        std::cout << "Verification of the two quadratic equation roots FAILS." << std::endl;//print out Verification of the two quadratic equation roots FAILS.
    }
}
void solveQuadraticEquation(double a, double b, double c) {
    std::cout << std::fixed << std::setprecision(4);
    if (a == 0) {//if a equals 0
        std::cout << "Error: Coefficient 'a' cannot be zero." << std::endl;//Error: Coefficient 'a' cannot be zero.
        return;
    }
    double discriminant = calculateDiscriminant(a, b, c);//calculate the discriminant of the quadratic equation
    std::cout << "The two roots of the quadratic equation ";
    printEquation(a, b, c);//print the equation in standard form
    if (discriminant >= 0) {//determine whether to find real or complex roots based on the discriminant
        findRealRoots(a, b, c, discriminant);
    } else {
        findComplexRoots(a, b, c, discriminant);
    }
}
int main() {
    double a, b, c;
    std::cout << "Enter three coefficients a, b, and c: ";//print out Enter three coefficients a, b, and c: 
    std::cin >> a >> b >> c;//scan the inputted a b and c
    std::cout << std::endl;//go to the next line
    solveQuadraticEquation(a, b, c);//solve the equation with a b and c
    return 0;
}

