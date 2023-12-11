#include<stdio.h>
int main(void)
{
    int i,j,k=16;
    for (i=0;i<1;++i)
    {
        for (j=0;j<=32;++j)
        {
            if (i+j<17)
            {
                printf(" ");
            }
            else
            {
                printf("@");
            }
        }
        printf("\n");
    }
    for (i=0;i<=16;++i)
    {
        for (j=0;j<=15;++j)
        {
            if (i+j<=15)
            {
                printf(" ");
            }
        }
        printf("@");
        for(j=1;j<=k;j++){
            printf("*");
        }
        printf("@");
        k=k+2;
        printf("\n");
    }
    for (j=0;j<=49;++j)
    {
        printf("@");
    }
    printf("\n");
    for (int i=0;i<10;++i)
    {
        for (j=0;j<=49;++j)
        {
            if (i<=5)
            {
                if (j==3||j==4||j==44||j==45)
                {
                    printf("%%");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    for (int i=0;i<=3;++i)
    {
        for (j=0;j<=49;++j)
        {
            if(i<=3)
            {
                if (j==3||j==4||j==44||j==45)
                {
                    printf("%%");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
