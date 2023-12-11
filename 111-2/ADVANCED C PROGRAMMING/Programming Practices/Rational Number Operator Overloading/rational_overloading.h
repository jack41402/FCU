using namespace std;

#ifndef rational
#define rational

class Rational {

  friend ostream &operator<<(ostream &, const Rational &); // Overload stream to output a rational number.
  friend istream &operator>>(istream &, Rational &); // Overload stream to input a rational number.
  friend Rational operator+(const int &, const Rational &); // Integer-Rational addition. 
  friend Rational operator-(const int &, const Rational &); // Integer-Rational subtraction. 
  friend Rational operator*(const int &, const Rational &); // Integer-Rational multiplication. 
  friend Rational operator/(const int &, const Rational &); // Integer-Rational division. 
  friend bool operator==(const int &, const Rational &); // Equal to relation for integer-rational numbers.
  friend bool operator!=(const int &, const Rational &); // Not equal to relation for integer-rational numbers.
  friend bool operator<(const int &, const Rational &); // Less than relation for integer-rational numbers.
  friend bool operator>(const int &, const Rational &); // Greater than to relation for integer-rational numbers.
  friend bool operator<=(const int &, const Rational &); // Less than or equal to relation for integer-rational numbers.
  friend bool operator>=(const int &, const Rational &); // Greater than or equal to relation for integer-rational numbers.
       
  public:
    Rational(const int = 0, const int = 1); // Rational default constructor.
    Rational(const Rational &); // Copy constructor.
    int getNume() const; // Get Numerator.
    int getDeno() const; // Get Denominator.
    void setRational(const int, const int); // Set new values to a rational object.
    Rational operator-() const; // Rational unary minus.
    Rational operator+(const Rational &) const; // Rational addition.
    Rational operator+(const int &) const; // Rational-integer addition.
    Rational operator-(const Rational &) const; // Rational subtraction.
    Rational operator-(const int &) const; // Rational-integer subtraction.
    Rational operator*(const Rational &) const; // Rational multiplication.
    Rational operator*(const int &) const; // Rational-integer multiplication.
    Rational operator/(const Rational &) const; // Rational division.
    Rational operator/(const int &) const; // Rational-integer division.
    bool operator==(const Rational &) const; // Equal to relation for rational numbers.
    bool operator==(const int &) const; // Equal to relation for rational-integer numbers.
    bool operator!=(const Rational &) const; // Not equal to relation for rational numbers.
    bool operator!=(const int &) const; // Not equal to relation for rational-integer numbers.
    bool operator<(const Rational &) const; // Less than relation for rational numbers.
    bool operator<(const int &) const; // Less than relation for rational-integer numbers.
    bool operator>(const Rational &) const; // Greater than relation for rational numbers.
    bool operator>(const int &) const; // Greater than relation for rational-integer numbers.
    bool operator<=(const Rational &) const; // Less than or equal to relation for rational numbers.
    bool operator<=(const int &) const; // Less than or equal to relation for rational-integer numbers.
    bool operator>=(const Rational &) const; // Greater than or equal to relation for rational numbers.
    bool operator>=(const int &) const; // Greater than or equal to relation for rational-integer numbers.
    Rational& operator=(const Rational &); // Assignment.
    Rational& operator=(const int &); // Assignment for integer expression.
    Rational& operator+=(const Rational &); // Assignment with addition.
    Rational& operator+=(const int &); // Assignment for integer expression with addition.
    Rational& operator-=(const Rational &); // Assignment with subtraction.
    Rational& operator-=(const int &); // Assignment for integer expression with subtraction.
    Rational& operator*=(const Rational &); // Assignment with multiplication.
    Rational& operator*=(const int &); // Assignment for integer expression with multiplication.
    Rational& operator/=(const Rational &); // Assignment with division.
    Rational& operator/=(const int &); // Assignment for integer expression with division.
    Rational rabs(void) const; // Absolute value of rational numbers.
    
  private:
    int nume; // numerator
    int deno;  // denominator
    
    int gcd(int, int); // GCD: greatest common divisor.
    void simplify(); // Simplify a rational number.
};

#endif
