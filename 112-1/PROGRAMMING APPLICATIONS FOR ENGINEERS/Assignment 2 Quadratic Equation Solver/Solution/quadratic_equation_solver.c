/* The program reads three coefficients a, b, and c of equation
   a*x*x+b*x+c=0. If b*b-4ac is greater than or equal to zeor,
   the real roots of the equation is computed and printed;
   otherwise, it outputs a message of no real roots.
*/

#include <stdio.h>
#include <math.h>

// Pretty printing of the quadratic equation. 
void print_equation(int a, int b, int c) {
	// Print coefficient a.
	if (a==1) printf("X**2"); // otherwise, a is 1, omit the coefficient.
	else if (a==-1) printf("-X**2"); // If a is -1 print the "-" sign only.
	else printf("%dX**2", a); // If a is nor 1 neither -1, print the coefficient.
    
    if (b>0) // For positive b, 
	  if (b==1) printf("+X"); // If b is 1, print the "+" sign only.
	  else printf("+%dX", b); // If b is not 1, print b with "+" sign.
    else if (b<0) // For negative b,
      if (b==-1) printf("-X"); // If b is -1, print the "-" sign only.
      else printf("%dX", b); // if b is not 1, print b only because it has a "-" sign.
    // If b is 0, omit the entire one-degree term, i.e., do not print any thing.
      
    if (c>0) printf("+%d", c); // If c is positive, print c with a "+" sign.
    else if (c<0) printf("%d", c); // If c is negative, print c only.
    // If c is 0, omit the entire constant term.
    
    printf("=0"); // Print the right-hand-side of the equation.
}

int main(void) {
  int a, b, c; // Coefficeints.
  int b_square_minus_4_a_c; // b^2-4*a*c.
  float root1, root2; // Real roots.
  float root_real, root_imaginary; // Real part and imaginary part of complex roots.
 
  printf("Solving roots of equation a*X^2+b*X+c = 0.\n\n"); // Strating message.
  do {
    printf("Please enter three integer coefficients a, b, and c: "); // Request to input coefficients.
    scanf("%d %d %d", &a, &b, &c); // Input a, b, and c.
	if (a==0) printf("The coefficient of X^2 cannot be zero.\n\n"); // Not a quadratic equation.
  } while (a==0); 
  b_square_minus_4_a_c = b * b - 4 * a * c; // Compute b^2-4*a*c.
  
  if (b_square_minus_4_a_c>0) { // Two real roots.
    root1 = (-b + sqrt(b_square_minus_4_a_c)) / (2.0 * a); // The frist root.
    root2 = (-b - sqrt(b_square_minus_4_a_c)) / (2.0 * a); // The second root.
    printf("\nThe real roots of equation "); // Print the real root message.
    print_equation(a, b, c); // Print the equation.
    if (root1==0.0) root1 = 0.0; // Make sure no -0.0000 is printed.
    if (root2==0.0) root2 = 0.0; // Make sure no -0.0000 is printed.
    printf(" are %6.4f and %6.4f.\n", root1, root2); // Print the real roots.
  }
  else if (b_square_minus_4_a_c==0) { // Multiple real root.
    root1 = -b / (2.0 * a); // The multiple real root.
    printf("\nThe multiple real root of equation "); // Print the real root message.
    print_equation(a, b, c); // Print the equation.
    if (root1==0.0) printf(" is 0.0000.\n"); // Print the zero multiple root.
    else printf(" is %6.4f.\n", root1); // Print the multiple real root.
  }  
  else { // Two complex roots.
  	root_real = -b / (2.0 * a); // The real part.
  	root_imaginary = sqrt(-b_square_minus_4_a_c) / (2.0 * fabs(a)); // The imagenary part.
    printf("\nThe complex roots of equation "); // Print the complex root message.
    print_equation(a, b, c); // Print the equation.
    if (root_real!=0.0) // If the real part is not zero
      if (root_imaginary!=1.0)
        printf(" are %6.4f+%6.4fi and %6.4f-%6.4fi.\n", // Print the complex roots.
	           root_real, root_imaginary, root_real, root_imaginary);
	  else 
        printf(" are %6.4f+i and %6.4f-i.\n", root_real, root_real); // Print the complex roots.	         
	else
	  if (root_imaginary!=1.0)
        printf(" are %6.4fi and -%6.4fi.\n", // Print the complex roots, imaginary part only.
	           root_imaginary, root_imaginary);
	  else printf(" are i and -i.\n"); // Print the complex roots, imaginary part only.
  }
  
  return 0;
}
