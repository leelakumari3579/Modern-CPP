#include<stdio.h>
#include"header.h"
int genNumSeq(int num)
{
    int pattern=3;
    if(num>0 && num<=30)
    {
        while(num!=0)
        {
            printf("%d ",pattern);
            pattern=pattern*2-1;
            num--;
        }
    }
    else
    {
        printf("re-enter the number: ");
        scanf("%d",&num);
        genNumSeq(num);
    }
}
