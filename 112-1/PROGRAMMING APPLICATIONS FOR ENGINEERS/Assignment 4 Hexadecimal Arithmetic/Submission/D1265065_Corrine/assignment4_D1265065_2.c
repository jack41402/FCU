#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Print n times of character c.
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

// Convert a hexadecimal string to its decimal value.
unsigned long long hexa2decimal(char *hexa) {
  unsigned long long decimal = 0, a; // Decimal value initial to 0. Use variable to change hexadecimal into decimal.
  int i; // Loop variable.
  
  for (i = 0; i < strlen(hexa) - 1; i++){
  	if(hexa[i] >= 'A') a = hexa[i] - 'A' + 10;//Judge if the string is alphabet or not, and then, use ASCII code to turn it into decimal numbers.
	else if('0' <= hexa[i] <= '9') a = hexa[i] - '0';
	decimal = (a + decimal) *16;//Calculate formula.
	}
	if(hexa[i] >= 'A') a = hexa[i] - 'A' + 10;
	else if('0' <= hexa[i] <= '9') a = hexa[i] - '0';
	decimal = a + decimal;

  return decimal;
}

// Compute sum = n1 + n2;
void hexa_addition(char *n1, char *n2, char *sum) {
  
  int l1, l2; // Length of string n1 and n2.
  int lmin, lmax; // lmin=min(l1, l2), lmax=max(l1, l2).
  int carry; // Carry bit.
  int i; // Loop variable.
  int a, b, c;// Use variables to change hexadecimal into decimal.
  l1 = strlen(n1); // Length of n1.
  l2 = strlen(n2); // Length of n2.
  strcpy(sum, "0"); // Initial sum to 0.
  if (l1>=l2) {lmin = l2; lmax = l1;} // Set lmin and lmax.
  else {lmin = l1; lmax = l2;}
  carry = 0; // Reset the carry to 0.
  for (i=0; i<lmax; i++) {
  	
  	if(n1[l1-(i+1)] >= 'A') a =  'A' - 10; //Judge if the string is alphabet or not, and then, use ASCII code to turn it into decimal numbers.
	else if('0' <= n1[l1-(i+1)] <= '9') a =  '0';
  	if(n2[l2-(i+1)] >= 'A') b =  'A' - 10;
	else if('0' <= n2[l2-(i+1)] <= '9') b =  '0';
	
  	if (i<lmin) // Add the i-th bit for both n1 and n2, counting from the least significant bit.
  	  sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + (n2[l2-(i+1)] - b) + carry;
  	else if (i<l1) // n1 is larger than n2, process reset of bits in n1.
  	  sum[lmax-(i+1)] = (n1[l1-(i+1)] - a) + carry;
  	else if (i<l2) // n2 is larger than n1, process reset of bits in n2.
  	  sum[lmax-(i+1)] = (n2[l2-(i+1)] - b) + carry;
  	carry = sum[lmax-(i+1)] / 16; // Next carry.
  	c = (sum[lmax-(i+1)] % 16 > 9) ? ( 'A' - 10) : ('0');
  	sum[lmax-(i+1)] = sum[lmax-(i+1)] % 16 + c; // The i-th bit of the sum.
  }
	
  if (carry==1) { // The most significant bit has a carry.
	sum[lmax+1] = '\0'; // Insert end-of-string, one bit more.
	for (i=lmax; i>0; i--) sum[i] = sum[i-1]; // Move the bits of sum one position to the right.
	sum[0] = '1'; // Put the carry bit to sum.
  }
  else sum[lmax] = '\0'; // Insert end-of-string.
}

// Compute sum = n1 * d, then shift to the left p positions.
void hexa_digit_product(char *n, char d, char *product, int p) {
  
  int leng; // Length of string n.
  int carry; // Carry bit.
  int d_product; // Product of single digit.
  int i; // Loop variable.
  int a, b, c;
  leng = strlen(n); // Length of n.
  if (d!='0') { // If the digit is not 0, then do the product and shift.
    carry = 0; // Initial carry to 0.
    for (i=0; i<leng; i++) { // Multiply single digit in n with d.
    a = (n[leng-i-1] >= 'A') ? ('A' - 10) : ('0');
    b = (d >= 'A' ) ? ('A' - 10) : ('0');
      d_product = (n[leng-i-1] - a) * (d - b) + carry;
      carry = d_product / 16; // New carry.
      c = (d_product % 16 > 9) ? ('A' - 10) : ('0');
      product[leng-i-1] = d_product % 16 + c; // Result of the product, a single digit.
	}
	if (carry != 0) { // If the final carry is one.
	  for (i=0; i<leng; i++) product[leng-i] = product[leng-i-1];
	  d = (carry > 9) ? ( 'A' - 10) : ('0'); // Shift the product to the rignt.
	  product[0] = carry + d ; // Insert the carry at the beginning.
	  leng++; // Increment the length.
	}
	for (i=0; i<p; i++) product[leng+i] = '0'; // Insert 0's, i.e., shift the product to the left.
	product[leng+p] = '\0';	// Insert end-of-string.
  }
  else strcpy(product, "0"); // The digit d is zero, the product is also zero.
}

int main (void) {
  char n1[33], n2[33]; // Inupt hexadecimal numerals, maximum 33 bits.
  char product[66];  // product = n1 * n2, maximum number of bits of product is 66.
  char partial_product[66];  // pratial product = n1 * n2, maximum number of bits of product is 66.
  char digit_product[66]; // Single digit product = n1 * d.
  int l1, l2, leng; // String lengths of n1, n2, and product;
  int swap;
  int i; // Loop variable.
  
  while (scanf("%s %s", n1, n2)==2) { // Read two binary numbers as 0-1 strings.
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
  	  hexa_digit_product(n1, n2[l2-i-1], digit_product, i); // Compute product with a single digit.
  	  hexa_addition(product, digit_product, partial_product); // Accumulate the product.
  	  strcpy(product, partial_product); // Copy the pratial product to product.
	}
    leng = strlen(product); // Final length of the product.
    if (swap) { // If n1 and n2 are swapped, print n2; then n1.
      printChar(leng-l2+2, ' '); // Print blanks before n2.
      printf("%s\n", n2); // Print n2.
      printf("*"); // Print "*" sign.
      printChar(leng-l1+1, ' '); // Print blanks before 1.
      printf("%s\n", n1); // Print n1.
	}
	else { // Otherwsie, print n1; then n2.
      printChar(leng-l1+2, ' '); // Print blanks before n1.
      printf("%s\n", n1); // Print n1.
      printf("*"); // Print "*" sign.
      printChar(leng-l2+1, ' '); // Print blanks before n2.
      printf("%s\n", n2); // Print n2.
	}
    printChar(leng+2, '-'); // Print separate line.
    printf("\n  %s\n", product); // Print two blanks and the sum.
    if (swap) // n1 and n2 are swapped.
      printf("%llu * %llu = %llu\n\n",  // Print n2*n1=sum in decimal.
	         hexa2decimal(n2), hexa2decimal(n1), hexa2decimal(product));
    else // n1 and n2 are not swaped.
	  printf("%llu * %llu = %llu\n\n",  // Print n1*n2=sum in decimal.
	         hexa2decimal(n1), hexa2decimal(n2), hexa2decimal(product));
  }
  return 0;
}
