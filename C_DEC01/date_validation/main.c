#include"header.h"
#include<stdio.h>
int main()
{
    int day,month,year;
    printf("enter date: ");
    scanf("%d %d %d",&day,&month,&year);
    date_valid(day,month,year);
}