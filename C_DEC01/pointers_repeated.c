#include<stdio.h>
#define size 5
int repeated(int *p,int x)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(x==p[i])
            count +=1;
    }
    printf("%d",count);
}
int main()
{
    int a[size]={7,8,55,7,70};
    int x=7;
    repeated(a,x);
    return 0;
}