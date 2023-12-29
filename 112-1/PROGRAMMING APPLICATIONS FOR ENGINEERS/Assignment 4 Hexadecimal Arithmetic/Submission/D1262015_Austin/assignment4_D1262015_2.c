#include <stdio.h>
#include <string.h>

void printChar(int n, char c) {
    for (int i = 0; i < n; i++)
        printf("%c", c);
}

unsigned long long convertHexaToDecimal(char *hexa) {
    unsigned long long decimal = 0;
    for (int i = 0; i < strlen(hexa); i++) {
        char c = hexa[i];
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
            decimal = decimal * 16 + (c - (c >= 'A' ? 'A' - 10 : '0'));
        } else {
            printf("Invalid hexadecimal input: %c\n", c);
            
            return 0;
        }
    }
    return decimal;
}

void convertDecimalToHexa(unsigned long long decimal, char *hexa) {
    sprintf(hexa, "%llX", decimal);
}

void multiplyHexaNumbers(char *n1, char *n2, char *result) {
    unsigned long long decimalResult = convertHexaToDecimal(n1) * convertHexaToDecimal(n2);
    convertDecimalToHexa(decimalResult, result);
}

void printMultiplicationResult(char *n1, char *n2, char *result) {
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int lResult = strlen(result);

    printChar(2 + lResult - l1, ' ');
    printf("%s\n", n1);

    printf("*");
    printChar(1 + lResult - l2, ' ');
    printf("%s\n", n2);

    printChar(2 + lResult, '-');
    printf("\n  ");
    printf("%s\n\n", result);

    printf("%llu * %llu = %llu\n\n", convertHexaToDecimal(n1), convertHexaToDecimal(n2), convertHexaToDecimal(result));
}

int main(void) {
    char n1[17], n2[17];
    char result[34];

    printf("Enter two hexadecimal numbers (or '0 0' to exit): ");
    while (scanf("%s %s", n1, n2) == 2) {
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) break;

        multiplyHexaNumbers(n1, n2, result);
        printMultiplicationResult(n1, n2, result);

        printf("Enter two hexadecimal numbers (or '0 0' to exit): ");
    }

    return 0;
}

