/*
  This program receives two integers m and n as input.
  Then, output m+n, m-n, m*n, m/n.
*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int m, n;

  printf("Input two integers m and n: "); // Request to input m and n.
  scanf("%d %d", &m, &n); // Input two integers m and n.
  printf("m+n=%d, m-n=%d, m*n=%d, m/n=%d\n", m+n, m-n, m*n, m/n); // Print m+n, m-n, m*n, m/n.
  
  return 0; 
}
