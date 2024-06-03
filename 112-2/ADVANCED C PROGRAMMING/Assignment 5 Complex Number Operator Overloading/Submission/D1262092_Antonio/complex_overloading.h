#ifndef COMPLEX_OVERLOADING_H
#define COMPLEX_OVERLOADING_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor with default value 0.0+0.0i
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Copy constructor
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    // Get real part of a complex number
    double getRe() const { return real; }

    // Get imaginary part of a complex number
    double getIm() const { return imag; }

    // Set real part of a complex number
    void setRe(double r) { real = r; }

    // Set imaginary part of a complex number
    void setIm(double i) { imag = i; }

    // Overloaded operators
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    // Overloaded assignment operators
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    // Overloaded comparison operators
    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    // Overloaded I/O stream operators
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

    // Calculate absolute value
    double abs() const { return std::sqrt(real * real + imag * imag); }
};

#endif  // COMPLEX_OVERLOADING_H
