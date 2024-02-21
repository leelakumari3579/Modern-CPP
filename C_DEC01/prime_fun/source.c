#include"header.h"
#include<stdio.h>
void check_pos_neg(int num)
{
    if(num>0)
        checkPrime(num);
    else
    {
        printf("\n re-enter the number");
        scanf("%d",&num);
        check_pos_neg(num);
    }
}
void checkPrime(int num)
{
    int i,flag=1;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("prime"); //return 1
    else    
        printf("not prime"); //return 0
}
/*
int prime(int n)   //prime series.
{
    int i,flag=1;
    if(n>0){
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("%d\n",n);
    }
}*/
