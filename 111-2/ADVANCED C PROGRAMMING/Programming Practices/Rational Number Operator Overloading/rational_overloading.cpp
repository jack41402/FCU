#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "rational_overloading.h"

using namespace std;

// Overload stream to output a ratioanl number.
ostream& operator<<(ostream &output, const Rational &r) {
	if (r.getDeno()==1) output << r.getNume();
  else output << r.getNume() << "/" << r.getDeno();
  return output;
}

// Overload stream to input a ratioanl number.
istream &operator>>(istream &input, Rational &r) {
  input >> r.nume;
  input.ignore(1);
  input >> r.deno;
  r.simplify();
  return input; 
}

// Rational default constructor.
Rational::Rational(const int m, const int n) {
  if (n==0) { // In case the denominator is 0.
    nume = 0;
    deno = 1;
  }
  else { // Simplify numerator and denominator.
    nume = m;
    deno = n;
  	this->simplify();
  }
}

// Copy constructor.
Rational::Rational(const Rational &r){
  nume = r.nume;
  deno = r.deno;
}

// Get Numerator.
int Rational::getNume() const {return this->nume;}

// Get Denominator.
int Rational::getDeno() const {return this->deno;}

// Set new values to a rational object.
void Rational::setRational(const int m, const int n) {
  this->nume = m;
  this->deno = n;
  this->simplify();
}

// Rational unary minus.
Rational Rational::operator-() const {
	Rational nega;
	
	nega.nume = -nume;
	nega.deno = deno;
	return nega;
}

// Rational addition.
Rational Rational::operator+(const Rational &r) const {
	Rational sum;
	
	sum.nume = nume * r.deno + r.nume * deno;
	sum.deno = deno * r.deno;
	sum.simplify();
	return sum;
}

// Rational-integer addition.
Rational Rational::operator+(const int &m) const {
	Rational sum;
	
	sum.nume = nume + m * deno;
	sum.deno = deno;
	sum.simplify();
	return sum;
} 

// Integer-Rational addition.
Rational operator+(const int &m, const Rational &r) {
	Rational sum;
	
	sum.nume = m * r.deno + r.nume;
	sum.deno = r.deno;
	sum.simplify();
	return sum;
}

// Rational subtraction.
Rational Rational::operator-(const Rational &r) const {
	Rational diff;
	
	diff.nume = nume * r.deno - r.nume * deno;
	diff.deno = deno * r.deno;
	diff.simplify();
	return diff;
}

// Rational-integer subtraction.
Rational Rational::operator-(const int &m) const {
	Rational diff;
	
	diff.nume = nume - m * deno;
	diff.deno = deno;
	diff.simplify();
	return diff;
}

// Integer-Rational subtraction.
Rational operator-(const int &m, const Rational &r) {
	Rational diff;
	
	diff.nume = m * r.deno - r.nume;
	diff.deno = r.deno;
	diff.simplify();
	return diff;
}

// Rational multiplication.
Rational Rational::operator*(const Rational &r) const {
	Rational prod;
	
	prod.nume = nume * r.nume;
	prod.deno = deno * r.deno;
	prod.simplify();
	return prod;
} 

// Rational-integer multiplication.
Rational Rational::operator*(const int &m) const {
	Rational prod;
	
	prod.nume = nume * m;
	prod.deno = deno;
	prod.simplify();
	return prod;
}

// Integer-Rational multiplication.
Rational operator*(const int &m, const Rational &r) {
	Rational prod;
	
	prod.nume = m * r.nume;
	prod.deno = r.deno;
	prod.simplify();
	return prod;
}

// Rational division.
Rational Rational::operator/(const Rational &r) const {
	Rational quot;
	
	quot.nume = nume * r.deno;
	quot.deno = deno * r.nume;
	quot.simplify();
	return quot;
} 

// Rational-integer division.
Rational Rational::operator/(const int &m) const {
	Rational quot;
	
	quot.nume = nume;
	quot.deno = deno * m;
	quot.simplify();
	return quot;
}

// Integer-Rational division.
Rational operator/(const int &m, const Rational &r) {
	Rational quot;
	
	quot.nume = m * r.deno;
	quot.deno = r.nume;
	quot.simplify();
	return quot;
}

// Equal to relation for rational numbers.
bool Rational::operator==(const Rational &r) const {
	return nume==r.nume && deno==r.deno;	
} 

// Equal to relation for rational-integer numbers. 
bool Rational::operator==(const int &m) const {
	return nume==m && deno==1;	
}

