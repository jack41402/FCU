#include <stdio.h>
#include <string.h>

void printChar(int n, char c) {
 int i;
 for (i=0; i<n; i++) printf("%c", c);
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

void hexadecimal_addition(char *n1, char *n2, char *sum) {
    unsigned long long l1, l2, carry=0, lmax, lmin, i, a, b, s;
    //a, b, s determine the decimal value of the corresponding digit respectively.
        l1 = strlen(n1);  l2 = strlen(n2);
        lmax = (l1>l2)?l1:l2;  lmin = (l1>l2)?l2:l1;
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
}

void hexadecimal_digit_product(char *n, char d, char *product, int p) {
  unsigned long long leng, carry = 0, d_product, i, a, b, c;
    //a, b, c determine the decimal value of the corresponding digit respectively.
  leng = strlen(n);
  if (d!='0') {
    carry = 0;
    for (i=0; i<leng; i++) {
      a = (n[leng-1-i]>'9')?'7':'0';
      b = (d>'9')?'7':'0';
      d_product = (n[leng-i-1] - a) * (d - b) + carry;
      c = (d_product%16>9)?'7':'0';
      carry = d_product / 16;
      product[leng-i-1] = d_product % 16 + c;
    }
      if (carry!=0){
          for (i=0; i<leng; i++) product[leng-i] = product[leng-i-1];
          d = (carry>9)?'7':'0';
          product[0] = carry + d;
          leng++;
      }
    for (i=0; i<p; i++) product[leng+i] = '0';
    product[leng+p] = '\0';
  }
  else strcpy(product, "0");
}

int main(void) {
    char n1[17], n2[17], product[34], partial_product[34], digit_product[34];
    int l1, l2, leng, i, swap;
    while (scanf("%s %s", n1, n2)==2) {
        if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break;
        l1 = strlen(n1);
        l2 = strlen(n2);
        swap = 0;
        if (l2>l1) {
          swap = 1;
          strcpy(product, n2);
          strcpy(n2, n1);
          strcpy(n1, product);
          i = l2; // Swap l1 and l2 (use i as the temporary memory).
          l2 = l1;
          l1 = i;
      }
        strcpy(product, "0");
        for (i=0; i<l2; i++) {
        strcpy(partial_product, "0");
        hexadecimal_digit_product(n1, n2[l2-i-1], digit_product, i);
        hexadecimal_addition(product, digit_product, partial_product);
        strcpy(product, partial_product);
      }
        leng = strlen(product);
        if (swap) {
          printChar(leng-l2+2, ' ');
          printf("%s\n", n2);
          printf("*");
          printChar(leng-l1+1, ' ');
          printf("%s\n", n1);
        }
        else {
          printChar(leng-l1+2, ' ');
          printf("%s\n", n1);
          printf("*");
          printChar(leng-l2+1, ' ');
          printf("%s\n", n2);
        }
        printChar(leng+2, '-');
        printf("\n  %s\n", product);
        if (swap)
          printf("%llu * %llu = %llu\n\n", hexadecimal(n2), hexadecimal(n1), hexadecimal(product));
        else
          printf("%llu * %llu = %llu\n\n", hexadecimal(n1), hexadecimal(n2), hexadecimal(product));
    }
    return 0;
}
