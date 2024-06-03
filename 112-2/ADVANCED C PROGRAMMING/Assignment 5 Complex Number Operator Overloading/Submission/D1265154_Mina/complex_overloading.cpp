#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "complex_overloading.h"
// Friend function for output stream
ostream &operator<<(ostream &output, const Complex &c){
	cout.unsetf(ios::showpos);// Avoid showing the positive sign for positive imaginary part
	if(c.Im == 0) output << c.Re ;// If imaginary part is 0, output only real part
	else 
	{// If imaginary part is positive, format output accordingly
		if(c.Im > 0) output << c.Re << "+" << c.Im << "i";
		else output << c.Re << c.Im << "i";// If imaginary part is negative
	}
	return output;
}
// Friend function for input stream
istream &operator>>(istream &intput, Complex &c)
{
	intput >> c.Re;
  	intput.ignore(1);// Ignore the '+' character
  	intput >> c.Im;
  	return intput;
}
// Overloading addition operator for double and Complex
Complex operator+(const double &d, const Complex &c)
{
	Complex sum;
	sum.Re = c.Re + d;
	sum.Im = c.Im; 
	return sum;
}
// Overloading subtraction operator for double and Complex
Complex operator-(const double &d, const Complex &c)
{
	Complex diff;
	diff.Re = c.Re - d;
	diff.Im = c.Im; 
	return diff;
}
// Overloading multiplication operator for double and Complex
Complex operator*(const double &d, const Complex &c) 
{
	Complex prod;
	prod.Re = c.Re * d;
	prod.Im = c.Im * d;
	return prod;
}
// Overloading division operator for double and Complex
Complex operator/(const double &d, const Complex &c)
{
	Complex quot;
	quot.Re = (c.Re * d) / (d * d);
	quot.Im = (c.Im * d) / (d * d);
	return quot;
}
// Overloading equality operator for double and Complex
bool operator==(const double &d, const Complex &c)
{
	if(c.Im != 0) return false;
	else return (d==c.Re);
}
// Overloading inequality operator for double and Complex
bool operator!=(const double &d, const Complex &c)
{
	if(c.Im != 0) return true;
	else return !(d==c.Re);
}
// Overloading addition operator for Complex and Complex
Complex Complex::operator+(const Complex &c) const
{
	Complex sum;
	sum.Re = this->Re + c.Re;
	sum.Im = this->Im + c.Im; 
	return sum;
}
// Overloading addition operator for Complex and double
Complex Complex::operator+(const double &d) const
{
	Complex sum;
	sum.Re = this->Re + d;
	sum.Im = this->Im; 
	return sum;
}
// Overloading subtraction operator for Complex and Complex
Complex Complex::operator-(const Complex &c) const
{
	Complex diff;
	diff.Re = this->Re - c.Re;
	diff.Im = this->Im - c.Im; 
	return diff;
}
// Overloading subtraction operator for Complex and double
Complex Complex::operator-(const double &d) const
{
	Complex diff;
	diff.Re = this->Re - d;
	diff.Im = this->Im; 
	return diff;
}
// Overloading multiplication operator for Complex and Complex
Complex Complex::operator*(const Complex &c) const
{
	Complex prod;
	prod.Re = this->Re * c.Re - this->Im * c.Im;
	prod.Im = this->Re * c.Im + this->Im * c.Re;
	return prod;
}
// Overloading multiplication operator for Complex and double
Complex Complex::operator*(const double &d) const
{
	Complex prod;
	prod.Re = this->Re * d;
	prod.Im = this->Im * d;
	return prod;
}
// Overloading division operator for Complex and Complex
Complex Complex::operator/(const Complex &c) const
{
	Complex quot;
	quot.Re = (this->Re * c.Re + this->Im * c.Im) / (c.Re * c.Re + c.Im * c.Im);
	quot.Im = (-Re * c.Im + this->Im * c.Re) / (c.Re * c.Re + c.Im * c.Im);
	return quot;
}
// Overloading division operator for Complex and double
Complex Complex::operator/(const double &d) const
{
	Complex quot;
	quot.Re = (this->Re * d) / (d * d);
	quot.Im = (this->Im * d) / (d * d);
	return quot;
} 
// Overloading equality operator for Complex and Complex
bool Complex::operator==(const Complex &c) const
{
	if(this->Re != c.Re || this->Im != c.Im) return false;
	else return true;
}
// Overloading equality operator for Complex and double
bool Complex::operator==(const double &d) const
{
	if(this->Im != 0) return false;
	else return (d==Re);
} 
// Overloading inequality operator for Complex and Complex
bool Complex::operator!=(const Complex &c) const
{
	if(this->Re != c.Re || this->Im != c.Im) return true;
	else return false;
} 
// Overloading inequality operator for Complex and double
bool Complex::operator!=(const double &d) const
{
	if(this->Im != 0) return true;
	else return !(d==Re);
}
// Overloading compound addition assignment operator for Complex
Complex& Complex::operator+=(const Complex &c)
{
	this->Re += c.Re;
	this->Im += c.Im; 
	return *this;
}
// Overloading compound addition assignment operator for double
Complex& Complex::operator+=(const double &d)
{
	this->Re += d; 
	return *this;
}
// Overloaded compound assignment operator-= for subtraction of a Complex number
Complex& Complex::operator-=(const Complex &c)
{
	this->Re -= c.Re;
	this->Im -= c.Im; 
	return *this;
}
// Overloaded compound assignment operator-= for subtraction of a double from a Complex number
Complex& Complex::operator-=(const double &d)
{
	this->Re -= d; 
	return *this;
}
// Overloaded compound assignment operator*= for multiplication by a Complex number
Complex& Complex::operator*=(const Complex &c)
{
	this->Re = this->Re * c.Re - this->Im * c.Im;
	this->Im = this->Re * c.Im + this->Im * c.Re;
	return *this;
}
// Overloaded compound assignment operator*= for multiplication by a double
Complex& Complex::operator*=(const double &d)
{
	this->Re *=  d;
	this->Im *=  d;
	return *this;
}

// Overloading compound division assignment operator for Complex numbers
Complex &Complex::operator/=(const Complex &c)
{
    // Using the formula for division of complex numbers
    this->Re = (this->Re * c.Re + this->Im * c.Im) / (c.Re * c.Re + c.Im * c.Im);
    this->Im = (-this->Re * c.Im + this->Im * c.Re) / (c.Re * c.Re + c.Im * c.Im);
    return *this;
}

// Overloading compound division assignment operator for a Complex number and a double
Complex &Complex::operator/=(const double &d)
{
    // Dividing real and imaginary parts separately
    Re = (this->Re * d) / (d * d);
    Im = (this->Im * d) / (d * d);
    return *this;
}

// Default constructor
Complex::Complex()
{
    this->Re = 0.0;
    this->Im = 0.0;
}

// Copy constructor
Complex::Complex(const Complex &c)
{
    this->Re = c.Re;
    this->Im = c.Im;
}

// Setter for imaginary part
void Complex::setIm(double i)
{
    Im = i;
}

// Setter for real part
void Complex::setRe(double r)
{
    Re = r;
}

// Getter for imaginary part
double Complex::getIm() const
{
    return Im;
}

// Getter for real part
double Complex::getRe() const
{
    return Re;
}

// Method to calculate the absolute value of a complex number
double Complex::abs(void) const
{
    return sqrt(this->Re * this->Re + this->Im * this->Im);
}

