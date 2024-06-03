#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"

using namespace std;

// Overload stream to output a ratioanl number.
ostream& operator<<(ostream &output, const Complex &r){
	if(r.im==0.0)
		output<<r.re;
	else if(r.im>0){
		if(r.re==0){
			output<<r.im<<"i";
		}
		else{
			output<<r.re<<"+"<<r.im<<"i";
		}
	}
	else{
		if(r.re==0.0)
			output<<r.im<<"i";
		else
			output<<r.re<<r.im<<"i";
	}
	return output;
}

// Overload stream to input a ratioanl number.
istream &operator>>(istream &input, Complex &r) {
    input >> r.re;
    input.ignore(1); // Ignore space.
    input >> r.im; 
    return input; 
}
// Complex default constructor.
Complex::Complex(const double r, const double i) {
	re=r;
	im=i;
}

// Copy constructor.
Complex::Complex(const Complex &r){
  re=r.re;
  im=r.im;
}

// Get real part.
double Complex::getRe() const {return re;}

// Get imaginary part.
double Complex::getIm() const {return im;}

// Set new values to a complex object.
void Complex::setComplex(const double r, const double i) {
  re=r;
  im=i;
}

// Complex unary minus.
Complex Complex::operator-() const {
	Complex nega;
	nega.re=-re;
	nega.im=-im;
	return nega;
}

// Complex addition.
Complex Complex::operator+(const Complex &r) const {
	Complex sum;
	sum.re=re+r.re;
	sum.im=im+r.im;
	return sum;
}

// Complex-double addition.
Complex Complex::operator+(const double &m) const {
	Complex sum;
	sum.re=re+m;
	sum.im=im;
	return sum;
} 

// Double-Complex addition.
Complex operator+(const double &m, const Complex &r) {
	Complex sum;
	sum.re=m+r.re;
	sum.im=r.im;
	return sum;
}

// Complex subtraction.
Complex Complex::operator-(const Complex &r) const {
	Complex diff;
	diff.re = re - r.re;
	diff.im = im - r.im;
	return diff;
}

// Complex-double subtraction.
Complex Complex::operator-(const double &m) const {
	Complex diff;
	diff.re = re - m;
	diff.im = im;
	return diff;
}

// Double-Complex subtraction.
Complex operator-(const double &m, const Complex &r) {
	Complex diff;
	diff.re = m - r.re;
	diff.im = -r.im;
	return diff;
}

// Complex multiplication.
Complex Complex::operator*(const Complex &r) const {
	Complex prod;
	prod.re = re * r.re - im * r.im;
	prod.im = re * r.im + im * r.re;
	return prod;
}

// Complex-double multiplication.
Complex Complex::operator*(const double &m) const {
	Complex prod;
	prod.re = re * m;
	prod.im = im * m;
	return prod;
}

// Double-Complex multiplication.
Complex operator*(const double &m, const Complex &r) {
	Complex prod;
	prod.re = m * r.re;
	prod.im = m * r.im;
	return prod;
}

// Complex division.
Complex Complex::operator/(const Complex &r) const {
	Complex quot;
	double dividend = r.re * r.re + r.im * r.im;
	quot.re = (re * r.re + im * r.im) / dividend;
	quot.im = (-re * r.im + im * r.re) / dividend;
	return quot;
}

// Complex-double division.
Complex Complex::operator/(const double &m) const {
	Complex quot;
	quot.re = re / m;
	quot.im = im / m;
	return quot;
}

// Double-Complex division.
Complex operator/(const double &m, const Complex &r) {
	Complex quot;
	double dividend = r.re * r.re + r.im * r.im;
	quot.re = (m * r.re) / dividend;
	quot.im = (-m * r.im) / dividend;
	return quot;
}

// Equal to relation for complex numbers.
bool Complex::operator==(const Complex &r) const {
	return re==r.re && im==r.im;	
}

// Equal to relation for complex-double numbers. 
bool Complex::operator==(const double &m) const {
	return re==m && im==0;	
}

// Equal to relation for double-complex numbers.
bool operator==(const double &m, const Complex &r) {
	return m==r.re && r.im==0;	
}

// Not equal to relation for complex numbers.
bool Complex::operator!=(const Complex &r) const {
	return !(*this==r);
}

// Not equal to relation for complex-double numbers.
bool Complex::operator!=(const double &m) const {
	return !(*this==m);
}

// Not equal to relation for double-complex numbers.
bool operator!=(const double &m, const Complex &r) {
	return !(m==r);	
}

// Assignment.
Complex& Complex::operator=(const Complex &r) {
	re=r.re;
	im=r.im;
	return *this;	
}

// Assignment for double expression.
Complex& Complex::operator=(const double &m) {
	re=m;
	im=0;
	return *this;	
}

// Assignment with addition.
Complex& Complex::operator+=(const Complex &r) {
	*this = *this + r;
	return *this;	
}

// Assignment for double expression with addition.
Complex& Complex::operator+=(const double &m) {
	*this = *this + m;
	return *this;	
}

// Assignment with substraction.
Complex& Complex::operator-=(const Complex &r) {
	*this = *this - r;
	return *this;	
}

// Assignment for double expression with substraction.
Complex& Complex::operator-=(const double &m) {
	*this = *this - m;
	return *this;	
}

// Assignment with multiplication.
Complex& Complex::operator*=(const Complex &r) {
	*this = *this * r;
	return *this;	
}

// Assignment for double expression with multiplication.
Complex& Complex::operator*=(const double &m) {
	*this = *this * m;
	return *this;	
}

// Assighment with division.
Complex& Complex::operator/=(const Complex &r) {
	*this = *this / r;
	return *this;	
}

// Assignment for double expression with division.
Complex& Complex::operator/=(const double &m) {
	*this = *this / m;
	return *this;	
}

// Absolute value of complex numbers.
double Complex::cabs(void) const {	
	return sqrt(re * re + im * im);	
}
