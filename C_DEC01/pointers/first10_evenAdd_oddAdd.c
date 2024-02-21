#include<stdio.h>
int even_odd_addition(int *even,int *odd)
{
    *even=0;
    *odd=0;
    for(int i=0;i<=20;i++)
    {
        if(i%2==0)
            *even +=i;
        else
            *odd +=i;
    }
    //printf("%d",*even);
   //printf("\n%d",*odd);
}
int main()
{
    int eve,od;
    even_odd_addition(&eve,&od);
    printf("%d",eve);
    printf("\n%d",od);
}