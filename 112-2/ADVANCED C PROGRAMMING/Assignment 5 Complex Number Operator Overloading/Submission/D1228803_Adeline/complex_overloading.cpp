//Complex_overloading

#include "complex_overloading.h"
#include <cmath>
#include <iomanip>

using namespace std; //Simplify access to standard library component

//Complex default constructor
Complex::Complex(double real, double imag)
{
  	re = real; //Parameter real the real part of the complex number
  	im = imag; //Parameter imaginary the imaginary part of the complex number
}

//Copy constructor
Complex::Complex(const Complex& other)
{
	//parameter other the complex number to copy
  	re = other.re;
  	im = other.im;
}

//Complex addition
Complex Complex::operator+(const Complex& other) const 
{
    return Complex(re + other.re, im + other.im); //Return the result of the addition operation
}

//Complex subtraction
Complex Complex::operator-(const Complex& other) const 
{
    return Complex(re - other.re, im - other.im); //Return the result of the subtraction operation
}

//Complex multiplication
Complex Complex::operator*(const Complex& other) const 
{
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);  //Return the result of the multiplication operation
}

//Complex division
Complex Complex::operator/(const Complex& other) const 
{
    double denominator = other.re * other.re + other.im * other.im;
     //Return the result of the division operation
    return Complex((re * other.re + im * other.im) / denominator, (im * other.re - re * other.im) / denominator);
}

//Overloaded assignment operator for Complex numbers.
Complex& Complex::operator=(const Complex& other) 
{
    re = other.re; //Assign the real part of 'other' to the real part of the current object
    im = other.im; //Assign the imaginary part of 'other' to the imaginary part of the current object
    return *this; //Return a reference to the current object.
}

// Overloaded compound addition operator for Complex numbers.
Complex& Complex::operator+=(const Complex& other) 
{
    re += other.re; //Add the real part of 'other' to the real part of the current object
    im += other.im; //Add the imaginary part of 'other' to the imaginary part of the current object
    return *this; //Return a reference to the current object.
}

// Overloaded compound subtraction operator for Complex numbers
Complex& Complex::operator-=(const Complex& other) 
{
    re -= other.re; //Subtract the real part of 'other' to the real part of the current object
    im -= other.im; //Subtract the imaginary part of 'other' to the imaginary part of the current object
    return *this;
}

//Overloaded compound multiplication operator for Complex numbers
Complex& Complex::operator*=(const Complex& other) 
{
    double temp_re = re;
    re = re * other.re - im * other.im; //Multiplication the real part of 'other' to the real part of the current object
    im = temp_re * other.im + im * other.re; //Multiplication the imaginary part of 'other' to the imaginary part of the current object
    return *this;
}

//Overloaded compound division operator for Complex numbers
Complex& Complex::operator/=(const Complex& other) 
{
    double denom = other.re * other.re + other.im * other.im;
    double temp_re = re;
    re = (re * other.re + im * other.im) / denom; //Division the real part of 'other' to the real part of the current object
    im = (im * other.re - temp_re * other.im) / denom; //Division the imaginary part of 'other' to the imaginary part of the current object
    return *this;
}

//Indicating whether the two Complex numbers are equal
bool Complex::operator==(const Complex& other) const 
{
    return re == other.re && im == other.im;  //Return true if both the real and imaginary parts are equal.
}

//Indicating whether the two Complex numbers are not equal
bool Complex::operator!=(const Complex& other) const 
{
    return !(*this == other);  //Return not true if both the real and imaginary parts are equal.
}

//Absolute value of complex number
double Complex::abs() const 
{
    return sqrt(re * re + im * im); //Return the result of the square root operation
}

//Overload stream to output a complex number
ostream& operator<<(ostream& os, const Complex& c) 
{
	//Fixed point format and 4 digits after the decimal point
    os << fixed << setprecision(4);
    if (c.im == 0) //Output based on real and imaginary part
	{
        os << c.re;
    } 
	else if (c.re == 0) 
	{
        os << c.im << "i";
    } 
	else 
	{
        os << c.re;
        if (c.im > 0) 
		{
            os << "+";
        }
        os << c.im << "i";
    }
    return os;
}

//Overload stream to input a complex number
istream& operator>>(istream& is, Complex& c) 
{
    is >> c.re >> c.im; //Input real and imaginary pary
    return is;
}

