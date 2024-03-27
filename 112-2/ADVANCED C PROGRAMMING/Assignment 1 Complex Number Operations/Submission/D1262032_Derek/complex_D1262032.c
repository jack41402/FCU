#include <stdio.h>
#include "complex_D1262032.h"
#include <math.h>

complex r2c(float x){// Convert a real number to a complex number
    complex c;
    c.re=x;
    c.im=0;
    return c;
};

complex add(complex x, complex y){
    complex add;
    add.re=x.re+y.re;
    add.im=x.im+y.im;
    return add;
};

complex minus(complex x, complex y){
    complex diff;
    diff.re=x.re-y.re;
    diff.im=x.im-y.im;
    return diff;
};

complex product(complex x, complex y){
    complex pro;
    pro.re=x.re*y.re-x.im*y.im;
    pro.im=x.re*y.im+x.im*y.re;
    return pro;
};

complex divide(complex x, complex y){
    complex quot;
    quot.re=(x.re*y.re+x.im*y.im)/(y.im*y.im+y.re*y.re);
    quot.im=(x.im*y.re-x.re*y.im)/(y.im*y.im+y.re*y.re);
    return quot;
};

float absComplex(complex x){// Absolute value of a complex number.
    float abs;
    abs=pow((x.re*x.re+x.im*x.im), 0.5);
    return abs;
};

void printComplex(complex x){// Print a complex number.
    if(x.re==0&&x.im==0) printf(" 0");
    else if(x.re==0) printf(" %.4f i ", x.im);
    else if(x.im==0) printf(" %.4f ", x.re);
    else if(x.im>0) printf(" %.4f+%.4f i ", x.re, x.im);
    else printf(" %.4f%.4f i ", x.re, x.im);
};
