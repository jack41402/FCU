 typedef struct {
    float re; // real number
    float im; // imaginary number
} complex;

complex add(complex, complex);
complex minus(complex, complex);
complex time(complex, complex);
complex divide(complex, complex);
float absComplex(complex);
complex r2c(float);

void printComplex(complex);
