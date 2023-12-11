#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define epsilon 0.000001 // Difference error.

// Print a term of the polynomial.
// degree: the degree of the polynomial; i: degree of the term, c: coefficient of the term.
void printTerm(int degree, int i, float c) {
     
  if (degree==i) { // The first term of the polynomia.
    if (c<0) printf("-"); // If c is negative, print a minus sign.
    if (c!=1) printf("%6.4f ", fabs(c)); // If c is not 1 print the coefficient; do not print 1.
  }
  else {
    if (c>0) printf(" + %6.4f ", fabs(c)); // Print a positive coefficient.
    else if (c<0) printf(" - %6.4f ", fabs(c)); // Printf a negative coefficient.
    }
  if (i>0 && c!=0) { // If not constant term and non-zero coefficient,
    printf("X"); // Print variable 'X'.
    if (i>1) printf("^%d", i); // If degree is higher than 1, print the degree.
  }
}

int main(void) {
  int n; // Degree of the polynomial.
  double a, b; // Interval (a, 0) and (b, 0).
  double coeff[11]; // Coefficients, maximum degree is 10.
  int T; // Number of the partitioned intervals.
  double interval; // Size of the partitioned interval.
  double point; // The middle point of each individual interval.
  double poly; // Value of evaluating the polynomial on point, P(point).
  double area; // Are of the covered area, Riemann sum of the current iteration.
  double last; // Riemann sum of the previous iteration.
  int i, j; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  do {
    printf("Enter the degree of polynomial P(x): ");
    scanf("%d", &n); // Input the degree of the polynomial.
  } while (n<0 || n>10);
  
  do {
    printf("Enter two real numbers a and b such that 0<b-a<=5: ");
    scanf("%lf %lf", &a, &b); // Input the interval bound.
  } while (a>=b || b-a>5);
  
  for (i=n; i>=0; i--) { // Randomly generate the coefficients.
    coeff[i] = (rand() % 2001) / 1000.0 - 1.0; // the value is between -1.0 and 1.0 (including).
  }
    
  printf("Polynomial P(x):\n"); // Output the polynomial.
  for (i=n; i>=0; i--) printTerm(n, i, coeff[i]); // Output a term.
  printf("\n\n");
  
  printf("Interval [a, b]: [%6.4lf, %6.4lf]\n", a, b); // Output interval [a, b].
  
  T=1; // Initial only one interval [a, b].
  area = -1; // Set initial area to -1.
  last = -2; // Set initial previous area to -2.
  // Continue when the difference error of two intration is greatier than epsilon.
  while (fabs(area-last)>epsilon) {
    interval = (b - a) / T; // Interval size.
    point = a + interval / 2; // Middle point of the first interval. 
    last = area; // The area of the previous iteration.
    area = 0; // Initial area to zero.
    for (i=0; i<T; i++) { // Compute bar area of all intervals.
      poly = 0; // Initial polynomial value to 0.
      for (j=0; j<=n; j++) poly += coeff[j] * pow(point, j); // Evaluate the polynomial area.
      area += fabs(poly) * interval; // Accumulate the area of Riemann sum.
      point += interval; // The middle point of the next interval.
    }
    // Output the number of intervals, interval size, and area of this iteration.
    printf("Number of intervals: %d, interval size: %8.6lf, area: %8.6lf\n", T, interval, area);
    T = T * 2; // Double the number of partitioned intervals.
  }
  
  printf("\nThe number of intervals: %d\n", T/2); // Output total number of intervals.
  // Output the final area.
  printf("Area of polynomial P(x) between (%6.4lf, 0.0) and (%6.4lf, 0.0): %8.6lf\n", a, b, area);
  
  return 0;
}
