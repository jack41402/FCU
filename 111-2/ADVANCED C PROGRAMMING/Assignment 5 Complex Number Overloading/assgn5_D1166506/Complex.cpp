#include <iomanip>
#include "Complex.h"

Complex::Complex ()
{
    real = 0.0 ;
    imaginary = 0.0 ;
}

Complex::Complex (const double &a , const double &b)
{
    real = a ;
    imaginary = b ;
}

Complex::Complex (const Complex &complex)
{
    real = complex.real ;
    imaginary = complex.imaginary ;
}

Complex::~Complex ()
{
    return;
}

std::ostream& operator<< (std::ostream &output , const Complex &complex)
{
    output << std::fixed << std::setprecision(4) ;
    if (complex.real!=0.0 && complex.imaginary!=0.0)
    {
        output << complex.real << std::showpos << complex.imaginary << "i\n" ;
    }
    else if (complex.real!=0)
    {
        output << complex.real << '\n' ;
    }
    else if (complex.imaginary!=0)
    {
        output << complex.imaginary
    }
    else
    {
        output << 0 << '\n' ;
    }
    return output;
}

std::istream& operator>> (std::istream & , Complex &)
{
    
}

Complex operator+ (const double & , const Complex &)
{
    
}

Complex operator- (const double & , const Complex &)
{
    
}

Complex operator* (const double & , const Complex &)
{
    
}

Complex operator/ (const double & , const Complex &)
{
    
}

bool operator== (const double & , const Complex &)
{
    
}

bool operator!= (const double & , const Complex &)
{
    
}

double Complex::getRe () const
{
    return 0;
}

double Complex::getIm () const
{
    return 0;
}

void Complex::setRe (const double &)
{

}

void Complex::setIm (const double &)
{

}

Complex Complex::operator- () const
{
    
}

Complex Complex::operator+ (const Complex &) const
{
    
}

Complex Complex::operator+ (const double &) const
{
    
}

Complex Complex::operator- (const Complex &) const
{
    
}

Complex Complex::operator- (const double &) const
{
    
}

Complex Complex::operator* (const Complex &) const
{
    
}

Complex Complex::operator* (const double &) const
{
    
}

Complex Complex::operator/ (const Complex &) const
{
    
}

Complex Complex::operator/ (const double &) const
{
    
}

bool Complex::operator== (const Complex &) const
{
    return false;
}

bool Complex::operator== (const double &) const
{
    return false;
}

bool Complex::operator!= (const Complex &) const
{
    return false;
}

bool Complex::operator!= (const double &) const
{
    return false;
}

Complex& Complex::operator= (const Complex &)
{
    
}

Complex& Complex::operator= (const double &)
{
    
}

Complex& Complex::operator+= (const Complex &)
{
    
}

Complex& Complex::operator+= (const double &)
{
    
}

Complex& Complex::operator-= (const Complex &)
{
    
}

Complex& Complex::operator-= (const double &)
{
    
}

Complex& Complex::operator*= (const Complex &)
{
    
}

Complex& Complex::operator*= (const double &)
{
    
}

Complex& Complex::operator/= (const Complex &)
{
    
}

Complex& Complex::operator/= (const double &)
{
    
}

Complex Complex::abs () const
{
    
}