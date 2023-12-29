#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Print n times of character c.
void printChar(int n, char c) {
    int i; // Loop variable.

    for (i = 0; i < n; i++) printf("%c", c); // Each iteration print one character c.
}

// Convert a hexadecimal character to its decimal value.
int hexCharToDecimal(char hexChar) {
    if (hexChar >= '0' && hexChar <= '9') {
        return hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        return hexChar - 'A' + 10;
    } 
}

// Convert a decimal value to its hexadecimal character representation.
char decimalToHexChar(int decimal) {
    if (decimal >= 0 && decimal <= 9) {
        return decimal + '0';
    } else if (decimal >= 10 && decimal <= 15) {
        return decimal - 10 + 'A';
    } else {
        return '0'; // Default to '0' for invalid decimals.
    }
}

// Convert a hexadecimal string to its decimal value.
unsigned long long hex2decimal(char *hex) {
    unsigned long long decimal = 0; // Decimal value initial to 0.
    int i; // Loop variable.

    for (i = 0; i < strlen(hex); i++) {
        decimal = decimal * 16 + hexCharToDecimal(hex[i]);
    }
    return decimal;
}



int main(void) {
    char n1[17], n2[17]; // Input hexadecimal numerals, maximum 23 digits.
    char sum[18]; // sum = n1 + n2, maximum number of bits of sum 23 digits.
    int l1, l2; // Length of string n1 and n2.
    int lmin, lmax; // lmin=min(l1, l2), lmax=max(l1, l2).
    int carry; // Carry bit.
    int i; // Loop variable.

    while (scanf("%s %s", n1, n2) == 2) { // Read two hexadecimal numbers.
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) break; // If both numbers are 0, terminate the program.

        l1 = strlen(n1); // Length of n1.
        l2 = strlen(n2); // Length of n2.
        if (l1 >= l2) {
            lmin = l2;
            lmax = l1;
        } else {
            lmin = l1;
            lmax = l2;
        }
        carry = 0; // Reset the carry to 0.

        for (i = 0; i < lmax; i++) {
            int digit1 = (i < l1) ? hexCharToDecimal(n1[l1 - (i + 1)]) : 0;
            int digit2 = (i < l2) ? hexCharToDecimal(n2[l2 - (i + 1)]) : 0;

            sum[lmax - (i + 1)] = digit1 + digit2 + carry;
            carry = sum[lmax - (i + 1)] / 16; // Next carry.
            sum[lmax - (i + 1)] = decimalToHexChar(sum[lmax - (i + 1)] % 16); // The i-th digit of the sum.
        }

        if (carry == 1) {
            sum[lmax + 1] = '\0'; // Insert end-of-string, one bit more.
            for (i = lmax; i > 0; i--) sum[i] = sum[i - 1]; // Move the bits of sum one position to the right.
            sum[0] = '1'; // Put the carry bit to sum.
        } else {
            sum[lmax] = '\0'; // Insert end-of-string.
        }

        printChar(l2 - l1, ' '); // If n2 is longer than n1, print blanks.
        printChar(carry + 2, ' '); // Print 2 or 3 blanks depending on carry.
        printf("%s\n", n1); // Print n1.
        printf("+"); // Print "+" sign.
        printChar(l1 - l2, ' '); // If n1 is longer than n2, print blanks.
        printChar(carry + 1, ' '); // Print 1 or 2 blanks depending on carry.
        printf("%s\n", n2); // Print n2.
        printChar(lmax + carry + 2, '-'); // Print separate line.
        printf("\n  %s\n", sum); // Print two blanks and the sum.
        printf("%lld + %lld = %lld", // Print n1+n2=sum in decimal.
               hex2decimal(n1), hex2decimal(n2), hex2decimal(sum));

        // Check and print overflow message.
        if (strlen(sum) == 18 && sum[0] > '1') printf("    ****Overflow!!!\n\n");
        else printf("\n\n"); // Print newline.
    }
    return 0;
}
