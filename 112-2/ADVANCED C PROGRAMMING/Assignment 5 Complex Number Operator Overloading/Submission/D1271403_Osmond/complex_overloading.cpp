#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include"complex_overloading.h"
using namespace std;

Complex::Complex(double R, double I){
	real=R;
	image=I;
}

Complex::Complex(const Complex& g){
	real=g.real;
	image=g.image;
}

Complex Complex::operator +(const double& h){
	Complex temp(real+h, image);
	return temp;
}

Complex Complex::operator +(const Complex& g){
	Complex temp(real+g.real, image+g.image);
	return temp;
}

Complex Complex::operator -(const double& h){
	Complex temp(real-h, image);
	return temp;
}


Complex Complex::operator -(const Complex& g){
	Complex temp(real-g.real, image-g.image);
	return temp;
}

Complex Complex::operator *(const double& h){
	Complex temp(real*h, image*h);
	return temp;
}

Complex Complex::operator *(const Complex& g){
	Complex temp(real*g.real-image*g.image, real*g.image+image*g.real);
	return temp;
}

Complex Complex::operator /(const double& h){
	Complex temp(real/h, image/h);
	return temp;
}

Complex Complex::operator /(const Complex& g){
	Complex temp((real*g.real+image*g.image)/(g.real*g.real+g.image*g.image), (image*g.real-real*g.image)/(g.real*g.real+g.image*g.image));
	return temp;
}

bool Complex::operator ==(const double& h){
	return (real==h)&&(image==0.0);
}

bool Complex::operator ==(const Complex& g){
	return (real==g.real)&&(image==g.image);
}

bool Complex::operator !=(const double& h){
	return (real!=h)||(image!=0.0);
}

bool Complex::operator !=(const Complex& g){
	return (real!=g.real)||(image!=g.image);
}

Complex& Complex::operator =(const double& h){
	real=h;
	image=0.0;
	return *this;
}

Complex& Complex::operator =(const Complex& g){
	real=g.real;
	image=g.image;
	return *this;
}

Complex& Complex::operator +=(const double& h){
	real+=h;
	return *this;
}

Complex& Complex::operator +=(const Complex& g){
	real+=g.real;
	image+=g.image;
	return *this; 
}

Complex& Complex::operator -=(const double& h){
	real-=h;
	return *this;
}

Complex& Complex::operator -=(const Complex& g){
	real-=g.real;
	image-=g.image;
	return *this;
}

Complex& Complex::operator *=(const double& h){
	real*=h;
	image*=h;
	return *this;
}

Complex& Complex::operator *=(const Complex& g){
	real=real*g.real-image*g.image;
	image=real*g.image+image*g.real;
	return *this;
}

Complex& Complex::operator /=(const double& h){
	real/=h;
	image/=h;
	return *this;
}

Complex& Complex::operator /=(const Complex& g){
	real=(real*g.real+image*g.image)/(g.real*g.real+g.image*g.image);
	image=(image*g.real-real*g.image)/(g.real*g.real+g.image*g.image);
	return *this;
}

ostream& operator <<(ostream& os , const Complex& g){
	os<< fixed << setprecision(4)<<g.real;
	if(g.image>0) os<< fixed << setprecision(4)<<'+'<<g.image<<'i';
	else if(g.image==0) os<< "";
	else os<< fixed << setprecision(4)<<g.image<<'i';
	return os;
}

istream& operator >>(istream& is, Complex& g){
	is>>g.real>>g.image;
	return is;
}

Complex operator +(const double& h, const Complex& g){
	Complex temp(h+g.real, g.image);
	return temp;
}

Complex operator -(const double& h, const Complex& g){
	Complex temp(h-g.real, g.image);
	return temp;
}

Complex operator *(const double& h, const Complex& g){
	Complex temp(h*g.real, h*g.image);
	return temp;
}
	
Complex operator /(const double& h, const Complex& g){
	Complex temp((h*g.real)/(g.real*g.real+g.image*g.image), (-h*g.image)/(g.real*g.real+g.image*g.image));
	return temp;
}

bool operator ==(const double& h, const Complex& g){
	return (h==g.real)&&(g.image==0.0);
}
	
bool operator !=(const double& h, const Complex& g){
	return (h!=g.real)||(g.image!=0.0);
}

double Complex::getRe(){
	return real;
}
double Complex::getIm(){
	return image;
}
void Complex::setRe(const double& h){
	real=h;
}
void Complex::setIm(const double& h){
	image=h;
}
double Complex::cabs(){
	return sqrt(real*real+image*image);
}
