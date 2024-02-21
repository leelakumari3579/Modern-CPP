#include<stdio.h>
int main()
{
    int arr[]={1,20,3};
    int arr1[]={8,2,28,82,2,2,1,4,6};
    int s1=sizeof(arr)/sizeof(arr[0]);
    int s2=sizeof(arr1)/sizeof(arr1[0]);
    int size=sizeof(arr)/sizeof(arr[0])+sizeof(arr1)/sizeof(arr1[0]);
    //printf("%d\n",size);
    int arr2[size];
    int i=0,n=0,m=0;
    while(i<s1 && i<s2)//for(int i=0;i<size;i++)
    {
        arr2[i]=arr[n];
        i++;
        arr2[i]=arr1[m];
        i++;
        n++;
        m++;
    }
    while(n<s1)
    {
        arr2[i]=arr[n];
        n++;
        i++;
    }
    while(m<s2)
    {
        arr2[i]=arr1[m];
        m++;
        i++;
    }
    for(int j=0;j<size;j++)
    {
        printf("%d\n",arr2[j]);
    }
}