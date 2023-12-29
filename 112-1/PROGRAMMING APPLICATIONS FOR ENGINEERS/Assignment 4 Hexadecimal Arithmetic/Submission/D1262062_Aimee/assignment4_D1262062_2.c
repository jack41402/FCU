# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
void inverse(char*number)// inverse the characters of the input 
{
	int length = strlen(number);
	int i, j, tmp;
	for(i = 0, j = length-1; i<j; ++i, --j)// Move to the next character and continue the process untill all the characters have been inversed.
	{
		tmp = number[i];// exchange the characters between number[i] and number[(length of the number)-1] 
		number[i] = number[j];
		number[j] = tmp;
	}
}
void hex_dec(char*number, int *num)// turn all the hexadecimal character in char array[] to a digit and store it in an int array[]
{
	int length = strlen(number);
	int i;
	for(i=0; i<length; ++i)
	{
		if (number[i] >= '0' && number[i] <= '9')
            num[i] = number[i] - '0';
        else
            num[i] = number[i] - 'A' + 10;
	}
	num[length] = 999;
}
int length(int *num)// count the length of an array[]
{
	int count = 0;
	int i;
	for (i=0; num[i] != 999; ++i)
	{
		count++;
	}
	return count;
}
void multiplication(int *num1, int *num2, int *result)// calculate the product of two input numbers
{
    int len1 = length(num1);
    int len2 = length(num2);
	int i, j;
	for (i = 0; i < len1 + len2; ++i) result[i] = 0;
	for (i = 0; i < len1; ++i) 
	{
        for (j = 0; j < len2; ++j) 
		{
            result[i + j] += num1[i] * num2[j];
            result[i + j + 1] += result[i + j] / 16;
            result[i + j] %= 16;
        }
    }
	if(result[len1 + len2 -1] == 0) result[len1 + len2 - 1] = 999;
	else result[len1 + len2] = 999;
}
unsigned long long decimal(char *num)// Convert a binary string to its decimal value.
{
	unsigned long long decimal = 0;
	int i;
	for(i=0; i<strlen(num); ++i) 
	{
		if(num[i] >= '0' && num[i] <= '9') decimal = decimal*16 + num[i] - '0';
		else decimal = decimal*16 + num[i] - 'A' + 10;
	}
	return decimal;
}
int main(void)
{
	char n1[65], n2[65];
	int n3[65] = {};
	int n4[65] = {};
	int result[65] = {};
	while (scanf("%s %s", n1, n2)==2) { // Read two binary numbers as 0-1 strings.
  	if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break;// If the two numbers are both 0, terminate the program.
	inverse(n1);// call out the inverse function to inverse the characters of n1
	inverse(n2);// call out the inverse function to inverse the characters of n2
	hex_dec(n1, n3);// turn the hexadecimal character of n1 to a digit and store in n3
	hex_dec(n2, n4);// turn the hexadecimal character of n2 to a digit and store in n4
	multiplication(n3, n4, result);// do the multiplication
	inverse(n1);
	inverse(n2);
	int i;
	int lenresult = length(result);
	int len_n3 = length(n3);
	int len_n4 = length(n4);
	for(i = 0; i < lenresult - len_n3 + 2; ++i)// print the space before n1 
		printf(" ");
	printf("%s", n1);
	printf("\n*");
	for(i = 0; i < lenresult - len_n4 + 1; ++i)// print the space before n2 
		printf(" ");
	printf("%s\n", n2);
	for(i = 0; i < lenresult + 2; ++i)// print the seperate line
		printf("-");
	printf("\n  ");// print the space befor product
	for(i=lenresult-1; i >= 0; --i)// print the hexadecimal of product
	{
		printf("%X", result[i]);
	}
	printf("\n");
	printf("%llu * %llu = %llu", decimal(n1), decimal(n2), decimal(n1)*decimal(n2));// verify correctness of the product using decimal multiplication
	printf("\n\n");
	}			
	return 0;
}