// Equal to relation for integer-rational numbers. 
bool operator==(const int &m, const Rational &r) {
	return m==r.nume && r.deno==1;	
} 

// Not equal to relation for rational numbers.
bool Rational::operator!=(const Rational &r) const {
	return !(*this==r);
}

// Not equal to relation for rational-integer numbers.
bool Rational::operator!=(const int &m) const {
	return !(*this==m);
}

// Not equal to relation for integer-rational numbers. 
bool operator!=(const int &m, const Rational &r) {
	return !(m==r);	
}

// Less than relation for rational numbers.
bool Rational::operator<(const Rational &r) const {
	return nume*r.deno < deno*r.nume; 
} 

// Less than relation for rational-integer numbers. 
bool Rational::operator<(const int &m) const {
	return nume < deno*m; 
}

// Less than relation for integer-rational numbers. 
bool operator<(const int &m, const Rational &r) {
	return m*r.deno < r.nume;	
}

// Greater than relation for rational numbers.
bool Rational::operator>(const Rational &r) const {
	return nume*r.deno > deno*r.nume; 
} 

// Greater than relation for rational-integer numbers.   
bool Rational::operator>(const int &m) const {
	return nume > deno*m; 
}

// Greater than relation for integer-rational numbers. 
bool operator>(const int &m, const Rational &r) {
	return m*r.deno > r.nume;	
}

// Less than or equal to relation for rational numbers.
bool Rational::operator<=(const Rational &r) const {
	return nume*r.deno <= deno*r.nume; 
}

// Less than or equal to relation for rational-integer numbers.
bool Rational::operator<=(const int &m) const {
	return nume <= deno*m;
}

// Less than or equal to relation for integer-rational numbers. 
bool operator<=(const int &m, const Rational &r) {
	return m*r.deno <= r.nume;	
}

// Greater than or equal to relation for rational numbers.
bool Rational::operator>=(const Rational &r) const {
	return nume*r.deno >= deno*r.nume; 
}  

// Greater than or equal to relation for rational-integer numbers.
bool Rational::operator>=(const int &m) const {
	return nume >= deno*m;
}

// Greater than or equal to relation for integer-rational numbers. 
bool operator>=(const int &m, const Rational &r) {
	return m*r.deno >= r.nume;	
}

// Assignment.
Rational& Rational::operator=(const Rational &r) {
	nume = r.nume;
	deno = r.deno;
	return *this;	
}

// Assignment for integer expression.
Rational& Rational::operator=(const int &m) {
	nume = m;
	deno = 1;
	return *this;	
} 

// Assignment with addition.
Rational& Rational::operator+=(const Rational &r) {
	*this = *this + r;
	return *this;	
}

// Assignment for integer expression with addition.
Rational& Rational::operator+=(const int &m) {
	*this = *this + m;
	return *this;	
}

// Assignment with substraction.
Rational& Rational::operator-=(const Rational &r) {
	*this = *this - r;
	return *this;	
}

// Assignment for integer expression with substraction.
Rational& Rational::operator-=(const int &m) {
	*this = *this - m;
	return *this;	
} 

// Assignment with multiplication.
Rational& Rational::operator*=(const Rational &r) {
	*this = *this * r;
	return *this;	
} 

// Assignment for integer expression with multiplication.
Rational& Rational::operator*=(const int &m) {
	*this = *this * m;
	return *this;	
}

// Assighment with division.
Rational& Rational::operator/=(const Rational &r) {
	*this = *this / r;
	return *this;	
} 

// Assignment for integer expression with division.
Rational& Rational::operator/=(const int &m) {
	*this = *this / m;
	return *this;	
}

// Absolute value of rational numbers.
Rational Rational::rabs(void) const {
	Rational abs;
	 
	if (nume<0) abs.nume = -nume;
	else abs.nume = nume;
	abs.deno = deno;
	return abs;	
}

// Euclidean algorithm of greatest common divisor (GCD).
int Rational::gcd(int m, int n) {
  if (m % n == 0) return n;
  else return gcd(n, m % n);
}

// Simplify a rational number.
void Rational::simplify() {
  if (nume*deno<0) { // Make the minus sign at the numerator.
    nume = -abs(nume);
    deno = abs(deno);
  }
  // Make numerator and denominator be relatively prime. 
  int g = gcd(abs(nume), deno);
  nume = nume / g;
  deno = deno / g;
}
