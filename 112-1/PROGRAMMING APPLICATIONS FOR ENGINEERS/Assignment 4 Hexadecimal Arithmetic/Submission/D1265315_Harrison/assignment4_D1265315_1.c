#include <string.h>
#include <stdio.h>
#include <math.h>

int hexmultipication(char n1[], char n2[], char finalproduct[], int counta, int countb) {
    int i, j, b, a, result, finalresult, finalsum;
    int carry = 0, zeronumber = 0, sum = 0, newcarry = 0, leadingzero = 0, countp = 0;
    char p[10][20];
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) 
            p[i][j] = 0;
    }
    
    for (i = 0; i < 10; i++) {
        for (a = 0; a < zeronumber; a++) 
            p[i][a] = 0;
        
        for (j = 0; j < 20; j++) {
            result = n1[j] * n2[i] + carry;
            finalresult = result % 16;
            carry = result / 16;
            p[i][j + zeronumber] = finalresult;
        }
        zeronumber++;
    }

    for (i = 0; i < 20; i++) {
        sum = 0;
        for (j = 0; j < countb; j++) 
            sum = sum + p[j][i];
        
        sum = sum + newcarry;
        finalsum = sum % 16;
        newcarry = sum / 16;
        finalproduct[i] = finalsum;	
    }
    
    for (i = 19; i >= 0; i--) {
        if (finalproduct[i] == 0) 
            leadingzero++;
        else 
            break;
    }
    countp = 20 - leadingzero;
    return countp;
}

void hextodec(char hex[], int hexlength) {
    int i;
    for (i = 0; i < hexlength; i++) {
        if (hex[i] - '0' < 10) 
            hex[i] = hex[i] - '0';
        else 
            hex[i] = hex[i] - 'A' + 10;
    }
}

void hexdigitoutput(char hex[], char newhex[], int hexlength) {
    int i;
    for (i = 0; i < hexlength; i++) {
        if (hex[i] < 10) 
            newhex[i] = hex[i] + '0';
        else 
            newhex[i] = hex[i] - 10 + 'A';
    }
}

unsigned long long hextodecimal(char hex[], int hexlength) {
    int i;
    unsigned long long decimal = 0;
    for (i = 0; i < hexlength; i++) {
        if (hex[i] - '0' < 10) 
            hex[i] = hex[i] - '0';	
        else 
            hex[i] = hex[i] - 'A' + 10;
        
        decimal = (decimal << 4) + hex[i];
    }
    return decimal;
}

int main(void) {
    int i, counta, countb, countprd, lmax;
    unsigned long long decimal1, decimal2, decimalproduct;
    char n1[20], n2[20], inverse1[20], inverse2[20], product[20];
    char newproduct[20];
    
    while (1) {
        if (scanf("%s %s", n1, n2) != 2) 
            break;
        
        if (strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) 
            break;
        
        for (i = 0; i < 20; i++) 
            newproduct[i] = 0;
        
        for (i = 0; i < 20; i++) 
            product[i] = 0;
        
        for (i = counta; i < 20; i++) 
            inverse1[i] = 0;
        
        for (i = countb; i < 20; i++) 
            inverse2[i] = 0;
        
        counta = strlen(n1);
        countb = strlen(n2);
        
        if (counta >= countb) 
            lmax = counta;
        else 
            lmax = countb;
        
        for (i = counta; i > 0; i--) 
            inverse1[counta - i] = n1[i - 1];
        
        for (i = countb; i > 0; i--) 
            inverse2[countb - i] = n2[i - 1];
        
        hextodec(inverse1, counta);
        hextodec(inverse2, countb);
        
        countprd = hexmultipication(inverse1, inverse2, product, counta, countb);
        
        if (strcmp(n1, "0") == 0 || strcmp(n2, "0") == 0) 
            countprd = 1;
        
        hexdigitoutput(product, newproduct, countprd);
        
        if (countprd > lmax) 
            lmax = countprd;
        else 
            lmax = lmax;
        
        for (i = 0; i < (lmax - counta + 2); i++) 
            printf(" ");
        
        printf("%s\n", n1);
        printf("*");
        
        for (i = 0; i < (lmax - countb + 1); i++) 
            printf(" ");
        
        printf("%s\n", n2);
        
        for (i = 0; i < (lmax + 2); i++) 
            printf("-");
        
        printf("\n");
        
        for (i = 0; i < (lmax - countprd + 2); i++) 
            printf(" ");
        
        if (strcmp(n1, "0") == 0 || strcmp(n2, "0") == 0) 
            printf("0");
        else {
            for (i = (countprd - 1); i >= 0; i--) 
                printf("%c", newproduct[i]);
        }
        
        printf("\n");
        
        decimal1 = hextodecimal(n1, counta);
        decimal2 = hextodecimal(n2, countb);
        decimalproduct = decimal1 * decimal2;
        printf("%llu * %llu = %llu\n", decimal1, decimal2, decimalproduct);
    }
    return 0;
}
