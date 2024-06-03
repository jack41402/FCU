#include"complex_overloading.h"
#include<iostream>
#include<math.h>
//make real part and imaginary part to 0
Complex::Complex(){
	r = 0;
	i = 0;
}
//make real part and imaginary part to a and b
Complex::Complex(double a, double b){
	r = a;
	i = b;
}
//C+C
Complex Complex::operator+(Complex C){
	return Complex(r+C.r, i+C.i);
}
//C+D
Complex Complex::operator+(double d){
	return Complex(r+d, i);
}
//D+C
Complex operator+(double d, Complex C){
	return Complex(d+C.r, C.i);
}
//C-C
Complex Complex::operator-(Complex C){
	return Complex(r-C.r, i-C.i);
}
//C-D
Complex Complex::operator-(double d){
	return Complex(r-d, i);
}
//D-C
Complex operator-(double d, Complex C){
	return Complex(d-C.r, C.i);
}
//C*C
Complex Complex::operator*(Complex C){
	return Complex(r*C.r-i*C.i, r*C.i+i*C.r);
}
//C*D
Complex Complex::operator*(double d){
	return Complex(r*d, i*d);
}
//D*C
Complex operator*(double d, Complex C){
	return Complex(d*C.r, d*C.i);
}
//C/C
Complex Complex::operator/(Complex C){
	return Complex((r*C.r+i*C.i)/(C.r*C.r+C.i*C.i), ((-1*r)*C.i+i*C.r)/(C.r*C.r+C.i*C.i));
}
//C/D
Complex Complex::operator/(double d){
	return Complex((r*d)/(d*d), (i*d)/(d*d));
}
//D/C
Complex operator/(double d, Complex C){
	return Complex((d*C.r)/(C.r*C.r+C.i*C.i), (-1*d*C.i)/(C.r*C.r+C.i*C.i));
}
//absoulte value
double Complex::abs(){
	return (sqrt(r*r+i*i));
}
//get the real part
double Complex::getRe(){
	return r;
}
//return the imaginary part
double Complex::getIm(){
	return i;
}
//set the real part value
void Complex::setRe(double d){
	r = d;
}
//set the imaginary part value
void Complex::setIm(double d){
	i = d;
}
//C==C
bool Complex::operator==(Complex C){
	return (r==C.r && i==C.i);
}
//C==d
bool Complex::operator==(double d){
	return (r == d && i==0.0);
}
//C!=C
bool Complex::operator!=(Complex C){
	return (r!=C.r || i!=C.i);
}
//C!=d
bool Complex::operator!=(double d){
	return (r!=d || i!=0.0);
}
//C=C
void Complex::operator=(Complex C){
	r = C.r;
	i = C.i;
}
//C=d
void Complex::operator=(double d){
	r = d;
	i = 0.0;
}
//C+=C
void Complex::operator+=(Complex C){
	r = r+C.r;
	i = i+C.i;
}
//C+=d
void Complex::operator+=(double d){
	r = r+d;
}
//C-=C
void Complex::operator-=(Complex C){
	r = r - C.r;
	i = i -C.i;
}
//C-=d
void Complex::operator-=(double d){
	r = r-d;
}
//C*=C
void Complex::operator*=(Complex C){
	r = r*C.r-i*C.i;
	i = r*C.i+i*C.r;
}
//C*=d
void Complex::operator*=(double d){
	r = r*d;
	i = i*d;
}
//C/=C
void Complex::operator/=(Complex C){
	r = (r*C.r+i*C.i)/(C.r*C.r+C.i*C.i);
	i = (-1*r*C.i+i*C.r)/(C.r*C.r+C.i*C.i);
}
//C/=d
void Complex::operator/=(double d){
	r = (r*d)/d*d;
	i = (i*d)/d*d;
}
