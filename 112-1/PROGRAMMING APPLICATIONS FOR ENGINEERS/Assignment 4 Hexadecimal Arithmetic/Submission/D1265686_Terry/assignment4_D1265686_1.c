//
//  main.c
//  assignment4_D1265686_1
//
//  Created by 何柏勳 on 2023/11/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Print n times of character c.
void printchar(int n, char c) {
 int i; // Loop vairable.
 
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}


int main()
{
    char in1[17]; //input 1
    char in2[17]; //input 2
    

    int i,a,b; //a is the length of in1; b is the length of in2.
    
    while(scanf("%s %s", in1, in2)==2){
        if(strcmp(in1,"0")==0&&strcmp(in2,"0")==0) break;
        
        
        a=strlen(in1);
        b=strlen(in2);
        
        
        int in11[17],in22[17];
        for(i=0;i<a;++i) //Convert each one to decimal one by one
        {
            if(in1[i]>='0'&&in1[i]<='9')
            {
                in11[i]=in1[i]-'0';
            }
            else
            {
                in11[i]=in1[i]-'A'+10;
            }
        }
        
        for(i=0;i<b;++i)
        {
            if(in2[i]>='0'&&in2[i]<='9')
            {
                in22[i]=in2[i]-'0';
            }
            else
            {
                in22[i]=in2[i]-'A'+10;
            }
        }
        
        
        int max,min;
        if(a>b) // Determine who is longer
        {
            max=a;
            min=b;
        }
        else
        {
            max=b;
            min=a;
        }
        
        int carry=0;
        int sum[18];
        
        for(i=0;i<max;++i) //Perform hexadecimal arithmetic and add each of them up one by one.
        {
            if(i<min)
                sum[max-i-1]=in11[a-i-1]+in22[b-i-1]+carry;
            else if(i<a)
            {
                sum[max-i-1]=in11[a-i-1]+carry;
            }
            else if(i<b)
            {
                sum[max-i-1]=in22[b-i-1]+carry;
            }
            carry=sum[max-i-1]/16;
            
            sum[max-i-1]=sum[max-i-1]%16 ;
            
            
        }
        if(carry==1) //Determine whether to carry or not
        {
            sum[max+1]='\0';
            for(i=0;i<max;++i)
            {
                sum[max-i]=sum[max-i-1];
            }
            sum[0]=1;
            max=max+1;
        }
        
        //print out the result and then make sure the format meets requirements
        printchar(2,' ');
        printchar(max-a,' ');
        printf("%s\n",in1);
        printf("+ ");
        printchar(max-b,' ');
        printf("%s\n",in2);
        printchar(max+2,'-');
        printf("\n");
        
        char sum2[17];
        for(i=0;i<max;++i)
        {
            if(sum[i] >= 0 && sum[i] <= 9)
            {
                sum2[i]=sum[i]+'0';
            }
            else
            {
                sum2[i]=sum[i]+'A'-10;
            }
        }
        sum2[max]='\0';
        printchar(2,' ');
        
        printf("%s ",sum2);
        
        
        
        printf("\n");
        
        unsigned long in111=0;
        for(i=0;i<a;++i) //Convert the result to decimal
        {
            if(in1[i]>='0' && in1[i]<='9')
            {
                in111=in111*16+(in1[i]-'0');
            }
            else if(in1[i]>='A' && in1[i]<='F')
            {
                in111=in111*16+(in1[i]-'A'+10);
            }
        }
        unsigned long in222=0;
        for(i=0;i<b;++i) //Convert the result to decimal
        {
            if(in2[i]>='0' && in2[i]<='9')
            {
                in222=in222*16+(in2[i]-'0');
            }
            else if(in2[i]>='A' && in2[i]<='F')
            {
                in222=in222*16+(in2[i]-'A'+10);
            }
        }
        printf("%lu",in111);
        printf(" + ");
        printf("%lu",in222);
        printf(" = ");
        
        unsigned long p;
        p=in111+in222;
        printf("%lu",p);
        
        //Determine whether is overflow or not
        if (strlen(sum2) > 16 || (strlen(sum2) == 16 && strcmp(sum2, "FFFFFFFFFFFFFFFF") > 0))
            printf("    ****Overflow!!!\n\n");
        else printf("\n\n");
    }
}

