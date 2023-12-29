//
//  main.c
//  assignment4_D1265065_1
//
//  Created by Corrine  on 2023/11/29.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Print n times of character c.
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Use loop to print character c.
}

// Convert an hexadecimal string to its decimal value.
unsigned long long hexa2decimal(char *hexa) {
  unsigned long long decimal = 0; // Decimal value initial to 0.
    int i; // Loop variable.
    int a = 0; // Use variable to change hexadecimal into decimal.
      for (i=0; i<strlen(hexa)-1; i++) {
          if(hexa[i] >= 'A') a = hexa[i] - 'A' + 10; //Judge if the string is alphabet or not, and then, use ASCII code to turn it into decimal numbers.
          else if('0' <= hexa[i] <= '9') a = hexa[i] - '0';
          decimal = (a + decimal) * 16; //Calculate formula.
      }
      if(hexa[i] >= 'A') a = hexa[i] - 'A' + 10;
      else if('0' <= hexa[i] <= '9') a = hexa[i] - '0';
      decimal = a + decimal;
    return decimal;
}

int main (void) {
  char n1[17], n2[17]; // Inupt binary numerals, maximum 17 digits.
  char sum[18]; // maximum number of bits of sum 18 digits.
  int l1, l2; // Length of string n1 and n2.
  int lmin, lmax; // lmin=min(l1, l2), lmax=max(l1, l2).
  int carry; // Carry bit.
  int d_sum; // Sum of single digit.
  int i; // Loop variable.
  int a, b, c; // Use variables to change hexadecimal into decimal.
  
  while (scanf("%s %s", n1, n2)==2) { // Read two hexadecimal numbers as 0-1 strings.
      if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break; // If the two numbers are both 0, terminate the program.
      
      l1 = strlen(n1); // Length of n1.
      l2 = strlen(n2); // Length of n2.
      if (l1>=l2) {lmin = l2; lmax = l1;} // Set lmin and lmax.
      else {lmin = l1; lmax = l2;}
      carry = 0; // Reset the carry to 0.
      for (i=0; i<lmax; i++) {
          a = (n1[l1-(i+1)] >= 'A') ? ('A'-10) : ('0'); //Judge if the string is alphabet or not, and then, use ASCII code to turn it into decimal numbers.
          b = (n2[l2-(i+1)] >= 'A') ? ('A'-10) : ('0');
        if (i<lmin) // Add the i-th digit for both n1 and n2, counting from the left-most digit.
          sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + (n2[l2-(i+1)] - b) + carry;
        else if (i<l1) // n1 is larger than n2, process reset of digit in n1.
          sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + carry;
        else if (i<l2) // n2 is larger than n1, process reset of digit in n2.
          sum[lmax-(i+1)] = (n2[l2-(i+1)] - b) + carry;
        carry = sum[lmax-(i+1)] / 16; // Next carry.
        c = (sum[lmax-(i+1)] % 16 > 9) ? ('A'-10) : ('0');
        sum[lmax-(i+1)] = sum[lmax-(i+1)] % 16 + c; // The i-th digit of the sum.
    }
    
    if (carry==1) { // The most significant digit has a carry.
      sum[lmax+1] = '\0'; // Insert end-of-string, one bit more.
      for (i=lmax; i>0; i--) sum[i] = sum[i-1]; // Move the bits of sum one position to the right.
      sum[0] = '1'; // Put the carry bit to sum.
    }
    else sum[lmax] = '\0'; // Insert end-of-string.
    
    printChar(l2-l1, ' '); // If n2 is longer than n1, print blanks.
    printChar(carry+2, ' '); // Print 2 or 3 blanks depending on carry.
    printf("%s\n", n1); // Print n1.
    printf("+"); // Print "+" sign.
    printChar(l1-l2, ' '); // If n1 is longer than n2, print blanks.
    printChar(carry+1, ' '); // Print 1 or 2 blanks depending on carry.
    printf("%s\n", n2); // Print n2.
    printChar(lmax+carry+2, '-'); // Print separate line.
    printf("\n  %s\n", sum); // Print two blanks and the sum.
    printf("%llu + %llu = %llu",  // Print n1+n2=sum in decimal.
           hexa2decimal(n1), hexa2decimal(n2), hexa2decimal(sum));
    // Check and print overflow message. If sum reaches the maximum number of digits,
      if (strlen(sum)>16 && strlen(sum)==16 && strcmp(sum,"FFFFFFFFFFFFFF")>0) printf("    **** Overflow!!!\n\n"); // Check and print overflow message.
      else printf("\n\n"); // Print newline.
  }
  return 0;
}
