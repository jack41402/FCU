#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n; // The input even positive integer, maximum value 2000.
  unsigned char byte_data[2000]; // The randomly generated byte data.
  unsigned char proc_data[2000]; // The byte data after process.
  int i, j; // Loop variable.

  do {
  	printf("Enter an even positive integer n (0<n<=2000): ");
	scanf("%d", &n); // Input an even positive integer.
  } while (n%2!=0); // Repeat, if n is odd.
  
  srand(n); // Use n as the seed of random number generator.
  
  // Generate n bytes, each byte data is between 0 and 255.
  for (i=0; i<n; i++) byte_data[i] = rand() % 256; 
  
  // Outupt byte data, maximum 30 bytes in one line.
  printf("\nThe randomly generated byte data are:\n");
  for (i=0; i<n; i++) {
  	printf("%02X ", byte_data[i]); // Print the initial byte data using hexadecimal numerals.
  	if ((i+1)%30==0) printf("\n"); // Print a newline for every 40 bytes.
  }
  if (i%30!=0) printf("\n"); // If the last line is less than 40 bytes, print a newline.
  printf("\n"); // Print an additional newline.
  
  for (i=0; i<n; i=i+2) { // Each iteration processes two bytes.
    proc_data[i] = 0X00;
    for (j=0; j<8; j++) // Generate Y_i.
	    proc_data[i] = proc_data[i] | (((byte_data[i+1] >> (7 - j))& 0X01) << j);
    proc_data[i+1] = ~((byte_data[i]>>4) | (byte_data[i]<<4)); // Generate Y_(i+1).
  }
  
  printf("\nThe processed byte data are:\n");
  for (i=0; i<n; i++) {
  	printf("%02X ", proc_data[i]); // Print the processed byte data using hexadecimal numerals.
  	if ((i+1)%30==0) printf("\n"); // Print a newline for every 30 bytes.
  }
  if (i%30!=0) printf("\n"); // If the last line is less than 30 bytes, print a newline.
  printf("\n"); // Print an additional newline.

  return 0;
}