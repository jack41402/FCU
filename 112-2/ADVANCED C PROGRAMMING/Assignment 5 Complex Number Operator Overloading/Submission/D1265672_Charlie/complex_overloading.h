#ifndef complex_overloading_h
#define complex_overloading_h
using namespace std;


class Complex{
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);
    friend Complex operator+(const double &, const Complex &);
    friend Complex operator-(const double &, const Complex &);
    friend Complex operator*(const double &, const Complex &);
    friend Complex operator/(const double &, const Complex &);
    friend bool operator==(const double &, const Complex &);
    friend bool operator!=(const double &, const Complex &);
    
    public:
    Complex(const double =0.0, const double =0.0);// Complex default constructor.
    Complex(const Complex &);// Copy constructor.
    double getIm() const;
    double getRe() const;
    void setRe(double);
    void setIm(double);
    Complex operator-() const;
    Complex operator+(const Complex &) const;
    Complex operator+(const double &) const;
    Complex operator-(const Complex &) const;
    Complex operator-(const double &) const;
    Complex operator*(const Complex &) const;
    Complex operator*(const double &) const;
    Complex operator/(const Complex &) const;
    Complex operator/(const double &) const;
    bool operator==(const Complex &) const;
    bool operator==(const double &) const;
    bool operator!=(const Complex &) const;
    bool operator!=(const double &) const;
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
    double cabs(void) const;
    
    private:
    double re;
    double im;
    
};

#endif