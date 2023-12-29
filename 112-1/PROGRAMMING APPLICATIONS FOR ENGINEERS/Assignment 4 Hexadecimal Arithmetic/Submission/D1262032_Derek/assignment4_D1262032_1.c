#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printChar(int n,char c){
    int i;
    for(i=0;i<n;i++) printf("%c", c);
}

unsigned long long hexadecimal(char *hexadecimal) {
    //hexadecimal to decimal
    unsigned long long decimal = 0, length, a;
    //a determines the decimal value of the corresponding digit.
    int i;
    for (i=0; i<strlen(hexadecimal)-1; i++){
        length = strlen(hexadecimal);
        a=(hexadecimal[i]>='A')?hexadecimal[i]-'7':hexadecimal[i]-'0';
        decimal = 16 * (decimal+a);
    }
    a=(hexadecimal[i]>='A')?hexadecimal[i]-'7':hexadecimal[i]-'0';
    decimal = decimal+a;
        return decimal;
}

int main(void){
    char n1[17], n2[17], sum[18];
    int l1, l2, carry=0, lmax, lmin, i, a, b, s;
    //a, b, s determine the decimal value of the corresponding digit respectively.
    while(scanf("%s %s", n1, n2)==2){
        if(strcmp(n1,"0")==0 && strcmp(n2,"0")==0) break;
        l1 = strlen(n1);
        l2 = strlen(n2);
        lmax = (l1>l2)?l1:l2;
        lmin = (l1>l2)?l2:l1;
        carry = 0 ;
        for(i=0; i<lmax; i++){
            a = (n1[l1-1-i]>'9')?'7':'0';
            b = (n2[l2-1-i]>'9')?'7':'0';
            if(i<lmin)
            sum[lmax-i-1] = (n1[l1-1-i]-a) + (n2[l2-1-i]-b) + carry;
            else if(i<l1) sum[lmax-i-1] = (n1[l1-1-i]-a) + carry;
            else if(i<l2) sum[lmax-i-1] = (n2[l2-1-i]-b) + carry;
            carry = sum[lmax-i-1] / 16;
            s = (sum[lmax-i-1]%16>9)?'7':'0';
            sum[lmax-i-1] = sum[lmax-i-1] % 16 + s;
        }
        if(carry==1){
            sum[lmax+1] = '\0';
            for(i=lmax; i>0; i--) sum[i] = sum[i-1];
            sum[0] = '1';
        }
        else sum[lmax] = '\0';
        printChar(l2-l1, ' ');
        printChar(carry+2, ' ');
        printf("%s\n+", n1);
        printChar(l1-l2, ' ');
        printChar(carry+1, ' ');
        printf("%s\n", n2);
        printChar(carry+lmax+2, '-');
        printf("\n  %s\n", sum);
        printf("%llu + %llu = %llu", hexadecimal(n1), hexadecimal(n2), hexadecimal(sum));
        if (strlen(sum) > 16 || (strlen(sum) == 16 && strcmp(sum, "FFFFFFFFFFFFFFFF") > 0))
            printf("    ****Overflow!!!\n\n");
        else printf("\n\n");
    }
    return 0;
}

