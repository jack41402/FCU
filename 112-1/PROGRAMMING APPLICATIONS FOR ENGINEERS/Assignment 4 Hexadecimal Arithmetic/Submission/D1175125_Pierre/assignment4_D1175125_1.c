
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printChar(int n, char c) {
    int i;
    for (i = 0; i < n; i++)
        printf("%c", c);
}
unsigned long long hex2dec(char *hex) {
    unsigned long long dec = 0;
    int i;
    char c;
    for (i = 0; i < strlen(hex); i++) {
        c = hex[i];
        dec = (c >= '0' && c <= '9') ? dec * 16 + (c - '0') : dec * 16 + (c - 'A' + 10);
    }
    return dec;
}
int main(void) {
    char n1[17], n2[17];
    char sum[18];
    int numlen1, numlen2;
    int lenmax, lenmin;
    int carry;
    int d_sum;
    int i;
    while (scanf("%s %s", n1, n2) == 2) {
        if (n1[0]=='0'&& n2[0]=='0') break;
        numlen1 = strlen(n1);
        numlen2 = strlen(n2);
        lenmax = (numlen1 > numlen2) ? numlen1 : numlen2;
        lenmin = (numlen1 > numlen2) ? numlen2 : numlen1;
        carry = 0;
        for (i = 0; i < lenmax; i++) {
            d_sum = 0;
            if (i < lenmin) {
                d_sum = (n1[numlen1 - (i + 1)] >= 'A') ? n1[numlen1 - (i + 1)] - 'A' + 10 : n1[numlen1 - (i + 1)] - '0';
                d_sum += (n2[numlen2 - (i + 1)] >= 'A') ? n2[numlen2 - (i + 1)] - 'A' + 10 : n2[numlen2 - (i + 1)] - '0';
            } else if (i < numlen1) {
                d_sum = (n1[numlen1 - (i + 1)] >= 'A') ? n1[numlen1 - (i + 1)] - 'A' + 10 : n1[numlen1 - (i + 1)] - '0';
            } else if (i < numlen2) {
                d_sum = (n2[numlen2 - (i + 1)] >= 'A') ? n2[numlen2 - (i + 1)] - 'A' + 10 : n2[numlen2 - (i + 1)] - '0';
            }
            d_sum += carry;
            carry = d_sum / 16;
            d_sum %= 16;
            sum[lenmax - (i + 1)] = (d_sum <= 9) ? d_sum + '0' : d_sum - 10 + 'A';
        }
        if (carry == 1) {
            sum[lenmax + 1] = '\0';
            for (i = lenmax; i > 0; i--)
                sum[i] = sum[i - 1];
            sum[0] = '1';
        } else {
            sum[lenmax] = '\0';
        }
        printChar(numlen2 - numlen1, ' ');
        printChar(carry + 2, ' ');
        printf("%s\n", n1);
        printf("+");
        printChar(numlen1 - numlen2, ' ');
        printChar(carry + 1, ' ');
        printf("%s\n", n2);
        printChar(lenmax + carry + 2, '-');
        printf("\n  %s\n", sum);
        printf("%llu + %llu = %llu", hex2dec(n1), hex2dec(n2), hex2dec(sum));
        if (strlen(sum) == 17 )
            printf("    ****Overflow!!!\n\n");
        else
            printf("\n\n");
    }
    return 0;
}

