// complex_overloading.cpp
#include "complex_overloading.h"

Complex::Complex(const double r, const double i) : re(r), im(i) {}

Complex::Complex(const Complex &c) : re(c.re), im(c.im) {}

double Complex::getRe() const { return re; }

double Complex::getIm() const { return im; }

void Complex::setRe(double r) { re = r; }

void Complex::setIm(double i) { im = i; }

double Complex::cabs() const { return sqrt(re * re + im * im); }

Complex Complex::operator-() const { return Complex(-re, -im); }

Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator+(const double &n, const Complex &c) {
    return Complex(c.re + n, c.im);
}

Complex operator-(const Complex &c1, const Complex &c2) {
    return Complex(c1.re - c2.re, c1.im - c2.im);
}

Complex operator-(const double &n, const Complex &c) {
    return Complex(n - c.re, -c.im);
}

Complex operator*(const Complex &c1, const Complex &c2) {
    return Complex(c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re);
}

Complex operator*(const double &n, const Complex &c) {
    return Complex(n * c.re, n * c.im);
}

Complex operator/(const Complex &c1, const Complex &c2) {
    double denom = c2.re * c2.re + c2.im * c2.im;
    double realPart = (c1.re * c2.re + c1.im * c2.im) / denom;
    double imagPart = (c1.im * c2.re - c1.re * c2.im) / denom;
    return Complex(realPart, imagPart);
}

Complex operator/(const double &n, const Complex &c) {
    double denom = c.re * c.re + c.im * c.im;
    double realPart = (n * c.re) / denom;
    double imagPart = (-n * c.im) / denom;
    return Complex(realPart, imagPart);
}

bool operator==(const Complex &c1, const Complex &c2) {
    return c1.re == c2.re && c1.im == c2.im;
}

bool operator==(const double &n, const Complex &c) {
    return c.re == n && c.im == 0;
}

bool operator!=(const Complex &c1, const Complex &c2) {
    return !(c1 == c2);
}

bool operator!=(const double &n, const Complex &c) {
    return !(c == n);
}


Complex& Complex::operator=(const Complex &c) {
    re = c.re;
    im = c.im;
    return *this;
}

Complex& Complex::operator=(const double &n) {
    re = n;
    im = 0;
    return *this;
}

Complex& Complex::operator+=(const Complex &c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex& Complex::operator+=(const double &n) {
    re += n;
    return *this;
}

Complex& Complex::operator-=(const Complex &c) {
    re -= c.re;
    im -= c.im;
    return *this;
}

Complex& Complex::operator-=(const double &n) {
    re -= n;
    return *this;
}

Complex& Complex::operator*=(const Complex &c) {
    double tempRe = re * c.re - im * c.im;
    im = re * c.im + im * c.re;
    re = tempRe;
    return *this;
}

Complex& Complex::operator*=(const double &n) {
    re *= n;
    im *= n;
    return *this;
}

Complex& Complex::operator/=(const Complex &c) {
    double denom = c.re * c.re + c.im * c.im;
    double tempRe = (re * c.re + im * c.im) / denom;
    im = (im * c.re - re * c.im) / denom;
    re = tempRe;
    return *this;
}

Complex& Complex::operator/=(const double &n) {
    re /= n;
    im /= n;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << std::fixed << std::setprecision(4);
    if (c.im == 0)
        out << c.re;
    else if (c.re == 0)
        out << c.im << "i";
    else {
        if (c.im < 0)
            out << c.re << c.im << "i";
        else
            out << c.re << "+" << c.im << "i";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Complex &c) {
    in >> c.re >> c.im;
    return in;
}
