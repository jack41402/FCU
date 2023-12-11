#include <stdio.h>
#include <math.h>
int main(void)
{
    long long int a,b,c;
    double root1,root2,D,x,y;//D為判別式開根號，x為i的係數，ｙ為-b/(2*a)
    printf("Solving roots of equation a*X^2+b*X+c = 0.\n"
           "Please enter three integer coefficients a, b, and c (a must not be equal to 0): \n");
    scanf("%lld%lld%lld", &a,&b,&c);
    while(a==0)//使a不為0
    {
        printf("Please enter three integer coefficients a, b, and c again (a must not be equal to 0): \n");
        scanf("%lld%lld%lld", &a,&b,&c);
    }
    D=pow(b*b-4*a*c,0.5);//判別式開根號
    root1=(-b+D)/(2*a);//公式解其中一根
    root2=(-b-D)/(2*a);//公式解另一根
    x=pow(4*a*c-b*b,0.5)/(2*a);
    y=-b/(2.*a);//加小數點變成double型別
    if(root1==0)
    {
        root1=0;
    }
    if(root2==0)
    {
        root2=0;
    }
    if(D==0)//重根
    {
        printf("The multiple real root of equation ");
    }
    else if(D>0)//兩相異實根
    {
        printf("The real roots of equation ");
    }
    else//共軛虛根
    {
        printf("The complex roots of equation ");
    }
    if(a!=0)//不用寫if(a==0)因為a==0時不用印
    {
        if(a==1)
            printf("X**2");
        else if(a==-1)
            printf("-X**2");
        else
            printf("%lldX**2", a);
    }
    if(b!=0)//不用寫if(b==0)因為b==0時不用印
    {
        if(b==1)
            printf("+X");
        else if(b==-1)
            printf("-X");
        else if(b>0)
            printf("+%lldX", b);
        else
            printf("%lldX", b);
    }
    if(c!=0)//不用寫if(c==0)因為c==0時不用印
    {
        if(c>0)
            printf("+%lld", c);
        else
            printf("%lld", c);
    }
    printf("=0 ");
    if(D==0)
    {
        printf("is %.4f.\n", root1);//取四位小數的重根
    }
    else if(D>0)
    {
        printf("are %.4f and %.4f.\n", root1, root2);//取四位小數的兩相異實根
    }
    else if(y==0)
    {
        printf("are %.4fi and -%.4fi.\n", x,x);//取四位小數且實部為0的兩共軛虛根
    }
    else
    {
        printf("are %.4f+%.4fi and %.4f-%.4fi.\n", y,x,y,x);//取四位小數且實部不為0的兩共軛虛根
    }
    return 0;
}
