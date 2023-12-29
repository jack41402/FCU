#include <stdio.h>
#include <string.h>
// Function to convert hexadecimal to decimal
unsigned long long int hexadecimalToDecimal(char hexadecimalNumber[]) {
    long long int decimalNumber = 0;
    int base = 1;
    int length = strlen(hexadecimalNumber);
    int i;

    // Convert each character to decimal
    for (i = 0; i < length; i++) {
    	decimalNumber *= 16;
        if (hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9') {
            decimalNumber += (hexadecimalNumber[i] - '0');
        } else if (hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F') {
            decimalNumber += (hexadecimalNumber[i] - '7');
        }

    }

    return decimalNumber;
}
void printChar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}

// Function to add two hexadecimal numbers
void addHexadecimal(char hexNum1[], char hexNum2[], char result[]) {
    int carry = 0;
    int length1 = strlen(hexNum1);
    int length2 = strlen(hexNum2);
    int maxLength ;
    int i;
    int digit1;
    int digit2;
    if(length1 > length2) {
	maxLength = length1; }
	else {maxLength = length2;}
    // Start from the rightmost digit
    for (i = 0; i < maxLength; i++) {
    	if(i<length1){digit1=hexNum1[length1-i-1];
		}
		else{digit1='0';
		}
		if(i<length2){digit2=hexNum2[length2-i-1];
		}
		else{digit2='0';
		}

        // Get the individual digits from the right
        // Convert hexadecimal digits to decimal
        if (digit1 >= '0' && digit1 <= '9') {
            digit1 = digit1 - '0';
        } else if (digit1 >= 'A' && digit1 <= 'F') {
            digit1 = digit1 - 'A' + 10;
        }

        if (digit2 >= '0' && digit2 <= '9') {
            digit2 = digit2 - '0';
        } else if (digit2 >= 'A' && digit2 <= 'F') {
            digit2 = digit2 - 'A' + 10;
        }

        // Add the digits and the carry
        int sum = digit1 + digit2 + carry;

        // Update the carry
        carry = sum / 16;

        // Update the result string
        result[maxLength - i - 1] = (sum % 16) + ((sum % 16 > 9) ? 'A' - 10 : '0');
    }

    // If there is a final carry, add it to the leftmost digit
    if (carry > 0) {
    	for(i=maxLength ;i>0;--i){
    		result[i]=result[i-1];
		}
        result[0] = carry + ((carry > 9) ? 'A' - 10 : '0');
        result[maxLength+1] = '\0';
    } else {
        result[maxLength] = '\0';
    }
    
    printf("  ");
	printChar(length2-length1, ' ');
	printChar(carry, ' ');
    printf("%s\n", hexNum1);
  	printf("+");
	printChar(length1-length2, ' ');
	printChar(carry, ' ');
	printf(" ");
    printf("%s\n", hexNum2);

    // Perform addition
   printChar(maxLength+carry+2,'-');
   printf("\n");

    // Display the result
   
    printf("  ");
	
    printf("%s",result);
	printf("\n");
        printf("%llu +", hexadecimalToDecimal(hexNum1));
        printf(" %llu = %llu", hexadecimalToDecimal(hexNum2),hexadecimalToDecimal(result));
         if (strlen(result)>16||strlen(result)==16 &&strcmp(result, "FFFFFFFFFFFFFFFF")> 0)
		  printf("    **** Overflow!!!\n\n"); // Check and print overflow message.
    else printf("\n\n"); // Print newline.
	}
   

   


int main() {
    char hexNum1[17];
    char hexNum2[17];
    char result[18];
int length1 = strlen(hexNum1);
    int length2 = strlen(hexNum2);
	int i; // Maximum length of the result is maxLength + 1
	while(1){

    // Input two hexadecimal numbers
  
    scanf("%s", hexNum1);
    scanf("%s", hexNum2);
	if(strcmp (hexNum1,"0")==0&&strcmp (hexNum2,"0")==0) break; 
	

    // Perform addition
   
    addHexadecimal(hexNum1, hexNum2, result);

   
}

    return 0;
}
