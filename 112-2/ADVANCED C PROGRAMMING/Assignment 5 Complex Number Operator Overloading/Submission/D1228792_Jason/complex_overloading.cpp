#include <iostream>
#include "complex_overloading.h"
#include <iomanip>
#include <math.h>
using namespace std;
Complex::Complex(){
	real = 0;
	imaginary = 0;
}
Complex::Complex(double a,double b){
	real = a;
	imaginary = b;
}
double Complex::getRe(){
	return real;
}
double Complex::getIm(){
	return imaginary;
}
void Complex::setRe(double r){
	real = r;
}
void Complex::setIm(double s){
	imaginary = s;
}
double Complex::absolute(){
	return (pow((real*real+imaginary*imaginary),0.5));
}
Complex Complex::operator+(Complex c){
	Complex z(real+c.real,imaginary+c.imaginary);
	return z;
}//complex+complex.
Complex Complex::operator+(double d){
	Complex z(real+d,imaginary);
	return z;
}//complex+double.
Complex operator+(double d,Complex c){
	Complex z(d+c.real,c.imaginary);
	return z;
}//double+complex.
Complex Complex::operator-(Complex c){
	Complex z(real-c.real,imaginary-c.imaginary);
	return z;
}//complex-complex
Complex Complex::operator-(double d){
	Complex z(real-d,imaginary);
	return z;
}//complex-double.
Complex operator-(double d,Complex c){
	Complex z(d-c.real,c.imaginary);
	return z;
}//double+complex.
Complex Complex::operator*(Complex c){
	Complex z(real*c.real-imaginary*c.imaginary,real*c.imaginary+imaginary*c.real);
	return z;
}//complex*complex.
Complex Complex::operator*(double d){
	Complex z(real*d,imaginary*d);
	return z;
}//complex*double.
Complex operator*(double d,Complex c){
	Complex z(d*c.real,d*c.imaginary);
	return z;
}//double*complex.
Complex Complex::operator/(Complex c){
	Complex z((real*c.real+imaginary*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary),(-1*real*c.imaginary+imaginary*c.real)/(c.real*c.real+c.imaginary*c.imaginary));
	return z;
}//complex/complex.
Complex Complex::operator/(double d){
	Complex z((real*d)/(d*d),(imaginary*d)/(d*d));
	return z;
}//complex/double.
Complex operator/(double d,Complex c){
	Complex z((d*c.real)/(c.real*c.real+c.imaginary*c.imaginary),(-1*d*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary));
	return z;
}//double/complex.
bool Complex::operator==(Complex c){
	return (real == c.real && imaginary == c.imaginary);
}//complex==complex.
bool Complex::operator==(double d){
	return (real == d && imaginary == 0.0);
}//complex==double.
bool operator==(double d,Complex c){
	return (c.real == d && c.imaginary == 0.0);
}//double==complex.
bool Complex::operator!=(Complex c){
	return (real != c.real || imaginary != c.imaginary);
}//complex!=complex.
bool Complex::operator!=(double d){
	return (real != d || imaginary != 0.0);
}//compelx!=double.
bool operator!=(double d,Complex c){
	return (c.real != d || c.imaginary != 0.0);
}//double!=complex.
void Complex::operator=(Complex c){
	real = real + c.real;
	imaginary = imaginary + c.imaginary;
}//complex=complex.
void Complex::operator=(double d){
	real =	 d;
}//complex=double.
void Complex::operator+=(Complex c){
	real = real + c.real;
	imaginary = imaginary + c.imaginary;
}//complex+=complex.
void Complex::operator+=(double d){
	real = real + d;
}//complex+=double.
void Complex::operator-=(Complex c){
	real = real - c.real;
	imaginary = imaginary - c.imaginary;
}//complex-=complex.
void Complex::operator-=(double d){
	real = real - d;
}//complex-=double.
void Complex::operator*=(Complex c){
	real = real*c.real-imaginary*c.imaginary;
	imaginary = real*c.imaginary+imaginary*c.real;
}//complex*=complex.
void Complex::operator*=(double d){
	real = real*d;
	imaginary = imaginary*d;
}//complex*=double.
void Complex::operator/=(Complex c){
	real = (real*c.real+imaginary*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary);
	imaginary = (-1*real*c.imaginary+imaginary*c.real)/(c.real*c.real+c.imaginary*c.imaginary);
}//complex/=complex.
void Complex::operator/=(double d){
	real = (real*d)/(d*d);
	imaginary = (imaginary*d)/(d*d);
}//complex/=double.
