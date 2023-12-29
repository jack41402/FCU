#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <limits.h> 
#define MAX_HEX_LENGTH 16
int hexDigits(unsigned long long num) {
    int digits = 1;
    while (num /= 16) { 
        digits++;
    }
    return digits;
}

int main() {
    // FILE *file;
    unsigned long long num1, num2, result;
    int scanResult;

    // Open the file in read mode
    // file = fopen("hexadecimal_addition.txt", "r");
    // Read until the end of the file
    while ((scanResult = scanf("%llX %llX", &num1, &num2)) != EOF) {
        // Check for termination condition
        if (num1 == 0 && num2 == 0) {
            break;
        }
        result = num1 + num2;
        int max_digits = hexDigits(result)+1;
        int is_overflow = 0;
        int i; 
        if (num1 > ULLONG_MAX - num2) {
            is_overflow = 1;
        }
        // Print formatted result
        // max_digits += 1;
        printf("%*llX\n", max_digits+1, num1);
        printf("+%*llX\n", max_digits, num2);
        for (i = 0; i < max_digits+1; i++) {
            printf("-");
        }
        if (is_overflow) {
            printf("\n 1%llX\n", result);
            printf("%llu + %llu = %llu    ****Overflow!!!\n",num1,num2,result);
        } else {
            printf("\n%*llX\n", max_digits+1, result);
            printf("%llu + %llu = %llu\n",num1,num2,result);
        }
        printf("\n");
    }

    // Close the file
    // fclose(file);
    return EXIT_SUCCESS;
}
