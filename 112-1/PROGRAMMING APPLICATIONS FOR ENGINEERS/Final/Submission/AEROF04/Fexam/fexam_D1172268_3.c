#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.

// Declare globe variables.
double a, b, c, d; // Points A(a, 0), B(0, b), C(c,0), and D(0, d).
int T; // Number of the partitioned intervals.

// ***** Complete the implementation of functions in Step a and Step b.  

// a. Define and implement four functions double f1(double x), double f2(double x), 
//    double f3(double x), and double f4(double x) for lines AB, BC, CD, and DA.

double f1(double x) {
	double f1;
	f1 = -b / a * x + b;
	return f1;
};

double f2(double x) {
	double f2;
	f2 = -c / b * x + c;
	return f2;
}; 

double f3(double x) {
	double f3
	f3 = -d / c * x + d;
	return f3;
};

double f4(double x) {
	double f4;
	f4 = -d / a * x + d;
};

// b. Define and implement function 
//      double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) 
//    to compute the area covered by two functional parameters f and g between interval (r, s) 
//    along the X axis.

double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) {
	double interval; // Size of the partitioned interval.
	double point; // The left-end point of each individual interval.
	double area; // Area of the covered region, left Riemann sum of the current iteration.
	double last; // Left Riemann sum of the previous iteration.
	int i; // Loop variable.
	area = -1;
	last = -2;
   	if(fabs(s - r) > epsilon){
   		if((last - area) > 0) {
   			
		   }
	}
}

int main(void) {
	double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
	double area; // Area of the quadrilateral.
    
	// c. Enter four real numbers (double type) a, b, c and d, where c<0<a and d<0<b, to 
	//    represent points A(a, 0), B(0, b), C(c,0), and D(0, d).
	printf("Enter real number a for point A(a, 0), a>0: ");
	scanf("%lf", &a); // Input point A.
	printf("Enter real number b for point B(0, b), b>0: ");
	scanf("%lf", &b); // Input point B.
	printf("Enter real number c for point C(c, 0), c<0: ");
	scanf("%lf", &c); // Input point C.
	printf("Enter real number d for point D(0, d), d<0: ");
	scanf("%lf", &d); // Input point D.  
	printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);
	
	// ***** Complete the program of the following steps.
  
	// d. Compute the area of quadrilateral ABCD using right Riemann sum approach.
  	printf("**** Compute the area of triangle BCD.\n");
  	for(i = 0; ){
  		right_Riemann_sum(c, a)
  		printf("Number of intervals: %lf, interval size: %lf, area: %lf");
	  }
  	
  	printf("\n**** Compute the area of triangle BAD.\n");
  	printf("Number of intervals: %lf, interval size: %lf, area: %lf");
  	
	// e. Print the area of triangle BCD, the area of triangle BAD, and the area of quadrilateral ABCD.
  	printf("\n>>>> Area of triangle BCD: ");
  	printf("\n>>>> Area of triangle BAD: ");
  	printf("\n>>>> Area of quadrilateral ABCD: ");
  	printf("\n>>>> The reasult of 1/2|(a-c)(b-d)| is: ");
  	printf("\n>>>> The error is: ");
	// f. Verify the result with the area formula 1/2|(a-c)(b-d)|.
  
	return 0;
}
