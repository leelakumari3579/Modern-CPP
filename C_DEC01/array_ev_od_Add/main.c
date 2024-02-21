#include"header.h"
#include<stdio.h>
int main()
{
    int size;
    printf("eneter size of an array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    even_odd(arr,size);
}