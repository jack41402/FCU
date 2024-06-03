//
//  complex_overloading.hpp
//  Assignment_5_D1265065
//
//  Created by Corrine  on 2024/5/13.
//

#ifndef complex_overloading_h
#define complex_overloading_h

#include <iostream>
#include <cmath>
using namespace std;
class complex{
private:
    double real;// Real part of the complex number
    double imag;// Imaginary part of the complex number
public:
    complex();// Default constructor
    complex(double re, double im);// Parameterized constructor
    
    // Getter methods
    double getRe() const;// Returns the real part of the complex number
    double getIm() const;// Returns the imaginary part of the complex number

    // Setter methods
    void setRe(double re);// Sets the real part of the complex number
    void setIm(double im);// Sets the imaginary part of the complex number

    //overloading 31 operator functions
    //unary operation
    complex operator - (); // - (minus sign)
    
    complex operator + (const complex)const; //complex + complex
    complex operator + (const double)const;//complex + double
    friend complex operator + (double, const complex&);//double + complex
    
    complex operator - (const complex&)const;//complex - complex
    complex operator - (const double)const;//complex - double
    friend complex operator - (double, const complex&);//double - complex
    
    complex operator * (const complex&)const;//complex * complex
    complex operator * (const double)const;//complex * double
    friend complex operator * (double, const complex);//double * complex
    
    complex operator / (const complex&)const;//complex  const/ complex
    complex operator / (const double)const;//complex / double
    friend complex operator / (double, const complex&);//double / complex

    bool operator == (complex);//complex == complex
    bool operator == (double);//complex == double
    friend bool operator == (double, complex);//double == complex
    
    bool operator != (complex);//complex != complex
    bool operator != (double);//complex != double
    friend bool operator != (double, complex);// double != complex
    
    complex& operator = (complex);//complex = complex
    complex& operator = (double);//complex = double
    complex& operator += (complex);//complex = complex + complex
    complex& operator += (double);//complex = complex + double
    complex& operator -= (complex);//complex = complex - complex
    complex& operator -= (double);//complex = complex + double
    complex& operator *= (complex);//complex = complex * complex
    complex& operator *= (double);//complex = complex * double
    complex& operator /= (complex);//complex = complex / complex
    complex& operator /= (double);//complex = complex / double
    
    friend istream& operator>>(istream& in, complex& c);//input
    friend ostream& operator<<(ostream& out, const complex& c);//output
};
#endif /* complex_overloading_hpp */
