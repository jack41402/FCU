#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h> 
#define MAX_LENGTH 65 

void addHex(char *n1, char *n2, char *sum) { // Function to add hexadecimal numbers
    unsigned long long int num1, num2, result; // Declare variables to hold hexadecimal numbers and their sum
    sscanf(n1, "%llx", &num1); // Convert hexadecimal string n1 to unsigned long long int num1
    sscanf(n2, "%llx", &num2); // Convert hexadecimal string n2 to unsigned long long int num2
    
    result = num1 + num2; // Perform addition of num1 and num2
    sprintf(sum, "  %llx", result); // Store the result of addition in hexadecimal format in the sum string

    // Convert the sum to uppercase
    int i;
    for (i = 0; sum[i]; i++) {
        sum[i] = toupper(sum[i]);
    }
}

void printHex(char *n1, char *n2, char *sum) { // Function to print hexadecimal addition in a specific format
    int len = strlen(n1) > strlen(n2) ? strlen(n1) : strlen(n2); // Determine the length of the longer string among n1 and n2
    printf("  %*s\n", len, n1); // Print n1 right-aligned with a width of len
    printf("+ %*s\n", len - strlen(n2), n2); // Print n2 right-aligned with a width of len, aligned below the '+' sign
	int i;
 	for (i = 0; i < len+2; i++) { // Print a line of dashes equal to the length of the longer string
        printf("-");
    }
    printf("\n%*s\n\n", len, sum); // Print the sum right-aligned with a width of len, followed by two newline characters
}

int main() { // Main function
    char n1[MAX_LENGTH], n2[MAX_LENGTH], sum[MAX_LENGTH]; // Declare character arrays to store hexadecimal numbers
    
    while (1) { // Loop until user inputs "0 0"
        scanf("%s %s", n1, n2); // Read two hexadecimal strings from input
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) { // Check if both input strings are "0"
            break; // Exit the loop if input is "0 0"
        }
        
        addHex(n1, n2, sum); // Call function to perform hexadecimal addition
        unsigned long long int result;
        sscanf(sum, "%llx", &result); // Convert sum string to unsigned long long int for comparison
        
        printHex(n1, n2, sum); // Print the input and sum in a specific format
        printf("%llu + %llu = %llu", strtoull(n1, NULL, 16), strtoull(n2, NULL, 16), result); // Print decimal addition
        if (result < strtoull(n1, NULL, 16) || result < strtoull(n2, NULL, 16)) { // Check for overflow
            printf("    ****Overflow!!!\n"); // Print overflow message if detected
        }
    	printf("\n");
    }
    
    return 0;
}

