#include "complex_overloading.h"

Complex Complex::operator+(const Complex& c) const {
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex& c) const {
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex& c) const {
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator/(const Complex& c) const {
    double denominator = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denominator,
                   (imag * c.real - real * c.imag) / denominator);
}

Complex& Complex::operator+=(const Complex& c) {
    real += c.real;
    imag += c.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    real -= c.real;
    imag -= c.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    double tempReal = real * c.real - imag * c.imag;
    imag = real * c.imag + imag * c.real;
    real = tempReal;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    double tempReal = (real * c.real + imag * c.imag) / denominator;
    imag = (imag * c.real - real * c.imag) / denominator;
    real = tempReal;
    return *this;
}

bool Complex::operator==(const Complex& c) const {
    return std::abs(real - c.real) < 1e-6 && std::abs(imag - c.imag) < 1e-6;
}

bool Complex::operator!=(const Complex& c) const {
    return !(*this == c);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}
