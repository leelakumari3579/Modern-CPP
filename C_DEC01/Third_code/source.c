#include"header.h"
#include<stdio.h>
void selection(struct candidate a[])
{
    int id=0,sum=0;
    float avg=0,max_avg=0;
    for(int i=0;i<3;i++)
    {
        sum += a[i].scores[0]+a[i].scores[1]+a[i].scores[2];
        avg=(float)sum/3;
        sum=0;
        if(max_avg<avg)
        {
            max_avg=avg;
            id +=1;
        }
    }
    printf("candidate%d scores average = %f",id,max_avg);
}