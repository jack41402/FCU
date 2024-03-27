typedef struct {
    float re; // real part;
    float im; // imaginary part;
} complex;

complex add(complex, complex);
complex minus(complex, complex);
complex multiply(complex, complex);
complex divide(complex, complex);
float absComplex(complex);
complex r2c(float);
void printComplex(complex);


