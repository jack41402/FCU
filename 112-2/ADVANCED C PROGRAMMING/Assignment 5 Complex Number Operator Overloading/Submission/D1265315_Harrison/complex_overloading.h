using namespace std;

#ifndef complex
#define complex

class Complex {

  friend ostream &operator<<(ostream &, const Complex &);
  friend istream &operator>>(istream &, Complex &);
  friend Complex operator+(const double &, const Complex &);
  friend Complex operator-(const double &, const Complex &);
  friend Complex operator*(const double &, const Complex &);
  friend Complex operator/(const double &, const Complex &);
  friend bool operator==(const double &, const Complex &);
  friend bool operator!=(const double &, const Complex &);
       
  public:
    Complex(const double = 0.0, const double = 0.0);
    Complex(const Complex &);
    double getRe() const;
    double getIm() const;
    void setComplex(const double, const double);
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
