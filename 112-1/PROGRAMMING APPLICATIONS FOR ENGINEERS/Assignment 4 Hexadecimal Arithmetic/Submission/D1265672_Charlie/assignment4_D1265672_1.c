#include <stdio.h>
#include <string.h>

// Print n times of character c.
void printChar(int n, char c) {
    int i; // Loop vairable.

    for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

// Convert an hex string to its decimal value.
unsigned long long hex2decimal(char *hex) {
    unsigned long long decimal = 0; // Decimal value initial to 0.
    int i; // Loop variable.
    char symbol;
    for (i=0; i<strlen(hex); i++){
        symbol = (hex[i]>'9')?'7':'0';
        decimal = decimal * 16 + hex[i] - symbol;
    }
    return decimal;
}

int main (void) {
    char n1[17], n2[17];
    char sum[18];
    int l1, l2; // Length of string n1 and n2.
    int lmin, lmax; // lmin=min(l1, l2), lmax=max(l1, l2).
    int carry; // Carry bit.
    int i; // Loop variable.
    char symbol, symbol2, symbol3;

    while (scanf("%s %s", n1, n2)==2) { // Read two binary numbers as 0-1 strings.
        if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break; // If the two numbers are both 0, terminate the program.

        l1 = strlen(n1); // Length of n1.
        l2 = strlen(n2); // Length of n2.
        if (l1>=l2) {lmin = l2; lmax = l1;} // Set lmin and lmax.
        else {lmin = l1; lmax = l2;}
        carry = 0; // Reset the carry to 0.

        for (i=0; i<lmax; i++) {
            symbol = (n1[l1-(i+1)] > '9')?'7':'0'; // set to char
            symbol2 = (n2[l2-(i+1)] > '9')?'7':'0'; // set to char
            if (i<lmin) // Add the i-th digit for both n1 and n2, counting from the left-most digit.
                sum[lmax-(i+1)] = (n1[l1-(i+1)] - symbol) + (n2[l2-(i+1)] - symbol2) + carry;
            else if (i<l1) // n1 is larger than n2, process reset of digit in n1.
                sum[lmax-(i+1)] = (n1[l1-(i+1)] - symbol) + carry;
            else if (i<l2) // n2 is larger than n1, process reset of digit in n2.
                sum[lmax-(i+1)] = (n2[l2-(i+1)] - symbol2) + carry;
            carry = sum[lmax-(i+1)] / 16; // Next carry.
            symbol3 = (sum[lmax-(i+1)] % 16 > 9)?'7':'0'; // set to char
            sum[lmax-(i+1)] = sum[lmax-(i+1)] % 16 + symbol3; // The i-th digit of the sum
        }

        if (carry>=1) {
            sum[lmax+1] = '\0'; // Insert end-of-string, one bit more.
            for (i=lmax; i>0; i--) sum[i] = sum[i-1]; // Move the bits of sum one position to the right.
            sum[0] = carry + '0'; // Put the carry bit to sum.
        }
        else sum[lmax] = '\0'; // Insert end-of-string.
        
        carry = (carry!=0)?1:0; //if carry print one more space.
        printChar(l2-l1, ' '); // If n2 is longer than n1, print blanks.
        printChar(carry+2, ' '); // Print 2 or 3 blanks depending on carry.
        printf("%s\n", n1); // Print n1.
        printf("+"); // Print "+" sign.
        printChar(l1-l2, ' '); // If n1 is longer than n2, print blanks.
        printChar(carry+1, ' '); // Print 1 or 2 blanks depending on carry.
        printf("%s\n", n2); // Print n2.
        printChar(lmax+carry+2, '-'); // Print separate line.
        printf("\n  %s\n", sum); // Print two blanks and the sum.
        printf("%llu + %llu = %llu", hex2decimal(n1), hex2decimal(n2), hex2decimal(sum));

        if (strlen(sum)>16) printf("    ****Overflow!!!\n\n");
        else printf("\n\n"); // Print newline.
    }
    return 0;
}
