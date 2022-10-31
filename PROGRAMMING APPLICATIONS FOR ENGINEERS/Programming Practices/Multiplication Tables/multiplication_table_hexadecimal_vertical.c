#include <stdio.h>

int main(void) {
  int i, j; // Loop variables.

  printf("Hexadecimal Multiplication Table in Vertical Format:\n\n"); // Print the title message. 
  for (i=1; i<=15; i++) { // Outer loop for the first operand.
    for (j=1; j<=15; j++) printf("    %X", i); // Print the first operands, nine terms.
    printf("\n"); // Print a newline.
    for (j=1; j<=15; j++) printf("  x %X", j); // Print the second operands, nine terms.
    printf("\n"); // Print a newline.
    for (j=1; j<=15; j++) printf("  ---"); // Print the separate line, nine times.
    printf("\n"); // Print a newline.
    for (j=1; j<=15; j++) printf("   %2X", i*j); // Print the products, nine terms.
    printf("\n\n"); // Print a newline and an empty line. 
  }
  return 0;
}
