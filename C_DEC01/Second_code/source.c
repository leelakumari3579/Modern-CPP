#include"header.h"
#include<stdio.h>
int ArraySorting(int arr[],int size)
{
    int e=0,o=0;
    int temp1=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        {
            e +=1;
        }
        else
        {
            o +=1;
        }
    }
    int even[e],odd[o];
    int j=0,k=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        {
            even[j]=arr[i];
            j++;
        }
        else
        {
            odd[k]=arr[i];
            k++;
        }
    }
    for(int i=0;i<e;i++)
    {
        for(int ev=i+1;ev<e;ev++)
        {
            if(even[i]>=even[ev])
            {
             temp1=even[i];
             even[i]=even[ev];
             even[ev]=temp1;
            }
        }
    }
    //for(int i=0;i<e;i++)
       // printf("\n%d ",even[i]);

    for(int i=0;i<o;i++)
    {
        for(int od=i+1;od<o;od++)
        {
            if(odd[i]<=odd[od])
            {
             temp1=odd[i];
             odd[i]=odd[od];
             odd[od]=temp1;
            }
        }
    }
    //for(int i=0;i<o;i++)
      //  printf(" %d ",odd[i]);
    for(int i=0;i<e;i++)
    {
        arr[i]=even[i];
    }
    for(int i=0;i<o;i++)
    {
        arr[e+i]=odd[i];
    }
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}