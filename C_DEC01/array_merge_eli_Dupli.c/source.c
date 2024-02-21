#include"header.h"
#include<stdio.h>
int merge_sorted(int a[],int b[],int s1,int s2)
{
    int size=s1+s2;
    int arr[size];
    int i=0;
    int n=0,m=0,count=0;
    while(i<size)
    {
        if(a[n]<b[m])
        {
            arr[i]=a[n];
            n++;
        }
        else if(b[m]<a[n])
        {
            arr[i]=b[m];
            m++;
        }
        else
        {
            count +=1;
            continue;
        }
        i++;
    }
    int newsize=sizeof(arr)/sizeof(arr[0]);
    for(int x=0;x<newsize;x++)
        printf("%d ",arr[x]);
    printf("\ncount of duplicates= %d",count);
}