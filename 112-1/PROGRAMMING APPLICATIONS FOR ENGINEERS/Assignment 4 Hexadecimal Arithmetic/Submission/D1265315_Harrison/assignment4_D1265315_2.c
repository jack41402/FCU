#include <stdio.h>
#include <string.h>

void hex_multiplication(char *n1, char *n2, char *sum, int *word);
void printChar(int n, char c);

void printChar(int n, char c) {
    int i; 
    for (i = 0; i < n; i++) printf("%c", c); 
}

int main(void) {
    int word[130]; 
    int i, j, I;
    int sum2; 
    char n1[20], n2[20], result1[20], result2[20];
    unsigned long long N1 = 0, N2 = 0, z, N;
    
    for (i = 0; i < 10; ++i) word['0' + i] = i; 
    for (i = 0; i < 6; i++) word['A' + i] = 10 + i; 
    
    while (scanf("%s %s", &n1, &n2) == 2 && (strcmp(n1, "0") != 0 || strcmp(n2, "0") != 0)) { //verify 
        char sum[20];
        //initialize the data
        N1 = 0; 
        N2 = 0; 
        z = 0; 
        sum2 = 20; 
        
        for (i = 0; i < 20; i++) result1[i] = '0'; 
        for (i = 0; i < 20; i++) result2[i] = '0'; 
        for (i = 0; i < 20; i++) sum[i] = '0'; 
        
        for (i = strlen(n1) - 1; i >= 0; i--) {
            N = word[n1[i]];
            for (j = 1; j <= z; j++) N = N * 16;
            N1 += N;
            z++;
        } //transfer character to number
        
        z = 0; 
        for (i = strlen(n2) - 1; i >= 0; i--) {
            N = word[n2[i]];
            for (j = 1; j <= z; j++) N = N * 16;
            N2 += N;
            z++;
        } 
        
        for (i = 0; i < strlen(n1); i++) result1[i] = n1[strlen(n1) - 1 - i];
        int flag = 0;
        
        for (i = 0; i < 20; i++) {
            if (result1[i] == '\0') flag = 1;
            if (flag) result1[i] = '0';
        }
        
        for (i = 0; i < strlen(n2); i++) result2[i] = n2[strlen(n2) - 1 - i];
        flag = 0;
        
        for (i = 0; i < 20; i++) {
            if (result2[i] == '\0') flag = 1;
            if (flag) result2[i] = '0';
        } //add 0 
        
        hex_multiplication(result1, result2, sum, word); // do the multiplication
        
        for (i = 19; i >= 0; i--) {
            if (sum[i] == '0') sum2--;
            else break;
        } //calculate sum
        
        if (strlen(n2) == 1 && n2[0] == '0') {
            sum2 = strlen(n1);
        }
        if (strlen(n1) == 1 && n1[0] == '0') {
            sum2 = strlen(n2);
        }
        
        printChar(2 + sum2 - strlen(n1), ' '); 
        for (i = 0; i < strlen(n1); i++) printf("%c", n1[i]);
        printf("\n*");
        printChar(2 + sum2 - strlen(n2) - 1, ' '); 
        for (i = 0; i < strlen(n2); i++) printf("%c", n2[i]);
        printf("\n");
        printChar(2 + sum2, '-');
        printf("\n  ");
        
        if (strlen(n1) == 1 && n1[0] == '0' || strlen(n2) == 1 && n2[0] == '0') {
            printChar(sum2 - 1, ' ');
            printf("0");
        } else {
            for (i = 19 - (20 - sum2); i >= 0; i--) printf("%c", sum[i]);
        }
        
        printf("\n%llu * %llu = %llu", N1, N2, N1 * N2);
        printf("\n\n");
    }
    
    return 0;
}

void hex_multiplication(char *result1, char *result2, char *sum, int *word) {
    char num[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int carry = 0, i, j, z;
    int SUM = 0; 
    char sep_sum[20][40]; 
    
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 40; j++) sep_sum[i][j] = '0'; 
    }
    
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            sep_sum[i][j] = num[(word[result1[j]] * word[result2[i]] + carry) % 16];
            carry = (word[result1[j]] * word[result2[i]] + carry) / 16;
        }
    } //n2 times n1
    
    for (i = 0; i < 20; i++) {
        for (j = 19; j >= 0; j--) sep_sum[i][j] = sep_sum[i][j - i];
        for (z = 0; z < i; z++) sep_sum[i][j] = '0';
    } //place the number
    
    carry = 0; 
    
    for (j = 0; j < 20; j++) {
        for (i = 0; i < 20; i++) {
            if (i == 19) SUM += carry;
            SUM = SUM + word[sep_sum[i][j]];
        } // add up the sum 
        sum[j] = num[SUM % 16]; // transfer number to c
        carry = SUM / 16;
        SUM = 0; 
    }
}

