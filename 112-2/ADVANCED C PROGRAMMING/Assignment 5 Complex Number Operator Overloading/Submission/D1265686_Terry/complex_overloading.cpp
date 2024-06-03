#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "complex_overloading.h"
using namespace std;


ostream & operator<<(ostream &output, const Complex &c){
    
    output << fixed << setprecision(4); // Set output precision
    
    double real = c.getRe();
    double imag = c.getIm();
    
    if(imag==0)
    {
        output<<real; // Output real part if imaginary part is zero
    }
    
    else if ( real == 0 ) // Output imaginary part if real part is zero
    {
        output << imag << "i";
    }
    
    else {
        if(imag < 0 ) output << real << imag << "i";
        else output << real << "+" << imag << "i";
    }
    
    return output;
}


istream &operator>>(istream &input, Complex &c){
    
    input>>c.re;
    
    input>>c.im;
    
    return input;
}


Complex::Complex(const double m, const double n){ re=m; im=n; }

Complex::Complex(const Complex &c){ re=c.re; im=c.im; }

double Complex::getIm() const{ return this->im; }

double Complex::getRe() const{ return this->re; }

void Complex::setRe(double n){ re=n; }

void Complex::setIm(double n){ im=n; }


// Add the input double value n to the real part re
Complex Complex :: operator + (const double &n) const {
    
    Complex u;
    u.re = re + n;
    u.im = im;
    return u;
}



// Unary negation operator overload for negating a complex number
Complex Complex::operator-() const {
    Complex negated;
    negated.re = -re;
    negated.im = -im;
    
    return negated;
}

// Binary addition operator overload for adding a double value to a complex number
Complex operator+(const double &n, const Complex &c) {
    Complex sum;
    sum.re = c.re + n;
    sum.im = c.im;
    return sum;
}

// Binary multiplication operator overload for multiplying a complex number by a double value
Complex Complex::operator*(const double &n) const {
    Complex product;
    product.re = re * n;
    product.im = im * n;
    
    return product;
}

// Binary subtraction operator overload for subtracting a complex number from another complex number
Complex Complex::operator-(const Complex &c) const {
    
    Complex difference;
    difference.re = re - c.re;
    difference.im = im - c.im;
    
    return difference;
}

// Binary subtraction operator overload for subtracting a complex number from a double value
Complex operator-(const double &n, const Complex &c) {

    Complex difference;
    difference.re = n - c.re;
    difference.im = -c.im;
    
    return difference;
}

// Binary multiplication operator overload for multiplying a double value by a complex number
Complex operator*(const double &n, const Complex &c) {
    
    Complex product;
    product.re = n * c.re;
    product.im = n * c.im;
    
    return product;
}


Complex Complex::operator-(const double &n) const{
    Complex diff;
    diff.re=re-n;
    diff.im=im;
    return diff;
}

Complex Complex::operator+(const Complex &c) const{
    Complex sum;
    sum.re=re+c.re;
    sum.im=im+c.im;
    return sum;
}

// Binary multiplication operator overload for multiplying two complex numbers
Complex Complex::operator*(const Complex &c) const {

    Complex product;
    product.re = re * c.re - im * c.im;
    product.im = re * c.im + im * c.re;
    
    return product;
}

// Binary division operator overload for dividing a complex number by a double value
Complex Complex::operator/(const double &n) const {
    
    Complex quotient;
    quotient.re = re / n;
    quotient.im = im / n;
    
    return quotient;
}




Complex operator/(const double &n, const Complex &c){
    Complex quot;
    quot.re=(n*c.re)/(c.re*c.re+c.im*c.im);
    quot.im=(-n*c.im)/(c.re*c.re+c.im*c.im);
    return quot;
}

bool Complex::operator==(const Complex &c) const{
    return (re==c.re && im==c.im);
}

bool Complex::operator!=(const double &n) const{
    return !(*this==n);
}

bool Complex::operator!=(const Complex &c) const{
    return !(*this==c);
}

bool Complex::operator==(const double &n) const{
    return (re==n && im==0);
}

bool operator!=(const double &n, const Complex &c){
    return !(n==c);
}

bool operator==(const double &n, const Complex &c){
    return (c.re==n && c.im==0);
}




// Assignment operator for assigning a double value to a complex number
Complex& Complex::operator=(const double &n) {
    // Assign the real part of the current complex number to the given double value n
    re = n;
    // Set the imaginary part to 0
    im = 0;
    // Return a reference to the current complex number
    return *this;
}

// Compound addition assignment operator for adding a complex number to the current complex number
Complex& Complex::operator+=(const Complex &c) {
    // Add the given complex number c to the current complex number using the addition operator
    *this = *this + c;
    // Return a reference to the current complex number
    return *this;
}

Complex& Complex::operator-=(const Complex &c){
    *this=*this-c;
    return *this;
}

// Assignment operator for assigning a complex number to another complex number
Complex& Complex::operator=(const Complex &c) {
    // Assign the real and imaginary parts of the given complex number c to the current complex number
    re = c.re;
    im = c.im;
    // Return a reference to the current complex number
    return *this;
}

Complex& Complex::operator*=(const double &n){
    *this=*this*n;
    return *this;
}

// Compound assignment operator overload for dividing a complex number by another complex number
Complex& Complex::operator/=(const Complex &c) {
    // Divide the current complex number by the given complex number
    *this = *this / c;
    
    return *this;
}

Complex& Complex::operator-=(const double &n){
    *this=*this-n;
    return *this;
}

// Compound assignment operator overload for multiplying a complex number by another complex number
Complex& Complex::operator*=(const Complex &c) {
    // Multiply the current complex number by the given complex number
    *this = *this * c;
    
    return *this;
}


Complex& Complex::operator/=(const double &n){
    *this =* this/n;
    return *this;
}


Complex Complex::operator/(const Complex &c) const{
    Complex quot;
    quot.re=(re*c.re+im*c.im)/(c.re*c.re+c.im*c.im);
    quot.im=(im*c.re-re*c.im)/(c.re*c.re+c.im*c.im);
    return quot;
}

// Method to calculate the absolute value (magnitude) of the complex number
double Complex::cabs() const {
    // Calculate the absolute value using the formula sqrt(re^2 + im^2)
    double absValue = sqrt(re * re + im * im);
    // Return the absolute value
    return absValue;
}

