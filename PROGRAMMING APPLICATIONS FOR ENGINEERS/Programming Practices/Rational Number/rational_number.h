typedef struct {
  int nume; // numerator
  int deno;  // denominator
} Rational;

// Rational number addition: a/b + c/d = (ad + bc) / bd.
Rational plus(Rational, Rational);

// Rational number subtraction: a/b - c/d = (ad - bc) / bd.
Rational minus(Rational, Rational);

// Rational number multiplication: a/b * c/d = ac/bd.
Rational time(Rational, Rational);

// Rational number division: a/b / c/d = ad/bc.
Rational divide(Rational, Rational);

// Absolute value of a rational number:  |a/b| = |a|/|b|.
Rational qabs(Rational);

// Convert a pair of integers to a rational number:  (p, q) => p/q.
Rational ii2r(int, int);

// Convert an integer to a rational number: (p) => p/1.
Rational i2r(int);

// Print a rational number.
void printr(Rational);
