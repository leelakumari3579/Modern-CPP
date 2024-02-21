#include"header1.h"
#include<stdio.h>
int fib(int n)
{
    int i,f1=1,f2=1,f3;
    for(i=2;i<n;i++)
    {
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    return f3;
}