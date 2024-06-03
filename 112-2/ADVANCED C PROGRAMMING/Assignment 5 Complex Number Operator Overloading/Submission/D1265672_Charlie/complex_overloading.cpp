#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "complex_overloading.h"
using namespace std;

ostream &operator<<(ostream &output, const Complex &c){// Overload stream to output a complex.
    cout << fixed << setprecision(4);
    if(c.getIm()==0) output<<c.getRe();
    else if(c.getRe()==0) output<<c.getIm()<<"i";
    else {
        if(c.getIm()<0) output<<c.getRe()<<c.getIm()<<"i";
        else output<<c.getRe()<<"+"<<c.getIm()<<"i";
    }
    return output;
}

istream &operator>>(istream &input, Complex &c){// Overload stream to input a complex.
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

Complex Complex::operator-() const{
    Complex nega;
    nega.re=-re;
    nega.im=-im;
    return nega;
}

Complex Complex::operator+(const Complex &c) const{
    Complex sum;
    sum.re=re+c.re;
    sum.im=im+c.im;
    return sum;
}

Complex Complex::operator+(const double &n) const{
    Complex sum;
    sum.re=re+n;
    sum.im=im;
    return sum;
}

Complex operator+(const double &n, const Complex &c){
    Complex sum;
    sum.re=c.re+n;
    sum.im=c.im;
    return sum;
}

Complex Complex::operator-(const Complex &c) const{
    Complex diff;
    diff.re=re-c.re;
    diff.im=im-c.im;
    return diff;
}

Complex Complex::operator-(const double &n) const{
    Complex diff;
    diff.re=re-n;
    diff.im=im;
    return diff;
}

Complex operator-(const double &n, const Complex &c){
    Complex diff;
    diff.re=n-c.re;
    diff.im=-c.im;
    return diff;
}

Complex Complex::operator*(const Complex &c) const{
    Complex prod;
    prod.re=re*c.re-im*c.im;
    prod.im=re*c.im+im*c.re;
    return prod;
}

Complex Complex::operator*(const double &n) const{
    Complex prod;
    prod.re=re*n;
    prod.im=im*n;
    return prod;
}

Complex operator*(const double &n, const Complex &c){
    Complex prod;
    prod.re=n*c.re;
    prod.im=n*c.im;
    return prod;
}

Complex Complex::operator/(const Complex &c) const{
    Complex quot;
    quot.re=(re*c.re+im*c.im)/(c.re*c.re+c.im*c.im);
    quot.im=(im*c.re-re*c.im)/(c.re*c.re+c.im*c.im);
    return quot;
}

Complex Complex::operator/(const double &n) const{
    Complex quot;
    quot.re=re/n;
    quot.im=im/n;
    return quot;
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

bool Complex::operator==(const double &n) const{
    return (re==n && im==0);
}

bool operator==(const double &n, const Complex &c){
    return (c.re==n && c.im==0);
}

bool Complex::operator!=(const Complex &c) const{
    return !(*this==c);
}

bool Complex::operator!=(const double &n) const{
    return !(*this==n);
}

bool operator!=(const double &n, const Complex &c){
    return !(n==c);
}

Complex& Complex::operator=(const Complex &c){
    re=c.re;
    im=c.im;
    return *this;
}

Complex& Complex::operator=(const double &n){
    re=n;
    im=0;
    return *this;
}

Complex& Complex::operator+=(const Complex &c){
    *this=*this+c;
    return *this;
}

Complex& Complex::operator+=(const double &n){
    *this=*this+n;
    return *this;
}

Complex& Complex::operator-=(const Complex &c){
    *this=*this-c;
    return *this;
}

Complex& Complex::operator-=(const double &n){
    *this=*this-n;
    return *this;
}

Complex& Complex::operator*=(const Complex &c){
    *this=*this*c;
    return *this;
}

Complex& Complex::operator*=(const double &n){
    *this=*this*n;
    return *this;
}

Complex& Complex::operator/=(const Complex &c){
    *this=*this/c;
    return *this;
}

Complex& Complex::operator/=(const double &n){
    *this=*this/n;
    return *this;
}

double Complex::cabs(void) const{
    double abs;
    abs=sqrt(re*re+im*im);
    return abs;
}
