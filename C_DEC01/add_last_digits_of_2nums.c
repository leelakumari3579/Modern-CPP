#include<stdio.h>
int add(int n,int m)
{
    int a=n%10;
    int b=m%10;
    return a+b;
}
int main()
{
    int x,y;
    printf("enter first number: ");
    scanf("%d",&x);
    printf("enter first number: ");
    scanf("%d",&y);
    int result = add(x,y);
    printf("addition of last digits of %d and %d is: %d",x,y,result);
}