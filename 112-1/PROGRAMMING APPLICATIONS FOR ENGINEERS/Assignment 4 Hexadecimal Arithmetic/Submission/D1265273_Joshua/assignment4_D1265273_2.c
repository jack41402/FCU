#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int change(char num)//A function that change char to int
{ 
	if ('0'<= num&& num<= '9')//if num between '0' and '9'(38 to 57), minus'0'(38) to calculate the int num
	{
		num= num- '0';
	}
	else if ('A'<= num&& num<= 'F')//if num between 'A' and 'F'(65 to 70), minus'A'(65) to calculate the int num
	{
		num= num- 'A'+10;
	}
	return num;
}

void reverse (char *g, char *r)//A function that reverse the input string
{
	int i;//define the loop vairable
	for (i=0; i<strlen(g); i++)//reverse the input string and copy to an another new array 
		{
			r[i]= g[strlen(g)-i-1];
		}
}

void con (char *re)//A function that compensate the space in the array with '0'
{
	int i;//define loop vairable
	for (i=strlen(re); i<=19; i++)//put '0' into the space area of the input array , in order to make string length to 16
		{
			re[i]= '0';
		}
}

void printchar(int n, char c)// Print n times of character c.
{
	int i;//define loop vairable
	for (i=0; i<n; i++)
	{
		printf("%c", c);//print c n times in the data type of char
	}
}


