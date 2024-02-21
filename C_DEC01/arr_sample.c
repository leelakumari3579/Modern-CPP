#include<stdio.h>
int main()
{

// reverse of an array.

   // int arr[]={21,32,13,345,76}; -->diclaration and assigning array elements
    //int arr1[20];                -->declaration
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int j=0,k=n-1,temp;
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    //for (int i=n-1;i>=0;i--)
      //  printf("%d\t",arr[i]);
    while(j<k)
    {
        temp=arr[j];
        arr[j]=arr[k];
        arr[k]=temp;
        j=j+1;
        k=k-1;
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}