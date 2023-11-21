#include <stdio.h>
#include <string.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int dict[130]={0} ;
char hex[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F'} ;

void transform(char *str)
{
    char temp[20] ;
    strcpy(temp, str) ;
    for (int i=strlen(str)-1 ; i>=0 ; --i) str[i] = temp[(strlen(str)-1)-i] ;
    for (int i=strlen(str) ; i<20 ; ++i) str[i] = '0' ;
    str[19] = '\0' ;
}

void addition(char *n1, char *n2, char *sum)
{
    for (int i=0 ; i<20 ; ++i)
    {
        sum[i] =
    }
}

void print_addition(char *n1, char *n2)
{
    printf("  ") ;
    for (int i=0 ; i<strlen(n1)-strlen(n2) ; ++i) printf(" ") ;
    printf("\n") ;
    printf("+ ") ;
    for (int i=0 ; i<strlen(n2)-strlen(n1) ; ++i) printf(" ") ;
    printf("\n") ;
    for (int i=0 ; i<MAX(strlen(n1), strlen(n2))+2 ; ++i) printf("-") ;
    printf("\n") ;
}

int main()
{
    setbuf(stdout, NULL) ;
    for (int i=0 ; i<10 ; ++i) dict['0'+i] = i ;
    for (int i=0 ; i<6 ; ++i) dict['A'+i] = 10 + i ;
    while (1)
    {
        char n1[20], n2[20] , cal_n1[20], cal_n2[20] , sum[20]="0" ;
        int num1, num2 ;
        scanf("%s %s", n1, n2) ;
        printf("%s %s\n", n1, n2) ;
        sscanf(n1, "%X", &num1) ;
        sscanf(n2, "%X", &num2) ;
        if (num1==0 && num2==0) break ;
        strcpy(cal_n1, n1) ;
        strcpy(cal_n2, n2) ;
        transform(cal_n1) ;
        transform(cal_n2) ;
        transform(sum) ;

    }
    return 0;
}
