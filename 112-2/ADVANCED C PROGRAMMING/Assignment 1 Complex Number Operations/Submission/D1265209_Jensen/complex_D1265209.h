typedef struct{
	float re; //real part
	float im; //imagenary part
}complex;

// complex addition.
complex add(complex, complex); 

// complex subtraction.
complex minus(complex, complex); 

// complex multiplication.
complex times(complex, complex); 

// complex division.
complex divide(complex, complex); 

// Absolute value of a complex number.
float absComplex(complex); 

// Convert a real number to a complex number
complex r2c(float); 

// Print a complex number.
void printComplex(complex); 


