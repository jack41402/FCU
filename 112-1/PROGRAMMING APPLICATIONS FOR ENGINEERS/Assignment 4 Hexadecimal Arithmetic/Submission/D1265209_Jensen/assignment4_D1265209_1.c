#include<stdio.h>
#include<string.h>

void printChar(int n, char c) 
{
 int i;
 for (i=0; i<n; i++) 
 printf("%c", c);
}
// transfer hexadecimal to decimal
char hextodecimal(char c) 
{
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    } 
    else if(c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    } 
}
//transfer decimal to hexadecimal
char decimaltohex(int a)
{
    if (a >= 0 && a <= 9) 
    {
        return a + '0';
    } 
    else if (a >= 10 && a <= 15) 
    {
        return a - 10 + 'A';
    }
}

//thransfer hexadecimal to decimal
unsigned long long hexdecimal(char *hexa) {
    unsigned long long decimal = 0;
    int i;
    for (i = 0; i < strlen(hexa); i++) 
    {
        char c = hexa[i];
        int digitValue;
        if (c >= '0' && c <= '9') 
        {
            digitValue = c - '0';
        } else if (c >= 'A' && c <= 'F') 
        {
            digitValue = c - 'A' + 10; 
        }  
        decimal = decimal * 16 + digitValue;
    }
    return decimal;
}

int main()
{
    //declare the value
    char n1[17], n2[17], sum[17];
    int carry;
    int l1, l2;
    int lmax, lmin;
    int d_sum;
    int i;
    // scan the number and make sure the number not equal 0 in both
    while (scanf("%s %s", n1, n2)==2)
    {
        if(strcmp(n1, "0")==0 && strcmp(n2, "0")==0)
        break;
        l1 = strlen(n1);
        l2 = strlen(n2);
        //judge which number is longer
        if(l1 >= l2)
        {
            lmax = l1;
            lmin = l2;
        }
        else
        {
            lmax = l2;
            lmin = l1;
        }
        //run for addtion
        carry = 0;
        for(i=0; i<lmax; i++)
        {
            if(i<lmin)
            sum[lmax - (i+1)] = hextodecimal(n1[l1 - (i+1)]) + hextodecimal(n2[l2 - (i+1)]) + carry;
            //only the longer number still exist
            else if(i<l1)
            sum[lmax - (i+1)] = hextodecimal(n1[l1 - (i+1)]) + carry;
            else if(i<l2)
            sum[lmax - (i+1)] = hextodecimal(n2[l2 - (i+1)]) + carry;
            //calculate the carry
            carry = sum[lmax - (i+1)] / 16;
            sum[lmax - (i+1)] = decimaltohex(sum[lmax - (i+1)] % 16);
        }
        //if last number still carry
        if (carry==1) 
        {
	        sum[lmax+1] = '\0'; 
            //move one more digite for carry
	        for (i=lmax; i>0; i--) sum[i] = sum[i-1]; 
	        sum[0] = '1';
        }
        else sum[lmax] = '\0'; 
        //print out
        //count the space before each number
        //print the number
        //print the sum
        printChar(l2-l1, ' '); 
        printChar(carry+2, ' ');
        printf("%s\n", n1);
        printf("+"); 
        printChar(l1-l2, ' '); 
        printChar(carry+1, ' '); 
        printf("%s\n", n2); // 
        printChar(lmax+carry+2, '-'); 
        printf("\n  %s\n", sum);
        printf("%llu + %llu = %llu", hexdecimal(n1), hexdecimal(n2), hexdecimal(sum));
        //make sure the sum does not overflow
        if (strlen(sum)==17 && sum[0]>='1') 
        printf("    ****Overflow!!!\n\n"); 
        else printf("\n\n");
    }
}