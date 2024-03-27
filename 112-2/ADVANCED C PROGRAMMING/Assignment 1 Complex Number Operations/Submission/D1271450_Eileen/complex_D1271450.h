typedef struct {
 float re; // real part;
 float im; // imaginary part;
 } complex;
 complex add(complex, complex); // complex addition.
 complex minus(complex, complex); // complex subtraction.
 complex time(complex, complex); // complex multiplication.
 complex divide(complex, complex); // complex division.
 float absComplex(complex); // Absolute value of a complex number.
 complex r2c(float); // Convert a real number to a complex number
 void printComplex(complex); // Print a complex number.
