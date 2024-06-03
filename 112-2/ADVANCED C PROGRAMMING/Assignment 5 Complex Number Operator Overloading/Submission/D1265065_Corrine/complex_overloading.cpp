//
//  complex_overloading.cpp
//  Assignment_5_D1265065
//
//  Created by Corrine  on 2024/5/13.
//
#include <iostream>
#include "complex_overloading.h"
// Default constructor initializes complex number to (0, 0)
complex::complex(){
    real = 0.0;
    imag = 0.0;
}
// Parameterized constructor initializes complex number with given real and imaginary parts
complex::complex(const double re, const double im){
    real = re;
    imag = im;
}
// Getter method for the real part
double complex::getRe() const{
    return real;
}
// Getter method for the imaginary part
double complex::getIm() const{
    return imag;
}
// Setter method for the real part
void complex::setRe(double re){
    real = re;
}
// Setter method for the imaginary part
void complex::setIm(double im){
    imag = im;
}
//overloading 31 operator functions
//unary operation
// Unary minus operator to negate the complex number
complex complex::operator - (){ // - (minus sign)
    return complex(-real, -imag);
}

complex complex::operator + (const complex c)const{//complex + complex
    return complex(real + c.real, imag + c.imag);
}
complex complex::operator + (const double scalar)const{//complex + double
    return complex(real + scalar, imag);
}
complex operator + (double scalar, const complex& c){//double + complex
    return complex(scalar + c.real, c.imag);
}
complex complex::operator - (const complex& c)const{//complex - complex
    return complex(real - c.real, imag - c.imag);
}
complex complex::operator - (const double scalar)const{//complex - double
    return complex(real - scalar, imag);
}
complex operator - (double scalar, const complex& c){//double - complex
    return complex(scalar - c.real, c.imag);
}

complex complex::operator * (const complex& c)const{//complex * complex
    double a = real * c.real - imag * c.imag;
    double b = real * c.imag + imag * c.real;
    return complex(a, b);
}
complex complex::operator * (const double scalar)const{//complex * double
    return complex(real * scalar, imag * scalar);
}
    
complex operator * (double scalar, const complex c){//double * complex
    complex a;
    a.real = scalar * c.real;
    a.imag = scalar * c.imag;
    return a;
}

complex complex::operator / (const complex& c)const{//complex / complex
    double denominator = c.real * c.real + c.imag * c.imag;
    return complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}
complex complex::operator / (const double scalar)const{//complex / double
    return complex(real / scalar, imag / scalar);
}
complex operator / (double scalar, const complex& c){//double / complex
    double denominator = c.real * c.real + c.imag * c.imag;
    return complex((scalar * c.real) / denominator, (-scalar * c.imag) / denominator);
}
//啥時加const
bool complex::operator == (complex c){//complex == complex
    return real==c.real && imag==c.imag;
}
bool complex::operator == (double scalar){//complex == double
    return real==scalar && imag==0;
}
bool operator == (double scalar, complex c){//double == complex
    return scalar==c.real && c.imag==0;
}
bool complex::operator != (complex c){//complex != complex
    return real!=c.real && imag!=c.imag;
}
bool complex::operator != (double scalar){//complex != double
    return real!=scalar && imag!=0;
}
bool operator != (double scalar, complex c){// double != complex
    return scalar!=c.real && c.imag!=0;
}

complex& complex::operator = (complex c){//complex = complex
    if (this != &c) {
            real = c.real;
            imag = c.imag;
        }
    return *this;
}
complex& complex::operator = (double scalar){//complex = double
    real = scalar;
    imag = 0.0;
    return *this;
}
complex& complex::operator += (complex c){//complex = complex + complex
    real += c.real;
    imag += c.imag;
    return *this;
}
complex& complex::operator += (double scalar){//complex = complex + double
    real += scalar;
    return *this;
}
complex& complex::operator -= (complex c){//complex = complex - complex
    real -= c.real;
    imag -= c.imag;
    return *this;
}
complex& complex::operator -= (double scalar){//complex = complex - double
    real -= scalar;
    return *this;
}
complex& complex::operator *= (complex c){//complex = complex * complex
    double re = real * c.real - imag * c.imag;
    double im = real * c.imag + imag * c.real;
    real = re;
    imag = im;
    return *this;
}
complex& complex::operator *= (double scalar){//complex = complex * double
    real *= scalar;
    imag *= scalar;
    return *this;
}
complex& complex::operator /= (complex c){//complex = complex / complex
    double denominator = c.real * c.real + c.imag * c.imag;
    double re = (real * c.real + imag * c.imag) / denominator;
    double im = (imag * c.real - real * c.imag) / denominator;
    real = re;
    imag = im;
    return *this;
}
complex& complex::operator /= (double scalar){//complex = complex / double
    real /= scalar;
    imag /= scalar;
    return *this;
}
// Input stream operator to read a complex number
std::istream& operator>>(istream& in, complex& c){
    in >> c.real >> c.imag;
            return in;
}
// Output stream operator to print a complex number
std::ostream& operator<<(ostream& out, const complex& c){
    out << c.real << (c.imag > 0 ? "+" : "");
    if(c.imag != 0) out << c.imag ;
    else out << "";
    out << (c.imag != 0 ? "i" : "");
            return out;
}
