#include"header.h"
#include<stdio.h>
int main()
{
    int size;
    printf("enter size of an array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    ArraySorting(arr,size);    
}