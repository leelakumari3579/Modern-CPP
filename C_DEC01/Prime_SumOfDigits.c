#include <stdio.h>

void isPrime(int n, int flag)
{
    if(n==0 || n==1)
        flag = 0;
        // return 0;
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        {
            flag = 0;
            break;
        }
    }
    // return 1;
    if(flag)
        printf("GOOGLY");
    else
        printf("NOT GOOGLY");
}

int main()
{
    int flag = 1;
    int num,n=0,rem;
    printf("enter number ");
    scanf("%d",&num);
    while(num>0)
    {
        rem = num%10;
        n = n + rem;
        num = num/10;
    }
    // int flag = isPrime(n);
    isPrime(n,flag);
    // if(flag)
    //     printf("GOOGLY");
    // else
    //     printf("NOT GOOGLY");
}