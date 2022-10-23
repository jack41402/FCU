#include <stdio.h>

// Print n copies of character c.
void printChar(int n, char c) {
 int i;
 
 for (i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
  int n; // Side of the triangle.
  int i; // Loop variable.
  
  // Input the value of n, 3<=n<=29.
  do {
    printf("Enter an integer between 3 and 29: ");
    scanf("%d", &n);
  } while ((n < 3) || (n > 29));
  
  // Draws an isosceles triangle with isosceles side of length n and 
	// bottom side of length 2*n-1 such that the triangle orientation 
	// is shown as in the execution example, i.e., the bottom of the 
	// triangle is on the right-hand-side of the triangle. 
	// Output 10 blanks on the left side of the figure, use '$' to mark 
	// the sides of the isosceles triangle, and ¡®@¡¯ to mark the 
	// interior points of the isosceles triangle
	
  return 0;
}
