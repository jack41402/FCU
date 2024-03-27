typedef struct {
	float re;  // Real part of the complex number
	float im;  // Imaginary part of the complex number
} complex;

complex add(complex a, complex b){   
	complex sum;
	
	sum.re = a.re + b.re;  // Adding the real parts of a and b
	sum.im = a.im + b.im;  // Adding the imaginary parts of a and b
	return sum;  // Returning the sum of the two complex numbers
} 

complex minus(complex a, complex b){
	complex diff;
	diff.re = a.re - b.re;  // Subtracting the real part of b from the real part of a
	diff.im = a.im - b.im;  // Subtracting the imaginary part of b from the imaginary part of a
	return diff;  // Returning the difference of the two complex numbers
}

complex time(complex a, complex b){
	complex prod;
	prod.re = a.re * b.re - a.im * b.im;  // Multiplying real parts and subtracting the product of imaginary parts
	prod.im = a.re * b.im + a.im * b.re;  // Multiplying real part of a with imaginary part of b, then adding
	return prod;  // Returning the product of the two complex numbers
}

complex divide(complex a, complex b){
	complex quot;
	float divirsor = b.re * b.re + b.im * b.im;  // Calculating the divisor
	quot.re = (a.re * b.re + a.im * b.im) / divirsor;  // Multiplying the conjugate of b and a, then dividing by the divisor
	quot.im = (a.im * b.re - a.re * b.im) / divirsor;  // Multiplying the conjugate of b and a, then dividing by the divisor
	return quot;  // Returning the quotient of the two complex numbers
}

float absComplex(complex z){
	return sqrt(z.re * z.re + z.im * z.im);  // Calculating the magnitude of the complex number 
}

void printComplex(complex z){ 
 	if(z.re == 0) 
  		printf("%.4f i ", z.im);  // Printing the imaginary part if real part is zero
 	else if(z.im == 0) 
  		printf("%.4f ", z.re);  // Printing the real part if imaginary part is zero
 	else 
  		printf("%.4f%+.4f i ", z.re, z.im);  // Printing both parts if neither is zero
}

complex r2c(float a) {
    complex result;
    result.re = a;  // Setting the real part of the result to the input value
    result.im = 0.0;  // Setting the imaginary part of the result to zero
    return result;  // Returning the complex number
}



