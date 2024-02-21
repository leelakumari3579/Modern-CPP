#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int a;
    printf("enter a value: ");
    scanf("%d",&a);
    if(a%2==0)
        printf("even number");
    else
        printf("odd number");
    return 0;
}