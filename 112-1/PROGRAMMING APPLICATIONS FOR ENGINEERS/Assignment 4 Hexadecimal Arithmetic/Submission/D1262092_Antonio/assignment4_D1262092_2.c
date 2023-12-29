#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(int count, char c) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%c", c);
    }
}

int main() {
    char hex1[17] = {}, hex2[17] = {};
    int length = 0, i;
    int len_hex1 = strlen(hex1), len_hex2 = strlen(hex2);

    while (1) {
        // Get input and verify
        scanf("%s %s", hex1, hex2);
        if (strcmp(hex1, "0") == 0 && strcmp(hex2, "0") == 0)
            break;

        // Get product
        unsigned long long decimal1 = 0, decimal2 = 0;
        sscanf(hex1, "%llx", &decimal1);
        sscanf(hex2, "%llx", &decimal2);
        unsigned long long product = decimal1 * decimal2;
		unsigned long long sum = product;
        // Calculate the length
        length = 0;
        while (1) {
        	length++;
            product = product / 16;
            if (product == 0)
                break;
        }
		sscanf(hex1, "%llX", &decimal1);
		sscanf(hex2, "%llX", &decimal2);
        // Print the output
        printChar(2 + length - strlen(hex1), ' ');
        printf("%s", hex1);
        printf("\n*");
        printChar(1 + length - strlen(hex2), ' ');
        printf("%s", hex2);
        printf("\n");
        printChar(2 + length, '-');
        printf("\n");
        printf("  %llX\n", sum);
        printf("%llu * %llu = %llu", decimal1, decimal2, sum);
        printf("\n\n");
    }
    return 0;
}

