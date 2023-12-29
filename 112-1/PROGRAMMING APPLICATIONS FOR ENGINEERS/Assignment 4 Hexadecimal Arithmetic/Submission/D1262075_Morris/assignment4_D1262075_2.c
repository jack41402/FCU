#include <stdio.h>
#include <string.h>

void printChar(int n, char c) {
    int i;
	for (i = 0; i < n; i++)
        printf("%c", c);
}

unsigned long long hexa2decimal(char *hexa) {//Convert hexadecimal to decimal and consider all cases of the representation.
    unsigned long long decimal = 0;
    int i;
	for (i = 0; i < strlen(hexa); i++) {
        char c = hexa[i];
        if (c >= '0' && c <= '9') {
            decimal = decimal * 16 + (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            decimal = decimal * 16 + (c - 'A' + 10);
        } 
    }
    return decimal;
}
//use 'sprintf' function to represent the number string converted from decimal number to hexadecimal's.
void decimal2hexa(unsigned long long decimal, char *hexa) {
    sprintf(hexa, "%llX", decimal);
}
//first convert two hexadecimal strings to decimal and multiply them, and convert the result back to hexadecimal representation.
void hexamulti(char *n1, char *n2, char *result) {
    unsigned long long decimal_result;
    decimal_result = hexa2decimal(n1) * hexa2decimal(n2);
	decimal2hexa(decimal_result, result);
}

int main(void) {
    char n1[17], n2[17];
    char result[34]; 
	int l1;
	int l2;
	int l3;
    while (scanf("%s %s", n1, n2) == 2) {
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) break;
        
		hexamulti(n1, n2, result);
        
		l1 = strlen(n1);
        l2 = strlen(n2);
        l3 = strlen(result);
        //print all the calculating process
        printChar(2+l3-l1, ' ');
        printf("%s\n*", n1);
        printChar(1+l3-l2, ' ');
        printf("%s\n", n2);
        printChar(2+l3, '-');
        printf("\n  %s\n", result);
        printf("%llu * %llu = %llu", hexa2decimal(n1), hexa2decimal(n2), hexa2decimal(result));
        printf("\n\n");
    }
    return 0;
}

