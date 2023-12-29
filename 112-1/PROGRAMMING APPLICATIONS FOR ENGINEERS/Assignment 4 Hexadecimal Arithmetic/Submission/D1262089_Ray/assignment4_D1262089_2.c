#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void hexToDecimal(char hex[], unsigned long long int *dec) {
    *dec = 0;
    int len = strlen(hex);
    int i;
    for (i = 0; i < len; i++) {
        *dec *= 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            *dec += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            *dec += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            *dec += hex[i] - 'a' + 10;
        }
    }
}

void decimalToHex(unsigned long long int dec, char hex[]) {
    int index = 0;
    while (dec > 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            hex[index++] = '0' + remainder;
        } else {
            hex[index++] = 'A' + remainder - 10;
        }
        dec /= 16;
    }
    hex[index] = '\0';
    
    // Reverse the hex string
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
        start++;
        end--;
    }
}

// Print n times of character c.
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

int main() {
    char n1[33], n2[33], product[65];
    unsigned long long int dec1, dec2, result;
    int l1, l2 ,lmul ; // Length of string n1  B n2 and mul.
    while (1) {
        // Read input
        scanf("%s %s", n1, n2);
        
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) {
            break;
        }
        l1=strlen(n1);
        l2=strlen(n2);
        // Multiply and print the result
        hexToDecimal(n1, &dec1);
        hexToDecimal(n2, &dec2);
        result = dec1 * dec2;
        decimalToHex(result, product);
        lmul=strlen(product);
        printChar(lmul-l1+1, ' '); // If sum is longer than n1, print blanks.
        printf(" %s\n", n1);
        printf("*");
        printChar(lmul-l2+1, ' '); // If sum is longer than n2, print blanks.
        printf("%s\n", n2);
        printChar(lmul+2, '-'); //  print -------.
        printf("\n");
        printf("  %s\n", product);
        
        // Print the result in decimal
        unsigned long long int resultDecimal;
        hexToDecimal(product, &resultDecimal);
        printf("%llu * %llu = %llu\n\n", dec1, dec2, resultDecimal);
    }
    
    return 0;
}
