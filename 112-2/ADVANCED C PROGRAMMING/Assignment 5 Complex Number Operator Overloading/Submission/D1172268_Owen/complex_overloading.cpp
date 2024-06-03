#include "complex_overloading.h"
#include <cmath>

Complex::Complex(){
	this->re = 0;
	this->im = 0;
}

Complex::Complex(Complex &a){
	this->re = a.re;
	this->im = a.im;
}

double Complex::getRe(){
	return this->re;
}

double Complex::getIm(){
	return this->im;
}

void Complex::setRe(double r){
	this->re = r;
}

void Complex::setIm(double s){
	this->im = s;
}

double Complex::absComplex(){
    return sqrt(this->re * this->re + this->im * this->im);
}

Complex operator+(Complex &c1, Complex &c2){
	Complex d;
	d.setRe(c1.getRe() + c2.getRe()); 
	d.setIm(c1.getIm() + c2.getIm()); 
	return d;
}

Complex operator+(double &d, Complex &c){
	Complex n;
	n.setRe(d + c.getRe()); 
	n.setIm(c.getIm()); 
	return n;
}

Complex operator+(Complex &c, double &d){
	Complex n;
	n.setRe(d + c.getRe()); 
	n.setIm(c.getIm()); 
	return n;
}

Complex operator-(Complex &c1, Complex &c2){
	Complex d;
	d.setRe(c1.getRe() - c2.getRe()); 
	d.setIm(c1.getIm() - c2.getIm()); 
	return d;
}

Complex operator-(double &d, Complex &c){
	Complex n;
	n.setRe(d - c.getRe()); 
	n.setIm(c.getIm()); 
	return n;
}
Complex operator-(Complex &c, double &d){
	Complex n;
	n.setRe(c.getRe() - d); 
	n.setIm(c.getIm()); 
	return n;
}

Complex operator*(Complex &c1, Complex &c2){
	Complex n;
	double a = c1.getRe();
	double b = c1.getIm();
	double c = c2.getRe();
	double d = c2.getIm();
	
	n.setRe(a * c - b * d); 
	n.setIm(a * d + b * c);
	return n;
}

Complex operator*(double &D, Complex &C){
	Complex n;
	double a = D;
	double b = 0;
	double c = C.getRe();
	double d = C.getIm();
	
	n.setRe(a * c - b * d); 
	n.setIm(a * d + b * c);
	return n;
}

Complex operator*(Complex &C, double &D){
	Complex n;
	double a = C.getRe();
	double b = C.getIm();
	double c = D;
	double d = 0;
	
	n.setRe(a * c - b * d); 
	n.setIm(a * d + b * c);
	return n;
}
Complex operator/(Complex &c1, Complex &c2){
	Complex n;
	double a = c1.getRe();
	double b = c1.getIm();
	double c = c2.getRe();
	double d = c2.getIm();
	
	n.setRe((a * c + b * d) / (pow(c, 2) + pow(d, 2))); 
	n.setIm((-a * d + b * c) / (pow(c, 2) + pow(d, 2))); 
	return n;
}

Complex operator/(double &D, Complex &C){
	Complex n;
	double a = D;
	double b = 0;
	double c = C.getRe();
	double d = C.getIm();
	
	n.setRe((a * c + b * d) / (pow(c, 2) + pow(d, 2))); 
	n.setIm((-a * d + b * c) / (pow(c, 2) + pow(d, 2))); 
	return n;
}

Complex operator/(Complex &C, double &D){
	Complex n;
	double a = C.getRe();
	double b = C.getIm();
	double c = D;
	double d = 0;
	
	n.setRe((a * c + b * d) / (pow(c, 2) + pow(d, 2))); 
	n.setIm((-a * d + b * c) / (pow(c, 2) + pow(d, 2))); 
	return n;
}

bool operator==(Complex &c1, Complex &c2){
	double a = c1.getRe();
	double b = c1.getIm();
	double c = c2.getRe();
	double d = c2.getIm();	
	if(a == c && b == d) return true;
	else return false;
}

bool operator==(double &D, Complex &C){
	double a = D;
	double b = 0;
	double c = C.getRe();
	double d = C.getIm();	
	if(a == c && b == d) return true;
	else return false;
}

bool operator==(Complex &C, double &D){
	double a = C.getRe();
	double b = C.getIm();
	double c = D;
	double d = 0;	
	if(a == c && b == d) return true;
	else return false;	
}

bool operator!=(Complex &c1, Complex &c2){
	double a = c1.getRe();
	double b = c1.getIm();
	double c = c2.getRe();
	double d = c2.getIm();	
	if(a != c || b != d) return true;
	else return false;
}

bool operator!=(double &D, Complex &C){
	double a = D;
	double b = 0;
	double c = C.getRe();
	double d = C.getIm();	
	if(a != c || b != d) return true;
	else return false;	
}

bool operator!=(Complex &C, double &D){
	double a = C.getRe();
	double b = C.getIm();
	double c = D;
	double d = 0;	
	if(a != c || b != d) return true;
	else return false;
}

Complex Complex::operator=(const Complex &c){
	this->re = c.re;
	this->im = c.im; 
	return *this;
}

Complex Complex::operator=(const double &d){
	this->re = d;
	this->im = 0; 
	return *this;
}

void Complex::operator+=(Complex &c){
	this->re += c.re;
	this->im += c.im; 
}

void Complex::operator+=(double &d){
	this->re += d;
	this->im += 0; 
}

void Complex::operator-=(Complex &c){
	this->re -= c.re;
	this->im -= c.im; 
}

void Complex::operator-=(double &d){
	this->re -= d;
	this->im -= 0; 
}

void Complex::operator*=(Complex &C){
	double a = this->re;
	double b = this->im;
	double c = C.getRe();
	double d = C.getIm();
	this->re = a * c - b * d;
	this->im = a * d + b * c; 
}

void Complex::operator*=(double &D){
	double a = this->re;
	double b = this->im;
	double c = D;
	double d = 0;
	this->re = a * c - b * d;
	this->im = a * d + b * c; 
}

void Complex::operator/=(Complex &C){
	double a = this->re;
	double b = this->im;
	double c = C.getRe();
	double d = C.getIm();
	this->re = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
	this->im = (-a * d + b * c) / (pow(c, 2) + pow(d, 2)); 
}

void Complex::operator/=(double &D){
	double a = this->re;
	double b = this->im;
	double c = D;
	double d = 0;
	this->re = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
	this->im = (-a * d + b * c) / (pow(c, 2) + pow(d, 2)); 
}

ostream& operator<<(ostream &os, Complex &c){
	if(c.re == 0) os << fixed << setprecision(4) << c.im <<'i';
	else if(c.im == 0) os << fixed << setprecision(4) << c.re;
	else if(c.im > 0) os << fixed << setprecision(4) << c.re << '+' << fixed << setprecision(4) << c.im <<'i';
	else if(c.im < 0) os << fixed << setprecision(4) << c.re << '-' << fixed << setprecision(4) << -c.im << 'i';
	
	return os;
}

istream& operator>>(istream &is, Complex &c){
	is >> c.re >> c.im;
	return is; 
}

Complex Complex::operator-(){
	this->re = -this->re;
	this->im = -this->im;
	return *this;
}

