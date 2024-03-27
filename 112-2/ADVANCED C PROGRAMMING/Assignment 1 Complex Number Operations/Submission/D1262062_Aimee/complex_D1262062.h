typedef struct{
	float re;
	float im;
} complex;

complex add(complex, complex);
complex minus(complex, complex);
complex time(complex, complex);
complex divide(complex, complex);
float absComplex(complex);
complex r2c(float);
void printComplex(complex);
