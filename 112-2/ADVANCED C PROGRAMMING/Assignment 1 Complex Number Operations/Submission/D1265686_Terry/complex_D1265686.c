//
//  complex_D1265686.c
//  quadratic_equation_verifier
//
//  Created by ¦ó¬f¾± on 2024/2/28.
//

#include "complex_D1265686.h"
#include <stdio.h>
#include <math.h>

//Add complex numbers
complex add(complex x, complex y) {
    complex sum;
    sum.re = x.re + y.re;
    sum.im = x.im + y.im;
    return sum;
}

//Subtract complex numbers
complex minus(complex x, complex y) {
    complex diff;
    diff.re = x.re - y.re;
    diff.im = x.im - y.im;
    return diff;
}

//Multiply complex numbers
complex ttime(complex x, complex y) {
    complex prod;
    prod.re = x.re * y.re - x.im * y.im;
    prod.im = x.re * y.im + x.im * y.re;
    return prod;
}

//divide complex numbers
complex divide(complex x, complex y){
    complex quot;
    quot.re = (x.re * y.re - x.im * y.im) / (y.re * y.re + y.im * y.im);
    quot.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
    return quot;
}

// Absolute value of a complex number
float absComplex(complex z) {
    return sqrt(z.re * z.re + z.im * z.im);
}


//Convert real number to imaginary number
complex r2c(float real) {
    complex result;
    result.re = real;
    result.im = 0.0;  // Set imaginary number to 0
    return result;
}

//Output in plural format
void printComplex (complex a) {
    if (a.re != 0) 
    {
        printf("%.4f",a.re);
    }
    if (a.im != 0)
    {
        if(a.re == 0)
        {
            if(a.im > 0)
            {
                printf("%.4f i",a.im);
            }
            else if(a.im < 0)
            {
                printf("%+.4f i",a.im);
            }
        }
        
        if(a.re != 0)
        {
            printf("%+.4f i",a.im);
        }
        
    }
    if (a.re == 0 && a.im == 0)
    {
        printf("0");
    }
}

