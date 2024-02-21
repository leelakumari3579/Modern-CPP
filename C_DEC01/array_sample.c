#include<stdio.h>
int main()
{
    int arr[]={10,20,11};
    int arr1[]={29,30,40,71,70,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int i=0,n=0,m=0;
    int arr2[9];
    while(i<size && i<size1)
    {
        arr2[i]=arr[n];
        n++;
        i++;
        arr2[i]=arr1[m];
        m++;
        i++;
    }
    while(n<size)
    {
        arr2[i]=arr[n];
        n++;
        i++;
    }
    while(m<size1)
    {
        arr2[i]=arr1[m];
        m++;
        i++;
    }
    for(int j=0;j<9;j++)
        printf("%d ",arr2[j]);
}