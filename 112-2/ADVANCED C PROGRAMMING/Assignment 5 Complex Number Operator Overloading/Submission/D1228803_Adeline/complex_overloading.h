// complex_overloading.h


#ifndef COMPLEX_OVERLOADING_H
#define COMPLEX_OVERLOADING_H

#include <iostream>


using namespace std; //Simplify access to standard library component

class Complex 
{
    public:
        double re, im;

        // Constructors
        Complex(double real = 0.0, double imag = 0.0); //Complex defalt constructor
        Complex(const Complex& other); //Copy constructor

        // Operator overloads
        Complex operator+(const Complex &) const; //Complex addition
        Complex operator-(const Complex &) const; //Complex subtraction
        Complex operator*(const Complex &) const; //Complex multiplicaiton
        Complex operator/(const Complex &) const; //Complex division
        Complex& operator=(const Complex &); //Assignment
        Complex& operator+=(const Complex &); //Assignment addition
        Complex& operator-=(const Complex &); //Assignment subtraction
        Complex& operator*=(const Complex &); //Assignment multiplication
        Complex& operator/=(const Complex &); //Assignment division
        bool operator==(const Complex &) const; //Equal to relation 
        bool operator!=(const Complex &) const; //Not equal to relation

        double abs() const; //Absolute value of complex number

    // Friend functions for I/O
    friend ostream &operator<<(ostream &os, const Complex &c); //Overload stream to output a complex number
    friend istream &operator>>(istream &is, Complex &c); //Overload stream to input a complex number
};

#endif

