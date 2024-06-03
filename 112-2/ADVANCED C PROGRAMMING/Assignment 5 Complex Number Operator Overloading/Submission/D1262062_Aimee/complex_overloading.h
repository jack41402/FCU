#ifndef COMPLEX_OVERLOADING_H
#define COMPLEX_OVERLOADING_H

#include <iostream>
using namespace std;

class Complex {
private:
    double re;
    double im;
    
public:
    // Constructors
    Complex();
    Complex(double re, double im);

    // Get the real or imaginary part of a complex number
    double getRe() const;
    double getIm() const;
    // Set the real or imaginary part of a complex number
    void setRe(double re);
    void setIm(double im);
    // Unary operator
	Complex operator-() const;
    // Overloaded operators
    Complex operator+(const Complex) const;// complex + complex
    Complex operator+(const double) const;//complex + double
    friend Complex operator+(double, const Complex);// double + complex
    Complex operator-(const Complex) const;// complex - complex
    Complex operator-(const double) const;//complex - double
    friend Complex operator-(double, const Complex);// double - complex
    Complex operator*(const Complex) const;// complex * complex
    Complex operator*(const double) const;//complex * double
    friend Complex operator*(double, const Complex);// double * complex
    Complex operator/(const Complex) const;// complex / complex
    Complex operator/(const double) const;//complex / double
    friend Complex operator/(double, const Complex);// double / complex
    bool operator==(const Complex) const;// determine complex == complex
    bool operator==(const double) const;// determine complex == double
    friend bool operator==(double, const Complex);// determine double == complex
    bool operator!=(const Complex) const;// determine complex != complex
    bool operator!=(const double) const;// determine complex != double
    friend bool operator!=(double, const Complex);// determine double != complex

    // Assignment operators
    Complex& operator=(const Complex);// complex = complex
    Complex& operator=(const double);// complex = double
    Complex& operator+=(const Complex);// complex += complex
    Complex& operator+=(const double);// complex += double
    Complex& operator-=(const Complex);// complex -= complex
    Complex& operator-=(const double);// complex -= double
    Complex& operator*=(const Complex);// complex *= complex
    Complex& operator*=(const double);// complex *= double
    Complex& operator/=(const Complex);// complex /= complex
    Complex& operator/=(const double);// complex /= double

    // Friend functions for I/O stream operators
    friend ostream& operator<<(ostream& os, const Complex& complex);
    friend istream& operator>>(istream& is, Complex& complex);
};

#endif



