#include<stdio.h>
int last2digit(int n)
{
    int res;
    n=n/10;
    res=n%10;
    printf("second digit from last: %d",res);
}
int main()
{
    int a;
    printf("enter a value: ");
    scanf("%d",&a);
    last2digit(a);
}