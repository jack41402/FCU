#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rational_number.h"

int main(void) {
  Rational a, b, c, d; // Four rational number variables.
  int nume, deno; // numerator and denominator.
  
  // Input rational number a.
  printf("Enter the numerator and denomiator of a: ");
  scanf("%d %d", &nume, &deno);
  a = ii2r(nume, deno);
  printf("Rational number a: ");
  printr(a);
  printf("\n\n");
  
  // Input rational number b.
  printf("Enter the numerator and denomiator of b: ");
  scanf("%d %d", &nume, &deno);
  b = ii2r(nume, deno);
  printf("Rational number b: ");
  printr(b);
  printf("\n\n");
  
  // Input rational number c.
  printf("Enter the numerator and denomiator of c: ");
  scanf("%d %d", &nume, &deno);
  c = ii2r(nume, deno);
  printf("Rational number c: ");
  printr(c);
  printf("\n\n");
  
  // Input rational number d.
  printf("Enter the numerator and denomiator of d: ");
  scanf("%d %d", &nume, &deno);
  d = ii2r(nume, deno);
  printf("Rational number d: ");
  printr(d);
  printf("\n\n");
  
  // Compute and print a + b.
  printf("a + b = ");
  printr(plus(a, b));
  printf("\n\n");
  
  // Compute and print a - b.
  printf("a - b = ");
  printr(minus(a, b));
  printf("\n\n");
  
  // Compute and print a * b.
  printf("a * b = ");
  printr(time(a, b));
  printf("\n\n");
  
  // Compute and print a / b.
  printf("a / b = ");
  printr(divide(a, b));
  printf("\n\n");
  
  // Compute and print |a|.
  printf("|a| = ");
  printr(qabs(a));
  printf("\n\n");
  
  // Compute and print a * |d - b| - (b + c / a) / |b + a - c * d|.
  printf("a * |d - b| - (b + c / a) / |b + a - c * d| = ");
  printr(minus(time(a, qabs(minus(d, b))),
               divide(plus(b, divide(c, a)), 
                      qabs(plus(b, minus(a, time(c, d)))))));
  printf("\n\n");
  
  return 0;
}
