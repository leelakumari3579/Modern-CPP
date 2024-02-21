#include<stdio.h>
int main()
/*{
    int n,rem,i=0,arr[4];
    printf("enter n value");
    scanf("%d",&n);
    while(n!=0)
    {
        rem=n%2;
        arr[i]=rem;
        i++;
        n=n/2;
    }
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int k=0;k<size;k++)
        printf("%d ",arr[k]);
    for(int j=0;j<size;j++)
    {
        if(arr[j]==1)
            printf("\n* ");
        else
            continue;
    }
}*/
{
    int n,rem=0;
    printf("enter n value");
    scanf("%d",&n);
    while(n!=0)
    {
        rem=n%2;
        if(rem==1)
            printf("* ");
        else if(rem==0)
        {
            n=n/2;
            continue;
        }
        else
            printf("not accepted");
        n=n/2;
    }
}