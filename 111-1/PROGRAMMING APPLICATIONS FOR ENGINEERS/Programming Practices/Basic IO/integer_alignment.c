
#include <stdio.h>

// This program solution outputs the results as specified in the problem.
// However, it is not a well-written program. You should try to improve it.

int main(void) { 

  printf("Integer sequence without alignment:\n");
  printf("12 -3 99999999 255\n6578 -457 808 -745784\n-12344 200025 89\n");

  printf("\n--------------------------------\n");
  
  printf("Integer sequence with left alignment:\n");
  printf("12       -3       99999999 255\n6578     -457     808      -745784\n-12344   200025   89\n"); 
  
  printf("\n--------------------------------\n");
  
  printf("Integer sequence with right alignment:\n");
  printf("      12       -3 99999999      255\n    6578     -457      808  -745784\n  -12344   200025       89\n"); 
  
  return 0; 
}
