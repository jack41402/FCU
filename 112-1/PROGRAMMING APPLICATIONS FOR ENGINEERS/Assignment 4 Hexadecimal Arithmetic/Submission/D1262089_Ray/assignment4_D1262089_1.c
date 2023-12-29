#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Function to perform hexadecimal addition
void hexAddition(char n1[], char n2[], char sum[]) {
    int carry = 0;
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int maxLen = len1 > len2 ? len1 : len2;
    
      
    // Make both input strings of equal length by padding with zeros
    while (strlen(n1) < maxLen) {
        memmove(n1 + 1, n1, strlen(n1) + 1);
        n1[0] = '0';
    }

    while (strlen(n2) < maxLen) {
        memmove(n2 + 1, n2, strlen(n2) + 1);
        n2[0] = '0';
    }

   
    // Perform hexadecimal addition
     int i;
    for (i = maxLen - 1; i >= 0; i--) {
        int digit1 = (n1[i] >= 'A') ? (n1[i] - 'A' + 10) : (n1[i] - '0');
        int digit2 = (n2[i] >= 'A') ? (n2[i] - 'A' + 10) : (n2[i] - '0');

        int tempSum = digit1 + digit2 + carry;

            carry = tempSum / 16;
       

        sum[i] = (tempSum % 16 < 10) ? (tempSum % 16 + '0') : (tempSum % 16 - 10 + 'A');
    }

    // Check for remaining carry
    

    if (carry > 0) {
        memmove(sum + 1, sum, strlen(sum) + 1);
        sum[0] = (carry < 10) ? (carry + '0') : (carry - 10 + 'A');
    }

    sum[maxLen + (carry > 0 ? 1 : 0)] = '\0'; //'\0'end signal 
}

// Function to convert a hexadecimal string to a decimal number
unsigned long long hexStringToDecimal(char hex[]) {
    unsigned long long result = 0;
    int len = strlen(hex);
    int i ;
    for (i = 0; i < len; i++) {
        int decimalValue = (hex[i] >= 'A') ? (hex[i] - 'A' + 10) : (hex[i] - '0');

        result = result * 16 + decimalValue;
    }

    return result;
}

// Print n times of character c.
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

// Main function
int main() {
    char n1[65], n2[65],sum[65];
    char n11[65], n21[65];
    int l1, l2 ,lsum ; // Length of string n1  B n2 and sum.
    while (1) {
        // Input two hexadecimal numbers
        scanf("%s %s", n1, n2);

        // Check for termination condition
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) {
            break;
        }
        l1=strlen(n1);
        l2=strlen(n2);
       
        //int i;
        // Perform hexadecimal addition
        memmove(n11 , n1, sizeof(n1) );
        memmove(n21 , n2, sizeof(n2) );
        hexAddition(n1, n2, sum);
        lsum=strlen(sum);
        // Display the input numbers for clarity
        printChar(lsum-l1+1, ' '); // If sum is longer than n1, print blanks.
        printf(" %s \n", n11);
        printf("+");
        printChar(lsum-l2+1, ' '); // If sum is longer than n2, print blanks.
        printf("%s \n", n21);
        // Print a line of dashes for clarity
        printChar(lsum+2, '-'); // //  print -------.
        printf("\n");

        // Display the result in hexadecimal and decimal
        printf("  %s\n", sum);
        printf("%llu + %llu = %llu", hexStringToDecimal(n1), hexStringToDecimal(n2), hexStringToDecimal(sum));

        // Check for overflow
        if (strlen(sum) > 16) {
            printf("    ****Overflow!!!\n");
            continue;
        }
        printf("\n");
    }

    return 0;
}
