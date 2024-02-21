#include"header1.h"
#include<stdio.h>
int main()
{
    int num;
    printf("enter number: ");
    scanf("%d",&num);
    int res=fib(num);
    printf("%d",res);
}