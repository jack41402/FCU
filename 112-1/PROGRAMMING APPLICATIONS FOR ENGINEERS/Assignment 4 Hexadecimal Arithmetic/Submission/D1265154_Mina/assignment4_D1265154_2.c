#include<stdio.h>
#include<string.h>

int check(char txt[17]);//Checks if the entered number is in hexadecimal format.
int charConvertDec(char c);//Convert a hexadecimal character to its decimal equivalent.
unsigned long long strConvertDec(char txt[17]);//Convert a hexadecimal string to its decimal equivalent, returns a 64-bit unsigned integer.
unsigned long long ex(int, int);// Function prototype to compute a power value

int main(void)
{
	char txt1[17], txt2[17], txt_sum[30];// Declare character arrays to store input and output
	unsigned long long num1, num2, sum, carry = 0, temp;// Declare variables for numerical operations
	int txt1_num, txt2_num;// Declare variables to store input lengths and loop control
	int width, small, ln = 0, rad,i,j;// Declare variables for width, minimum value, loop control, and radix
	while(1)
	{
		do// Loop to validate the first hexadecimal number input
		{
			scanf("%s", txt1);
		}while(check(txt1));// Validate input using the check function
		do// Loop to validate the second hexadecimal number input
		{
			scanf("%s", txt2);
		}while(check(txt2));// Validate input using the check function
		if (strcmp(txt1, "0")==0 && strcmp(txt2, "0")==0) break;// Check if both inputs are zero to break the loop
		txt1_num = strlen(txt1);// Get the length of the first input
		txt2_num = strlen(txt2);// Get the length of the second input
		if(txt1_num>=txt2_num)// Determine the smaller length between the two inputs
		{
			small = txt2_num;
		}
		else
		{
			small = txt1_num;
		}
		for( i = small-1;i >= 0;i--)// Perform multiplication of hexadecimal numbers using loops and conditions
		{
			temp = 0;
			if(small == txt1_num) // Determine which number is smaller and perform multiplication.
			{
				for( j = 0;j < txt2_num ; j++) temp += ex(j, charConvertDec(txt2[txt2_num-j-1])) * charConvertDec(txt1[i]);
				temp += carry;
				carry = 0;
				if(temp >= 16) // Handle carry and update the result array with the appropriate hexadecimal digit
				{
					carry = temp / 16;
					rad = temp%16;
					txt_sum[i] = rad>9 ? rad - 10 + 'A' : rad + '0';
				}
				else
				{
					txt_sum[i] = temp>9 ? temp - 10 + 'A' : temp + '0';
				}
			}
			else// Similar computation for the other scenario of multiplication
			{
				for( j = 0;j < txt1_num ; j++) temp += ex(j, charConvertDec(txt1[txt1_num-j-1])) * charConvertDec(txt2[i]);
				temp += carry;
				carry = 0;
				if(temp >= 16)
				{
					carry = temp / 16;
					rad = temp%16;
					txt_sum[i] = rad>9? rad - 10 + 'A' : rad + '0';
				}
				else
				{
					txt_sum[i] = temp>9 ? temp - 10 + 'A' : temp + '0';
				}
			}
		}
		if(carry)
		{// Loop to handle carry overflow
			ln = 0;
			while(carry >= 16)
			{
				for( i = strlen(txt_sum);i>0;i--) txt_sum[i] = txt_sum[i-1];
				txt_sum[0] = (carry%16)>9 ? (carry%16) - 10 + 'A' : (carry%16) + '0';
				carry = carry / 16;
				ln++;
			}
			if(carry)
			{
				for( i = strlen(txt_sum);i>0;i--) txt_sum[i] = txt_sum[i-1];
				txt_sum[0] = carry>9 ? carry - 10 + 'A' : carry + '0';
				ln++;
			}
			carry = 0;
			txt_sum[small + ln] = '\0';
		}
		else
		{
			txt_sum[small] = '\0';
		}
		width = strlen(txt_sum) + 2 ;
		printf("%*s\n*%*s\n", width, txt1, width-1, txt2);
		for( i = 0;i < width;i++) printf("-");
		printf("\n%*s\n", width, txt_sum);
		num1 = strConvertDec(txt1);
		num2 = strConvertDec(txt2);
		sum = num1 * num2;
		printf("%llu * %llu = %llu", num1, num2, sum);
		if(strlen(txt_sum) > 16) printf("    Overflow!!\n\n");
		else printf("\n\n");
	}
	return 0;
}

int check(char t[17])
{int i;
	for( i = 0;i < strlen(t);i++)
	{
		if(!((t[i]>='0'&&t[i]<='9') || (t[i]>='A'&&t[i]<='F') || (t[i]>='a'&&t[i]<='f')))
		{
			printf("The number entered is not in hexadecimal, please re-enter it.\n");
			return 1;
		}
	}
	return 0;
}

int charConvertDec(char c)
{
	if(c>='0'&&c<='9') return c -'0';
	else if(c>='A'&&c<='F') return c-'A'+10;
	else return c-'a'+10;
}
// Function to convert a hexadecimal string to its decimal equivalent
unsigned long long strConvertDec(char txt[17])
{
	unsigned long long sum = 0, sp;
	int l = strlen(txt),i,j; 
	for( i = l-1;i >= 0;i--)  
	{
		sp = 1;
		for( j = 0;j < (l - 1 - i);j++) sp *= 16;
		sum += charConvertDec(txt[i]) * sp;// Sum the product of each digit and its corresponding power of 16
	}
	return sum;// Return the decimal equivalent of the hexadecimal string
}
// Function to calculate the power of 16
unsigned long long ex(int x, int y)
{	int i;
	unsigned long long sp = 1;
	for( i = 0;i < x;i++) sp *= 16;// Compute power of 16
	return sp*y;// Return the result of 16 raised to the power of x, multiplied by y
}




