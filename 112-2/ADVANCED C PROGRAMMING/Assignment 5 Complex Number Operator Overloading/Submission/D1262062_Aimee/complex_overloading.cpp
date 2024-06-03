#include "complex_overloading.h"
#include <cmath>
#include <iomanip>
Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double re, double im) : re(re), im(im) {}
// Get the real part of a complex number
double Complex::getRe() const{
	return re;
}
// Get the imaginary part of a complex number
double Complex::getIm() const{
	return im;
}
// Set the real part of a complex number
void Complex::setRe(double re) {
	this->re = re;
}
// Set the imaginary part of a complex number
void Complex::setIm(double im) {
	this->im = im;
}
// Unary operator
Complex Complex::operator-() const{
	return Complex(-re, -im);
}
// Addition
Complex Complex::operator+(const Complex c) const{
	return Complex(re + c.re, im + c.im);
}
Complex Complex::operator+(const double d) const{
	return Complex(re + d, im);
}
Complex operator+(double d, const Complex c) {
    return Complex(d + c.re, c.im);
}
// Subtraction
Complex Complex::operator-(const Complex c) const{
	return Complex(re - c.re, im - c.im);
}
Complex Complex::operator-(const double d) const{
	return Complex(re - d, im);
}
Complex operator-(double d, const Complex c){
	return Complex(d - c.re, -c.im);
}
// Multiplication
Complex Complex::operator*(const Complex c) const{
	double resultRe = re * c.re - im * c.im;
    double resultIm = re * c.im + im * c.re;
    return Complex(resultRe, resultIm);
}
Complex Complex::operator*(const double d) const {
    return Complex(re * d, im * d);
}
Complex operator*(double d, const Complex c) {
    return Complex(d * c.re, d * c.im);
}
// Division
Complex Complex::operator/(const Complex c) const {
    double deno = c.re * c.re + c.im * c.im;
    if(deno == 0) return Complex();
    double resultRe = (re * c.re + im * c.im) / deno;
    double resultIm = (im * c.re - re * c.im) / deno;
    return Complex(resultRe, resultIm);
}
Complex Complex::operator/(const double d) const {
	if(d == 0) return Complex();
    return Complex(re / d, im / d);
}
Complex operator/(const double d, const Complex c) {
    double deno = c.re * c.re + c.im * c.im;
    if(deno == 0) return Complex();
    double resultRe = (d * c.re) / deno;
    double resultIm = (-d * c.im) / deno;
    return Complex(resultRe, resultIm);
}
// Equal
bool Complex::operator==(const Complex c) const {
    return (re == c.re) && (im == c.im);
}
bool Complex::operator==(const double d) const {
    return (re == d) && (im == 0.0);
}
bool operator==(const double d, const Complex c) {
    return (d == c.re) && (c.im == 0.0);
}
bool Complex::operator!=(const Complex c) const {
    return !(*this == c);
}
// Nonequal
bool Complex::operator!=(const double d) const {
    return !(*this == d);
}
bool operator!=(const double d, const Complex c) {
    return !(d == c);
}
// Assignment operators
Complex& Complex::operator=(const Complex c) {
    if (this != &c) {
        re = c.re;
        im = c.im;
    }
    return *this;
}
Complex& Complex::operator=(const double d) {
    re = d;
    im = 0.0;
    return *this;
}
Complex& Complex::operator+=(const Complex c) {
    re += c.re;
    im += c.im;
    return *this;
}
Complex& Complex::operator+=(const double d) {
    re += d;
    return *this;
}
Complex& Complex::operator-=(const Complex c) {
    re -= c.re;
    im -= c.im;
    return *this;
}
Complex& Complex::operator-=(const double d) {
    re -= d;
    return *this;
}
Complex& Complex::operator*=(const Complex c) {
    double tempRe = re;
    re = (re * c.re) - (im * c.im);
    im = (tempRe * c.im) + (im * c.re);
    return *this;
}
Complex& Complex::operator*=(const double d) {
    re *= d;
    im *= d;
    return *this;
}
Complex& Complex::operator/=(const Complex c) {
    double deno = c.re * c.re + c.im * c.im;
    double tempRe = re;
    re = (re * c.re + im * c.im) / deno;
    im = (im * c.re - tempRe * c.im) / deno;
    return *this;
}
Complex& Complex::operator/=(const double d) {
    re /= d;
    im /= d;
    return *this;
}
//I/O stream operators
ostream& operator<<(ostream& os, const Complex& c) {
	os << fixed << setprecision(4);
	if(c.im == 0) os << c.re;
	else if(c.re == 0) os << c.im;
	else if(c.im > 0) os << c.re << "+" << c.im << "i";
	else os << c.re << c.im << "i";
    return os;
}
istream& operator>>(istream& is, Complex& c) {
    is >> c.re >> c.im;
	return is;
}


