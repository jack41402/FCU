#ifndef ASSGN5_D1166506_COMPLEX_H
#define ASSGN5_D1166506_COMPLEX_H
#include <iostream>

class Complex
{
    friend std::ostream &operator<< (std::ostream & , const Complex &) ;
    friend std::istream &operator>> (std::istream & , Complex &) ;
    friend Complex operator+ (const double & , const Complex &) ;
    friend Complex operator- (const double & , const Complex &) ;
    friend Complex operator* (const double & , const Complex &) ;
    friend Complex operator/ (const double & , const Complex &) ;
    friend bool operator== (const double & , const Complex &) ;
    friend bool operator!= (const double & , const Complex &) ;

    private :
        double real ;
        double imaginary ;

    public :
        Complex () ;
        Complex (const double & , const double &) ;
        Complex (const Complex &) ;
        ~Complex() ;
        double getRe () const ;
        double getIm () const ;
        void setRe (const double &) ;
        void setIm (const double &) ;
        Complex operator- () const ;
        Complex operator+ (const Complex &) const ;
        Complex operator+ (const double &) const ;
        Complex operator- (const Complex &) const ;
        Complex operator- (const double &) const ;
        Complex operator* (const Complex &) const ;
        Complex operator* (const double &) const ;
        Complex operator/ (const Complex &) const ;
        Complex operator/ (const double &) const ;
        bool operator== (const Complex &) const ;
        bool operator== (const double &) const ;
        bool operator!= (const Complex &) const ;
        bool operator!= (const double &) const ;
        Complex& operator= (const Complex &) ;
        Complex& operator= (const double &) ;
        Complex& operator+= (const Complex &) ;
        Complex& operator+= (const double &) ;
        Complex& operator-= (const Complex &) ;
        Complex& operator-= (const double &) ;
        Complex& operator*= (const Complex &) ;
        Complex& operator*= (const double &) ;
        Complex& operator/= (const Complex &) ;
        Complex& operator/= (const double &) ;
        Complex abs () const ;
} ;

#endif //ASSGN5_D1166506_COMPLEX_H