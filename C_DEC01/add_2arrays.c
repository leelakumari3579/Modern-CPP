#include<stdio.h>
int main()
/*{
    int a[4]={10,20,30,20};
    int length=sizeof(a)/sizeof(a[0]);
    int b[7]={11,21,31,42,50,78,90};
    if(sizeof(b)/sizeof(b[0])>length)
        length=sizeof(b)/sizeof(b[0]);
    int res[length];
    for(int i=0;i<length;i++)
    {
        res[i]=(i<sizeof(a)/sizeof(a[0])?a[i]:0)+(i<sizeof(b)/sizeof(b[0])?b[i]:0);
    }
    for(int k=0;k<length;k++)
        printf("%d ",res[k]);
}*/
{
    int arr[]={10,30,40,50};
    int arr2[]={10,59,29,40,70,80,90};
    int s1=sizeof(arr)/sizeof(arr[0]);
    int s2=sizeof(arr2)/sizeof(arr2[0]);
    int i=0,j=0,k=0;
    int size=(sizeof(arr)/sizeof(arr[0])>=sizeof(arr2)/sizeof(arr2[0])?s1:s2);
    int arr3[size];
    while(i<s1 && j<s2)
    {
        arr3[k]=arr[i]+arr2[j];
        i++;
        j++;
        k++;
    }
    while(i<s1)
    {
        arr3[k]=arr[i];
        i++;
        k++;
    }
    while(j<s2)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    for(int n=0;n<sizeof(arr3)/sizeof(arr3[0]);n++)
        printf("%d ",arr3[n]);
}