/*
  This program prints the multiplication table of decimal digits (1 to 9) in the following
  two formats:

Multiplication Table Format 1:

      | 1   2   3   4   5   6   7   8   9
    --+------------------------------------
    1 | 1   2   3   4   5   6   7   8   9
    2 | 2   4   6   8  10  12  14  16  18
    3 | 3   6   9  12  15  18  21  24  27
    4 | 4   8  12  16  20  24  28  32  36
    5 | 5  10  15  20  25  30  35  40  45
    6 | 6  12  18  24  30  36  42  48  54
    7 | 7  14  21  28  35  42  49  56  63
    8 | 8  16  24  32  40  48  56  64  72
    9 | 9  18  27  36  45  54  63  72  81

************************************************************************

Multiplication Table Format 2:

  1*1= 1  1*2= 2  1*3= 3  1*4= 4  1*5= 5  1*6= 6  1*7= 7  1*8= 8  1*9= 9
  2*1= 2  2*2= 4  2*3= 6  2*4= 8  2*5=10  2*6=12  2*7=14  2*8=16  2*9=18
  3*1= 3  3*2= 6  3*3= 9  3*4=12  3*5=15  3*6=18  3*7=21  3*8=24  3*9=27
  4*1= 4  4*2= 8  4*3=12  4*4=16  4*5=20  4*6=24  4*7=28  4*8=32  4*9=36
  5*1= 5  5*2=10  5*3=15  5*4=20  5*5=25  5*6=30  5*7=35  5*8=40  5*9=45
  6*1= 6  6*2=12  6*3=18  6*4=24  6*5=30  6*6=36  6*7=42  6*8=48  6*9=54
  7*1= 7  7*2=14  7*3=21  7*4=28  7*5=35  7*6=42  7*7=49  7*8=56  7*9=63
  8*1= 8  8*2=16  8*3=24  8*4=32  8*5=40  8*6=48  8*7=56  8*8=64  8*9=72
  9*1= 9  9*2=18  9*3=27  9*4=36  9*5=45  9*6=54  9*7=63  9*8=72  9*9=81

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j;
  
  // Print the prelude message.
  printf("Multiplication Table for Decimal Digits (1 to 9) Format 1:\n\n");
  
  // Print the table head.
  printf("      |");
  for (i=1; i<10; i++) printf("%2d  ", i);
  
  // Print the dividing line.
  printf("\n    --+");
  for (i=1; i<10; i++) printf("----");
  printf("\n");
  
  // Print the table contents
  for (i=1; i<10; i++) {  
    printf("    %d |", i); // Print the head of each raw.
    for (j=1; j<10; j++) printf("%2d  ", i*j); // Print the product of two numbers nine times.
    printf("\n");    
  }
  
  // Print the separate line.
  printf("\n************************************************************************\n\n");
  
  // Print the prelude message.
  printf("Multiplication Table for Decimal Digits (1 to 9) Format 2:\n\n");
  
  // Print the multiplication table of format 2.
  for (i=1; i<10; i++) {
    printf("  ");
    for (j=1; j<10; j++) {
      printf("%d*%d=%2d  ", i, j, i*j); // Each line prints 9 expressions.
    }
    printf("\n");
  }
  
  return 0; 
}
