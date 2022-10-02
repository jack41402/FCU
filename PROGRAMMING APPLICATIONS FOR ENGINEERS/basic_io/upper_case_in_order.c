/*
  This program inputs three English letters.
  Convert them to the corresponding upper case letters.
  Then output a string with these three letters in the alpabetical order.
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
  char letter1, letter2, letter3;

  printf("Input three letters: "); // Request to input three letters.
  scanf("%c %c %c", &letter1, &letter2, &letter3); // Input three letters.
  letter1 = toupper(letter1); // Convert letter1 to the upper case.
  letter2 = toupper(letter2); // Convert letter2 to the upper case.
  letter3 = toupper(letter3); // Convert letter3 to the upper case.
  // List all six possible orders in cases.
  if (letter1<=letter2 && letter2<=letter3) printf("%c %c %c\n", letter1, letter2, letter3);
  if (letter1<=letter3 && letter3<=letter2) printf("%c %c %c\n", letter1, letter3, letter2);
  if (letter2<=letter1 && letter1<=letter3) printf("%c %c %c\n", letter2, letter1, letter3);
  if (letter2<=letter3 && letter3<=letter1) printf("%c %c %c\n", letter2, letter3, letter1);
  if (letter3<=letter1 && letter1<=letter2) printf("%c %c %c\n", letter3, letter1, letter2);
  if (letter3<=letter2 && letter2<=letter1) printf("%c %c %c\n", letter3, letter2, letter1);
  
  return 0; 
}
