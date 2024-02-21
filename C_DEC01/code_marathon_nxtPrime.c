#include<stdio.h>
int main()
{
    int arr[5]={3,6,7,2,8};
    int max=0,min=arr[0];
    for(int i=0;i<5;i++)
        arr[i]=arr[i]*arr[i];
    for(int i=0;i<5;i++) 
        printf("%d ",arr[i]);
    for(int i=1;i<5;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("\nmax=%d  min=%d",max,min);
    int num=max-min;
    printf("\nmax - min value = %d",num);
    
    int fl=0;
    while(fl==0)
    {
        num++;
        fl=1;
        for(int i=2;i<num;++i)
        {
            if(num%i==0)
            {
                fl=0;
                break;
            }
        }
    }
    printf("\n next prime is %d",num);
}