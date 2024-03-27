#include "complex_D1175125.h"
#include <math.h>

complex add(complex a, complex b){
    complex c;
    c.re=a.re+b.re;
    c.im=a.im+b.im;
    return c;
}
complex minus(complex a, complex b){
    complex c;
    c.re=a.re-b.re;
    c.im=a.im-b.im;
    return c;
}
complex Time(complex a, complex b){
    complex c;
    c.re=a.re*b.re-a.im*b.im;
    c.im=a.re*b.im+a.im*b.re;
    return c;
}
complex divide(complex a, complex b){
    complex c;
    c.re=(a.re*b.re+a.im*b.im/(a.im*a.im+b.im*b.im));
    c.im=(-a.re*b.im+b.re*a.im)/(a.im*a.im+b.im*b.im);
    return c;
}
float absComplex(complex a){
    return sqrt(a.re*a.re+a.im*a.im);
}
complex r2c(float a){
    complex b;
    b.re=a;
    b.im=0;
    return b;
}
void printComplex(complex a) {
    if (a.re != 0) {
        printf("%.4f", a.re);
    }

    if (a.im != 0) {
        if (a.re != 0&&a.im>0) {
            printf(" + ");
            printf("%.4f i", a.im);
        }else if(a.re != 0&&a.im<0){
            printf(" - ");
            printf("%.4f i", -a.im);
        }
    }
    if (a.re == 0 && a.im == 0) {
        printf("0");
    }
}
