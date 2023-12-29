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
        dec = (c >= '0' && c <= '9') ? dec * 16 + (c - '0') : dec * 16 + (c - 'A' + 10);
    }
    return dec;
}
void dec2hex(unsigned long long dec, char *hex) {
    sprintf(hex, "%llX", dec);
}
void hex_multi(char *n1, char *n2, char *sum) {
    unsigned long long dec_sum;
    dec_sum = hex2dec(n1) * hex2dec(n2);
    dec2hex(dec_sum, sum);
}
int main(void) {
    char n1[9], n2[9];
    char sum[17];
    int numlen1;
    int numlen2;
    int sumlen;
    while (scanf("%s %s", n1, n2) == 2) {
        if(n1[0]=='0'&& n2[0]=='0') break;
        hex_multi(n1,n2,sum);
        numlen1 = strlen(n1);
        numlen2 = strlen(n2);
        sumlen = strlen(sum);
        printChar(2+sumlen-numlen1,' ');
        printf("%s\n*", n1);
        printChar(1+sumlen-numlen2,' ');
        printf("%s\n", n2);
        printChar(2+sumlen,'-');
        printf("\n  %s\n", sum);
        printf("%llu * %llu = %llu", hex2dec(n1), hex2dec(n2), hex2dec(sum));
        printf("\n\n");
    }
    return 0;
}

