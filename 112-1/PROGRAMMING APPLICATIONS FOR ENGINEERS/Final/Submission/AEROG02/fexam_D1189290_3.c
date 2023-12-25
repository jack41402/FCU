#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.000001 
double a, b, c, d; 
int T; 
double f1(double x){
	return(-b / a) * x + b;
}
double f2(double x){
	return(-b / c) * x + b;
} 
double f3(double x){
	return(-d / c) * x + d;
}
double f4(double x){
	return(-d / a) * x + d;
}
double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) {
	double interval; 
	double point; 
	double area; 
	double last; 
	int i; 
    T = 1;
    area = -1;
    last = -2;
    while(fabs(area - last) > epsilon){
    	interval = fabs(r - s) / T;
    	point = r + interval;
    	last = area;
    	area = 0;
    	for(i = 0 ; i < T ; i++){
    		area += fabs((*f)(point) - (*g)(point)) * interval;
    		point += interval;
		}
		printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", T, interval, area);
		T = T * 2;
	}
	return area;
}
int main(){
	double areaBCD, areaBAD;
	double area; 
	printf("Enter real number a for point A(a, 0), a>0: ");
	scanf("%lf", &a); 
	printf("Enter real number b for point B(0, b), b>0: ");
	scanf("%lf", &b);
	printf("Enter real number c for point C(c, 0), c<0: ");
	scanf("%lf", &c); 
	printf("Enter real number c for point D(0, d), d<0: ");
	scanf("%lf", &d); 
	printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);
	printf("**** Compute the area of traingle BCD.\n");
	areaBCD = right_Riemann_sum(c , 0, f2, f3);
	printf("The number of intervals: %d\n\n", T / 2);
	printf("**** Compute the area of traingle BAD.\n");
	areaBAD = right_Riemann_sum(0, a, f1, f4);
	printf("The number of intervals: %d\n\n", T / 2);
	area = areaBCD + areaBAD;
	printf(">>>> Area of traingle BCD: %8.6lf\n", areaBCD);
	printf(">>>> Area of triangle BAD: %8.6lf\n", areaBAD);
	printf(">>>> Area of the quadrilateral ABCD: %8.6lf\n", area);
	printf(">>>> The result of 1/2|(a-c)(b-d)| is: %8.6lf\n", 0.5 * fabs((a - c) * (b - d)));
	printf(">>>> The error is: %8.6lf", fabs(area - 0.5 * fabs((a - c) * (b - d))));
	return 0;
}
