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
	sqrt=x*x;
};

double f2(double x) {
	sqrt=x*x;
}; 

double f3(double x) {
	-sqrt=x*x;
};

double f4(double x) {
	-sqrt=x*x;
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
   area=-1;
   last=-2;
   if(area-last)>epsilon{
   interval=s+point/ *f;
   
   }

}

int main(void) {
	double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
	double area; // Area of the quadrilateral.
	double size;
    int g,i,t,n,f,r,s,max_BCD_area,max_BAD_area;
    int intermax;
	// c. Enter four real numbers (double type) a, b, c and d, where c<0<a and d<0<b, to 
	//    represent points A(a, 0), B(0, b), C(c,0), and D(0, d).
	printf("Enter real number a for point A(a, 0), a>0: ");
	scanf("%lf", &a); // Input point A.
	printf("Enter real number b for point B(0, b), b>0: ");
	scanf("%lf", &b); // Input point B.
	printf("Enter real number c for point C(c, 0), c<0: ");
	scanf("%lf", &c); // Input point C.
	printf("Enter real number c for point D(0, d), d<0: ");
	scanf("%lf", &d); // Input point D.  
	printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);
	
	// ***** Complete the program of the following steps.
  right_Riemann_sum(r,s,  (*f)(double),  (*g)(double));
	// d. Compute the area of quadrilateral ABCD using right Riemann sum approach.
  printf("****Compute the area of triangle BCD.\n");
  for(i=0;i<r;++i){
  	printf("Numbers of intervals %d,  interval size: %8.6lf,  area: %9.6lf",g,size,area);
  	g+=g*2;
  	intermax=pow(g,2);
  	printf("\n");
  }
  printf("The number of intervals:  %d" ,intermax);
  printf("\n****Compute the area of triangle BAD.\n");
  for(i=0;i<s;++i){
  	printf("Numbers of intervals %d,  interval size: %8.6lf,  area: %9.6lf",g,size,area);
  	g+=g*2;
  	intermax=pow(g,2);
  	printf("\n");
  }
  printf(">>>>The number of intervals:  %d" ,intermax);
  printf("\n\n");
	// e. Print the area of triangle BCD, the area of triangle BAD, and the area of quadrilateral ABCD.
  printf(">>>> Area if triangle BCD: %9.6lf\n", max_BCD_area );
  printf(">>>> Area if triangle BAD: %9.6lf\n", max_BAD_area);
  n=max_BCD_area+max_BAD_area;
  printf(">>>> Area of the quadrilateral ABCD:  %9.6lf\n",n);
  printf(">>>> The result of 1/2|(a-c)(b-d)| is: %9.6lf\n",n );
  t=(1/2)fabs(a-c)(b-d);
  printf(">>>> The error is %8.6lf",t );
	// f. Verify the result with the area formula 1/2|(a-c)(b-d)|.
  if((1/2)fabs(a-c)(b-d)<0.000001){
  	printf("error");
  }
  	
  }
	return 0;
}