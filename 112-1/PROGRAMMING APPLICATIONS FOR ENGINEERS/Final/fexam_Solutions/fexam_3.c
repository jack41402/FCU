/*
  Giving four points A(a, 0), B(0, b), C(c,0), and D(0, d), where 
  c<0<a and d<0<b on the XY-plane, the area of quadrilateral
  (blue shaded region) is 1/2|(a-c)(b-d)|. The equations of lines AB, BC,
  CD, and DA are bx+ay=ab, bx+cy=bc, dx+cy=dc, and dx+ay=ad, respectively.
  Write a C program to perform the following steps:
  a. Enter four real numbers a, b, c and d, where c<0<a and d<0<b, to 
     represent points A(a, 0), B(0, b), C(c,0), and D(0, d).
  b. Compute the area of quadrilateral ABCD using left Riemann 
     sum approach.
  c. Verify the result with the area formula 1/2|(a-c)(b-d)|.
  (Hint: The equations of lines AB, BC, CD, and DA can be rewritten 
         to y=f1(x)=-b/a x+b, y=f2(x)=-b/c x+b, y=f3(x)=-d/c x+d, 
		 and y=f4(x)=-d/a x+d, respectively.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.

// Declare globe variables.
double a, b, c, d; // Points A(a, 0), B(0, b), C(c,0), and D(0, d).
int T; // Number of the partitioned intervals.

// Function of line AB, y=f1(x)=-b/a x+b.
double f1(double x) {
  return (-b / a) * x + b;
}
// Function of line BC, y=f2(x)=-b/c x+b.
double f2(double x) {
  return (-b / c) * x + b;
}
// Function of line CD, y=f3(x)=-d/c x+d.
double f3(double x) {
  return (-d / c) * x + d;
}
// Function of line DA, y=f4(x)=-d/a x+d.
double f4(double x) {
  return (-d / a) * x + d;
}

// r, s: Interval (r, 0) and (s 0).
// *f: the first function pointer. A funtional parameter.
// *g: the second function pointer. A functional parameter.
double right_Riemann_sum(double r, double s, double (*f)(double), double (*g)(double)) {
  double interval; // Size of the partitioned interval.
  double point; // The left-end point of each individual interval.
  double area; // Area of the covered region, left Riemann sum of the current iteration.
  double last; // Left Riemann sum of the previous iteration.
  int i; // Loop variable.
  
  T = 1; // Initial only one interval [r, s].
  area = -1; // Set initial area to -1. 
  last = -2; // Set initial previous area to -2.
  // Continue when the difference error of two intration is greatier than epsilon.
  while (fabs(area-last)>epsilon) { 
    interval = fabs(r - s) / T; // Interval size.
    point = r + interval; // right-end point of the first interval. 
    last = area; // The area of the previous iteration.
    area = 0; // Initial area to zero.
    for (i=0; i<T; i++) { // Compute bar area of all intervals.
      area += fabs((*f)(point) - (*g)(point)) * interval; // Accumulate the area of Riemann sum.
      point += interval; // The right-end point of the next interval.
    }
    // Output the number of intervals, interval size, and area of this iteration.
    printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", T, interval, area);
    T = T * 2; // Double the number of partitioned intervals.
  }
  
  return area;  // Return the resulting area.
}

int main(void) {
  double areaBCD, areaBAD; // Area of triangle BCD and triangle BAD.
  double area; // Area of the quadrilateral.
  
  printf("Enter real number a for point A(a, 0), a>0: ");
  scanf("%lf", &a); // Input point A.
  printf("Enter real number b for point B(0, b), b>0: ");
  scanf("%lf", &b); // Input point B.
  printf("Enter real number c for point C(c, 0), c<0: ");
  scanf("%lf", &c); // Input point C.
  printf("Enter real number c for point D(0, d), d<0: ");
  scanf("%lf", &d); // Input point D.  
  printf("\nPoints: A=(%6.4lf, 0), B=(0, %6.4lf), C=(%6.4lf, 0), D=(0, %6.4lf)\n\n", a, b, c, d);
  
  // Computer the area triangle BCD covered by line x=c, y-axis, line BC, and line CD.
  printf("**** Compute the area of triangle BCD.\n");
  areaBCD = right_Riemann_sum(c, 0, f2, f3);  
  printf("The number of intervals: %d\n\n", T/2); // Output total number of intervals.
  
  // Computer the area of triangle BAD covered by y-axis, line x=a, line AB, and line DA.
  printf("**** Compute the area of triangle BAD.\n");
  areaBAD = right_Riemann_sum(0, a, f1, f4);  
  printf("The number of intervals: %d\n\n", T/2); // Output total number of intervals.
  
  area = areaBCD + areaBAD; // Area of the quadrilateral.
  
  // Output the final area.
  printf(">>>> Area of triangle BCD: %8.6lf\n", areaBCD);
  printf(">>>> Area of triangle BAD: %8.6lf\n", areaBAD);
  printf(">>>> Area of the quadrilateral ABCD: %8.6lf\n", area);
  printf(">>>> The result of 1/2|(a-c)(b-d)| is: %8.6lf\n", 0.5*fabs((a-c)*(b-d)));
  printf(">>>> The error is: %8.6lf\n", fabs(area-0.5*fabs((a-c)*(b-d))));
  
  return 0;
}
