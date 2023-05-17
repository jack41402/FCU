#include <iostream>
#include <iomanip>
#include <cmath>
#include "complex_overloading.h"

const double epsilon=1e-6 ;

bool verify (const double &a , const double &b , const double &c , const Complex &root1 , const Complex &root2)
{
    bool root1_verify , root2_verify ;
    root1_verify = (((a*root1*root1 + b*root1 + c)-0).cabs()<epsilon) ;
    root2_verify = (((a*root2*root2 + b*root2 + c)-0).cabs()<epsilon) ;
    if (root1_verify && root2_verify) return true;
    else return false;
}

int main ()
{
    double a , b , c , d ;
    Complex root1 , root2 ;
    do
    {
        std::cout << "Enter coefficients a, b, and c: " ;
        std::cin >> a >> b >> c ;
    }
    while (fabs(a-0)<epsilon) ;
    std::cout << std::fixed << std::setprecision(4) ;
    std::cout << "\nThe two roots of quadratic equation " ;
    if (fabs(a-0)>epsilon)
    {
        if (fabs(fabs(a)-1)<epsilon) std::cout << ((a>0) ? "" : "-") << "X**2" ;
        else std::cout << a << "X**2" ;
    }
    if (fabs(b-0)>epsilon)
    {
        if (fabs(fabs(b)-1)<epsilon) std::cout << ((b>0) ? "+" : "-") << "X" ;
        else std::cout << std::showpos << b << "X" ;
    }
    if (fabs(c-0)>epsilon) std::cout << std::showpos << c ;
    std::cout << "=0.0000" ;
    std::cout << std::resetiosflags(std::ios::showpos) ;
    d = b * b - 4 * a * c ;
    if (d>0)
    {
        root1 = (-b+sqrt(d))/(2*a) ;
        root2 = (-b-sqrt(d))/(2*a) ;
        std::cout << " are:\n\t" << root1 << " and " << root2 << '\n' ;
    }
    else if (fabs(d-0)<epsilon)
    {
        root1 = root2 = (-b+sqrt(d))/(2*a) ;
        std::cout << " is:\n\t" << root1 << '\n' ;
    }
    else
    {
        root1.setRe((-b)/(2*a)) , root1.setIm(+sqrt(fabs(d))/(2*a)) ;
        root2.setRe((-b)/(2*a)) , root2.setIm(-sqrt(fabs(d))/(2*a)) ;
        std::cout << " are:\n\t" << root1 << " and " << root2 << '\n' ;
    }
    std::cout << "Verification of the two quadratic equation roots " ;
    if (verify(a , b , c , root1 , root2)) std::cout << "PASSED.\n" ;
    else std::cout << "FAILED." ;
}
