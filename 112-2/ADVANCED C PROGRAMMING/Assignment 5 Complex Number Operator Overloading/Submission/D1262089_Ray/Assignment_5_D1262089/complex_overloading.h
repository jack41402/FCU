#ifndef COMPLEX_OVERLOADING_H
#define COMPLEX_OVERLOADING_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Complex {
private:
    double re;
    double im;

public:
    // Constructors
    Complex(const double r = 0.0, const double i = 0.0);
    Complex(const Complex &);
    
    // Getter and Setter methods
    double getRe() const;
    double getIm() const;
    void setRe(double);
    void setIm(double);

    // Unary minus operator
    Complex operator-() const;

    // Binary operators
    friend Complex operator+(const Complex &, const Complex &);
    friend Complex operator+(const double &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator-(const double &, const Complex &);
    friend Complex operator*(const Complex &, const Complex &);
    friend Complex operator*(const double &, const Complex &);
    friend Complex operator/(const Complex &, const Complex &);
    friend Complex operator/(const double &, const Complex &);

    // Comparison operators
    friend bool operator==(const Complex &, const Complex &);
    friend bool operator==(const double &, const Complex &);
    friend bool operator!=(const Complex &, const Complex &);
    friend bool operator!=(const double &, const Complex &);


    Complex& operator=(const Complex &);
    Complex& operator=(const double &);
    Complex& operator+=(const Complex &);
    Complex& operator+=(const double &);
    Complex& operator-=(const Complex &);
    Complex& operator-=(const double &);
    Complex& operator*=(const Complex &);
    Complex& operator*=(const double &);
    Complex& operator/=(const Complex &);
    Complex& operator/=(const double &);

    // Absolute value
    double cabs() const;

    // Stream operators
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);
};

#endif