int main(void)
{
	char sign[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};//define a array with all 16 different sign
	char a[20], b[20], c[20], d[20], sum[30];//define six different array. With a(first input string), b(second input string)
	char partical_product[20][20], partical_product_2[20][20];//define two two dimensional array for calculation
	int i, j, carry, k;//define loop vairable and vairable for calculation
	int l1, l2, lmax, lmin, sum_2[20];//define the vairable for the string length
	unsigned long long m, data, x, n;// define the varible in the data type of unsigned long long in order to calculate the decimal value
	
	while(1)
	{
		for(i=0;i<20;i++) c[i]=0;//initialization for the array c
		for(i=0;i<20;i++) d[i]=0;//initialization for the array d
		for(i=0;i<20;i++) sum_2[i]=0;//initialization for the array sum_2
		for (i=0; i<20; i++)//initialization for the array partical_product
		{
			for (j=0; j<20; j++)
			{
				partical_product[i][j]=0;
			}
		}
		for (i=0; i<20; i++)//initialization for the array partical_product_2
		{
			for (j=0; j<20; j++)
			{
				partical_product_2[i][j]=0;
			}
		}
		scanf("%s %s", &a, &b);//scan the input string
		if (strcmp(a, "0")== 0 && strcmp(b, "0")== 0) break;//vreify if the two array are both zero, if yes, not continue the program
		reverse (a, c);//reverse the input string a
		reverse (b, d);//reverse the inpyt string b
		con (c);//put '0' into the space area of the array c
		con (d);//put '0' into the space area of the array d,
		l1= strlen(a);//calculate the string length of string a
		l2= strlen(b);//calculate the string length of string a
		if (l1>=l2)//define the value of lmax and lmin
		{
			lmax= l1, lmin= l2;//if l1>=l2, l1 is the value of lmax
		}
		else 
		{
			lmax= l2, lmin= l1;//if l1<l2, l2 is the value of lmax
		} 
		if (l1>=l2)
		{
			for(i=0; i<8; i++)//Multiplier
			{
				for (j=0; j<9; j++)
				{
//			change the char c[i] and char d[i] into int and find the remainder 
//			when it divide by 16. Then, find the corresponding sign of sum[i] and copy to the array partical_product
					partical_product[i][j]= sign[(change(c[j])*change(d[i])+carry)%16];
					//calculate the carry by find the quotient when devided by 16
					carry= (change (c[j])* change (d[i])+carry)/16;
				}
				carry=0;//define the carry into 0 whenever i+1
			}
		}
		else 
		{
			for(i=0; i<8; i++)
			{
				for (j=0; j<9; j++)
				{
//			change the char c[i] and char d[i] into int and find the remainder 
//			when it divide by 16. Then, find the corresponding sign of sum[i] and copy to the array partical_product
					partical_product[i][j]= sign[(change(c[i])*change(d[j])+carry)%16];
					//calculate the carry by find the quotient when devided by 16
					carry= (change (c[i])* change (d[j])+carry)/16;
				}
				carry=0;//define the carry into 0 whenever i+1
			}	
		}
		
		k=0;//define the vairable
		for (i=0; i<8; i++)//move the bits of partical_product  to the right
		{
			for (j=0; j<9; j++)
			{
				if (i==0)//when i=0, the bits aren't moving
				{
					partical_product_2[i][j]= partical_product[i][j];
				}
				else//move the bits to the right depand on the value of i
				{
					partical_product_2[i][j+i]= partical_product[i][j];
				}
			}
		}
		
		for (i=1; i<8; i++)//put '0' into the space area after the bit of the partical_product move to the right in order to alignment 
		{
			for (j=0; j<i; j++)
			{
				partical_product_2[i][j]= '0';
			}
		}
		printf("\n");//switch to the next line
		
		carry=0;//define the vairable 
		for (i=0; i<18; i++)//adder
		{
			for (j=0; j<18; j++)
			{
				sum_2[i]= sum_2[i]+ change(partical_product_2[j][i]);//add all the bits of partical_product_2 together
			}
			sum_2[i]+=carry;//add the carry bits
			sum[i]=sign[sum_2[i]%16];//use the remainder when divide by 16 to find the coresponding sign
			carry= sum_2[i]/16;//calculate the carry value
		}

		if (strcmp(a,"0")== 0|| strcmp(b,"0")== 0)//when one of a or b is '0', print 0
		{
			//print the column of the multiplication
			printchar(lmax-strlen(a)+2, ' ');//printing the space before the first string
			printf("%s", a);//print string a
			printf("\n");//switch to the next line
			printf("*");//print the * sign
			printchar(lmax-strlen(b)+1, ' ');//print the space between + sign and string b
			printf("%s", b);//print string b
			printf("\n");//switch to the next line
			printchar(lmax+2, '-');// print the divide line 
			printf("\n");//switch to the next line
			printchar(lmax+1, ' ');//print the space before the addition result
			printf("%c", '0');//print the value 0
		}
		else //when the multiplication isn't going to times 0
		{
			k=0;//define the vairable
			for (i=17; i>=0; i--)//finding how many '0' before the result of the multiplication
			{
				if (sum[i]=='0')
				{
					k++;
				}
				else 
				{
					break;
				}
			}
			printchar (strlen(sum)- k- strlen(a)+ 1, ' ');//printing the space before the first string 
			printf("%s", a);//print string a
			printf("\n");//switch to the next line
			printf("*");//print the * sign
			printchar (strlen(sum)- k- strlen(b), ' ');//print the space between * sign and string b
			printf("%s", b);//print string b
			printf("\n");//switch to the next line
			printchar(strlen(sum)-k+1, '-');// print the divide line
			printf("\n");//switch to the next line
			printchar(2, ' ');//print the space before the multiplication result
				for (i=17-k; i>=0; i--)//print the multiplication result
			{
				printf("%c", sum[i]);
			}
		}
		printf("\n");//switch to the next line
		
		m=0, data=1, x=0;//define the vairable
		for (i=strlen(a); i>0; i--)//calculate the decimal value of a string
		{
			x=change(a[i-1])*data;//calculate the decimal value of each character of string a
			m+= x;//add all the value of the decimal togeter 
			data*=16;//the value of data need to times 16 every time
		}
		
		n=0, data=1, x=0;//define the vairable
		for (i=strlen(b); i>0; i--)//calculate the decimal value of b string
		{
			x=change(b[i-1])*data;//calculate the decimal value of each character of string b
			n+= x;//add all the value of the decimal togeter 
			data*=16;//the value of data need to times 16 every time
		}
		printf("%llu *",m);//print the decimal value of string a
		printf(" %llu =",n);//print the decimal value of string b
		printf(" %llu", m*n);//print the decimal value of string a times string b
		printf("\n");//switch to the next line
	}
	return 0;
}


