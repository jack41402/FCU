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
void hex_dec(char*number, int *num) // turn all the hexadecimal character in char array[] to a digit and store it in an int array[]
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
void addition(int *num1, int *num2, int *sum)// calculate the sum of two input numbers
{
	int len1 = length(num1);
	int len2 = length(num2);
	int lenmin, lenmax, flag = 0;
	if(len1>len2)
	{
		lenmax = len1;
		lenmin = len2;
		flag = 1;
	}
	else
	{
		lenmax = len2;
		lenmin = len1;
	}
	int j, carry = 0;
	for(j=0; j<lenmin; ++j)
	{
		int temp_sum = num1[j] + num2[j] + carry;
        sum[j] = temp_sum % 16;
        carry = temp_sum / 16;
	}
	for(j=lenmin; j<lenmax; ++j)
	{
		if(flag)
		{
			int temp_sum = num1[j] + carry;
			 sum[j] = temp_sum % 16;
        	carry = temp_sum / 16;
		}
		else
		{
			int temp_sum = num2[j] + carry;
			 sum[j] = temp_sum % 16;
        	carry = temp_sum / 16;
		}
	}
	sum[lenmax] = carry;
	if(sum[lenmax] == 0) 	sum[lenmax] = 999;
	else sum[lenmax+1] = 999;
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
	int sum[65] = {};
	while (scanf("%s %s", n1, n2)==2) { // Read two binary numbers as 0-1 strings.
  	if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break;// If the two numbers are both 0, terminate the program.
	inverse(n1);// call out the inverse function to inverse the characters of n1
	inverse(n2);// call out the inverse function to inverse the characters of n2
	hex_dec(n1, n3);// turn the hexadecimal character of n1 to a digit and store in n3
	hex_dec(n2, n4);// turn the hexadecimal character of n2 to a digit and store in n4
	addition(n3, n4, sum);// do the calculation
	inverse(n1);
	inverse(n2);
	int i;
	int lensum = length(sum);
	int len_n3 = length(n3);
	int len_n4 = length(n4);
	for(i = 0; i < lensum - len_n3 + 2; ++i)// print the space before n1
		printf(" ");
	printf("%s", n1);
	printf("\n+");
	for(i = 0; i < lensum - len_n4 + 1; ++i)// print the space before n2
		printf(" ");
	printf("%s\n", n2);
	for(i = 0; i < lensum + 2; ++i)// print the seperate line
		printf("-");
	printf("\n  ");// print the space befor sum
	for(i=lensum-1; i>=0; --i)// print the hexadecimal of sum
	{
		printf("%X", sum[i]);
	}
	printf("\n");
	printf("%llu + %llu = %llu", decimal(n1), decimal(n2), decimal(n1) + decimal(n2));// verify correctness of the sum using decimal addition
	if(lensum>16) printf("    ****Overflow!!!");// check and print overflow message.
	printf("\n\n");
	}			
	return 0;
}