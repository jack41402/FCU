#include <stdio.h>
#include <math.h>
#include "rational_number.h"

// GCD: greatest common divisor
int gcd(int m, int n) {
  m = abs(m);
  n = abs(n);
  if (m % n == 0) return n;
  else return gcd(n, m % n);
}

// Rational number simplification.
void simplify(Rational *r) {
  int g;

  if (r->deno==0) {r->nume = 0; r->deno = 1;}
  else if (r->deno<0) {r->nume = -r->nume; r->deno = -r->deno;}
  g = gcd(r->nume, r->deno); // GCD of numerator and denominator.
  r->nume = r->nume / g;
  r->deno = r->deno / g;  
}

// Rational number addition: a/b + c/d = (ad + bc) / bd.
Rational plus(Rational x , Rational y) {
  Rational sum;
  int g;
  
  sum.nume = x.nume * y.deno + y.nume * x.deno;
  sum.deno = x.deno * y.deno;
  simplify(&sum);
  return sum;
}

// Rational number subtraction: a/b - c/d = (ad - bc) / bd.
Rational minus(Rational x , Rational y) {
  Rational diff;
  int g;
  
  diff.nume = x.nume * y.deno - y.nume * x.deno;
  diff.deno = x.deno * y.deno;
  simplify(&diff);
  return diff;
}

// Rational number multiplication: a/b * c/d = ac/bd.
Rational time(Rational x, Rational y) {
  Rational prod;
  int g;
  
  prod.nume = x.nume * y.nume ;
  prod.deno = x.deno * y.deno;
  simplify(&prod);
  return prod;
}

// Rational number division: a/b / c/d = ad/bc.
Rational divide(Rational x, Rational y) {
  Rational quot;
  int g;
  
  if (y.nume!=0) { 
    quot.nume = x.nume * y.deno ;
    quot.deno = x.deno * y.nume; }
  else {
    quot.nume = 0;
    quot.deno = 1; } 
  simplify(&quot);
  return quot;
}

// Absolute value of a rational number:  |a/b| = |a|/|b|.
Rational qabs(Rational r) {
  Rational s;
  s.nume = abs(r.nume);
  s.deno = abs(r.deno);
  return s;
}

// Convert a pair of integers to a rational number:  (p, q) => p/q.
Rational ii2r(int n, int d) {
  Rational r;
  
  r.nume = n;
  r.deno = d;
  simplify(&r);
  return r;
}

// Convert an integer to a rational number: (p) => p/1.
Rational i2r(int n) {
  Rational r;
  
  r.nume = n;
  r.deno = 1;
  return r;
}

// Print a rational number.
void printr(Rational r) {

  printf("%d/%d", r.nume, r.deno);
}
