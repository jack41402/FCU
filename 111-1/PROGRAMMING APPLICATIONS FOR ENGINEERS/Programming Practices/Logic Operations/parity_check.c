#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void) {
  int parity; // Single bit to indicate even (0) or odd (1) parity.
  int length; // Length of binary stream in bits, maximum 2000.
  int pairs; // Number of nibble pairs.
  int one_bit; // Number of 1_bit in the binary stream. 
  unsigned char stream[250]; // Maximum 250 pairs of hexadecimal digits.
  int i, j; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  while (1){ // Continue to process until input parity and length are 0's.  
    // Input parity and length.
    do {
	  printf("Enter parity and stream length: ");
      scanf("%d %d", &parity, &length);
	} while ((parity!=0 && parity!=1) || length<0 || length>2000);
    printf("%d %d\n", parity, length); // Echo the input data.
    if (parity==0 && length==0) break; // If parity and length are 0's, stop the loop and terminate the program.
    
    printf("Input binary streams (%d bytes): \n", (int) ceil(length/8.0));
    pairs = (int) ceil(length / 8.0); // Number of pairs of nibbles.
    for (i=0; i<pairs; i++) stream[i] = rand() % 256; // Generate the data stream randomly. 
    printf("\n");
    
    one_bit = 0; // Initial the number of 1-bit to 0.
    printf("The binary stream is:\n"); // Output the binary stream.
    for (i=0; i<pairs; i++) {
      for (j=0; j<8; j++) {
      	if (i*8+j==length) break; // If reach the end of binary stream, stop the loop.
      	printf("%d", (stream[i]>>(7-j))&0X01); // Output a bit.
      	if (((stream[i]>>(7-j))&0X01)==1) one_bit++; // If the j-th bit of the i-th byte is 1, increment one_bit. 
	  }
	  printf(" "); // Output a space, after a byte or at the end of stream.
	  if ((i+1)%8==0) printf("\n"); // Output a newline after every eight bytes.
	}
	if (pairs%8!=0) printf("\n"); // Output a newline, if the number of bytes is not multiple of 8.
	printf("\n");
	
	if (parity==0) printf("**** Even Parity.    ");
	else printf("**** Odd Parity.    ");
	printf("The binary stream has %d ones. ", one_bit);
	if (one_bit%2==parity) printf("Parity check passes.\n\n");
	else printf("Parity check fails.\n\n");
  
    printf("-----------------------------------------------------\n"); // Print a separated line.
  }
  
  return 0;
}
