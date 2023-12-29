#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 9 // Considering 32 bits, each digit represents 4 bits

// Function to perform hexadecimal multiplication
void multiplyHex(char *n1, char *n2, char *product) {
    unsigned long long int num1, num2, result;
    sscanf(n1, "%llx", &num1); // Convert hexadecimal string n1 to unsigned long long int num1
    sscanf(n2, "%llx", &num2); // Convert hexadecimal string n2 to unsigned long long int num2

    result = num1 * num2; // Perform multiplication of num1 and num2
    sprintf(product, "%llx", result); // Store the result of multiplication in hexadecimal format in the product string

    int i;
    for (i = 0; product[i]; i++) {
        product[i] = toupper(product[i]); // Convert the product to uppercase
    }
}

// Function to print the multiplication operation and result in a specific format
void printHex(char *n1, char *n2, char *product) {
    int len = strlen(n1) + strlen(n2); // Calculate the total length required for alignment
    printf("     %*s\n", len - strlen(n2), n1); // Print n1 right-aligned with a width of len
    printf("   * %*s\n", (int)strlen(n2), n2); // Print n2 aligned below the '*' sign, right-aligned
    int i;
    for (i = 0; i < len; i++) {
        printf("-"); // Print a line of dashes equal to the total length (n1 + n2)
    }
    printf("\n%*s\n", len, product); // Print the product right-aligned with a width of len
    printf("%s * %s = %s\n\n", n1, n2, product); // Print the multiplication expression below the product
}

int main() {
    char n1[MAX_LENGTH], n2[MAX_LENGTH], product[MAX_LENGTH * 2]; // Maximum product length can be sum of n1 and n2 lengths

    while (1) {
        scanf("%s %s", n1, n2); // Read two hexadecimal strings from input
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) { // Check if both input strings are "0"
            break; // Exit the loop if input is "0 0"
        }

        multiplyHex(n1, n2, product); // Call function to perform hexadecimal multiplication
        printHex(n1, n2, product); // Print the input, multiplication, and expression in a specific format
    }

    return 0;
}

