#include <iostream>
#include <cstdlib>
#include <cmath>
#include "complex_overloading.h"

using namespace std;

ostream& operator << (ostream &output, const Complex &c){
	if(c.im == 0.0) output << c.re;
	else if(c.im > 0.0){
		if(c.re == 0.0) output << c.im << "i";
		else output << c.re << "+" << c.im << "i";
	}
	else{
		if(c.re == 0.0) output << c.im << "i";
		else output << c.re << c.im << "i";
	} 
	return output;
}
istream& operator >> (istream &input, Complex &c){
	input >> c.re;
	input.ignore(1);
	input >> c.im;
	return input;
} 
Complex::Complex(const double r, const double i){
	re = r;
	im = i;
}
Complex::Complex(const Complex &r){
	re = r.re;
	im = r.im;
}
double Complex::getRe() const{
	return re;
}
double Complex::getIm() const{
	return im;
}
void Complex::setComplex(const double r, const double i){
	re = r;
	im = i;
}
Complex Complex::operator-() const{
	Complex c;
	c.re = -re;
	c.im = -im;
	return c;
}
Complex Complex::operator+(const Complex &r) const{
	Complex c;
	c.re = re + r.re;
	c.im = im + r.im;
	return c;
}
Complex Complex::operator+(const double &r) const{
	Complex c;
	c.re = re + r;
	c.im = im;
	return c;
}
Complex operator+(const double &r, const Complex &i){
	Complex c;
	c.re = r + i.re;
	c.im = i.im;
	return c;
}
Complex Complex::operator-(const Complex &c) const{
	Complex sub;
	sub.re = re - c.re;
	sub.im = im - c.im;
	return sub;
}
Complex Complex::operator-(const double &c) const{
	Complex sub;
	sub.re = re - c;
	sub.im = im;
	return sub;
}
Complex operator-(const double &r, const Complex &i){
	Complex sub;
	sub.re = r - i.re;
	sub.im = -i.im;
	return sub;
}
Complex Complex::operator*(const Complex &c) const{
	Complex times;
	times.re = re * c.re - im * c.im;
	times.im = re * c.im + im * c.re;
	return times;
}
Complex Complex::operator*(const double &c) const{
	Complex times;
	times.re = re * c;
	times.im = im * c;
	return times;
}
Complex operator*(const double &r, const Complex &i){
	Complex times;
	times.re = r * i.re;
	times.im = r * i.im;
	return times;
}
Complex Complex::operator/(const Complex &c) const{
	Complex quot;
	double div = c.re * c.re + c.im * c.im;
	quot.re = (re * c.re + im * c.im) / div;
	quot.im = (-re * c.im + im * c.re ) / div;
	return quot;
}
Complex Complex::operator/(const double &c) const{
	Complex quot;
	quot.re = re / c;
	quot.im = im / c;
	return quot;
}
Complex operator/(const double &r, const Complex &i){
	Complex quot;
	double div = i.re * i.re + i.im * i.im;
	quot.re = (r / i.re) / div;
	quot.im = (-r / i.im) / div;
	return quot;
}
bool Complex::operator==(const Complex &c) const{
	return re == c.re && im == c.im;
}
bool Complex::operator==(const double &c) const{
	return re == c && im == 0;
}
bool operator==(const double &r, const Complex &i){
	return r == i.re && i.im == 0;
}
bool Complex::operator!=(const Complex &c) const{
	return !(*this == c);
}
bool Complex::operator!=(const double &c) const{
	return !(*this == c);
}
bool operator!=(const double &r, const Complex &i){
	return !(r == i);
}
Complex& Complex::operator=(const Complex &c){
	re = c.re;
	im = c.im;
	return *this;
}
Complex& Complex::operator=(const double &c) {
	re = c;
	im = 0;
	return *this;	
} 
Complex& Complex::operator+=(const Complex &c) {
	*this = *this + c;
	return *this;	
}
Complex& Complex::operator+=(const double &c) {
	*this = *this + c;
	return *this;	
}
Complex& Complex::operator-=(const Complex &c) {
	*this = *this - c;
	return *this;	
}
Complex& Complex::operator-=(const double &c) {
	*this = *this - c;
	return *this;	
} 
Complex& Complex::operator*=(const Complex &c) {
	*this = *this * c;
	return *this;	
} 
Complex& Complex::operator*=(const double &c) {
	*this = *this * c;
	return *this;	
}
Complex& Complex::operator/=(const Complex &c) {
	*this = *this / c;
	return *this;	
}
Complex& Complex::operator/=(const double &c) {
	*this = *this / c;
	return *this;	
}
double Complex::cabs(void) const {	
	return sqrt(re * re + im * im);	
}
