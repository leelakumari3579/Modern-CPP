#include"header.h"
#include<stdio.h>
int reverse(int num)
{
    int rem=0,rev=0;
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return "reverse of a number",rev;
}