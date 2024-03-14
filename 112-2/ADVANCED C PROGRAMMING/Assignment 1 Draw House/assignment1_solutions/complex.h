typedef struct {
	float re; // real part;
	float im; // imaginary part;
} complex;

complex add(complex, complex); // Complex addition.

complex minus(complex, complex); // Complex subtraction.

complex time(complex, complex); // Complex multiplication.

complex divide(complex, complex); // Complex division.

float absComplex(complex); // Absolute value of a complex number.

complex r2c(float); // Convert a real number to a complex number

void printComplex(complex); // Print a complex number.
