//Define a structure to represent complex numbers
typedef struct 
{
	float realpart; //real part of the complex number;
	float imaginarypart; //imaginary part of the complex number;
} complex;

//complex addition
complex add(complex, complex); 

//complex subtraction
complex subtract(complex, complex); 

//complex multiplication
complex multiply(complex, complex); 

//complex division
complex divide(complex, complex); 

//Absolute value of a complex number
float absoluteComplex(complex); 

//Convert a real number to a complex number
complex realpartTOcomplexpart(float); 

//Print a complex number 
void printComplex(complex);

//Verify the equation
int Verify(complex, complex, float, float, float);
