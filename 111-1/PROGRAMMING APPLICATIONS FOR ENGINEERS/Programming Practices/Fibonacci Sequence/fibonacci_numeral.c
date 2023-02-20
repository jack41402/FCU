#include<stdio.h>
#include<stdlib.h>

// Maximum 40 Fibonacci numbers because fib(39)>100000000.
// The first dimension stores the Fibonacci number fib(i) and the second
// dimension is 1 or 0, denoting whether that number is selected not not, 
// i.e., bit value of Fibonacci numeral.
int fib[2][40];
int fib_index; // Index of a Fibonacci number that will be marked 1 in a Fibonacci numeral.

void find_fib_index(int k) {
	int i; // Loop variable.

	for (i=1; i<40; i++) {
		if (fib[0][i] <= k)
			fib[1][i] = 0; // Mark the bit value i as 0.
		else { 
			// Mark 1 at the index of the Fibonacci numeral.
			fib[1][i - 1] = 1; 
			// Set the current index of the Fibonacci numeral.
			fib_index = i - 1; 
			break;
		}
	} 
}

int main(void) {
	int n; // Input data.
	int fib_index_head; // First index of the Fibonacci numeral.
	int remainder; // Remainder of the integer to be converted.
	int i; // Loop index.
	
	// Generate sequence of Fibonacci numbers, upto fib(39).
	fib[0][0] = 1;
	fib[0][1] = 1;
	for (i=2; i<40; i++) fib[0][i] = fib[0][i-1] + fib[0][i-2];
	
	do {
		printf("Enter a positive integer n between 1 and 100000000 (0 to stop): ");
		scanf("%d", &n); // Input an integer.
		if (n == 0) break; // If n is 0, stop the program.

		find_fib_index(n); // Find the first index of the Fibonacci numeral.
		fib_index_head = fib_index; // Save the first index.
		// The remaining integer to be converted to a Fibonacci numeral.
		remainder = n - fib[0][fib_index_head]; 

		while (remainder > 0) { // When remainder is not 0, continue.
			find_fib_index(remainder); // Find the next index of the Fibonacci numeral.
			remainder = remainder - fib[0][fib_index]; // Update remainder.
		}

		// Print the Fibonacci numeral.
		printf("The Fibonacci numeral of n is: ");
		for (i = fib_index_head; i > 0; i--)
			printf("%d", fib[1][i]); // Print the Fibonacci base numeral.
		printf(" (fib)\n"); // Print "(fib)".

		printf("---------------------------------------\n"); // Print a separate line.
	} while (1);
}

