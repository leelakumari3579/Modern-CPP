#include"header.h"
#include<stdio.h>
int date_valid(int day,int month,int year)
{
    if(year>=1900 && year<=2023)
    {
        if(month>=1 && month<=12)
        {
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                printf("valid date");
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                printf("valid date");
            else if(( day<=28) && (month==2))
                printf("valid date");
            else if((day==29) && (month==2))
            {
                if((year%400==0) || (year%4==0 && year%100!=0))
                    printf("valid date");
            }
            else
                printf("not a valid date");
        }
        else
            printf("not a valid month");
    }
    else
        printf("not a valid year");
}