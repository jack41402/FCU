

#include<stdio.h>
#include<string.h>

int check(char txt[17]); //Checks if the entered number is in hexadecimal format.
int charConvertDec(char c); //Convert a hexadecimal character to its decimal equivalent.
unsigned long long strConvertDec(char txt[17]); //Convert a hexadecimal string to its decimal equivalent, returns a 64-bit unsigned integer.

int main(void)
{
    char txt1[17], txt2[17], txt_sum[17]; // Declaration of character arrays to store input and result.
    unsigned long long num1, num2, sum; // Declaration of variables to store decimal representations and their sum.
    int txt1_num, txt2_num, i; // Declaration of variables for string lengths and loop counters.
    int carry = 0, temp, width, big, gap; // Declaration of variables for carrying values in addition, temporary storage, and formatting.

    while(1) // Infinite loop for continuous input and processing.
    {
        do
        {
            scanf("%s", txt1); // Input the first hexadecimal number and validate using the check function.
        } while(check(txt1));

        do
        {
            scanf("%s", txt2); // Input the second hexadecimal number and validate using the check function.
        } while(check(txt2));

        if (strcmp(txt1, "0") == 0 && strcmp(txt2, "0") == 0) break; // If both input numbers are "0", exit the infinite loop and end the program.

        txt1_num = strlen(txt1); // Calculate the length of the first input string.
        txt2_num = strlen(txt2); // Calculate the length of the second input string.

        if(txt1_num >= txt2_num)
        {
            big = txt1_num;
            gap = txt1_num - txt2_num;
        }
        else
        {
            big = txt2_num;
            gap = txt2_num - txt1_num;
        }
        // Determine the larger input string and the gap in lengths between the two strings.

        for(i = big-1; i >= 0; i--) // Loop through each position from the highest digit to the lowest digit.
        {
            if(i > gap-1) // Check if both input numbers have digits at this position.
            {
                if(big == txt1_num)
                {
                    temp = charConvertDec(txt1[i]) + charConvertDec(txt2[i-gap]) + carry; // Perform addition of digits at the current position.
                    carry = 0; // Reset carry for the next iteration.

                    if(temp >= 16)
                    {
                        carry = temp / 16; // Calculate the carry for the next position.
                        txt_sum[i] = temp - 16 > 9 ? temp - 16 - 10 + 'A' : temp - 16 + '0'; // Convert the sum to ASCII representation.
                    }
                    else
                    {
                        txt_sum[i] = temp > 9 ? temp - 10 + 'A' : temp + '0'; // Convert the sum to ASCII representation.
                    }
                }
                else
                {
                    temp = charConvertDec(txt1[i-gap]) + charConvertDec(txt2[i]) + carry; // Perform addition of digits at the current position.
                    carry = 0; // Reset carry for the next iteration.

                    if(temp >= 16)
                    {
                        carry = temp / 16; // Calculate the carry for the next position.
                        txt_sum[i] = temp - 16 > 9 ? temp - 16 - 10 + 'A' : temp - 16 + '0'; // Convert the sum to ASCII representation.
                    }
                    else
                    {
                        txt_sum[i] = temp > 9 ? temp - 10 + 'A' : temp + '0'; // Convert the sum to ASCII representation.
                    }
                }
            }
            else
            {
                if(big == txt1_num)
                {
                    temp = charConvertDec(txt1[i]) + carry; // Perform addition of digits at the current position.
                    carry = 0; // Reset carry for the next iteration.

                    if(temp >= 16)
                    {
                        carry = temp / 16; // Calculate the carry for the next position.
                        txt_sum[i] = temp - 16 > 9 ? temp - 16 - 10 + 'A' : temp - 16 + '0'; // Convert the sum to ASCII representation.
                    }
                    else
                    {
                        txt_sum[i] = temp > 9 ? temp - 10 + 'A' : temp + '0'; // Convert the sum to ASCII representation.
                    }
                }
                else
                {
                    temp = charConvertDec(txt2[i]) + carry; // Perform addition of digits at the current position.
                    carry = 0; // Reset carry for the next iteration.

                    if(temp >= 16)
                    {
                        carry = temp / 16; // Calculate the carry for the next position.
                        txt_sum[i] = temp - 16 > 9 ? temp - 16 - 10 + 'A' : temp - 16 + '0'; // Convert the sum to ASCII representation.
                    }
                    else
                    {
                        txt_sum[i] = temp > 9 ? temp - 10 + 'A' : temp + '0'; // Convert the sum to ASCII representation.
                    }
                }
            }
        }

        if(carry)
        {
            for(i = strlen(txt_sum); i > 0; i--) txt_sum[i] = txt_sum[i-1]; // Shift all elements in the array to the right.
            txt_sum[0] = carry + '0'; // Assign the carry to the first position.
            txt_sum[big+1] = '\0'; // Null-terminate the string.
            carry = 0; // Reset carry.
        }
        else
        {
            txt_sum[big] = '\0'; // Null-terminate the string.
        }

        width = strlen(txt_sum) + 2; // Calculate the width for formatting.

        printf("%*s\n+%*s\n", width, txt1, width-1, txt2); // Print the formatted addition.
        for(i = 0; i < width; i++) printf("-"); // Print the horizontal line.
        printf("\n%*s\n", width, txt_sum); // Print the result.
        num1 = strConvertDec(txt1); // Convert the first input to decimal.
        num2 = strConvertDec(txt2); // Convert the second input to decimal.
        sum = num1 + num2; // Calculate the sum.
        printf("%llu + %llu = %llu", num1, num2, sum); // Print the decimal representation and sum.
        if(strlen(txt_sum) > 16) printf("    Overflow!!\n\n"); // Check for overflow and print a warning if necessary.
        else printf("\n\n"); // Print newline characters for formatting.
    }

    return 0; // Return 0 to indicate successful execution.
}

int check(char t[17])
{
    int i;
    for(i = 0; i < strlen(t); i++)
    {
        if (!((t[i] >= '0' && t[i] <= '9') || (t[i] >= 'A' && t[i] <= 'F') || (t[i] >= 'a' && t[i] <= 'f')))
        {
            printf("The number entered is not in hexadecimal, please re-enter it.\n"); // Display error message for invalid input.
            return 1; // Return 1 to indicate input validation failure.
        }
    }
    return 0; // Return 0 to indicate successful input validation.
}

int charConvertDec(char c) // Function to convert a hexadecimal character to its decimal equivalent.
{
    if(c >= '0' && c <= '9') return c - '0'; // If the character is a digit, convert to decimal.
    else if(c >= 'A' && c <= 'F') return c - 'A' + 10; // If the character is an uppercase letter A-F, convert to decimal.
    else return c - 'a' + 10; // If the character is a lowercase letter a-f, convert to decimal.
}

unsigned long long strConvertDec(char txt[17]) // Function to convert a hexadecimal string to its decimal equivalent.
{
    unsigned long long sum = 0, sp; // Initialize variables to store the sum and positional weight.
    int l = strlen(txt), j, i; // Get the length of the string and declare loop counters.

    for(i = l-1; i >= 0; i--) // Loop through each position from the highest digit to the lowest digit.
    {
        sp = 1; // Initialize positional weight as 1 for the rightmost digit.

        for(j = 0; j < (l - 1 - i); j++) sp *= 16; // Calculate the positional weight for the current digit.

        sum += charConvertDec(txt[i]) * sp; // Convert the digit to decimal and add it to the running sum.
    }

    return sum; // Return the final decimal sum.
}




