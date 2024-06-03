#include "complex_overloading.h"
Complex::Complex(double r , double i ) : re(r), im(i) {}
Complex::Complex(const Complex& r) : re(r.re), im(r.im) {}
double Complex::getRe() const { return re; }
double Complex::getIm() const { return im; }
void Complex::setComplex(double r, double i) {
    re = r;
    im = i;
}
Complex Complex::operator-() const {
    return Complex(-re, -im);
}
Complex Complex::operator+(const Complex& r) const {
    return Complex(re + r.re, im + r.im);
}
Complex Complex::operator+(const double &m) const {
    return Complex(re + m, im);
}
Complex operator+(const double& m, const Complex& r) {
    return Complex(m + r.re, r.im);
}
Complex Complex::operator-(const Complex& r) const {
    return Complex(re - r.re, im - r.im);
}
Complex Complex::operator-(const double &m) const {
    return Complex(re - m, im);
}
Complex operator-(const double &m, const Complex& r) {
    return Complex(m - r.re, -r.im);
}
Complex Complex::operator*(const Complex& r) const {
    return Complex(re * r.re - im * r.im, re * r.im + im * r.re);
}
Complex Complex::operator*(const double &m) const {
    return Complex(re * m, im * m);
}
Complex operator*(const double &m, const Complex& r) {
    return Complex(m * r.re, m * r.im);
}
Complex Complex::operator/(const Complex& r) const {
    double temp = r.re * r.re + r.im * r.im;
    return Complex((re * r.re + im * r.im) / temp, (-re * r.im + im * r.re) / temp);
}
Complex Complex::operator/(const double& m) const {
    return Complex(re / m, im / m);
}
Complex operator/(const double& m, const Complex& r) {
    double temp = r.re * r.re + r.im * r.im;
    return Complex((m * r.re) / temp, (-m * r.im) / temp);
}
bool Complex::operator==(const Complex& r) const {
    return re == r.re && im == r.im;
}
bool Complex::operator==(const double& m) const {
    return re == m && im == 0;
}
bool operator==(const double& m, const Complex& r) {
    return m == r.re && r.im == 0;
}
bool Complex::operator!=(const Complex& r) const {
    return !(*this == r);
}
bool Complex::operator!=(const double& m) const {
    return !(*this == m);
}
bool operator!=(double m, const Complex& r) {
    return !(m == r);
}
Complex& Complex::operator=(const Complex& r) {
    re = r.re;
    im = r.im;
    return *this;
}
Complex& Complex::operator=(const double& m) {
    re = m;
    im = 0;
    return *this;
}
Complex& Complex::operator+=(const Complex& r) {
    *this = *this + r;
    return *this;
}
Complex& Complex::operator+=(const double& m) {
    *this = *this + m;
    return *this;
}
Complex& Complex::operator-=(const Complex& r) {
    *this = *this - r;
    return *this;
}
Complex& Complex::operator-=(const double& m) {
    *this = *this - m;
    return *this;
}
Complex& Complex::operator*=(const Complex& r) {
    *this = *this * r;
    return *this;
}
Complex& Complex::operator*=(const double& m) {
    *this = *this * m;
    return *this;
}
Complex& Complex::operator/=(const Complex& r) {
    *this = *this / r;
    return *this;
}
Complex& Complex::operator/=(const double& m) {
    *this = *this / m;
    return *this;
}
double Complex::cabs() const {
    return sqrt(re * re + im * im);
}
ostream& operator<<(ostream& output, const Complex& r) {
    if (r.getIm() == 0.0) output << r.getRe();
    else if (r.getIm() > 0.0) {
        if (r.getRe() == 0.0) output << r.getIm() << "i";
        else output << r.getRe() << "+" << r.getIm() << "i";
    }
    else {
        if (r.getRe() == 0.0) output << r.getIm() << "i";
        else output << r.getRe() << r.getIm() << "i";
    }
    return output;
}

istream& operator>>(istream& input, Complex& r) {
   
    input >> r.re; // Input the real part.
    input.ignore(1); // Ignore space.
    input >> r.im; // Input the imaginary part.
    return input;
}
