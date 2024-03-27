#include <stdio.h>
#include <math.h>
#include "complex_D1265315.h"


// Complex addition: (a+bi)+(c+di) = (a+c)+(b+d)i
complex add(complex x , complex y) {
  complex sum;
  
  sum.re = x.re + y.re;
  sum.im = y.im + x.im;
  return sum;
}

// Complex subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
complex minus(complex x , complex y) {
  complex diff;
  
  diff.re = x.re - y.re;
  diff.im = x.im - y.im;
  return diff;
}

// Complex multiplication: (a+bi)×(c+di) = (a×c-b×d) + (a×d+b×c)i
complex multiplie(complex x, complex y){
    complex prod;
    
    prod.re = x.re*y.re - x.im*y.im;
    prod.im = x.re*y.im + x.im*y.re;
    return prod;
}
// Complex division: (a+bi)÷(c+di) = ((a×c+b×d)+(-a×d+b×c)i)÷(c2+d2)
complex divide(complex x, complex y){
    complex quot;
    quot.re = (x.re*y.re+x.im*y.im) / (pow(y.re, 2) + pow(y.im, 2));
    quot.im = (-x.re*y.im+x.im*y.re) / (pow(y.re, 2) + pow(y.im, 2));
    return quot;
}

// Complex absolute value: |a+bi| = (a2+b2)1/2
float absComplex(complex x){
    float abst;
    abst = sqrt(pow(x.re, 2) + pow(x.im, 2));
    return abst;
}

// Convert a real number to a complex number
complex r2c(float x, float y){
    complex cmp;
        cmp.re = x;
        cmp.im = y;
    return cmp;
}

// Print a complex number.
void printComplex(complex x){
    if (x.im == 0){
        printf("%6.4f", x.re);
    }
    else{
        if(x.re == 0){
            printf("%6.4f i", x.im);
        }
        else{
            if (x.im > 0){
                printf("%6.4f+%6.4f i", x.re, x.im);
            }
            else{
                printf("%6.4f%6.4f i", x.re, x.im);
            }
        }
    }
}

