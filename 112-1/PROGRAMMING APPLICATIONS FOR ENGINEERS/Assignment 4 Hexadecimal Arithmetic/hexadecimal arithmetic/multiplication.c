#include <stdio.h>
#include <string.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define swap(a, b) {typeof(a) temp=a; a=b; b=temp;}

int dict[130]={0} ;
char hex[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F'} ;

void printChar(int n, char ch)
{
    for (int i=0 ; i<n ; ++i) printf("%c", ch) ;
}

void transform(char *str)
{
    char temp[20] ;
    strcpy(temp, str) ;
    for (int i=strlen(str)-1 ; i>=0 ; --i) str[i] = temp[(strlen(str)-1)-i] ;
    for (int i=strlen(str) ; i<20 ; ++i) str[i] = '0' ;
    str[19] = '\0' ;
}

void addition(const char *n1, const char *n2, char *sum)
{
    int carry=0 ;
    for (int i=0 ; i<20 ; ++i)
    {
        sum[i] = hex[(dict[n1[i]]+dict[n2[i]]+carry)%16] ;
        carry = (dict[n1[i]]+dict[n2[i]]+carry) / 16 ;
    }
    for (int i=18 ; i>=0 ; --i)
    {
        if (sum[i]!='0') break ;
        else sum[i] = '\0' ;
    }
}

void multiplication(const char *n1, const char n2, int shift, char *sum)
{
    int carry=0 ;
    for (int i=shift, j=0 ; i<19 ; ++i, ++j)
    {
        sum[i] = hex[(dict[n1[j]]*dict[n2]+carry)%16] ;
        carry = (dict[n1[j]]*dict[n2]+carry) / 16 ;
    }
}

void print_multiplication(const char *n1, const char *n2, const char *sum)
{
    int max_length=max(strlen(n1), max(strlen(n2), strlen(sum))) ;
    printChar(2+max_length-strlen(n1), ' ') ;
    printf("%s\n*", n1) ;
    printChar(1+max_length-strlen(n2), ' ') ;
    printf("%s\n", n2) ;
    printChar(2+max_length, '-') ;
    printf("\n") ;
    printChar(2+max_length-strlen(sum), ' ') ;
    printf("%s\n", sum) ;
}

int main()
{
    setbuf(stdout, NULL) ;
    for (int i=0 ; i<10 ; ++i) dict['0'+i] = i ;
    for (int i=0 ; i<6 ; ++i) dict['A'+i] = 10 + i ;
    while (1)
    {
        char n1[20], n2[20] , cal_n1[20], cal_n2[20] , sum[20]={0} ;
        printf("%s\n", sum);
        unsigned long long int num1, num2 ;
        scanf("%s %s", n1, n2) ;
        sscanf(n1, "%llx", &num1), sscanf(n2, "%llx", &num2) ;
        if (num1==0 && num2==0) break ;
        strcpy(cal_n1, n1), strcpy(cal_n2, n2) ;
        transform(cal_n1), transform(cal_n2), transform(sum) ;
        for (int i=0 ; i< strlen(cal_n2) ; ++i)
        {
            char temp[20], sum_copy[20] ;
            transform(temp) ;
            multiplication(cal_n1, cal_n2[i], i, temp) ;
            printf("temp: %s\n", temp) ;
            strcpy(sum_copy, sum) ;
            addition(temp, sum_copy, sum) ;
            printf("sum: %s\n", sum) ;
        }
        for (int i=0 ; i<strlen(sum)/2 ; ++i) swap(sum[i], sum[strlen(sum)-i-1])
        print_multiplication(n1, n2, sum) ;
//        printf("%llu + %llu = %llu", num1, num2, num1+num2) ;
//        if (strlen(sum)>16) printf("\t****Overflow!!!") ;
//        printf("\n\n") ;
    }
    return 0;
}
