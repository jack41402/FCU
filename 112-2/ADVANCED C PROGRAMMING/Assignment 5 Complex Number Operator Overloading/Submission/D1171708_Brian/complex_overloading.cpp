#include "complex_overloading.h"
#include <iostream>
#include <math.h>
using namespace std;

Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double real,double image) :re(real),im(image){}
double Complex::getRe(){
	return re; 
}
double Complex::getIm(){
	return im; 
}
void Complex::setRe(double re){ 
	re = re; 
}
void Complex::setIm(double im){ 
	im = im; 
}
Complex Complex::operator+(const Complex &c){
	Complex add;
	add.re = re+c.re;
	add.im = im+c.im;
	return add;
}
 
Complex Complex::operator-(const Complex &c){
	Complex minus;
	minus.re = re-c.re;
	minus.im = im-c.im;
	return minus;
}
 
Complex Complex::operator*(const Complex &c){
	Complex time;
	time.re = re*c.re-im*c.im;
	time.im = re*c.im+im*c.re;
	return time;
}

Complex Complex::operator/(const Complex &c){
	Complex div;
	double d=c.re*c.re+c.im*c.im;
	div.re = (re*c.re-im*(-c.im))/d;
	div.im = (re*(-c.im)+im*c.re)/d;
	return div;
}
bool Complex::operator==(const Complex &c){
	return (re == c.re)&&(im == c.im);
}
bool Complex::operator!=(const Complex &c){
    return !(*this == c);
}


Complex operator+(const double d,const Complex &c){
	return Complex(c.re+d, c.im);
}

Complex operator-(const double d,const Complex &c){
	return Complex(c.re-d, c.im);
}

Complex operator*(const double d,const Complex &c){
	return Complex(c.re*d, c.im);
}

Complex operator/(const double d,const Complex &c){
	return Complex(c.re/d, c.im);
}
bool operator==(const double d,const Complex &c){
	return ((d == c.re)&&(c.im==0));
}

bool operator!=(const double d,const Complex &c){
	return !((d == c.re)&&(c.im==0));
}



Complex operator+(const Complex &c,const double d) {
    return Complex(c.re+d, c.im);
}

Complex operator-(const Complex &c,const double d) {
    return Complex(c.re-d, c.im);
}

Complex operator*(const Complex &c,const double d) {
    return Complex(c.re*d, c.im*d);
}

Complex operator/(const Complex &c,const double d) {
    if (d != 0.0)
        return Complex(c.re/d, c.im/d);
    else
        return c;
}

bool operator==(const Complex &c,const double d){
	return (d == c.re)&&(d == c.im);
}
bool operator!=(const Complex &c,const double d){
    return !((d == c.re)&&(c.im==0));
}



double Complex::abs(){
    return sqrt(re*re+im*im);
}
double Complex::square(){
	return sqrt(re);
}

Complex& Complex::operator=(const Complex &c) {
    re = c.re;
    im = c.im;
    return *this;
}

Complex& Complex::operator+=(const Complex &c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex& Complex::operator-=(const Complex &c) {
    re -= c.re;
    im -= c.im;
    return *this;
}

Complex& Complex::operator*=(const Complex &c) {
    Complex tmp(*this);
    re = tmp.re*c.re-im*c.im;
    im = tmp.re*c.im+tmp.im*c.re;
    return *this;

}

Complex& Complex::operator/=(const Complex &c) {
	Complex tmp(*this);
    double d=c.re*c.re+c.im*c.im;
	re = (tmp.re*c.re-tmp.im*(-c.im))/d;
	im = (tmp.re*(-c.im)+tmp.im*c.re)/d;
    return *this;
}



ostream& operator<<(ostream &out, const Complex &c) {
	if (c.im<0){
		out << c.re << "-" << -c.im << "i";
	}
	if (c.im==0){
		out << c.re;
	}
	if (c.im>0){
		out << c.re << "+" << c.im << "i";
	} 	
    return out;
}

istream& operator>>(istream &in, Complex &c) {
    in >> c.re >> c.im;
    return in;
}

Complex Complex::operator-(){
    return Complex(-re, -im);
}
/*
ostream& operator<<(ostream &out, double d) {
    out << d;
    return out;
}

istream& operator>>(istream &in,  double &d){
	in >> d;
	return in;
}*/










