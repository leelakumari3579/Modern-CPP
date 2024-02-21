#include<stdio.h>
int function(int num1)
{
    int max=0;
    while(num1!=0)
    {
        num1=num1%10;
        if(num1>max)
        {
            max=num1;
        }
        num1=num1/10;
    }
    printf("largest digit in given number %d",max);
}
int main()
{
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    function(num);
}