#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printChar(int n, char c) {
    int i;
    for (i = 0; i < n; i++)
        printf("%c", c);
}

unsigned long long hexa2decimal(char *hexa) {
    unsigned long long decimal = 0;
    int i;
    for (i = 0; i < strlen(hexa); i++) {//Convert hexadecimal to decimal and consider all cases of the representation.
        char c = hexa[i];
        if (c >= '0' && c <= '9') {
            decimal = decimal * 16 + (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            decimal = decimal * 16 + (c - 'A' + 10);
        } 
    }
    return decimal;
}

int main(void) {
    char n1[17], n2[17];
    char sum[18]; 
    int l1, l2;
    int lmax, lmin;
    int carry;
    int d_Sum;
    int i;

    while (scanf("%s %s", n1, n2) == 2) {
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) break;
		
        l1 = strlen(n1);
        l2 = strlen(n2);
        lmax = (l1 > l2) ? l1 : l2;
        lmin = (l1 > l2) ? l2 : l1;
        carry = 0;

        for (i = 0; i < lmax; i++) {
            d_Sum = 0;
            if (i < lmin) {//Plus each digit of n1 and n2
                d_Sum = (n1[l1 - (i + 1)] >= 'A') ? n1[l1 - (i + 1)] - 'A' + 10 : n1[l1 - (i + 1)] - '0';
                d_Sum += (n2[l2 - (i + 1)] >= 'A') ? n2[l2 - (i + 1)] - 'A' + 10 : n2[l2 - (i + 1)] - '0';
            } else if (i < l1) {//In the cases, i exceed the digit that n2 have,so only plus n1.
                d_Sum = (n1[l1 - (i + 1)] >= 'A') ? n1[l1 - (i + 1)] - 'A' + 10 : n1[l1 - (i + 1)] - '0';
            } else if (i < l2) {//In the cases i exceed the digit that n1 have, so only plus n2.
                d_Sum = (n2[l2 - (i + 1)] >= 'A') ? n2[l2 - (i + 1)] - 'A' + 10 : n2[l2 - (i + 1)] - '0';
            }
            d_Sum += carry;//consider the carry issue
            carry = d_Sum / 16;
            d_Sum %= 16;
            sum[lmax - (i + 1)] = (d_Sum <= 9) ? d_Sum + '0' : d_Sum - 10 + 'A';
        }

        if (carry == 1) {// Replace the first bit to carry(if necessary).
            sum[lmax + 1] = '\0';
            for (i = lmax; i > 0; i--)
                sum[i] = sum[i - 1];
            sum[0] = '1';
        } else {
            sum[lmax] = '\0';
        }// Print all calculating process
        printChar(l2 - l1, ' ');
        printChar(carry + 2, ' ');
        printf("%s\n", n1);
        printf("+");
        printChar(l1 - l2, ' ');
        printChar(carry + 1, ' ');
        printf("%s\n", n2);
        printChar(lmax + carry + 2, '-');
        printf("\n  %s\n", sum);
        printf("%llu + %llu = %llu", hexa2decimal(n1), hexa2decimal(n2), hexa2decimal(sum));

        if (strlen(sum) == 17 )// If the lenght of sum exceed 16 digit, print overflow. 
            printf("    ****Overflow!!!\n\n");
        else
            printf("\n\n");
    }
    return 0;
}

