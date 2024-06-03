#pragma once
#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

#ifndef complex
#define complex

class Complex {

    friend ostream& operator<<(ostream&, const Complex&); // Overload stream to output a complex number.
    friend istream& operator>>(istream&, Complex&); // Overload stream to input a complex number.
    friend Complex operator+(const double&, const Complex&); // Double-Complex addition. 
    friend Complex operator-(const double&, const Complex&); // Double-Complex subtraction. 
    friend Complex operator*(const double&, const Complex&); // Double-Complex multiplication. 
    friend Complex operator/(const double&, const Complex&); // Double-Complex division. 
    friend bool operator==(const double&, const Complex&); // Equal to relation for double-complex numbers.
    friend bool operator!=(const double&, const Complex&); // Not equal to relation for double-complex numbers.

public:
    Complex(const double = 0.0, const double = 0.0); // Complex default constructor.
    Complex(const Complex&); // Copy constructor.
    double getRe() const; // Get real part.
    double getIm() const; // Get imaginary part.
    void setComplex(const double, const double); // Set new values to a complex object.
    Complex operator-() const; // Complex unary minus.
    Complex operator+(const Complex&) const; // Complex addition.
    Complex operator+(const double&) const; // Complex-double addition.
    Complex operator-(const Complex&) const; // Complex subtraction.
    Complex operator-(const double&) const; // Complex-double subtraction.
    Complex operator*(const Complex&) const; // Complex multiplication.
    Complex operator*(const double&) const; // Complex-double multiplication.
    Complex operator/(const Complex&) const; // Complex division.
    Complex operator/(const double&) const; // Complex-double division.
    bool operator==(const Complex&) const; // Equal to relation for complex numbers.
    bool operator==(const double&) const; // Equal to relation for complex-double numbers.
    bool operator!=(const Complex&) const; // Not equal to relation for complex numbers.
    bool operator!=(const double&) const; // Not equal to relation for complex-double numbers.
    Complex& operator=(const Complex&); // Assignment.
    Complex& operator=(const double&); // Assignment for double expression.
    Complex& operator+=(const Complex&); // Assignment with addition.
    Complex& operator+=(const double&); // Assignment for double expression with addition.
    Complex& operator-=(const Complex&); // Assignment with substraction. 
    Complex& operator-=(const double&); // Assignment for double expression with substraction.
    Complex& operator*=(const Complex&); // Assignment with multiplication.
    Complex& operator*=(const double&); // Assignment for double expression with multiplication.
    Complex& operator/=(const Complex&); // Assighment with division. 
    Complex& operator/=(const double&); // Assighment for double expression with division.
    double cabs(void) const; // Absolute value of complex numbers.

private:
    double re; // real part
    double im;  // imaginary part
};

#endif
