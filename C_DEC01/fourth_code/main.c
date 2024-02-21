#include"header.h"
#include<stdio.h>
int main()
{
    int start;
    printf("enter the starting point");
    scanf("%d",&start);
    int end;
    printf("enter the ending point");
    scanf("%d",&end);
    fndMaxFreqDigit(start,end);
}