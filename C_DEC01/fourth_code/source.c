#include"header.h"
#include<stdio.h>
int fndMaxFreqDigit(int start,int end)
{
   int d=0,rem=0;
    int count=0;
    int d_count=0;
    for(int i=start;i<=end;i++)
    {
        int j=i;
        while(j!=0)
        {
            d=j%10;
            count +=1;
            j = j/10;
            //printf("%d ",d);
        }
    }
    int arr[count],k=0;
    for(int i=start;i<=end;i++)
    {
        int j=i;
        while(j!=0)
        {
            rem=j%10;
            arr[k]=rem;
           // printf("%d ",rem);
           // printf("\n%d ",arr[k]);
            j=j/10;
            k++;
        }
    }
    for(int i=0;i<count;i++)
    {
        for(int x=i+1;x<count;x++)
        {
            if(arr[i]==arr[x])
            {
                d_count +=1;
                //printf("%d ",arr[i]);
                //printf("\t%d ",d_count);
            }
        }
    }
    int a[d_count],l=0;
    for(int i=0;i<count;i++)
    {
        for(int x=i+1;x<count;x++)
        {
            if(arr[i]==arr[x])
            {
                a[l]=arr[x];
                //printf("\n%d ",a[l]);
                l++;
            }
        }
    }
    int least=0;
    for(int i=0;i<d_count;i++)
    {
        for(int j=i+1;j<d_count;j++)
        {
            if(a[i]<a[j])
                least=a[i];
        }
    }
    printf("maximum frequency from %d to %d is digit %d",start,end,least);
}