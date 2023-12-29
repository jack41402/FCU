#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int add(char num)//when enter a num that data type is char return a int value 
{ 
	if ('0'<= num&& num<= '9')//if num between '0' and '9'(38 to 57), minus'0'(38) to calculate the int num
	{
		num= num- '0';
	}
	else if ('A'<= num&& num<= 'F')//if num between 'A' and 'F'(65 to 70), minus'A'(65) to calculate the int num
	{
		num= num- 'A'+10;
	}
	return num;//return the int num
}

void printchar(int n, char c)// Print n times of character c.
{
	int i;//loop vairable
	for (i=0; i<n; i++)
	{
		printf("%c", c);//print c n times in the data type of char
	}
}

int main(void)
{
	char sign[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};//define a array with all 16 different sign
	int carry=0;//define the initial carry to 0
	char a[18], b[18], c[18], d[18], sum[18];//define six different array. With a(first input string), b(second input string)
	int i, j=0, n;//define loop vairable and vairable for calculation
	unsigned long long k, m,data=1,x=0;// define the varible in the data type of unsigned long long in order to calculate the decimal value
	
	while (1)
	{
		scanf("%s %s",&a,&b);//scan the two input string 
		if (strcmp(a, "0")== 0 && strcmp(b, "0")== 0) break;//vreify if the two array are both zero, if yes, not continue the program
		printf("\n");
		
		for (i=0; i<strlen(a); i++)//reverse the first input string and copy to an another new array c
		{
			c[i]= a[strlen(a)-i-1];
		}
		for (i=0; i<strlen(b); i++)//reverse the second input string and copy to an another new array d
		{
			d[i]= b[strlen(b)-i-1];
		}
		
		for (i=strlen(a); i<=16; i++)//put '0' into the space area of the array c, in order to make strlen(c) to 16
		{
			c[i]= '0';
		}
		for (i=strlen(b); i<=16; i++)//put '0' into the space area of the array d, in order to make strlen(d) to 16
		{
			d[i]= '0';
		}
		
		for (i=0; i<=16; i++)//adder
		{
//			change the char c[i] and char d[i] into int and find the remainder 
//			when it divide by 16. Then, find the corresponding sign of sum[i]
				sum[i]= sign[(add(c[i])+add(d[i])+ carry)%16];
				//calculate the carry by find the quotient when devided by 16
				carry= (add(c[i])+add(d[i])+ carry)/ 16;
				if (i== 15)//pick out the last carry to verify if the result is overflow or not
				{
					n= carry;
				}
		}
		
		j=0;//define the vairable j to 0
		for (i=16; i>=0; i--)//finding how many '0' before the result of the addition
		{
			if (sum[i]=='0')
			{
				j++;
			}
			else 
			{
				break;
			}
		}
		//print the column of the addition
		printchar (17- j- strlen(a)+ 2, ' ');//printing the space before the first string 
		printf("%s", a);//print string a
		printf("\n");//switch to the next line
		printf("+");//print the + sign
		printchar (17- j- strlen(b)+1, ' ');//print the space between + sign and string b
		printf("%s", b);//print string b
		printf("\n");//switch to the next line
		printchar(17-j+2, '-');// print the divide line 
		printf("\n");//switch to the next line
		printchar(2, ' ');//print the space before the addition result
		
		for (i=16-j; i>=0; i--)//print the addition result
		{
			printf("%c", sum[i]);
		}
		printf("\n");//switch to the next line 
		k=0, data=1, x=0;//define the vairable 
		for (i=strlen(a); i>0; i--)//calculate the decimal value of a string
		{
			x=add(a[i-1])*data;//calculate the decimal value of each character of string a
			k+= x;//add all the value of the decimal togeter 
			data*=16;//the value of data need to times 16 every time
		}
		m=0, data=1, x=0;//define the vairable 
		for (i=strlen(b); i>0; i--)//calculate the decimal value of b string
		{
			x=add(b[i-1])*data;//calculate the decimal value of each character of string b
			m+= x;//add all the value of the decimal togeter 
			data*=16;//the value of data need to times 16 every time
		}
		printf("%llu +",k);//print the decimal value of string a
		printf(" %llu =",m);//print the decimal value of string b
		printf(" %llu", k+m);//print the decimal value of string a times string b
		//verify if the result is overflow or not
		if (n!=0)//if the final carry isn't 0, the result will be overflow
		{
			printchar(4, ' ');//print the space before the word overflow
			printf("****Overflow!!!");// print overflow
		}
		printf("\n");//switch to the next line
	}
	return 0;
}
