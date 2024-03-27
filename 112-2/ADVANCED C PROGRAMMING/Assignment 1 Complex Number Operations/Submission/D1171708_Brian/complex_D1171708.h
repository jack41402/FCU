typedef struct {
  float re; // real part
  float im;  // imaginary part
} complex;

complex add(complex, complex); // complex addition.
//Complex addition: (a+bi)+(c+di) = (a+c)+(b d)i

complex minus(complex, complex); // complex subtraction.
// Complex subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i

complex time(complex, complex); // complex multiplication.
//Complex multiplication: (a+bi)×(c+di) = (a×c-b×d) + (a×d+b×c)i

complex divide(complex, complex); // complex division.
//Complex division: (a+bi)÷(c+di) = ((a×c+b×d)+(-a×d+b×c)i)÷(c^2+d^2)

float absComplex(complex); // Absolute value of a complex number.
// Complex absolute value: |a+bi| = (a^2+b^2)^(1/2)

complex r2c(float); // Convert a real number to a complex number

void printComplex(complex, complex); // Print a complex number.
