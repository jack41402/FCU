#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include"complex_overloading.h"
using namespace std;

Complex::Complex(double R, double I){//Default constructor
	r=R;
	i=I;
}

Complex::Complex(const Complex& c){//Copy constructor
	r=c.r;
	i=c.i;
}

Complex Complex::operator +(const double& d){//Overloading "+" operator for Complex + double
	Complex temp(r+d, i);
	return temp;
}

Complex Complex::operator +(const Complex& c){//Overloading "+" operator for Complex + Complex
	Complex temp(r+c.r, i+c.i);
	return temp;
}

Complex Complex::operator -(const double& d){//Overloading "-" operator for Complex - double
	Complex temp(r-d, i);
	return temp;
}


Complex Complex::operator -(const Complex& c){//Overloading "-" operator for Complex - Complex
	Complex temp(r-c.r, i-c.i);
	return temp;
}

Complex Complex::operator *(const double& d){//Overloading "*" operator for Complex * double
	Complex temp(r*d, i*d);
	return temp;
}

Complex Complex::operator *(const Complex& c){//Overloading "*" operator for Complex * complex
	Complex temp(r*c.r-i*c.i, r*c.i+i*c.r);
	return temp;
}

Complex Complex::operator /(const double& d){//Overloading "/" operator for Complex / double
	Complex temp(r/d, i/d);
	return temp;
}

Complex Complex::operator /(const Complex& c){//Overloading "/" operator for Complex / Complex
	Complex temp((r*c.r+i*c.i)/(c.r*c.r+c.i*c.i), (i*c.r-r*c.i)/(c.r*c.r+c.i*c.i));
	return temp;
}

bool Complex::operator ==(const double& d){//Overloading "==" operator for Complex == double
	return (r==d)&&(i==0.0);
}

bool Complex::operator ==(const Complex& c){//Overloading "==" operator for Complex == Complex
	return (r==c.r)&&(i==c.i);
}

bool Complex::operator !=(const double& d){//Overloading "!=" operator for Complex != double
	return (r!=d)||(i!=0.0);
}

bool Complex::operator !=(const Complex& c){//Overloading "!=" operator for Complex != Complex
	return (r!=c.r)||(i!=c.i);
}

Complex& Complex::operator =(const double& d){//Overloading "=" operator for Complex = double
	r=d;
	i=0.0;
	return *this;
}

Complex& Complex::operator =(const Complex& c){//Overloading "=" operator for Complex = Complex
	r=c.r;
	i=c.i;
	return *this;
}

Complex& Complex::operator +=(const double& d){//Overloading "+=" operator for Complex += double
	r+=d;
	return *this;
}

Complex& Complex::operator +=(const Complex& c){//Overloading "+=" operator for Complex += Complex
	r+=c.r;
	i+=c.i;
	return *this; 
}

Complex& Complex::operator -=(const double& d){//Overloading "-=" operator for Complex -= double
	r-=d;
	return *this;
}

Complex& Complex::operator -=(const Complex& c){//Overloading "-=" operator for Complex -= Complex
	r-=c.r;
	i-=c.i;
	return *this;
}

Complex& Complex::operator *=(const double& d){//Overloading "*=" operator for Complex *= double
	r*=d;
	i*=d;
	return *this;
}

Complex& Complex::operator *=(const Complex& c){//Overloading "*=" operator for Complex *= Complex
	r=r*c.r-i*c.i;
	i=r*c.i+i*c.r;
	return *this;
}

Complex& Complex::operator /=(const double& d){//Overloading "/=" operator for Complex /= double
	r/=d;
	i/=d;
	return *this;
}

Complex& Complex::operator /=(const Complex& c){//Overloading "/=" operator for Complex /= Complex
	r=(r*c.r+i*c.i)/(c.r*c.r+c.i*c.i);
	i=(i*c.r-r*c.i)/(c.r*c.r+c.i*c.i);
	return *this;
}

ostream& operator <<(ostream& os , const Complex& c){//Overloading "<<" operator for Complex
	if(c.r!=0) os<< fixed << setprecision(4)<<c.r;
	if(c.i>0&&c.r!=0) os<< fixed << setprecision(4)<<'+'<<c.i<<'i';//If imaginary part > 0
	else if(c.i!=0) os<< fixed << setprecision(4)<<c.i<<'i';//If imaginary part < 0 or real part = 0
	return os;
}

istream& operator >>(istream& is, const Complex& c){//Overloading ">>" operator for Complex
	is>>c.r>>c.i;
	return is;
}

Complex operator +(const double& d, const Complex& c){//Overloading "+" operator for double + Complex
	Complex temp(d+c.r, c.i);
	return temp;
}

Complex operator -(const double& d, const Complex& c){//Overloading "-" operator for double - Complex
	Complex temp(d-c.r, c.i);
	return temp;
}

Complex operator *(const double& d, const Complex& c){//Overloading "*" operator for double * Complex
	Complex temp(d*c.r, d*c.i);
	return temp;
}
	
Complex operator /(const double& d, const Complex& c){//Overloading "/" operator for double / Complex
	Complex temp((d*c.r)/(c.r*c.r+c.i*c.i), (-d*c.i)/(c.r*c.r+c.i*c.i));
	return temp;
}

bool operator ==(const double& d, const Complex& c){//Overloading "==" operator for double == Complex
	return (d==c.r)&&(c.i==0.0);
}
	
bool operator !=(const double& d, const Complex& c){//Overloading "!=" operator for double != Complex
	return (d!=c.r)||(c.i!=0.0);
}

double Complex::getRe(){//Get the real part of a Complex number
	return r;
}
double Complex::getIm(){//Get the imaginary part of a Complex number
	return i;
}
void Complex::setRe(const double& d){//Set the real part of a Complex number
	r=d;
}
void Complex::setIm(const double& d){//Set the imaginary part of a Complex number
	i=d;
}
double Complex::cabs(){//Calculate the absolute value of a Complex number
	return sqrt(r*r+i*i);
}
