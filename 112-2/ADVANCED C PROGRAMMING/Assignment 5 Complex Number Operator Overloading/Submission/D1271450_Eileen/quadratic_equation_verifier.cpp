#include <iostream>
#include <cmath>
#include "complex_overloading.h"

using namespace std;//bring names from the std namespace
Complex::Complex(double r, double i) : re(r), im(i) { }//initialize real and imaginary parts
Complex::Complex(const Complex &c) : re(c.re), im(c.im) { }//copy real and imaginary parts from another Complex object
double Complex::getRe() const { return re; }//retrieve the real part of a Complex object
double Complex::getIm() const { return im; }//retrieve the imaginary part of a Complex object
void Complex::setRe(double r) { re = r; }//set the real part of a Complex object
void Complex::setIm(double i) { im = i; }//set the imaginary part of a Complex object
Complex Complex::operator-() const {//minus operator for Complex objects
    return Complex(-re, -im);//return the negation of the complex number
}
Complex Complex::operator+(const Complex &c) const {//plus operator for adding two Complex objects
    return Complex(re + c.re, im + c.im);//returns the sum of the complex numbers
}
Complex Complex::operator+(double r) const {//plus operator for adding a double to a Complex object
    return Complex(re + r, im);//returns the sum
}
Complex operator+(double r, const Complex &c) {//friend function for adding a Complex object to a double
    return Complex(r + c.re, c.im);//returns the sum
}
Complex Complex::operator-(const Complex &c) const {//minus operator for subtracting two Complex objects
    return Complex(re - c.re, im - c.im);//returns the difference
}
Complex Complex::operator-(double r) const {//minus operator for subtracting a double from a Complex object
    return Complex(re - r, im);//returns the difference
}
Complex operator-(double r, const Complex &c) {//friend function for subtracting a Complex object from a double
    return Complex(r - c.re, -c.im);//returns the difference
}
Complex Complex::operator*(const Complex &c) const {//multiplication operator for multiplying two Complex objects
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);//returns the product
}
Complex Complex::operator*(double r) const {//multiplication operator for multiplying a Complex object by a scalar
    return Complex(re * r, im * r);//returns the product
}
Complex operator*(double r, const Complex &c) {//friend function for multiplying a scalar by a Complex object
    return Complex(r * c.re, r * c.im);//returns the product
}
Complex Complex::operator/(const Complex &c) const {//division operator for dividing two Complex objects
    double denominator = c.re * c.re + c.im * c.im;
    return Complex((re * c.re + im * c.im) / denominator, (im * c.re - re * c.im) / denominator);//returns the quotient
}
Complex Complex::operator/(double r) const {//division operator for dividing a Complex object by a scalar
    return Complex(re / r, im / r);//returns the quotient
}
Complex operator/(double r, const Complex &c) {//friend function for dividing a scalar by a Complex object
    double denominator = c.re * c.re + c.im * c.im;
    return Complex((r * c.re) / denominator, (-r * c.im) / denominator);//returns the quotient
}
bool Complex::operator==(const Complex &c) const {//equality operator for comparing two Complex objects for equality
    return re == c.re && im == c.im;
}
bool Complex::operator==(double r) const {//equality operator for comparing a Complex object with a scalar for equality
    return re == r && im == 0;
}
bool operator==(double r, const Complex &c) {//friend function for comparing a scalar with a Complex object for equality
    return r == c.re && c.im == 0;
}
bool Complex::operator!=(const Complex &c) const {//finequality operator for comparing two Complex objects for non quality
    return !(*this == c);
}
bool Complex::operator!=(double r) const {//inequality operator for comparing a Complex object with a scalar for non quality
    return !(*this == r);
}
bool operator!=(double r, const Complex &c) {//friend function for comparing a scalar with a Complex object for non equality
    return !(r == c);
}
Complex& Complex::operator=(const Complex &c) {//assigning a Complex object to another Complex object
    if (this != &c) {
        re = c.re;
        im = c.im;
    }
    return *this;
}
Complex& Complex::operator=(double r) {//assigning a scalar to a Complex object
    re = r;
    im = 0;
    return *this;
}
Complex& Complex::operator+=(const Complex &c) {//adding a Complex object to this Complex object
    *this = *this + c;
    return *this;
}
Complex& Complex::operator+=(double r) {//adding a scalar to this Complex object
    *this = *this + r;
    return *this;
}
Complex& Complex::operator-=(const Complex &c) {//subtracting a Complex object from this Complex object
    *this = *this - c;
    return *this;
}
Complex& Complex::operator-=(double r) {//subtracting a scalar from this Complex object
    *this = *this - r;
    return *this;
}
Complex& Complex::operator*=(const Complex &c) {//multiplying this Complex object by another Complex object
    *this = *this * c;
    return *this;
}
Complex& Complex::operator*=(double r) {//multiplying this Complex object by a scalar
    *this = *this * r;
    return *this;
}
Complex& Complex::operator/=(const Complex &c) {//dividing this Complex object by another Complex object
    *this = *this / c;
    return *this;
}
Complex& Complex::operator/=(double r) {//dividing this Complex object by a scalar
    *this = *this / r;
    return *this;
}
double Complex::magnitude() const {
    return sqrt(re * re + im * im);//return the magnitude of this Complex object
}
Complex Complex::conjugate() const {
    return Complex(re, -im);//return the conjugate of this Complex object
}


ostream& operator<<(ostream &output, const Complex &c) {//friend function to overload the output stream operator for Complex objects
    if (c.im == 0) output << c.re;
    else if (c.re == 0) output << c.im << "i";
    else output << c.re << (c.im > 0 ? "+" : "-") << abs(c.im) << "i";
    return output;
}
istream& operator>>(istream &input, Complex &c) {//friend function to overload the input stream operator for Complex objects
    char ch;
    input >> c.re >> ch >> c.im >> ch;
    return input;
}

