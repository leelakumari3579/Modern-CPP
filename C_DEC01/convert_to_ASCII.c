#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a;
    printf("enter a value ");
    scanf("%c",&a);
    if(a>='A' && a<='Z')
    {
        printf("upper\n");
        int con=a+32;
        printf("%cconverted character = %c",a,con);
    }
    else if(a>='a' && a<='z')
    {
        printf("lower\n");
        int con=a-32;
        printf("%cconverted character = %c",a,con);
    }
    else if(isdigit(a)) 
    {
        printf("digit");
        /*int num;
        num=(int)(a);
        int d;
        while(num!=0)
        {
            d=num%10;
            printf("%d\t",d);
            num /= 10;
        }*/
        printf("\nASCII value of %c is %d",a,a);
    }
    else
    {
        printf("not a valid character");
    }
}