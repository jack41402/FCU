#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex {
private:
    double re;//real part
    double im;//imaginary part

public:
    Complex(double r = 0, double i = 0);//default constructor
    Complex(const Complex &c);//copy constructor

    double getRe() const;//get real part
    double getIm() const;//get imaginary part
    void setRe(double r);//set real part
    void setIm(double i);//set imaginary part

    Complex operator-() const;//unary minus
    Complex operator+(const Complex &c) const;//complex addition
    Complex operator+(double r) const;//complex integer addition
    friend Complex operator+(double r, const Complex &c);//integer complex addition

    Complex operator-(const Complex &c) const;//complex subtraction
    Complex operator-(double r) const;//complex-integer subtraction
    friend Complex operator-(double r, const Complex &c);//integer-complex subtraction

    Complex operator*(const Complex &c) const;//complex multiplication
    Complex operator*(double r) const;//complex-integer multiplication
    friend Complex operator*(double r, const Complex &c);//integer-complex multiplication

    Complex operator/(const Complex &c) const;//complex division
    Complex operator/(double r) const;//complex-integer division
    friend Complex operator/(double r, const Complex &c);//integer-complex division

    bool operator==(const Complex &c) const;//equal to relation for complex numbers
    bool operator==(double r) const;//equal to relation for complex-integer numbers
    friend bool operator==(double r, const Complex &c);//equal to relation for integer-complex numbers

    bool operator!=(const Complex &c) const;//not equal to relation for complex numbers
    bool operator!=(double r) const;//not equal to relation for complex-integer numbers
    friend bool operator!=(double r, const Complex &c);//not equal to relation for integer-complex numbers

    Complex& operator=(const Complex &c);//assignment
    Complex& operator=(double r);//assignment for integer expression

    Complex& operator+=(const Complex &c);//assignment with addition
    Complex& operator+=(double r);//assignment for integer expression with addition

    Complex& operator-=(const Complex &c);//assignment with subtraction
    Complex& operator-=(double r);//assignment for integer expression with subtraction

    Complex& operator*=(const Complex &c);//assignment with multiplication
    Complex& operator*=(double r);//assignment for integer expression with multiplication

    Complex& operator/=(const Complex &c);//assignment with division
    Complex& operator/=(double r);//assignment for integer expression with division

    double magnitude() const;//magnitude of complex numbers
    Complex conjugate() const;//conjugate of complex numbers

    friend std::ostream& operator<<(std::ostream &output, const Complex &c);//overload stream to output a complex number
    friend std::istream& operator>>(std::istream &input, Complex &c);//overload stream to input a complex number
};

#endif

