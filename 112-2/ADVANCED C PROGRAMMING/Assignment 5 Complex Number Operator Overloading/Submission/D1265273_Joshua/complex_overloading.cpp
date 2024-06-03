#include"complex_overloading.h"
#include<iostream>
#include<math.h>
//make real part and imaginary part to 0
Complex::Complex(){
	rel = 0;
	img = 0;
}
//make real part and imaginary part to a and b
Complex::Complex(double a, double b){
	rel = a;
	img = b;
}
//C+C
Complex Complex::operator+(Complex C){
	return Complex(rel+C.rel, img+C.img);
}
//C+D
Complex Complex::operator+(double d){
	return Complex(rel+d, img);
}
//D+C
Complex operator+(double d, Complex C){
	return Complex(d+C.rel, C.img);
}
//C-C
Complex Complex::operator-(Complex C){
	return Complex(rel-C.rel, img-C.img);
}
//C-D
Complex Complex::operator-(double d){
	return Complex(rel-d, img);
}
//D-C
Complex operator-(double d, Complex C){
	return Complex(d-C.rel, C.img);
}
//C*C
Complex Complex::operator*(Complex C){
	return Complex(rel*C.rel-img*C.img, rel*C.img+img*C.rel);
}
//C*D
Complex Complex::operator*(double d){
	return Complex(rel*d, img*d);
}
//D*C
Complex operator*(double d, Complex C){
	return Complex(d*C.rel, d*C.img);
}
//C/C
Complex Complex::operator/(Complex C){
	return Complex((rel*C.rel+img*C.img)/(C.rel*C.rel+C.img*C.img), ((-1*rel)*C.img+img*C.rel)/(C.rel*C.rel+C.img*C.img));
}
//C/D
Complex Complex::operator/(double d){
	return Complex((rel*d)/(d*d), (img*d)/(d*d));
}
//D/C
Complex operator/(double d, Complex C){
	return Complex((d*C.rel)/(C.rel*C.rel+C.img*C.img), (-1*d*C.img)/(C.rel*C.rel+C.img*C.img));
}
//absoulte value
double Complex::abs(){
	return (sqrt(rel*rel+img*img));
}
//get the real part
double Complex::getRe(){
	return rel;
}
//return the imaginary part
double Complex::getIm(){
	return img;
}
//set the real part value
void Complex::setRe(double d){
	rel = d;
}
//set the imaginary part value
void Complex::setIm(double d){
	img = d;
}
//C==C
bool Complex::operator==(Complex C){
	return (rel==C.rel && img==C.img);
}
//C==d
bool Complex::operator==(double d){
	return (rel == d && img==0.0);
}
//C!=C
bool Complex::operator!=(Complex C){
	return (rel!=C.rel || img!=C.img);
}
//C!=d
bool Complex::operator!=(double d){
	return (rel!=d || img!=0.0);
}
//C=C
void Complex::operator=(Complex C){
	rel = C.rel;
	img = C.img;
}
//C=d
void Complex::operator=(double d){
	rel = d;
	img = 0.0;
}
//C+=C
void Complex::operator+=(Complex C){
	rel = rel+C.rel;
	img = img+C.img;
}
//C+=d
void Complex::operator+=(double d){
	rel = rel+d;
}
//C-=C
void Complex::operator-=(Complex C){
	rel = rel - C.rel;
	img = img -C.img;
}
//C-=d
void Complex::operator-=(double d){
	rel = rel-d;
}
//C*=C
void Complex::operator*=(Complex C){
	rel = rel*C.rel-img*C.img;
	img = rel*C.img+img*C.rel;
}
//C*=d
void Complex::operator*=(double d){
	rel = rel*d;
	img = img*d;
}
//C/=C
void Complex::operator/=(Complex C){
	rel = (rel*C.rel+img*C.img)/(C.rel*C.rel+C.img*C.img);
	img = (-1*rel*C.img+img*C.rel)/(C.rel*C.rel+C.img*C.img);
}
//C/=d
void Complex::operator/=(double d){
	rel = (rel*d)/d*d;
	img = (img*d)/d*d;
}
