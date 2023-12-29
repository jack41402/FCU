
#include <stdio.h>
#include <string.h>
#include <math.h>
// Print n times of character c.
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

// Convert hexadecimal string to its decimal value.
unsigned long long hex2decimal(char *hex) {
    unsigned long long decimal = 0; // Decimal value initial to 0.
    int x;
    int i;
    for(i=0;i<strlen(hex);++i)
    {
        if(hex[i]<='9')
        {
            x=hex[i]-'0';
        }
        else
        {
            x=hex[i]-'A'+10;
        }
        decimal = decimal*16+x;
    }
    return decimal;
}


void hex_addition(char *n1, char *n2, char *sum) {
  
  int l1, l2; // Length of string n1 and n2.
  int lmin, lmax; // lmin=min(l1, l2), lmax=max(l1, l2).
  int carry; // Carry bit.
  int i; // Loop variable.
    char a,b,c;
  
  l1 = strlen(n1); // Length of n1.
  l2 = strlen(n2); // Length of n2.
  strcpy(sum, "0"); // Initial sum to 0.
  if (l1>=l2) {lmin = l2; lmax = l1;} // Set lmin and lmax.
  else {lmin = l1; lmax = l2;}
  carry = 0; // Reset the carry to 0.
  for (i=0; i<lmax; i++) {
      
      if(n1[l1-(i+1)]>'9'){
          a = '7';
      }
      else{
          a = '0';
      }
      if(n2[l2-(i+1)]>'9'){
          b = '7';
      }
      else{
          b = '0';
      }
      
      //Perform calculations after judging different possibilities
      if (i<lmin)
          sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + (n2[l2-(i+1)] - b) + carry;
      else if (i<l1)
        sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + carry;
      else if (i<l2)
        sum[lmax-(i+1)] = (n2[l2-(i+1)] - b) + carry;
      carry = sum[lmax-(i+1)] / 16;
      if(sum[lmax-(i+1)] % 16>9){
          c = '7';
      }
      else{
          c = '0';
      }
      sum[lmax-(i+1)] = sum[lmax-(i+1)] % 16 + c;
  }
    
  if (carry>=1) { // The most significant bit has a carry.
    sum[lmax+1] = '\0'; // Insert end-of-string, one bit more.
    for (i=lmax; i>0; i--) sum[i] = sum[i-1]; // Move the bits of sum one position to the right.
    sum[0] = carry; // Put the carry bit to sum.
  }
  else sum[lmax] = '\0'; // Insert end-of-string.
}


void decimal_digit_product(char *n, char d, char *product, int p) {
  
  int leng; // Length of string n.
  int carry; // Carry bit.
  int d_product; // Product of single digit.
  int i; // Loop variable.
    char a,b,c,e;
  
  leng = strlen(n); // Length of n.
  if (d!='0') { // If the digit is not 0, then do the product and shift.
    carry = 0; // Initial carry to 0.
    for (i=0; i<leng; i++) {
        if(n[leng-i-1]>'9'){
            a = '7';
        }
        else{
            a = '0';
        }
        if(d>'9'){
            b = '7';
        }
        else{
            b = '0';
        }

      d_product = (n[leng-i-1] - a) * (d - b) + carry;
      carry = d_product / 16;
        if(d_product % 16 > 9){
            c = '7';
        }
        else{
            c = '0';
        }
      product[leng-i-1] = d_product % 16 + c; // Resutl of the product, a single digit.
    }
    if (carry>=1) { // If the final carry is one.
      for (i=0; i<leng; i++) product[leng-i] = product[leng-i-1]; // Shift the product to the rignt.
        if(carry>9){
            e = '7';
        }
        else{
            e = '0';
        }
      product[0] = carry + e; // Insert the carry at the beginning.
      leng++; // Increment the length.
    }
    for (i=0; i<p; i++) product[leng+i] = '0';
    product[leng+p] = '\0';    // Insert end-of-string.
  }
  else strcpy(product, "0"); // The digit d is zero, the product is also zero.
}

int main (void) {
  char n1[17], n2[17]; // input1 and input2
  char product[18];  // product = n1 * n2
  char partial_product[18];  // pratial product = n1 * n2
  char digit_product[18]; // Single digit product = n1 * d.
  int l1, l2, leng; // String lengths of n1, n2, and product;
  int swap;
  int i; // Loop variable.
  
  while (scanf("%s %s", n1, n2)==2) {
      if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break; // If the two numbers are both 0, terminate the program.
      
      l1 = strlen(n1); // Length of n1.
      l2 = strlen(n2); // Length of n2.
      swap = 0;
      if (l2>l1) { // Swap the two numbers to make |n1|<=|n2|.
        swap = 1;
        strcpy(product, n2); // product<--n2; (use product as the temporary memory)
        strcpy(n2, n1); // n2<--n1;
        strcpy(n1, product); // n1<--product.
        i = l2; // Swap l1 and l2 (use i as the temporary memory).
        l2 = l1;
        l1 = i;
    }
      strcpy(product, "0"); // Initial the product to 0.
      for (i=0; i<l2; i++) {
        strcpy(partial_product, "0"); // Initial the partial product to 0.
          decimal_digit_product(n1, n2[l2-i-1], digit_product, i); // Compute product with a single digit.
        hex_addition(product, digit_product, partial_product); // Accumulate the product.
        strcpy(product, partial_product); // Copy the pratial product to product.
    }
    leng = strlen(product); // Final length of the product.
    if (swap) { // If n1 and n2 are swapped, print n2; then n1.
      printChar(leng-l2+2, ' '); // Print blanks befor n2.
      printf("%s\n", n2); // Print n2.
      printf("*"); // Print "*" sign.
      printChar(leng-l1+1, ' '); // Print blanks befor 1.
      printf("%s\n", n1); // Print n1.
    }
    else { // Otherwsie, print n1; then n2.
      printChar(leng-l1+2, ' '); // Print blanks befor n1.
      printf("%s\n", n1); // Print n1.
      printf("*"); // Print "*" sign.
      printChar(leng-l2+1, ' '); // Print blanks befor n2.
      printf("%s\n", n2); // Print n2.
    }
    printChar(leng+2, '-'); // Print separate line.
    printf("\n  %s\n", product); // Print two blanks and the sum.
    if (swap)
      printf("%llu * %llu = %llu\n\n",  // Print n2*n1=sum in decimal.
             hex2decimal(n2), hex2decimal(n1), hex2decimal(product));
    else // n1 and n2 are not swaped.
      printf("%llu * %llu = %llu\n\n",  // Print n1*n2=sum in decimal.
             hex2decimal(n1), hex2decimal(n2), hex2decimal(product));
  }
  return 0;
}


