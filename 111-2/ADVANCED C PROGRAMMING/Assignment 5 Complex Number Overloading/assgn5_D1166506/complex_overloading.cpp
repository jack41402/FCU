#include <iomanip>
#include <cmath>
#include "complex_overloading.h"

// Default constructor
Complex::Complex ()
{
    real = 0.0 ;
    imaginary = 0.0 ;
}

// Assignment constructor
Complex::Complex (const double &a , const double &b)
{
    real = a ;
    imaginary = b ;
}

// Copy constructor
Complex::Complex (const Complex &complex)
{
    real = complex.real ;
    imaginary = complex.imaginary ;
}

// Destructor
Complex::~Complex ()
{
    return;
}

// ostream operator <<
std::ostream& operator<< (std::ostream &output , const Complex &complex)
{
    output << std::resetiosflags(std::ios::showpos) ;
    output << std::fixed << std::setprecision(4) ;
    if (complex.real!=0.0 && complex.imaginary!=0.0)
    {
        output << complex.real << std::showpos << complex.imaginary << 'i' ;
    }
    else if (complex.real!=0)
    {
        output << complex.real ;
    }
    else if (complex.imaginary!=0)
    {
        output << complex.imaginary ;
    }
    else
    {
        output << 0.0 ;
    }
    return output;
}

// istream operator >>
std::istream& operator>> (std::istream &input , Complex &complex)
{
    input >> complex.real ;
    input >> complex.imaginary ;
    input.ignore(1) ;
    return input;
}

// double + Complex
Complex operator+ (const double &num , const Complex &complex)
{
    Complex temp ;
    temp.real = num + complex.real ;
    temp.imaginary = complex.imaginary ;
    return temp;
}

// double - Complex
Complex operator- (const double &num , const Complex &complex)
{
    Complex temp ;
    temp.real = num - complex.real ;
    temp.imaginary = -complex.imaginary ;
    return temp;
}

// double * Complex
Complex operator* (const double &num , const Complex &complex)
{
    Complex temp ;
    temp.real = num * complex.real ;
    temp.imaginary = num * complex.imaginary ;
    return temp;
}

// double / Complex
Complex operator/ (const double &num , const Complex &complex)
{
    Complex temp ;
    temp.real = (num * complex.real)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    temp.imaginary = (-num * complex.imaginary)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    return temp;
}

// double == Complex
bool operator== (const double &num , const Complex &complex)
{
    return (num==complex.real && complex.imaginary==0);
}

// double != Complex
bool operator!= (const double &num , const Complex &complex)
{
    return (num!=complex.real || complex.imaginary!=0);
}

// Get real number of Complex
double Complex::getRe () const
{
    return this->real;
}

// Get imaginary number of Complex
double Complex::getIm () const
{
    return this->imaginary;
}

// Set real number of Complex
void Complex::setRe (const double &num)
{
    this->real = num ;
}

// Set imaginary number of Complex
void Complex::setIm (const double &num)
{
    this->imaginary = num ;
}

// -Complex
Complex Complex::operator- () const
{
    Complex temp ;
    temp.real = -this->real ;
    temp.imaginary = this->imaginary ;
    return temp;
}

// Complex + Complex
Complex Complex::operator+ (const Complex &complex) const
{
    Complex temp ;
    temp.real = this->real + complex.real ;
    temp.imaginary = this->imaginary + complex.imaginary ;
    return temp;
}

// Complex + double
Complex Complex::operator+ (const double &num) const
{
    Complex temp ;
    temp.real = this->real + num ;
    temp.imaginary = this->imaginary ;
    return temp;
}

// Complex - Complex
Complex Complex::operator- (const Complex &complex) const
{
    Complex temp ;
    temp.real = this->real - complex.real ;
    temp.imaginary = this->imaginary - complex.imaginary ;
    return temp;
}

// Complex - double
Complex Complex::operator- (const double &num) const
{
    Complex temp ;
    temp.real = this->real - num ;
    temp.imaginary = this->imaginary ;
    return temp;
}

// Complex * Complex
Complex Complex::operator* (const Complex &complex) const
{
    Complex temp ;
    temp.real = this->real * complex.real - this->imaginary * complex.imaginary ;
    temp.imaginary = this->real * complex.imaginary + this->imaginary * complex.real ;
    return temp;
}

// Complex * double
Complex Complex::operator* (const double &num) const
{
    Complex temp ;
    temp.real = this->real * num ;
    temp.imaginary = this->imaginary * num ;
    return temp;
}

// Complex / Complex
Complex Complex::operator/ (const Complex &complex) const
{
    Complex temp ;
    temp.real = (this->real * complex.real + this->imaginary * complex.imaginary)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    temp.imaginary = (-this->real * complex.imaginary + this->imaginary * complex.real)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    return temp;
}

// Complex / double
Complex Complex::operator/ (const double &num) const
{
    Complex temp ;
    temp.real = (this->real * num)/(num*num) ;
    temp.imaginary = (this->imaginary * num)/(num*num) ;
    return temp;
}

// Complex == Complex
bool Complex::operator== (const Complex &complex) const
{
    return (this->real==complex.real && this->imaginary==complex.imaginary);
}

// Complex == double
bool Complex::operator== (const double &num) const
{
    return (this->real==num && this->imaginary==0);
}

// Complex != Complex
bool Complex::operator!= (const Complex &complex) const
{
    return (this->real!=complex.real || this->imaginary!=complex.imaginary);
}

// Complex != double
bool Complex::operator!= (const double &num) const
{
    return (this->real!=num || this->imaginary!=num);
}

// Complex = Complex
Complex& Complex::operator= (const Complex &complex)
{
    real = complex.real ;
    imaginary = complex.imaginary ;
    return *this;
}

// Complex = double
Complex& Complex::operator= (const double &num)
{
    real = num ;
    imaginary = 0 ;
    return *this;
}

// Complex += Complex
Complex& Complex::operator+= (const Complex &complex)
{
    real = this->real + complex.real ;
    imaginary = this->imaginary + complex.imaginary ;
    return *this;
}

// Complex += double
Complex& Complex::operator+= (const double &num)
{
    real = this->real + num ;
    return *this;
}

// Complex -= Complex
Complex& Complex::operator-= (const Complex &complex)
{
    real = this->real - complex.real ;
    imaginary = this->imaginary - complex.imaginary ;
    return *this;
}

// Complex -= double
Complex& Complex::operator-= (const double &num)
{
    real = this->real - num ;
    return *this;
}

// Complex *= Complex
Complex& Complex::operator*= (const Complex &complex)
{
    real = this->real * complex.real - this->imaginary * complex.imaginary ;
    imaginary = this->real * complex.imaginary + this->imaginary * complex.real ;
    return *this;
}

// Complex *= double
Complex& Complex::operator*= (const double &num)
{
    real = this->real * num ;
    imaginary = this->imaginary * num ;
    return *this;
}

// Complex /= Complex
Complex& Complex::operator/= (const Complex &complex)
{
    real = (this->real * complex.real + this->imaginary * complex.imaginary)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    imaginary = (-this->real * complex.imaginary + this->imaginary * complex.real)/(complex.real*complex.real + complex.imaginary*complex.imaginary) ;
    return *this;
}

// Complex /= double
Complex& Complex::operator/= (const double &num)
{
    real = (this->real * num)/(num*num) ;
    imaginary = (this->imaginary * num)/(num*num) ;
    return *this;
}

double Complex::cabs () const
{
    return sqrt(real*real + imaginary*imaginary) ;
}