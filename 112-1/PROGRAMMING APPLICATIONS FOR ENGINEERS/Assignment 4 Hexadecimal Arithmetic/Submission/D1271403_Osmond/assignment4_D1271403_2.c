#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>

#define MAX_HEX_LENGTH 16

// Function to calculate the number of hexadecimal digits in a given number
int hexDigits(unsigned long long num) {
    int digits = 1;
    while (num /= 16) {
        digits++;
    }
    return digits;
}

int main() {
    // Variables for input numbers and result
    unsigned long long num1, num2, result;
    int scanResult;

    // Uncomment the following lines to read input from a file
    // FILE *file;
    // file = fopen("hexadecimal_addition.txt", "r");

    // Read input until the end of the file
    while ((scanResult = scanf("%llX %llX", &num1, &num2)) != EOF) {
        // Check for the termination condition
        if (num1 == 0 && num2 == 0) {
            break;
        }

        // Perform addition
        result = num1 + num2;

        // Calculate the maximum number of digits in the hexadecimal representation
        int max_digits = hexDigits(result) + 1;

        // Variable to track overflow
        int is_overflow = 0;

        // Check for overflow condition
        int i;
        if (num1 > ULLONG_MAX - num2) {
            is_overflow = 1;
        }

        // Print formatted result
        printf("%*llX\n", max_digits + 1, num1);
        printf("+%*llX\n", max_digits, num2);

        // Print a line of dashes for separation
        for (i = 0; i < max_digits + 1; i++) {
            printf("-");
        }

        // Print result and handle overflow
        if (is_overflow) {
            printf("\n 1%llX\n", result);
            printf("%llu + %llu = %llu    ****Overflow!!!\n", num1, num2, result);
        } else {
            printf("\n%*llX\n", max_digits + 1, result);
            printf("%llu + %llu = %llu\n", num1, num2, result);
        }

        // Print a newline for better formatting
        printf("\n");
    }

    // Uncomment the following line to close the file
    // fclose(file);

    // Exit the program
    return EXIT_SUCCESS;
}

