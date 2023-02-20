/* Tower of Hanoi: Moving n discs from sour via aux to dest.
   This program uses stacks to represent the the pegs.
   After every move, the contents of the pegs are printed.
*/
#include <stdio.h>
#include <stdlib.h>
#include "hanoi_stack_array.h"

// Print the conents of the three pegs from bottom to top.
void print_pegs(Stack ppeg1, Stack ppeg2, Stack ppeg3) {
  printf("\nPeg A: ");
  print_stack(ppeg1);
  printf("\nPeg B: ");
  print_stack(ppeg2);
  printf("\nPeg C: ");
  print_stack(ppeg3);
}

/* The first three peg parameters sour, aux, and dest are
   the source peg, auxiliary peg, and destination peg for
   disk movements.
   The next three peg parameters ppeg1, ppeg2, ppeg3 are the
   three pegs in their order for the output purpose.
*/
void hanoi(int n, Stack *sour, Stack *aux, Stack *dest,
           Stack *ppeg1, Stack *ppeg2, Stack *ppeg3) {
  static int step = 1;
  
  if (n>0) {
  	// Move n-1 disks from sour to aux using dest as the helping peg.
    hanoi(n-1, sour, dest, aux, ppeg1, ppeg2, ppeg3);
    // Move the disk at the bottom from sour to dest.
    push(dest, pop(sour));
    printf("\n\n**********************************************\n");
    // top(dest) is the disk being move.
    // get_name(sour): Name of the source peg.
    // get_name(dest): Name of the destination peg.
    printf(">>>> Step %d: Move disk %d from %s to %s\n", step++, top(*dest),
	       get_name(sour), get_name(dest));
    print_pegs(*ppeg1, *ppeg2, *ppeg3); // Print the content of the three pegs.
	// Move n-1 disks from aux to dest using sour as the helping peg.
    hanoi(n-1, aux, sour, dest, ppeg1, ppeg2, ppeg3);
  }
}

int main(void) {
  Stack peg1, peg2, peg3; // Three pegs using stacks.
  int i, k; // Loop variables.

  initial_stack(&peg1, "Peg A"); // Source peg.
  initial_stack(&peg2, "Peg B"); // Auxiliary peg.
  initial_stack(&peg3, "Peg C"); // Destination peg.
  
  // Read the number of disks between 1 and 12.
  do { 
    printf("Please enter the number of disks: ");
    scanf("%d", &k); // Enter a number n.
  } while (k<1 || k>12);

  // Place disks in the source peg starting with the largest disk.
  for (i=k; i>0; i--) push(&peg1, i);

  printf("\nInitial pegs:\n"); // Print the initial pegs.
  print_pegs(peg1, peg2, peg3); 
  hanoi(k, &peg1, &peg2, &peg3, &peg1, &peg2, &peg3); // Run tower of Hanoi.
  printf("\n\nFinish!!!\n\n"); // Done.
  
  return 0;
}
